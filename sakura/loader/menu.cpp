#include "../libs/xor/xorstr.h"
#include "../../imgui/imgui.h"

#include "menu.h"
#include "injector.h"

#include <iostream>
#include <windows.h>

bool Sakura::Menu::Active = true;
ImGuiWindowFlags Sakura::Menu::WindowFlags = ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar;

bool stylesInit = false;
bool autoClose = false;
bool autoInject = false;
char modulePath[MAX_PATH];
char moduleName[32];
char statusText[32];
PROCESS_INFORMATION processInfo;

void Sakura::Init()
{
    sprintf(statusText, /*:)*/XorStr<0xE3, 3, 0xE0B6E8BD>("\xD9\xCD" + 0xE0B6E8BD).s);
    sprintf(moduleName, /*sakura.dll*/XorStr<0x41, 11, 0x13E9D3ED>("\x32\x23\x28\x31\x37\x27\x69\x2C\x25\x26" + 0x13E9D3ED).s);
}

void Sakura::InitStyles()
{
    ImGuiStyle& s = ImGui::GetStyle();
    s.WindowBorderSize = 0;

    s.Colors[ImGuiCol_Button] = ImVec4(0.3529f, 0.1176f, 0.3058f, 0.9f);
    s.Colors[ImGuiCol_ButtonActive] = ImVec4(0.3529f, 0.1176f, 0.3058f, 0.7f);
    s.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.3529f, 0.1176f, 0.3058f, 0.5f);

    s.Colors[ImGuiCol_FrameBg] = ImVec4(0.3529f, 0.1176f, 0.3058f, 0.9f);
    s.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.3529f, 0.1176f, 0.3058f, 0.7f);
    s.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.3529f, 0.1176f, 0.3058f, 0.5f);

    s.Colors[ImGuiCol_CheckMark] = ImVec4(1.f, 1.f, 1.f, 1.f);

    stylesInit = true;
}

void Sakura::Inject()
{
    bool moduleExists = true;
    bool processExists = true;

    GetModuleFileName(NULL, modulePath, MAX_PATH);
    char* index = strrchr(modulePath, '\\');
    modulePath[index - modulePath + 1] = 0;
    strcat_s(modulePath, MAX_PATH, moduleName);
    WIN32_FIND_DATA WFD;

    if (FindFirstFile(modulePath, &WFD) == INVALID_HANDLE_VALUE)
    {
        sprintf(statusText, /*sakura.dll is missing!*/XorStr<0x59, 23, 0x4747249C>("\x2A\x3B\x30\x29\x2F\x3F\x71\x04\x0D\x0E\x43\x0D\x16\x46\x0A\x01\x1A\x19\x02\x02\x0A\x4F" + 0x4747249C).s);
        moduleExists = false;
    }

    if (Injector::GetProcessInfo("hl.exe", &processInfo) == false && moduleExists)
    {
        sprintf(statusText, /*hl.exe is missing!*/XorStr<0x82, 19, 0x7A22A4AD>("\xEA\xEF\xAA\xE0\xFE\xE2\xA8\xE0\xF9\xAB\xE1\xE4\xFD\xFC\xF9\xFF\xF5\xB2" + 0x7A22A4AD).s);
        processExists = false;
    }

    if (Injector::InjectModule("hl.exe", modulePath) == true && moduleExists && processExists)
    {
        sprintf(statusText, /*Injected!*/XorStr<0xB0, 10, 0xE54EBF17>("\xF9\xDF\xD8\xD6\xD7\xC1\xD3\xD3\x99" + 0xE54EBF17).s);

        if (autoClose)
            exit(0);
    }
}

void Sakura::Menu::Draw()
{
    if (Active)
    {
        if (!stylesInit)
            InitStyles();

        if (autoInject)
            Sakura::Inject();

        ImGui::SetNextWindowSize({ 200, 200 });
        ImGui::SetNextWindowPos({ 0, 0 }, ImGuiCond_Once);
        ImGui::SetNextWindowBgAlpha(1.0f);
        ImGui::Begin(/*##sinj*/XorStr<0xE2, 7, 0xFFCB6CF5>("\xC1\xC0\x97\x8C\x88\x8D" + 0xFFCB6CF5).s, &Active, WindowFlags);
        {
            ImGui::Text(statusText);
            ImGui::Checkbox(/*Auto close on inject*/XorStr<0x23, 21, 0x7822FFE3>("\x62\x51\x51\x49\x07\x4B\x45\x45\x58\x49\x0D\x41\x41\x10\x58\x5C\x59\x51\x56\x42" + 0x7822FFE3).s, &autoClose);
            ImGui::Checkbox(/*Auto inject*/XorStr<0x04, 12, 0x629C4877>("\x45\x70\x72\x68\x28\x60\x64\x61\x69\x6E\x7A" + 0x629C4877).s, &autoInject);
            if (!autoInject && ImGui::Button(/*Inject*/XorStr<0xBE, 7, 0xA29A5E2B>("\xF7\xD1\xAA\xA4\xA1\xB7" + 0xA29A5E2B).s))
                Sakura::Inject();
        }
        ImGui::End();
    }
}