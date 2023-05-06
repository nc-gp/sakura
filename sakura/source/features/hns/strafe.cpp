#include "../../client.h"

bool Sakura::HNS::Strafe::Packet = false;
bool Sakura::HNS::Strafe::Active = false;

float FrameCount;
float FpsCount;
float InterpFps;
float PreStrafe;
float JumpOff;

float Keyforwardm = false;
float Keymoveleft = false;
float Keymoveright = false;
float Keyback = false;
float Keyduck = false;
float Keyjump = false;

bool Cstrafe = false;

Vector vStart, vEnd;
Vector vStartjumppos;
float flJumpdist;
float flJumpmesstime;
bool bJumped;

float YawForVec(float* fwd)
{
	if (fwd[1] == 0 && fwd[0] == 0)
		return 0;
	else
	{
		float yaw = atan2(fwd[1], fwd[0]) * (180 / M_PI);
		if (yaw < 0)yaw += 360;
		return yaw;
	}
}

inline float EndSpeed(float StartSpeed, float gravity, float frametime, float distance)
{
	while (distance > 0)
	{
		StartSpeed += gravity * frametime;
		float dist = StartSpeed * frametime;
		distance -= dist;
	}
	return StartSpeed;
}

inline float interp(float s1, float s2, float s3, float f1, float f3)
{
	if (s2 == s1)return f1;
	if (s2 == s3)return f3;
	if (s3 == s1)return f1;
	return f1 + ((s2 - s1) / (s3 - s1)) * ((f3 - f1)/*/1*/);
}

float Damage()
{
	Vector start = pmove->origin;
	Vector vForward, vecEnd;
	float va[3];
	g_Engine.GetViewAngles(va);
	g_Engine.pfnAngleVectors(va, vForward, NULL, NULL);
	vecEnd[0] = start[0] + vForward[0] * 8192; vecEnd[1] = start[1] + vForward[1] * 8192; vecEnd[2] = start[2] + vForward[2] * 8192;
	pmtrace_t* trace = g_Engine.PM_TraceLine(start, vecEnd, 1, 2, -1);
	float fDistance = ((start.z) - (trace->endpos.z)) - (pmove->flags & FL_DUCKING) ? 18.0f : 36.0f;
	float endSpeed = EndSpeed(pmove->flFallVelocity, 800, 1 / 1000.0f, fDistance);
	if (interp(504.80001f, endSpeed, 1000, 1, 100) > 0)
		return interp(504.80001f, endSpeed, 1000, 1, 100);
	else return 0;
}

float Damage2()
{
	float endSpeed = EndSpeed(pmove->flFallVelocity, 800, 1 / 1000.0f, g_Local.flHeightorigin);
	if (interp(504.80001f, endSpeed, 1000, 1, 100) > 0)
		return interp(504.80001f, endSpeed, 1000, 1, 100);
	else return 0;
}

void TraceEdge(int x,int y, float& mind)
{
	Vector start = pmove->origin;
	start[2] -= 0.1f;
	Vector end = start;
	end[1] += x * mind;
	end[0] += y * mind;
	pmtrace_s* t1 = g_Engine.PM_TraceLine(end, start, 1, (pmove->flags & FL_DUCKING) ? 1 : 0, -1);
	if (!(t1->startsolid))
		mind = (t1->endpos - start).Length2D();
}

inline float EdgeDistance() 
{
	float mind = 250;
	TraceEdge(-1, 0, mind);
	TraceEdge(1, 0, mind);
	TraceEdge(0, 1, mind);
	TraceEdge(0, -1, mind);
	TraceEdge(-1, -1, mind);
	TraceEdge(1, 1, mind);
	TraceEdge(1, -1, mind);
	TraceEdge(-1, 1, mind);
	return mind;
}

void Kz(float frametime, struct usercmd_s *cmd)
{
	if (bJumped && (pmove->flags & FL_ONGROUND || pmove->movetype == MOVETYPE_FLY))
	{
		Vector endpos = pmove->origin;

		endpos.z -= (pmove->flags & FL_DUCKING) ? 18.0f : 36.0f;
		vEnd = endpos;

		if (endpos.z == vStartjumppos.z)
		{
			Vector lj = endpos - vStartjumppos;
			float dist = lj.Length() + 32.0625f + 0.003613;

			if (dist >= 200)
			{
				InterpFps = FpsCount / FrameCount;
				FpsCount = 0;
				FrameCount = 0;
				flJumpdist = dist;
				flJumpmesstime = GetTickCount() + (int)cvar.kz_display_time * 1000;
			}
		}

		bJumped = false;
	}

	if (!bJumped && (pmove->flags & FL_ONGROUND) && cmd->buttons & IN_JUMP)
	{
		PreStrafe = pmove->velocity.Length2D();

		if (EdgeDistance() != 250)
			JumpOff = EdgeDistance();
		else 
			JumpOff = 0;

		vStartjumppos = pmove->origin;
		vStartjumppos.z -= (pmove->flags & FL_DUCKING) ? 18.0f : 36.0f;
		vStart = vStartjumppos;
		bJumped = true;
	}

	if (cmd->buttons & IN_FORWARD) 
		Keyforwardm = true;
	else 
		Keyforwardm = false;

	if (cmd->buttons & IN_MOVELEFT) 
		Keymoveleft = true;
	else 
		Keymoveleft = false;

	if (cmd->buttons & IN_MOVERIGHT) 
		Keymoveright = true;
	else 
		Keymoveright = false;

	if (cmd->buttons & IN_BACK) 
		Keyback = true;
	else 
		Keyback = false;

	if (cmd->buttons & IN_DUCK) 
		Keyduck = true;
	else 
		Keyduck = false;

	if (cmd->buttons & IN_JUMP) 
		Keyjump = true;
	else 
		Keyjump = false;
}


void Sakura::HNS::Strafe::Logic(usercmd_s* cmd)
{
	if (!cvar.kz_strafe)
		return;

	if (!Active)
		return;

	if (!(pmove->flags & FL_ONGROUND) && (pmove->movetype != MOVETYPE_FLY) && !(cmd->buttons & IN_ATTACK) && !(cmd->buttons & IN_ATTACK2 && IsCurWeaponKnife()))
	{
		if (cvar.kz_strafe_psilent ? !Packet : 1)
		{
			if (cvar.kz_strafe_psilent)
				bSendpacket(false);

			if (pmove->velocity.Length2D() < 15)
				cmd->forwardmove = 400, cmd->sidemove = 0;
			else
			{
				float dir = 0;
				if (cmd->buttons & IN_MOVERIGHT)
					dir = 90;
				if (cmd->buttons & IN_BACK)
					dir = 180;
				if (cmd->buttons & IN_MOVELEFT)
					dir = -90;

				Vector ViewAngles;

				g_Engine.GetViewAngles(ViewAngles);
				ViewAngles.y += dir;

				Vector vspeed = Vector(pmove->velocity.x / pmove->velocity.Length(), pmove->velocity.y / pmove->velocity.Length(), 0.0f);
				float va_speed = YawForVec(vspeed);
				float adif = va_speed - ViewAngles.y;

				while (adif < -180)
					adif += 360;

				while (adif > 180)
					adif -= 360;

				cmd->sidemove = (437.8928) * (adif > 0 ? 1 : -1);
				cmd->forwardmove = 0;
				cmd->viewangles.y -= (-adif);

				float sdmw = cmd->sidemove;
				float fdmw = cmd->forwardmove;

				if (cmd->buttons & IN_MOVERIGHT)
					cmd->forwardmove = -sdmw, cmd->sidemove = fdmw;

				if (cmd->buttons & IN_BACK)
					cmd->forwardmove = -fdmw, cmd->sidemove = -sdmw;

				if (cmd->buttons & IN_MOVELEFT)
					cmd->forwardmove = sdmw, cmd->sidemove = -fdmw;
			}
		}

		if (cvar.kz_strafe_psilent)
			Packet = !Packet;
	}
	else
		Packet = false;
}

void KzFameCount()
{
	if (bJumped)
	{
		FrameCount += 1;
		FpsCount += (1 / pmove->frametime);
	}
}

void DrawKzWindows()
{
	if (!cvar.kz_show_kz)
		return;

	if (!Sakura::Player::Local::IsAlive())
		return;

	ImVec2 windowpos;
	ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.0f, 0.0f, 0.0f, 0.25f));
	ImGui::SetNextWindowPos(ImVec2(20, (ImGui::GetIO().DisplaySize.y / 2) - ImGui::GetIO().DisplaySize.y / 20 * 1), ImGuiCond_Once);
	ImGui::Begin(/*kz*/XorStr<0x1C, 3, 0x85263541>("\x77\x67" + 0x85263541).s, NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize);
	{
		ImVec4 col_default_text = ImGui::GetStyleColorVec4(ImGuiCol_Text);
		ImVec4 col = col_default_text;
		ImVec4 col2 = col_default_text;
		static float fMaxPspeed = 0.f;
		if (pmove->velocity.Length2D() == 0)
			fMaxPspeed = 0.0;
		if (pmove->velocity.Length2D() > fMaxPspeed)
			fMaxPspeed = pmove->velocity.Length2D();
		if (Damage() >= g_Local.iPostHealth)
			col = ImColor(1.f, 0.f, 0.f, 1.0f);
		if (Damage2() >= g_Local.iPostHealth)
			col2 = ImColor(1.f, 0.f, 0.f, 1.0f);

		if (flJumpmesstime > GetTickCount())
		{
			ImGui::Text(/*Display Time:   %.1f*/XorStr<0x0B, 21, 0xBF337B20>("\x4F\x65\x7E\x7E\x63\x71\x68\x32\x47\x7D\x78\x73\x2D\x38\x39\x3A\x3E\x32\x2C\x78" + 0xBF337B20).s, (flJumpmesstime - GetTickCount()) / 1000);
			ImGui::TextColored(ImVec4(1.f, 0.f, 1.f, 1.f), /*Fps:            %.1f*/XorStr<0x0F, 21, 0x8B186DF7>("\x49\x60\x62\x28\x33\x34\x35\x36\x37\x38\x39\x3A\x3B\x3C\x3D\x3E\x3A\x0E\x10\x44" + 0x8B186DF7).s, InterpFps);
			ImGui::TextColored(ImVec4(1.f, 0.f, 1.f, 1.f), /*Jump Off Edge:  %.1f*/XorStr<0x94, 21, 0x2239080C>("\xDE\xE0\xFB\xE7\xB8\xD6\xFC\xFD\xBC\xD8\xFA\xF8\xC5\x9B\x82\x83\x81\x8B\x97\xC1" + 0x2239080C).s, JumpOff);
			ImGui::TextColored(ImVec4(1.f, 0.f, 1.f, 1.f), /*Jump Distance:  %.1f*/XorStr<0x8B, 21, 0x33B81E82>("\xC1\xF9\xE0\xFE\xAF\xD4\xF8\xE1\xE7\xF5\xFB\xF5\xF2\xA2\xB9\xBA\xBE\xB2\xAC\xF8" + 0x33B81E82).s, flJumpdist);
			ImGui::TextColored(ImVec4(1.f, 0.f, 1.f, 1.f), /*Start speed:    %.1f*/XorStr<0xE9, 21, 0x529406AE>("\xBA\x9E\x8A\x9E\x99\xCE\x9C\x80\x94\x97\x97\xCE\xD5\xD6\xD7\xD8\xDC\xD4\xCA\x9A" + 0x529406AE).s, PreStrafe);
		}
		ImGui::TextColored(col, /*Damage Predict: %.1f*/XorStr<0x1D, 21, 0x4F78E196>("\x59\x7F\x72\x41\x46\x47\x03\x74\x57\x43\x43\x41\x4A\x5E\x11\x0C\x08\x00\x1E\x56" + 0x4F78E196).s, Damage());
		ImGui::TextColored(col2, /*Damage In Fall: %.1f*/XorStr<0x16, 21, 0x883B6354>("\x52\x76\x75\x78\x7D\x7E\x3C\x54\x70\x3F\x66\x40\x4E\x4F\x1E\x05\x03\x09\x19\x4F" + 0x883B6354).s, Damage2());
		ImGui::Text(/*Height:         %.1f*/XorStr<0x47, 21, 0xF990AF3F>("\x0F\x2D\x20\x2D\x23\x38\x77\x6E\x6F\x70\x71\x72\x73\x74\x75\x76\x72\x76\x68\x3C" + 0xF990AF3F).s, g_Local.flHeightorigin);
		ImGui::Text(/*Ground Angle:   %.1f*/XorStr<0x56, 21, 0x89D13536>("\x11\x25\x37\x2C\x34\x3F\x7C\x1C\x30\x38\x0C\x04\x58\x43\x44\x45\x43\x49\x59\x0F" + 0x89D13536).s, g_Local.flGroundangle);
		ImGui::Text(/*Speed:          %.1f*/XorStr<0xCF, 21, 0x2CBEA599>("\x9C\xA0\xB4\xB7\xB7\xEE\xF5\xF6\xF7\xF8\xF9\xFA\xFB\xFC\xFD\xFE\xFA\xCE\xD0\x84" + 0x2CBEA599).s, pmove->velocity.Length2D());
		ImGui::Text(/*Speed Max:      %.1f*/XorStr<0x95, 21, 0x0F78A9B9>("\xC6\xE6\xF2\xFD\xFD\xBA\xD6\xFD\xE5\xA4\xBF\x80\x81\x82\x83\x84\x80\x88\x96\xCE" + 0x0F78A9B9).s, fMaxPspeed);
		ImGui::Text(/*Speed In Fall:  %.1f*/XorStr<0xB1, 21, 0xE1D4154E>("\xE2\xC2\xD6\xD1\xD1\x96\xFE\xD6\x99\xFC\xDA\xD0\xD1\x84\x9F\xE0\xE4\xEC\xF2\xA2" + 0xE1D4154E).s, pmove->flFallVelocity);
		ImGui::TextColored(ImVec4(1.f, 0.f, EdgeDistance(), 1.f), /*Edge Distance:  %.1f*/XorStr<0xB7, 21, 0x39A0BD20>("\xF2\xDC\xDE\xDF\x9B\xF8\xD4\xCD\xCB\xA1\xAF\xA1\xA6\xFE\xE5\xE6\xE2\xE6\xF8\xAC" + 0x39A0BD20).s, EdgeDistance());

		windowpos.x = ImGui::GetWindowPos().x + ImGui::GetWindowSize().x + 5;
		windowpos.y = ImGui::GetWindowPos().y;
	}
	ImGui::PopStyleColor();
	ImGui::End();

	ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.0f, 0.0f, 0.0f, 0.25f));
	ImGui::SetNextWindowPos(ImVec2(windowpos.x, windowpos.y), ImGuiCond_Always);
	if (ImGui::Begin(/*kzkeys*/XorStr<0x1B, 7, 0xA3E008BE>("\x70\x66\x76\x7B\x66\x53" + 0xA3E008BE).s, NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::Text("%s", Keyforwardm ? /*  W*/XorStr<0x6F, 4, 0xCB49D5D9>("\x4F\x50\x26" + 0xCB49D5D9).s : " |");
		ImGui::Text("%s %s %s", Keymoveleft ? /*A*/XorStr<0x47, 2, 0xD9F4BA3C>("\x06" + 0xD9F4BA3C).s : /*-*/XorStr<0xD5, 2, 0xA94E7FFD>("\xF8" + 0xA94E7FFD).s, Keyback ? /*S*/XorStr<0x82, 2, 0x68B5B516>("\xD1" + 0x68B5B516).s : /*+*/XorStr<0x6A, 2, 0x5F495829>("\x41" + 0x5F495829).s, Keymoveright ? /*D*/XorStr<0xC0, 2, 0x65A9A911>("\x84" + 0x65A9A911).s : /*-*/XorStr<0x2C, 2, 0xA376F6C0>("\x01" + 0xA376F6C0).s);
		ImGui::Text(Keyduck ? /* Duck*/XorStr<0xB0, 6, 0x3E5E6182>("\x90\xF5\xC7\xD0\xDF" + 0x3E5E6182).s : " |");
		ImGui::Text(Keyjump ? /* Jump*/XorStr<0xED, 6, 0x33BF3C57>("\xCD\xA4\x9A\x9D\x81" + 0x33BF3C57).s : " |");
	}
	ImGui::PopStyleColor();
	ImGui::End();
}