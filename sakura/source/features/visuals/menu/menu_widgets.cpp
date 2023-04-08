#include "../../../client.h"

static const char* Sakura::Menu::Widgets::Helpers::PatchFormatStringFloatToInt(const char* fmt)
{
	if (fmt[0] == '%' && fmt[1] == '.' && fmt[2] == '0' && fmt[3] == 'f' && fmt[4] == 0) // Fast legacy path for "%.0f" which is expected to be the most common case.
		return "%d";
	const char* fmt_start = ImParseFormatFindStart(fmt);    // Find % (if any, and ignore %%)
	const char* fmt_end = ImParseFormatFindEnd(fmt_start);  // Find end of format specifier, which itself is an exercise of confidence/recklessness (because snprintf is dependent on libc or user).
	if (fmt_end > fmt_start && fmt_end[-1] == 'f')
	{
		if (fmt_start == fmt && fmt_end[0] == 0)
			return "%d";
		ImGuiContext& g = *GImGui;
		ImFormatString(g.TempBuffer.Data, sizeof(g.TempBuffer), "%.*s%%d%s", (int)(fmt_start - fmt), fmt, fmt_end); // Honor leading and trailing decorations, but lose alignment/precision.
		return g.TempBuffer.Data;
	}
	return fmt;
}

static float Sakura::Menu::Widgets::Helpers::CalcMaxPopupHeightFromItemCount(int items_count)
{
	ImGuiContext& g = *GImGui;
	if (items_count <= 0)
		return FLT_MAX;
	return (g.FontSize + g.Style.ItemSpacing.y) * items_count - g.Style.ItemSpacing.y + (g.Style.WindowPadding.y * 2);
}

static bool Sakura::Menu::Widgets::Helpers::Items_ArrayGetter(void* data, int idx, const char** out_text)
{
	const char* const* items = (const char* const*)data;
	if (out_text)
		*out_text = items[idx];
	return true;
}

static bool Sakura::Menu::Widgets::Helpers::Items_SingleStringGetter(void* data, int idx, const char** out_text)
{
	// FIXME-OPT: we could pre-compute the indices to fasten this. But only 1 active combo means the waste is limited.
	const char* items_separated_by_zeros = (const char*)data;
	int items_count = 0;
	const char* p = items_separated_by_zeros;
	while (*p)
	{
		if (idx == items_count)
			break;
		p += strlen(p) + 1;
		items_count++;
	}
	if (!*p)
		return false;
	if (out_text)
		*out_text = p;
	return true;
}

void Sakura::Menu::Widgets::Helpers::RenderCheckMar1k(ImVec2 pos, ImU32 col, float sz)
{
	ImGuiContext& g = *GImGui;
	ImGuiWindow* window = g.CurrentWindow;

	float thickness = ImMax(sz / 5.0f, 1.0f);
	sz -= thickness * 0.5f;
	pos = ImVec2(pos.x + thickness * 0.25f, pos.y + thickness * 0.25f);

	float third = sz / 3.0f;
	float bx = pos.x + third;
	float by = pos.y + sz - third * 0.5f;
	window->DrawList->PathLineTo(ImVec2(bx - third, by - third));
	window->DrawList->PathLineTo(ImVec2(bx, by));
	window->DrawList->PathLineTo(ImVec2(bx + third * 2, by - third * 2));
	window->DrawList->PathStroke(col, false, thickness);
}

bool Sakura::Menu::Widgets::Tab(const char* icon, const char* label, const ImVec2& size_arg, const bool selected)
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();
	if (window->SkipItems)
		return false;

	static float sizeplus = 0.f;

	ImGuiContext& g = *GImGui;
	const ImGuiStyle& style = g.Style;
	const ImGuiID id = window->GetID(label);
	const ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);

	ImVec2 pos = window->DC.CursorPos;

	ImVec2 size = ImGui::CalcItemSize(size_arg, label_size.x + style.FramePadding.x * 2.f, label_size.y + style.FramePadding.y * 2.f);

	const ImRect bb(pos, ImVec2(pos.x + size.x, pos.y + size.y));
	ImGui::ItemSize(size, style.FramePadding.y);
	if (!ImGui::ItemAdd(bb, id))
		return false;

	bool hovered, held;
	bool pressed = ImGui::ButtonBehavior(bb, id, &hovered, &held, 0);

	float t = selected ? 1.0f : 0.0f;

	float ANIM_SPEED = (ImGui::GetIO().Framerate / 4.f) * (1.f / ImGui::GetIO().Framerate);
	if (g.LastActiveId == g.CurrentWindow->GetID(label))// && g.LastActiveIdTimer < ANIM_SPEED)
	{
		float t_anim = ImSaturate(g.LastActiveIdTimer / ANIM_SPEED);
		t = selected ? (t_anim) : (1.0f - t_anim);
	}

	ImU32 bg_col = ImGui::GetColorU32(ImLerp(ImVec4(cvar.visual_menu_color_items[0], cvar.visual_menu_color_items[1], cvar.visual_menu_color_items[2], 0.f), ImVec4(cvar.visual_menu_color_tab_selected[0], cvar.visual_menu_color_tab_selected[1], cvar.visual_menu_color_tab_selected[2], Sakura::Menu::currentAlphaFade / 255.f), t));

	if (selected)
		window->DrawList->AddRectFilled(bb.Min, bb.Max, bg_col);

	ImGui::PushFont(Sakura::Menu::Fonts::titleTabFont);
	window->DrawList->AddText(ImVec2(bb.Min.x + 35, bb.Min.y + 19), ImColor(255 / 255.f, 255 / 255.f, 255 / 255.f, Sakura::Menu::currentAlphaFade / 255.f), label);
	ImGui::PopFont();

	ImGui::PushFont(Sakura::Menu::Fonts::icons);
	window->DrawList->AddText(ImVec2(bb.Min.x + 5, bb.Min.y + size_arg.y / 2 - ImGui::CalcTextSize(icon).y / 2), GetMenuColor(Sakura::Menu::currentAlphaFade / 255.f), icon);
	ImGui::PopFont();

	return pressed;
}

bool Sakura::Menu::Widgets::SubTab(const char* label, const ImVec2& size_arg, const bool selected)
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();
	if (window->SkipItems)
		return false;

	static float sizeplus = 0.f;

	ImGuiContext& g = *GImGui;
	const ImGuiStyle& style = g.Style;
	const ImGuiID id = window->GetID(label);
	const ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);

	ImVec2 pos = window->DC.CursorPos;

	ImVec2 size = ImGui::CalcItemSize(size_arg, label_size.x + style.FramePadding.x * 2.0f, label_size.y + style.FramePadding.y * 2.0f);

	const ImRect bb(pos, ImVec2(pos.x + size.x, pos.y + size.y));
	ImGui::ItemSize(size, style.FramePadding.y);
	if (!ImGui::ItemAdd(bb, id))
		return false;

	bool hovered, held;
	bool pressed = ImGui::ButtonBehavior(bb, id, &hovered, &held, 0);

	float t = selected ? 1.0f : 0.0f;

	float ANIM_SPEED = (ImGui::GetIO().Framerate / 4.f) * (1.f / ImGui::GetIO().Framerate);
	if (g.LastActiveId == g.CurrentWindow->GetID(label))
	{
		float t_anim = ImSaturate(g.LastActiveIdTimer / ANIM_SPEED);
		t = selected ? (t_anim) : (1.0f - t_anim);
	}

	ImU32 bg_col = ImGui::GetColorU32(ImLerp(ImVec4(cvar.visual_menu_color_widgets[0], cvar.visual_menu_color_widgets[1], cvar.visual_menu_color_widgets[2], 0.f), ImVec4(cvar.visual_menu_color_subtab_selected[0], cvar.visual_menu_color_subtab_selected[1], cvar.visual_menu_color_subtab_selected[2], Sakura::Menu::currentAlphaFade / 255.f), t));
	ImU32 bg_col2 = ImGui::GetColorU32(ImLerp(ImVec4(cvar.visual_menu_color_widgets[0], cvar.visual_menu_color_widgets[1], cvar.visual_menu_color_widgets[2], 0.f), GetMenuColor(Sakura::Menu::currentAlphaFade / 255.f), t));

	if (selected)
	{
		window->DrawList->AddRectFilled({ bb.Min.x,bb.Min.y }, { bb.Max.x,bb.Max.y }, bg_col);
		window->DrawList->AddRectFilled({ bb.Max.x,bb.Max.y }, { bb.Max.x - 3,bb.Min.y }, bg_col2);
	}

	ImGui::PushFont(Sakura::Menu::Fonts::titleTabFont);
	window->DrawList->AddText(ImVec2(bb.Min.x + 5, bb.Min.y + size_arg.y / 2 - ImGui::CalcTextSize(label).y / 2), ImColor(255 / 255.f, 255 / 255.f, 255 / 255.f, Sakura::Menu::currentAlphaFade / 255.f), label);
	ImGui::PopFont();

	return pressed;
}

bool Sakura::Menu::Widgets::SubSubTab(const char* icon, const char* label, const ImVec2& size_arg, const bool selected, ImFont* customFont)
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();
	if (window->SkipItems)
		return false;

	static float sizeplus = 0.f;

	ImGuiContext& g = *GImGui;
	const ImGuiStyle& style = g.Style;
	const ImGuiID id = window->GetID(label);
	const ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);

	ImVec2 pos = window->DC.CursorPos;

	ImVec2 size = ImGui::CalcItemSize(size_arg, label_size.x + style.FramePadding.x * 2.f, label_size.y + style.FramePadding.y * 2.f);

	const ImRect bb(pos, ImVec2(pos.x + size.x, pos.y + size.y));
	ImGui::ItemSize(size, style.FramePadding.y);
	if (!ImGui::ItemAdd(bb, id))
		return false;

	bool hovered, held;
	bool pressed = ImGui::ButtonBehavior(bb, id, &hovered, &held, 0);

	float t = selected ? 1.0f : 0.0f;

	float ANIM_SPEED = (ImGui::GetIO().Framerate / 4.f) * (1.f / ImGui::GetIO().Framerate);
	if (g.LastActiveId == g.CurrentWindow->GetID(label))
	{
		float t_anim = ImSaturate(g.LastActiveIdTimer / ANIM_SPEED);
		t = selected ? (t_anim) : (1.0f - t_anim);
	}

	ImU32 bg_col = ImGui::GetColorU32(ImLerp(ImVec4(1.f, 1.f, 1.f, 0.f), GetMenuColor(Sakura::Menu::currentAlphaFade / 255.f), t));

	ImGui::PushFont(customFont ? customFont : Sakura::Menu::Fonts::icons);
	window->DrawList->AddText(ImVec2(bb.Min.x + size_arg.x / 2 - ImGui::CalcTextSize(icon).x / 2, bb.Min.y + size_arg.y / 2 - ImGui::CalcTextSize(icon).y / 2), ImColor(255 / 255.f, 255 / 255.f, 255 / 255.f, Sakura::Menu::currentAlphaFade / 255.f), icon);

	if (selected)
		window->DrawList->AddText(ImVec2(bb.Min.x + size_arg.x / 2 - ImGui::CalcTextSize(icon).x / 2, bb.Min.y + size_arg.y / 2 - ImGui::CalcTextSize(icon).y / 2), bg_col, icon);
	
	ImGui::PopFont();

	if (hovered)
	{
		ImGui::BeginTooltip();
		ImGui::Text(label);
		ImGui::EndTooltip();
	}

	return pressed;
}

bool Sakura::Menu::Widgets::Checkbox(const char* label, float* v)
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();
	if (window->SkipItems)
		return false;

	ImGuiContext& g = *GImGui;
	const ImGuiStyle& style = g.Style;
	const ImGuiID id = window->GetID(label);
	const ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);

	float last_active_id_timer = g.LastActiveIdTimer;

	const float square_sz = ImGui::GetFrameHeight();
	const ImVec2 pos = window->DC.CursorPos;
	const ImRect total_bb(pos, ImVec2(pos.x + square_sz + (label_size.x > 0.0f ? style.ItemInnerSpacing.x + label_size.x : 0.0f), pos.y + label_size.y + style.FramePadding.y * 2.0f));
	ImGui::ItemSize(total_bb, style.FramePadding.y);
	if (!ImGui::ItemAdd(total_bb, id))
		return false;

	bool hovered, held;
	bool pressed = ImGui::ButtonBehavior(total_bb, id, &hovered, &held);
	if (pressed)
	{
		*v = !(*v);
		g.LastActiveIdTimer = 0.0f;
		ImGui::MarkItemEdited(id);
	}

	const ImRect check_bb(pos, ImVec2(pos.x + square_sz, pos.y + square_sz));

	if (g.LastActiveIdTimer == 0.0f && g.LastActiveId == g.CurrentWindow->GetID(label) && !pressed)
		g.LastActiveIdTimer = last_active_id_timer;

	float t = *v ? 1.0f : 0.0f;

	float ANIM_SPEED = (ImGui::GetIO().Framerate / 8.f) * (1.f / ImGui::GetIO().Framerate);
	if (g.LastActiveId == g.CurrentWindow->GetID(label))// && g.LastActiveIdTimer < ANIM_SPEED)
	{
		float t_anim = ImSaturate(g.LastActiveIdTimer / ANIM_SPEED);
		t = *v ? (t_anim) : (1.0f - t_anim);
	}

	ImU32 col_bg = ImGui::GetColorU32(ImVec4(120 / 255.f, 120 / 255.f, 120 / 255.f, 120 / 255.f));
	ImU32 col_bg2 = ImGui::GetColorU32(ImLerp(ImVec4(190 / 255.f, 190 / 255.f, 190 / 255.f, 0.f), ImVec4(GetMenuColor()), t));
	ImU32 col_bg3 = ImGui::GetColorU32(ImLerp(ImVec4(190 / 255.f, 190 / 255.f, 190 / 255.f, 0.f), ImVec4(1.f, 1.f, 1.f, 1.f), t));

	window->DrawList->AddRect(check_bb.Min, check_bb.Max, col_bg, 4.f, 15, 2.f);
	window->DrawList->AddRectFilled(check_bb.Min, check_bb.Max, col_bg2, 4.f);

	if (v)
	{
		Sakura::Menu::Widgets::Helpers::RenderCheckMar1k(ImVec2{ check_bb.Min.x + 4,check_bb.Min.y + 4 }, col_bg3, square_sz - 8);
	}

	if (label_size.x > 0.0f)
		ImGui::RenderText(ImVec2(check_bb.Max.x + style.ItemInnerSpacing.x, check_bb.Min.y + style.FramePadding.y), label);

	return pressed;
}

bool Sakura::Menu::Widgets::SliderScalar(const char* label, ImGuiDataType data_type, void* p_data, const void* p_min, const void* p_max, const char* format)
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();
	if (window->SkipItems)
		return false;

	ImGuiContext& g = *GImGui;
	const ImGuiStyle& style = g.Style;
	const ImGuiID id = window->GetID(label);
	const float w = ImGui::CalcItemWidth();

	const ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);
	const ImRect frame_bb(window->DC.CursorPos, ImVec2(window->DC.CursorPos.x + w, window->DC.CursorPos.y + label_size.y + style.FramePadding.y * 2.0f + 10));
	const ImRect total_bb(frame_bb.Min, ImVec2(frame_bb.Max.x + label_size.x > 0.0f ? style.ItemInnerSpacing.x + label_size.x : 0.0f, frame_bb.Max.y + 0.0f));

	ImGui::ItemSize(total_bb, style.FramePadding.y);
	ImGui::ItemAdd(total_bb, id, &frame_bb);


	// Default format string when passing NULL
	if (format == NULL)
		format = ImGui::DataTypeGetInfo(data_type)->PrintFmt;
	else if (data_type == ImGuiDataType_S32 && strcmp(format, "%d") != 0)
		format = Sakura::Menu::Widgets::Helpers::PatchFormatStringFloatToInt(format);

	// Tabbing or CTRL-clicking on Slider turns it into an input box
	const bool hovered = ImGui::ItemHoverable(frame_bb, id);
	bool temp_input_is_active = ImGui::TempInputIsActive(id);
	if (!temp_input_is_active)
	{
		// Tabbing or CTRL-clicking on Slider turns it into an input box
		const bool input_requested_by_tabbing =  (g.LastItemData.StatusFlags & ImGuiItemStatusFlags_FocusedByTabbing) != 0;
		const bool clicked = hovered && ImGui::IsMouseClicked(0, id);
		const bool make_active = (input_requested_by_tabbing || clicked || g.NavActivateId == id || g.NavActivateInputId == id);
		if (make_active && clicked)
			ImGui::SetKeyOwner(ImGuiKey_MouseLeft, id);
		if (make_active)
			if (input_requested_by_tabbing || (clicked && g.IO.KeyCtrl) || g.NavActivateInputId == id)
				temp_input_is_active = true;

		if (make_active && !temp_input_is_active)
		{
			ImGui::SetActiveID(id, window);
			ImGui::SetFocusID(id, window);
			ImGui::FocusWindow(window);
			g.ActiveIdUsingNavDirMask |= (1 << ImGuiDir_Left) | (1 << ImGuiDir_Right);
		}
	}

	if (temp_input_is_active)
	{
		// Only clamp CTRL+Click input when ImGuiSliderFlags_AlwaysClamp is set
		const bool is_clamp_input = (0 & ImGuiSliderFlags_AlwaysClamp) != 0;
		return ImGui::TempInputScalar(frame_bb, id, label, data_type, p_data, format, is_clamp_input ? p_min : NULL, is_clamp_input ? p_max : NULL);
	}

	ImGui::RenderNavHighlight(frame_bb, id);
	window->DrawList->AddRectFilled(ImVec2{ frame_bb.Min.x + 0,frame_bb.Min.y + 7 + 10 }, ImVec2{ frame_bb.Max.x - 12,frame_bb.Max.y - 3 }, ImColor((int)(cvar.visual_menu_slider_bg_color[0] * 255), (int)(cvar.visual_menu_slider_bg_color[1] * 255), (int)(cvar.visual_menu_slider_bg_color[2] * 255), Sakura::Menu::currentAlphaFade), 6.f);

	ImRect grab_bb;
	const bool value_changed = ImGui::SliderBehavior(frame_bb, id, data_type, p_data, p_min, p_max, format/*, power*/, ImGuiSliderFlags_None, &grab_bb);
	if (value_changed)
		ImGui::MarkItemEdited(id);

	float t = hovered ? 1.0f : 0.0f;

	float ANIM_SPEED = (ImGui::GetIO().Framerate / 8.f) * (1.f / ImGui::GetIO().Framerate);
	if (g.LastActiveId == g.CurrentWindow->GetID(label))
	{
		float t_anim = ImSaturate(g.LastActiveIdTimer / ANIM_SPEED);
		t = hovered ? (t_anim) : (1.0f - t_anim);
	}

	ImU32 col_bg;

	col_bg = ImGui::GetColorU32(ImLerp((ImVec4)GetMenuColor(0.65f), GetMenuColor(Sakura::Menu::currentAlphaFade / 255.f), t));

	// Render grab
	window->DrawList->AddRectFilled(ImVec2{ frame_bb.Min.x + 0,frame_bb.Min.y + 7 + 10 }, ImVec2{ grab_bb.Min.x,grab_bb.Max.y - 1 }, col_bg, 6.f);

	// Display value using user-provided display format so user can add prefix/suffix/decorations to the value.
	char value_buf[64];
	const char* value_buf_end = value_buf + ImGui::DataTypeFormatString(value_buf, IM_ARRAYSIZE(value_buf), data_type, p_data, format);

	if (label_size.x > 0.0f)
		ImGui::RenderText(ImVec2(frame_bb.Min.x, frame_bb.Min.y + 1), label);


	if (label_size.x > 0.0f)
		ImGui::RenderText(ImVec2(frame_bb.Max.x - ImGui::CalcTextSize(value_buf).x - 12, frame_bb.Min.y + 1), value_buf);

	return value_changed;
}

bool Sakura::Menu::Widgets::SliderFloat(const char* label, float* v, float v_min, float v_max, const char* format)
{
	return SliderScalar(label, ImGuiDataType_Float, v, &v_min, &v_max, format);
}

bool Sakura::Menu::Widgets::SliderInt(const char* label, int* v, int v_min, int v_max, const char* format)
{
	return SliderScalar(label, ImGuiDataType_S32, v, &v_min, &v_max, format);
}

bool Sakura::Menu::Widgets::Button(const char* label, const ImVec2& size_arg, ImGuiButtonFlags flags)
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();
	if (window->SkipItems)
		return false;

	ImGuiContext& g = *GImGui;
	const ImGuiStyle& style = g.Style;
	const ImGuiID id = window->GetID(label);
	const ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);

	ImVec2 pos = window->DC.CursorPos;
	if ((flags & ImGuiButtonFlags_AlignTextBaseLine) && style.FramePadding.y < window->DC.CurrLineTextBaseOffset) // Try to vertically align buttons that are smaller/have no padding so that text baseline matches (bit hacky, since it shouldn't be a flag)
		pos.y += window->DC.CurrLineTextBaseOffset - style.FramePadding.y;
	ImVec2 size = ImGui::CalcItemSize(size_arg, label_size.x + style.FramePadding.x * 2.0f, label_size.y + style.FramePadding.y * 2.0f);

	const ImRect bb(pos, { pos.x + size.x, pos.y + size.y });
	ImGui::ItemSize(size, style.FramePadding.y);
	if (!ImGui::ItemAdd(bb, id))
		return false;

	if (window->Flags & ImGuiItemFlags_ButtonRepeat)
		flags |= ImGuiButtonFlags_Repeat;
	bool hovered, held;
	bool pressed = ImGui::ButtonBehavior(bb, id, &hovered, &held, flags);

	ImU32 col;
	// Render
	if (hovered)
		col = GetMenuColor();
	else
		col = ImColor(120, 120, 120, 120);

	window->DrawList->AddRectFilled(bb.Min, bb.Max, col, 4, 15);
	if (held) window->DrawList->AddRectFilled(bb.Min, bb.Max, col, 4, 15);
	ImGui::RenderTextClipped({ bb.Min.x + style.FramePadding.x, bb.Min.y + style.FramePadding.y }, { bb.Max.x - style.FramePadding.x,  bb.Max.y - style.FramePadding.y }, label, NULL, &label_size, style.ButtonTextAlign, &bb);

	return pressed;
}

bool Sakura::Menu::Widgets::BeginCombo(const char* label, const char* preview_value, ImGuiComboFlags flags)
{
	// Always consume the SetNextWindowSizeConstraint() call in our early return paths
	ImGuiContext& g = *GImGui;
	bool has_window_size_constraint = (g.NextWindowData.Flags & ImGuiNextWindowDataFlags_HasSizeConstraint) != 0;
	g.NextWindowData.Flags &= ~ImGuiNextWindowDataFlags_HasSizeConstraint;

	ImGuiWindow* window = ImGui::GetCurrentWindow();
	if (window->SkipItems)
		return false;

	IM_ASSERT((flags & (ImGuiComboFlags_NoArrowButton | ImGuiComboFlags_NoPreview)) != (ImGuiComboFlags_NoArrowButton | ImGuiComboFlags_NoPreview)); // Can't use both flags together

	const ImGuiStyle& style = g.Style;
	const ImGuiID id = window->GetID(label);

	const float arrow_size = (flags & ImGuiComboFlags_NoArrowButton) ? 0.0f : ImGui::GetFrameHeight();
	const ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);
	const float expected_w = ImGui::CalcItemWidth();
	const float w = (flags & ImGuiComboFlags_NoPreview) ? arrow_size : expected_w;
	const ImRect frame_bb(window->DC.CursorPos, ImVec2(window->DC.CursorPos.x + w, window->DC.CursorPos.y + label_size.y + style.FramePadding.y * 2.0f + 10));
	const ImRect total_bb(frame_bb.Min, ImVec2(frame_bb.Max.x + label_size.x > 0.0f ? style.ItemInnerSpacing.x + label_size.x : 0.0f, frame_bb.Max.y + 0.0f));
	ImGui::ItemSize(total_bb, style.FramePadding.y);
	ImGui::ItemAdd(total_bb, id, &frame_bb);


	bool hovered, held;
	bool pressed = ImGui::ButtonBehavior(frame_bb, id, &hovered, &held);
	bool popup_open = ImGui::IsPopupOpen(label);


	const ImRect value_bb(frame_bb.Min, ImVec2(frame_bb.Max.x - arrow_size, frame_bb.Max.y - 0.0f));

	if (!(flags & ImGuiComboFlags_NoArrowButton))
	{
		ImGui::RenderArrow(window->DrawList, ImVec2(frame_bb.Max.x - arrow_size + style.FramePadding.y, frame_bb.Min.y + style.FramePadding.y + 10), Sakura::Colors::White(), popup_open ? ImGuiDir_Down : ImGuiDir_Left);
	}

	float t = popup_open ? 1.0f : 0.0f;

	float ANIM_SPEED = 0.2f;
	if (g.LastActiveId == g.CurrentWindow->GetID(label))// && g.LastActiveIdTimer < ANIM_SPEED)
	{
		float t_anim = ImSaturate(g.LastActiveIdTimer / ANIM_SPEED);
		t = popup_open ? (t_anim) : (1.0f - t_anim);
	}

	ImU32 col_bg;
	ImU32 col_bg2;
	//ImU32 col_bg3;

	col_bg = ImGui::GetColorU32(ImVec4(cvar.visual_menu_combo_bg_color[0], cvar.visual_menu_combo_bg_color[1], cvar.visual_menu_combo_bg_color[2], 120 / 255.f));
	col_bg2 = ImGui::GetColorU32((ImVec4)GetMenuColor(0.65f));

	window->DrawList->AddRectFilled({ frame_bb.Min.x, frame_bb.Min.y + 10 }, frame_bb.Max, col_bg, 3.f, 15);
	if (hovered)
		window->DrawList->AddRectFilled({ frame_bb.Min.x, frame_bb.Min.y + 10 }, frame_bb.Max, col_bg2, 3.f);

	if (preview_value != NULL && !(flags & ImGuiComboFlags_NoPreview))
		ImGui::RenderTextClipped({ frame_bb.Min.x + style.FramePadding.x,frame_bb.Min.y + style.FramePadding.y + 10 }, value_bb.Max, preview_value, NULL, NULL, ImVec2(0.0f, 0.0f));

	if (label_size.x > 0)
		ImGui::RenderText(ImVec2(frame_bb.Min.x, frame_bb.Min.y + style.FramePadding.y - 10), label);

	if ((pressed || g.NavActivateId == id) && !popup_open)
	{
		if (window->DC.NavLayerCurrent == 0)
			window->NavLastIds[0] = id;
		ImGui::OpenPopupEx(id);
		popup_open = true;
	}

	if (!popup_open)
		return false;

	if (has_window_size_constraint)
	{
		g.NextWindowData.Flags |= ImGuiNextWindowDataFlags_HasSizeConstraint;
		g.NextWindowData.SizeConstraintRect.Min.x = ImMax(g.NextWindowData.SizeConstraintRect.Min.x, w);
	}
	else
	{
		if ((flags & ImGuiComboFlags_HeightMask_) == 0)
			flags |= ImGuiComboFlags_HeightRegular;
		IM_ASSERT(ImIsPowerOfTwo(flags & ImGuiComboFlags_HeightMask_));    // Only one
		int popup_max_height_in_items = -1;
		if (flags & ImGuiComboFlags_HeightRegular)     popup_max_height_in_items = 8;
		else if (flags & ImGuiComboFlags_HeightSmall)  popup_max_height_in_items = 4;
		else if (flags & ImGuiComboFlags_HeightLarge)  popup_max_height_in_items = 20;
		ImGui::SetNextWindowSizeConstraints(ImVec2(w, 0.0f), ImVec2(FLT_MAX, Sakura::Menu::Widgets::Helpers::CalcMaxPopupHeightFromItemCount(popup_max_height_in_items)));
	}

	char name[16];
	ImFormatString(name, IM_ARRAYSIZE(name), /*##Combo_%02d*/XorStr<0x3F, 13, 0x6EB02304>("\x1C\x63\x02\x2D\x2E\x26\x2A\x19\x62\x78\x7B\x2E" + 0x6EB02304).s, g.BeginPopupStack.Size); // Recycle windows based on depth

	// Peak into expected window size so we can position it
	if (ImGuiWindow* popup_window = ImGui::FindWindowByName(name))
		if (popup_window->WasActive)
		{
			//ImVec2 size_expected = ImGui::CalcWindowExpectedSize(popup_window);
			ImVec2 size_expected = ImGui::CalcWindowNextAutoFitSize(popup_window);
			if (flags & ImGuiComboFlags_PopupAlignLeft)
				popup_window->AutoPosLastDirection = ImGuiDir_Left;
			//ImRect r_outer = ImGui::GetWindowAllowedExtentRect(popup_window);
			ImRect r_outer = ImGui::GetPopupAllowedExtentRect(popup_window);
			ImVec2 pos = ImGui::FindBestWindowPosForPopupEx(frame_bb.GetBL(), size_expected, &popup_window->AutoPosLastDirection, r_outer, frame_bb, ImGuiPopupPositionPolicy_ComboBox);
			ImGui::SetNextWindowPos(pos);
		}

	// We don't use BeginPopupEx() solely because we have a custom name string, which we could make an argument to BeginPopupEx()
	ImGuiWindowFlags window_flags = ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_Popup | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoMove;

	// Horizontally align ourselves with the framed text
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(style.FramePadding.x, style.WindowPadding.y));
	bool ret = ImGui::Begin(name, NULL, window_flags);
	ImGui::PopStyleVar();
	if (!ret)
	{
		ImGui::EndPopup();
		IM_ASSERT(0);   // This should never happen as we tested for IsPopupOpen() above
		return false;
	}
	return true;
}

void Sakura::Menu::Widgets::EndCombo()
{
	ImGui::EndPopup();
}

// Old API, prefer using BeginCombo() nowadays if you can.
bool Sakura::Menu::Widgets::Combo(const char* label, float* current_item, bool (*items_getter)(void*, int, const char**), void* data, int items_count, int popup_max_height_in_items)
{
	ImGuiContext& g = *GImGui;

	// Call the getter to obtain the preview string which is a parameter to BeginCombo()
	const char* preview_value = NULL;
	if (*current_item >= 0 && *current_item < items_count)
		items_getter(data, *current_item, &preview_value);

	// The old Combo() API exposed "popup_max_height_in_items". The new more general BeginCombo() API doesn't have/need it, but we emulate it here.
	if (popup_max_height_in_items != -1 && !(g.NextWindowData.Flags & ImGuiNextWindowDataFlags_HasSizeConstraint))
		ImGui::SetNextWindowSizeConstraints(ImVec2(0, 0), ImVec2(FLT_MAX, Sakura::Menu::Widgets::Helpers::CalcMaxPopupHeightFromItemCount(popup_max_height_in_items)));

	if (!BeginCombo(label, preview_value, ImGuiComboFlags_None))
		return false;

	ImGui::PushStyleColor(ImGuiCol_Header, (ImVec4)Sakura::Menu::GetMenuColor(0.39f));
	ImGui::PushStyleColor(ImGuiCol_HeaderHovered, (ImVec4)Sakura::Menu::GetMenuColor(0.80f));
	ImGui::PushStyleColor(ImGuiCol_HeaderActive, (ImVec4)Sakura::Menu::GetMenuColor(1.00f));
	// Display items
	// FIXME-OPT: Use clipper (but we need to disable it on the appearing frame to make sure our call to SetItemDefaultFocus() is processed)
	bool value_changed = false;
	for (int i = 0; i < items_count; i++)
	{
		ImGui::PushID((void*)(intptr_t)i);
		const bool item_selected = (i == *current_item);
		const char* item_text;
		if (!items_getter(data, i, &item_text))
			item_text = "*Unknown item*";
		if (ImGui::Selectable(item_text, item_selected))
		{
			value_changed = true;
			*current_item = i;
		}
		if (item_selected)
			ImGui::SetItemDefaultFocus();
		ImGui::PopID();
	}
	ImGui::PopStyleColor(3);

	EndCombo();
	return value_changed;
}

// Combo box helper allowing to pass an array of strings.
bool Sakura::Menu::Widgets::Combo(const char* label, float* current_item, const char* const items[], int items_count, int height_in_items)
{
	ImGui::Dummy(ImVec2(0, 2));
	const bool value_changed = Combo(label, current_item, Sakura::Menu::Widgets::Helpers::Items_ArrayGetter, (void*)items, items_count, height_in_items);
	return value_changed;
}

// Combo box helper allowing to pass all items in a single string literal holding multiple zero-terminated items "item1\0item2\0"
bool Sakura::Menu::Widgets::Combo(const char* label, float* current_item, const char* items_separated_by_zeros, int height_in_items)
{
	ImGui::Dummy(ImVec2(0, 2));
	int items_count = 0;
	const char* p = items_separated_by_zeros;       // FIXME-OPT: Avoid computing this, or at least only when combo is open
	while (*p)
	{
		p += strlen(p) + 1;
		items_count++;
	}
	bool value_changed = Combo(label, current_item, Sakura::Menu::Widgets::Helpers::Items_SingleStringGetter, (void*)items_separated_by_zeros, items_count, height_in_items);
	return value_changed;
}

bool Sakura::Menu::Widgets::ColorEdit(const char* label, float* color, ImGuiColorEditFlags flags)
{
	ImGui::PushStyleColor(ImGuiCol_FrameBg, (ImVec4)Sakura::Menu::GetMenuColor(0.39f));
	ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, (ImVec4)Sakura::Menu::GetMenuColor(0.80f));
	ImGui::PushStyleColor(ImGuiCol_FrameBgActive, (ImVec4)Sakura::Menu::GetMenuColor(1.00f));
	ImGui::ColorEdit4(label, color, flags);
	ImGui::PopStyleColor(3);
	ImGui::SameLine();
	ImGui::Text(label);
	return true;
}