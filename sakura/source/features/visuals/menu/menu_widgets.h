#pragma once

namespace Sakura
{
	namespace Menu
	{
		namespace Widgets
		{
			namespace Helpers
			{
				void RenderCheckMar1k(ImVec2 pos, ImU32 col, float sz);
				static bool Items_ArrayGetter(void* data, int idx, const char** out_text);
				static bool Items_SingleStringGetter(void* data, int idx, const char** out_text);
				static float CalcMaxPopupHeightFromItemCount(int items_count);
				static const char* PatchFormatStringFloatToInt(const char* fmt);

			};

			bool Combo(const char* label, float* current_item, const char* const items[], int items_count, int height_in_items = -1);
			bool Combo(const char* label, float* current_item, const char* items_separated_by_zeros, int popup_max_height_in_items = -1);      // Separate items with \0 within a string, end item-list with \0\0. e.g. "One\0Two\0Three\0"
			bool Combo(const char* label, float* current_item, bool(*items_getter)(void* data, int idx, const char** out_text), void* data, int items_count, int popup_max_height_in_items = -1);

			bool ColorEdit(const char* label, float* color, ImGuiColorEditFlags flags = 0);
			//bool List(float current_item, std::vector<std::string> items, int& item, ImColor color = ImColor(1.f, 1.f, 1.f));

			bool Tab(const char* icon, const char* label, const ImVec2& size_arg, const bool selected);
			bool SubTab(const char* label, const ImVec2& size_arg, const bool selected);
			bool SubSubTab(const char* icon, const char* label, const ImVec2& size_arg, const bool selected, ImFont* customFont = nullptr);
			bool Checkbox(const char* label, float* v);
			bool SliderScalar(const char* label, ImGuiDataType data_type, void* p_data, const void* p_min, const void* p_max, const char* format);
			bool SliderFloat(const char* label, float* v, float v_min, float v_max, const char* format);
			bool SliderInt(const char* label, int* v, int v_min, int v_max, const char* format);
			bool Button(const char* label, const ImVec2& size_arg = {}, ImGuiButtonFlags flags = NULL);
			bool BeginCombo(const char* label, const char* preview_value, ImGuiComboFlags flags);
			void EndCombo();
		};
	};
};