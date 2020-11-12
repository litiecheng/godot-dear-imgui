#include "native_imgui.h"
#include "scene/resources/mesh.h"
#include "../../core/os/os.h"


bool native_imgui::handleButtonDic(String label, bool newState) {
	bool oldState;

	if (buttonDict.has(label)) {
		oldState = buttonDict[label];

		if (oldState != newState) {
			if (newState) {
				buttonDict[label] = newState;
			}
		} else if (oldState == newState && oldState == true) {
			buttonDict[label] = !newState;
		}
	}

	return buttonDict[label];
}

inline const char *native_imgui::convertStringToChar(String string) {
	return string.utf8().get_data();
}

inline ImVec2 native_imgui::Vector2ToImVec(const Vector2 &vec) {
	return ImVec2(vec.x, vec.y);
}

inline Vector2 native_imgui::ImVec2ToVector2(const ImVec2 &vec) {
	return Vector2(vec.x, vec.y);
}

inline Color native_imgui::ImVec4ToColor(const ImVec4 &vec) {
	return Color(vec.x, vec.y, vec.z, vec.w);
}

float native_imgui::valuesGetter(void *data, int idx) {
	float *_data = (float *)data;
	return _data[idx];
}


void native_imgui::_bind_methods() {
	ClassDB::bind_method(D_METHOD("ImGui_ArrowButton", "label", "int dir"), &native_imgui::ArrowButton);
	ClassDB::bind_method(D_METHOD("ImGui_Begin", "name", "open"), &native_imgui::Begin);
	ClassDB::bind_method(D_METHOD("ImGui_BeginChild", "ImGuiID", "size", "border"), &native_imgui::BeginChild);
	ClassDB::bind_method(D_METHOD("ImGui_BeginChildFrame", "ImGuiID", "size"), &native_imgui::BeginChildFrame);
	ClassDB::bind_method(D_METHOD("ImGui_BeginCombo", "label", "preview"), &native_imgui::BeginCombo);
	ClassDB::bind_method(D_METHOD("ImGui_BeginPopup", "str_id"), &native_imgui::BeginPopup);
	ClassDB::bind_method(D_METHOD("ImGui_Button", "text", "size"), &native_imgui::Button);
	ClassDB::bind_method(D_METHOD("ImGui_BeginGroup"), &native_imgui::BeginGroup);
	ClassDB::bind_method(D_METHOD("ImGui_BeginPopupContextItem", "str_id"), &native_imgui::BeginPopupContextItem);
	ClassDB::bind_method(D_METHOD("ImGui_BeginPopupContextVoid", "str_id"), &native_imgui::BeginPopupContexVoid);
	ClassDB::bind_method(D_METHOD("ImGui_BeginPopupContextWindow", "str_id"), &native_imgui::BeginPopupContextWindow);
	ClassDB::bind_method(D_METHOD("ImGui_BeginPopupModal", "lable", "open"), &native_imgui::BeginPopupModal);
	ClassDB::bind_method(D_METHOD("ImGui_BeginTabBar", "str_id"), &native_imgui::BeginTabBar);
	ClassDB::bind_method(D_METHOD("ImGui_BeginTabBarItem", "label", "open"), &native_imgui::BeginTabBarItem);
	ClassDB::bind_method(D_METHOD("ImGui_BeginTooltip"), &native_imgui::BeginTooltip);
	ClassDB::bind_method(D_METHOD("ImGui_BeginMenu"), &native_imgui::BeginMenu);
	ClassDB::bind_method(D_METHOD("ImGui_BeginMainMenuBar"), &native_imgui::BeginMainMenuBar);
	ClassDB::bind_method(D_METHOD("ImGui_Bullet"), &native_imgui::Bullet);
	ClassDB::bind_method(D_METHOD("ImGui_BulletText", "text"), &native_imgui::BulletText);
	ClassDB::bind_vararg_method(METHOD_FLAGS_DEFAULT, "ImGui_BulletTextV", &native_imgui::BulletTextV, MethodInfo("BulletTextV"));
	ClassDB::bind_method(D_METHOD("ImGui_CalcListClipping", "item count", "item height"), &native_imgui::CalcListClipping);
	ClassDB::bind_method(D_METHOD("ImGui_CalcTextSize", "text", "end char"), &native_imgui::CalcTextSize);
	ClassDB::bind_method(D_METHOD("ImGui_CaptureKeyboardFromApp", "bool"), &native_imgui::CaptureKeyboardFromApp);
	ClassDB::bind_method(D_METHOD("ImGui_CaptureMouseFromApp", "bool"), &native_imgui::CaptureMouseFromApp);
	ClassDB::bind_method(D_METHOD("ImGui_CheckboxFlags", "label"), &native_imgui::CheckboxFlags);
	ClassDB::bind_method(D_METHOD("ImGui_CollapsingHeader", "label"), &native_imgui::CollapsingHeader);
	ClassDB::bind_method(D_METHOD("ImGui_CheckBox", "label", "value"), &native_imgui::CheckBox);
	ClassDB::bind_method(D_METHOD("ImGui_CloseCurrentPopup"), &native_imgui::CloseCurrentPopup);
	ClassDB::bind_method(D_METHOD("ImGui_ColorButton", "desc_id", "color"), &native_imgui::ColorButton);
	ClassDB::bind_method(D_METHOD("ImGui_CalcItemWidth"), &native_imgui::CalcItemWidth);
	ClassDB::bind_method(D_METHOD("ImGui_ColorPicker3", "label", "Vector3"), &native_imgui::ColorPicker3);
	ClassDB::bind_method(D_METHOD("ImGui_ColorEdit3", "label", "Vector3"), &native_imgui::ColorEdit3);
	ClassDB::bind_method(D_METHOD("ImGui_ColorPicker4", "label", "Vector4"), &native_imgui::ColorPicker3);
	ClassDB::bind_method(D_METHOD("ImGui_ColorEdit4", "label", "Vector4"), &native_imgui::ColorEdit3);
	//ClassDB::bind_method(D_METHOD("ImGui_DragFloat"), &native_imgui::DragFloat); Seems like max args are 5.
	/*

	All other drag functions are missing due to max arg is 5.
	Max arg seems to be 13 when you look at D_METHOD, but 5 when you look at create method bind in
	ClassDB::bind_method.

	Investigation needed.

	*/ 
	ClassDB::bind_method(D_METHOD("ImGui_Dummy"), &native_imgui::Dummy);
	ClassDB::bind_method(D_METHOD("ImGui_EndChildFrame"), &native_imgui::EndChildFrame);
	ClassDB::bind_method(D_METHOD("ImGui_EndChild"), &native_imgui::EndChild);
	ClassDB::bind_method(D_METHOD("ImGui_EndCombo"), &native_imgui::EndCombo);
	ClassDB::bind_method(D_METHOD("ImGui_EndPopup"), &native_imgui::EndPopup);
	ClassDB::bind_method(D_METHOD("ImGui_End"), &native_imgui::End);
	ClassDB::bind_method(D_METHOD("ImGui_EndFrame"), &native_imgui::EndFrame);
	ClassDB::bind_method(D_METHOD("ImGui_EndGroup"), &native_imgui::EndGroup);
	ClassDB::bind_method(D_METHOD("ImGui_EndMenu"), &native_imgui::EndMenu);
	ClassDB::bind_method(D_METHOD("ImGui_EndMainMenuBar"), &native_imgui::EndMainMenuBar);
	ClassDB::bind_method(D_METHOD("ImGui_GetClipBoardtext"), &native_imgui::GetClipboardText);
	ClassDB::bind_method(D_METHOD("ImGui_GetColumnIndex"), &native_imgui::GetColumnIndex);
	ClassDB::bind_method(D_METHOD("ImGui_GetColumnOffset", "index"), &native_imgui::GetColumnOffset);
	ClassDB::bind_method(D_METHOD("ImGui_GetColumnsCount", "index"), &native_imgui::GetColumnsCount);
	ClassDB::bind_method(D_METHOD("ImGui_GetColumnWidth", "index"), &native_imgui::GetColumnWidth);
	ClassDB::bind_method(D_METHOD("ImGui_GetContentRegionAvail"), &native_imgui::GetContentRegionAvail);
	ClassDB::bind_method(D_METHOD("ImGui_GetContentRegionAvailWidth"), &native_imgui::GetContentRegionAvailWidth);
	ClassDB::bind_method(D_METHOD("ImGui_GetContentRegionMax"), &native_imgui::GetContentRegionMax);
	ClassDB::bind_method(D_METHOD("ImGui_GetCursorPos"), &native_imgui::GetCursorPos);
	ClassDB::bind_method(D_METHOD("ImGui_GetCursorPosX"), &native_imgui::GetCursorPosX);
	ClassDB::bind_method(D_METHOD("ImGui_GetCursorPosY"), &native_imgui::GetCursorPosY);
	ClassDB::bind_method(D_METHOD("ImGui_GetCursorScreenPos"), &native_imgui::GetCursorScreenPos);
	ClassDB::bind_method(D_METHOD("ImGui_GetCursorStartPos"), &native_imgui::GetCursorStartPos);
	ClassDB::bind_method(D_METHOD("ImGui_GetFont"), &native_imgui::GetFont);
	ClassDB::bind_method(D_METHOD("ImGui_GetFontSize"), &native_imgui::GetFontSize);
	ClassDB::bind_method(D_METHOD("ImGui_GetFontTexUvWhitePixel"), &native_imgui::GetFontTexUvWhitePixel);
	ClassDB::bind_method(D_METHOD("ImGui_GetFrameCount"), &native_imgui::GetFrameCount);
	ClassDB::bind_method(D_METHOD("ImGui_GetFrameHeight"), &native_imgui::GetFrameHeight);
	ClassDB::bind_method(D_METHOD("ImGui_GetFrameHeightWithSpacing"), &native_imgui::GetFrameHeightWithSpacing);
	ClassDB::bind_method(D_METHOD("ImGui_GetID"), &native_imgui::GetID);
	ClassDB::bind_method(D_METHOD("ImGui_GetItemRectMax"), &native_imgui::GetItemRectMax);
	ClassDB::bind_method(D_METHOD("ImGui_GetItemRectMax"), &native_imgui::GetItemRectMin);
	ClassDB::bind_method(D_METHOD("ImGui_GetItemRectMax"), &native_imgui::GetItemRectSize);
	ClassDB::bind_method(D_METHOD("ImGui_GetKeyIndex"), &native_imgui::GetKeyIndex);
	ClassDB::bind_method(D_METHOD("ImGui_GetKeyPressedAmount"), &native_imgui::GetKeyPressedAmount);
	ClassDB::bind_method(D_METHOD("ImGui_GetMouseCursor"), &native_imgui::GetMouseCursor);
	ClassDB::bind_method(D_METHOD("ImGui_GetMouseDragDelta"), &native_imgui::GetMouseDragDelta);
	ClassDB::bind_method(D_METHOD("ImGui_GetMousePos"), &native_imgui::GetMousePos);
	ClassDB::bind_method(D_METHOD("ImGui_GetMousePosOnOpeningCurrentPopup"),
		&native_imgui::GetMousePosOnOpeningCurrentPopup);
	ClassDB::bind_method(D_METHOD("ImGui_GetScrollMaxX"), &native_imgui::GetScrollMaxX);
	ClassDB::bind_method(D_METHOD("ImGui_GetScrollMaxY"), &native_imgui::GetScrollMaxY);
	ClassDB::bind_method(D_METHOD("ImGui_GetScrollX"), &native_imgui::GetScrollX);
	ClassDB::bind_method(D_METHOD("ImGui_GetScrollY"), &native_imgui::GetScrollY);
	ClassDB::bind_method(D_METHOD("ImGui_GetStyle"), &native_imgui::GetStyle);
	ClassDB::bind_method(D_METHOD("ImGui_GetStyleColorName"), &native_imgui::GetStyleColorName);
	ClassDB::bind_method(D_METHOD("ImGui_GetStyleColorVec4"), &native_imgui::GetStyleColorVec4);
	ClassDB::bind_method(D_METHOD("ImGui_GetTextLineHeight"), &native_imgui::GetTextLineHeight);
	ClassDB::bind_method(D_METHOD("ImGui_GetTextLineHeightWithSpacing"), &native_imgui::GetTextLineHeightWithSpacing);
	ClassDB::bind_method(D_METHOD("ImGui_GetTime"), &native_imgui::GetTime);
	ClassDB::bind_method(D_METHOD("ImGui_GetTreeNodeToLabelSpacing"), &native_imgui::GetTreeNodeToLabelSpacing);
	ClassDB::bind_method(D_METHOD("ImGui_GetWindowContentRegionMax"), &native_imgui::GetWindowContentRegionMax);
	ClassDB::bind_method(D_METHOD("ImGui_GetWindowContentRegionMin"), &native_imgui::GetWindowContentRegionMin);
	ClassDB::bind_method(D_METHOD("ImGui_GetWindowContentRegionWidth"), &native_imgui::GetWindowContentRegionWidth);
	ClassDB::bind_method(D_METHOD("ImGui_GetWindowWidth"), &native_imgui::GetWindowWidth);
	ClassDB::bind_method(D_METHOD("ImGui_GetWindowHeight"), &native_imgui::GetWindowHeight);
	ClassDB::bind_method(D_METHOD("ImGui_GetWindowPos"), &native_imgui::GetWindowPos);
	ClassDB::bind_method(D_METHOD("ImGui_GetWindowSize"), &native_imgui::GetWindowSize); 
	ClassDB::bind_method(D_METHOD("ImGui_EndTabBar"), &native_imgui::EndTabBar);
	ClassDB::bind_method(D_METHOD("ImGui_Indent"), &native_imgui::Indent);
	ClassDB::bind_method(D_METHOD("ImGui_InputDouble", "label", "value", "step", "fastStep", "format"), &native_imgui::InputDouble);
	ClassDB::bind_method(D_METHOD("ImGui_InputFloat", "label", "value", "format"), &native_imgui::InputFloat);
	ClassDB::bind_method(D_METHOD("ImGui_InputFloat2", "label", "value", "format"), &native_imgui::InputFloat2);
	ClassDB::bind_method(D_METHOD("ImGui_InputFloat3", "label", "value", "format"), &native_imgui::InputFloat3);
	ClassDB::bind_method(D_METHOD("ImGui_InputFloat4", "label", "value", "format"), &native_imgui::InputFloat4);
	ClassDB::bind_method(D_METHOD("ImGui_InputInt", "label", "value", "step", "fastStep"), &native_imgui::InputInt);
	ClassDB::bind_method(D_METHOD("ImGui_InputInt2", "label", "value", "step", "fastStep"), &native_imgui::InputInt2);
	ClassDB::bind_method(D_METHOD("ImGui_InputInt3", "label", "value", "step", "fastStep"), &native_imgui::InputInt3);
	/*ClassDB::bind_method(D_METHOD("ImGui_InputInt4", "label", "value", "step", "fastStep", "format"), &native_imgui::InputInt4);*/
	ClassDB::bind_method(D_METHOD("ImGui_InputScalar"), &native_imgui::InputScalar);
	ClassDB::bind_method(D_METHOD("ImGui_InputText"), &native_imgui::InputText);
	ClassDB::bind_method(D_METHOD("ImGui_InputTextMultiline"), &native_imgui::InputTextMultiline);
	ClassDB::bind_method(D_METHOD("ImGui_InputTextWithHint"), &native_imgui::InputTextWithHint);
	ClassDB::bind_method(D_METHOD("ImGui_InvisibleButton"), &native_imgui::InvisibleButton);
	ClassDB::bind_method(D_METHOD("ImGui_IsAnyItemActive"), &native_imgui::IsAnyItemActive);
	ClassDB::bind_method(D_METHOD("ImGui_IsAnyItemFocused"), &native_imgui::IsAnyItemFocused);
	ClassDB::bind_method(D_METHOD("ImGui_IsAnyItemHovered"), &native_imgui::IsAnyItemHovered);
	ClassDB::bind_method(D_METHOD("ImGui_IsAnyMouseDown"), &native_imgui::IsAnyMouseDown);
	ClassDB::bind_method(D_METHOD("ImGui_IsItemActivated"), &native_imgui::IsItemActivated);
	ClassDB::bind_method(D_METHOD("ImGui_IsItemClicked"), &native_imgui::IsItemClicked);
	ClassDB::bind_method(D_METHOD("ImGui_IsItemDeactivated"), &native_imgui::IsItemDeactivated);
	ClassDB::bind_method(D_METHOD("ImGui_IsItemDeactivatedAfterChange"), &native_imgui::IsItemDeactivatedAfterChange);
	ClassDB::bind_method(D_METHOD("ImGui_IsItemDeactivatedAfterEdit"), &native_imgui::IsItemDeactivatedAfterEdit);
	ClassDB::bind_method(D_METHOD("ImGui_IsItemEdited"), &native_imgui::IsItemEdited);
	ClassDB::bind_method(D_METHOD("ImGui_IsItemFocused"), &native_imgui::IsItemFocused);
	ClassDB::bind_method(D_METHOD("ImGui_IsItemHovered"), &native_imgui::IsItemHovered);
	ClassDB::bind_method(D_METHOD("ImGui_IsItemToggledOpen"), &native_imgui::IsItemToggledOpen);
	ClassDB::bind_method(D_METHOD("ImGui_IsItemVisible"), &native_imgui::IsItemVisible);
	ClassDB::bind_method(D_METHOD("ImGui_IsKeyDown", "key"), &native_imgui::IsKeyDown);
	ClassDB::bind_method(D_METHOD("ImGui_IsKeyReleased", "key"), &native_imgui::IsKeyReleased);
	ClassDB::bind_method(D_METHOD("ImGui_IsKeyPressed", "key"), &native_imgui::IsKeyPressed);
	ClassDB::bind_method(D_METHOD("ImGui_IsMouseClicked", "button"), &native_imgui::IsMouseClicked);
	ClassDB::bind_method(D_METHOD("ImGui_IsMouseDoubleClicked", "button"), &native_imgui::IsMouseDoubleClicked);
	ClassDB::bind_method(D_METHOD("ImGui_IsMouseDown", "button"), &native_imgui::IsMouseDown);
	ClassDB::bind_method(D_METHOD("ImGui_IsMouseDragging"), &native_imgui::IsMouseDragging);
	ClassDB::bind_method(D_METHOD("ImGui_IsMouseHoveringRect"), &native_imgui::IsMouseHoveringRect);
	ClassDB::bind_method(D_METHOD("ImGui_IsMousePosValid"), &native_imgui::IsMousePosValid);
	ClassDB::bind_method(D_METHOD("ImGui_IsMouseReleased"), &native_imgui::IsMouseReleased);
	ClassDB::bind_method(D_METHOD("ImGui_IsPopupOpen", "str_id"), &native_imgui::IsPopupOpen);
	ClassDB::bind_method(D_METHOD("ImGui_IsRectVisible"), &native_imgui::IsRectVisible);
	ClassDB::bind_method(D_METHOD("ImGui_IsWindowAppearing"), &native_imgui::IsWindowAppearing);
	ClassDB::bind_method(D_METHOD("ImGui_IsWindowCollapsed"), &native_imgui::IsWindowCollapsed);
	ClassDB::bind_method(D_METHOD("ImGui_IsWindowFocused"), &native_imgui::IsWindowFocused);
	ClassDB::bind_method(D_METHOD("ImGui_IsWindowHovered"), &native_imgui::IsWindowHovered);
	ClassDB::bind_vararg_method(METHOD_FLAGS_DEFAULT, "ImGui_LabelText", &native_imgui::LabelText, MethodInfo("LabelText"));
	ClassDB::bind_vararg_method(METHOD_FLAGS_DEFAULT, "ImGui_LabelTextV", &native_imgui::LabelTextV, MethodInfo("LabelTextV"));
	ClassDB::bind_method(D_METHOD("ImGui_ListBox"), &native_imgui::ListBox); // Really broken, might not be fixable
	ClassDB::bind_method(D_METHOD("ImGui_ListBoxFooter"), &native_imgui::ListBoxFooter);
	ClassDB::bind_method(D_METHOD("ImGui_ListBoxHeader"), &native_imgui::ListBoxHeader);
	ClassDB::bind_method(D_METHOD("ImGui_LogButtons"), &native_imgui::LogButtons);
	ClassDB::bind_method(D_METHOD("ImGui_LogFinish"), &native_imgui::LogFinish);
	ClassDB::bind_vararg_method(METHOD_FLAGS_DEFAULT, "ImGui_LogText", &native_imgui::LogText, MethodInfo("LogText"));
	ClassDB::bind_method(D_METHOD("ImGui_LogToClipboard"), &native_imgui::LogToClipboard);
	ClassDB::bind_method(D_METHOD("ImGui_MenuItem", "label", "shortcut", "selected", "enabled"), &native_imgui::MenuItem);
	ClassDB::bind_method(D_METHOD("ImGui_NewFrame"), &native_imgui::NewFrame);
	ClassDB::bind_method(D_METHOD("ImGui_NextColumn"), &native_imgui::NextColumn);
	ClassDB::bind_method(D_METHOD("ImGui_OpenPopup"), &native_imgui::OpenPopup);
	ClassDB::bind_method(D_METHOD("ImGui_OpenPopupContextItem"), &native_imgui::OpenPopupContextItem);
	ClassDB::bind_method(D_METHOD("ImGui_OpenPopupOnItemClick"), &native_imgui::OpenPopupOnItemClick);
	ClassDB::bind_method(D_METHOD("ImGui_PlotHistogram"), &native_imgui::PlotHistogram);
	ClassDB::bind_method(D_METHOD("ImGui_PlotLines"), &native_imgui::PlotLines);
	ClassDB::bind_method(D_METHOD("ImGui_PopAllowKeyboardFocus"), &native_imgui::PopAllowKeyboardFocus);
	ClassDB::bind_method(D_METHOD("ImGui_PopButtonRepeat"), &native_imgui::PopButtonRepeat);
	ClassDB::bind_method(D_METHOD("ImGui_PopClipRect"), &native_imgui::PopClipRect);
	ClassDB::bind_method(D_METHOD("ImGui_PopFont"), &native_imgui::PopFont);
	ClassDB::bind_method(D_METHOD("ImGui_PopID"), &native_imgui::PopID);
	ClassDB::bind_method(D_METHOD("ImGui_PopItemWidth"), &native_imgui::PopItemWidth);
	ClassDB::bind_method(D_METHOD("ImGui_PopStyleColor"), &native_imgui::PopStyleColor);
	ClassDB::bind_method(D_METHOD("ImGui_PopStyleVar"), &native_imgui::PopStyleVar);
	ClassDB::bind_method(D_METHOD("ImGui_PopTextWrapPos"), &native_imgui::PopTextWrapPos);
	ClassDB::bind_method(D_METHOD("ImGui_ProgressBar"), &native_imgui::ProgressBar);
	ClassDB::bind_method(D_METHOD("ImGui_PushAllowKeyboardFocus"), &native_imgui::PushAllowKeyboardFocus);
	ClassDB::bind_method(D_METHOD("ImGui_PushButtonRepeat"), &native_imgui::PushButtonRepeat);
	ClassDB::bind_method(D_METHOD("ImGui_PushClipRect"), &native_imgui::PushClipRect);
	ClassDB::bind_method(D_METHOD("ImGui_PushFont"), &native_imgui::PushFont);
	ClassDB::bind_method(D_METHOD("ImGui_PushID"), &native_imgui::PushID);
	ClassDB::bind_method(D_METHOD("ImGui_PushItemWidth"), &native_imgui::PushItemWidth);
	ClassDB::bind_method(D_METHOD("ImGui_PushStyleColor"), &native_imgui::PushStyleColor);
	ClassDB::bind_method(D_METHOD("ImGui_PushStyleVar"), &native_imgui::PushStyleVar);
	ClassDB::bind_method(D_METHOD("ImGui_PushTextWrapPos"), &native_imgui::PushTextWrapPos);
	ClassDB::bind_method(D_METHOD("ImGui_RadioButton", "label", "state"), &native_imgui::RadioButton);
	ClassDB::bind_method(D_METHOD("ImGui_Render"), &native_imgui::Render);
	ClassDB::bind_method(D_METHOD("ImGui_Separator"), &native_imgui::Separator);
	ClassDB::bind_method(D_METHOD("ImGui_SameLine"), &native_imgui::SameLine);
	ClassDB::bind_method(D_METHOD("ImGui_Selectable"), &native_imgui::Selectable);
	ClassDB::bind_method(D_METHOD("ImGui_SetClipboardText"), &native_imgui::SetClipboardText);
	ClassDB::bind_method(D_METHOD("ImGui_SetColorEditOptions"), &native_imgui::SetColorEditOptions);
	ClassDB::bind_method(D_METHOD("ImGui_SetColumnOffset", "column index", "offset_x"), &native_imgui::SetColumnOffset);
	ClassDB::bind_method(D_METHOD("ImGui_SetColumnWidth"), &native_imgui::SetColumnWidth);
	ClassDB::bind_method(D_METHOD("ImGui_SetCursorPos"), &native_imgui::SetCursorPos);
	ClassDB::bind_method(D_METHOD("ImGui_SetCursorPosX"), &native_imgui::SetCursorPosX);
	ClassDB::bind_method(D_METHOD("ImGui_SetCursorPosY"), &native_imgui::SetCursorPosY);
	ClassDB::bind_method(D_METHOD("ImGui_SetCursorScreenPos"), &native_imgui::SetCursorScreenPos);
	ClassDB::bind_method(D_METHOD("ImGui_SetItemAllowOverlap"), &native_imgui::SetItemAllowOverlap);
	ClassDB::bind_method(D_METHOD("ImGui_SetItemDefaultFocus"), &native_imgui::SetItemDefaultFocus);
	ClassDB::bind_method(D_METHOD("ImGui_SetKeyboardFocusHere"), &native_imgui::SetKeyboardFocusHere);
	ClassDB::bind_method(D_METHOD("ImGui_SetMouseCursor", "cursor"), &native_imgui::SetMouseCursor);	
	ClassDB::bind_method(D_METHOD("ImGui_SetNextItemOpen", "bool is_open", "condition"), &native_imgui::SetNextItemOpen);
	ClassDB::bind_method(D_METHOD("ImGui_SetNextItemWidth", "width"), &native_imgui::SetNextItemWidth);
	ClassDB::bind_method(D_METHOD("ImGui_SetNextTreeNodeOpen", "open", "cond"), &native_imgui::SetNextTreeNodeOpen);
	ClassDB::bind_method(D_METHOD("ImGui_SetNextWindowBgAlpha", "alpha"), &native_imgui::SetNextWindowBgAlpha);
	ClassDB::bind_method(D_METHOD("ImGui_SetNextWindowCollapsed", "collapsed", "cond"), &native_imgui::SetNextWindowCollapsed);
	ClassDB::bind_method(D_METHOD("ImGui_SetNextWindowContentSize", "size"), &native_imgui::SetNextWindowContentSize);
	ClassDB::bind_method(D_METHOD("ImGui_SetNextWindowFocus"), &native_imgui::SetNextWindowFocus);
	ClassDB::bind_method(D_METHOD("ImGui_SetNextWindowPos", "pos", "cond", "pivot"), &native_imgui::SetNextWindowPos);
	ClassDB::bind_method(D_METHOD("ImGui_SetNextWindowSize", "size", "cond"), &native_imgui::SetNextWindowSize);
	ClassDB::bind_method(D_METHOD("ImGui_SetNextWindowSizeConstraints", "min", "max"), &native_imgui::SetNextWindowSize);
	ClassDB::bind_method(D_METHOD("ImGui_SetScrollFromPosX", "x"), &native_imgui::SetScrollFromPosX);
	ClassDB::bind_method(D_METHOD("ImGui_SetScrollFromPosY", "y"), &native_imgui::SetScrollFromPosY);
	ClassDB::bind_method(D_METHOD("ImGui_SetScrollHere", "center_ration"), &native_imgui::SetScrollHere);
	ClassDB::bind_method(D_METHOD("ImGui_SetScrollHereX", "center_x_ration"), &native_imgui::SetScrollHereX);
	ClassDB::bind_method(D_METHOD("ImGui_SetScrollHereY", "center_Y_ration"), &native_imgui::SetScrollHereY); 
	ClassDB::bind_method(D_METHOD("ImGui_SetScrollX", "x"), &native_imgui::SetScrollX);
	ClassDB::bind_method(D_METHOD("ImGui_SetScrollY", "y"), &native_imgui::SetScrollY);
	ClassDB::bind_method(D_METHOD("ImGui_SetTabItemClosed", "label of tab"), &native_imgui::SetTabItemClosed);
	ClassDB::bind_vararg_method(METHOD_FLAGS_DEFAULT, "ImGui_SetTooltip", &native_imgui::SetTooltip, MethodInfo("SetTooltip"));
	ClassDB::bind_vararg_method(METHOD_FLAGS_DEFAULT, "ImGui_SetTooltipV", &native_imgui::SetTooltipV, MethodInfo("SetTooltipV"));
	ClassDB::bind_method(D_METHOD("ImGui_SetWindowCollapsed", "collapsed", "cond"), &native_imgui::SetWindowCollapsed);
	ClassDB::bind_method(D_METHOD("ImGui_SetWindowFocus"), &native_imgui::SetWindowFocus);
	ClassDB::bind_method(D_METHOD("ImGui_SetWindowFontScale", "scale"), &native_imgui::SetWindowFontScale);
	ClassDB::bind_method(D_METHOD("ImGui_SetWindowPos", "pos", "cond"), &native_imgui::SetWindowPos);
	ClassDB::bind_method(D_METHOD("ImGui_SetWindowSize", "size", "cond"), &native_imgui::SetWindowSize);
	//ClassDB::bind_method(D_METHOD("ImGui_ShowFontSelector", "laber"), &native_imgui::ShowFontSelector);
	ClassDB::bind_method(D_METHOD("ImGui_SliderAngle", "label", "rads"), &native_imgui::SliderAngle);
	ClassDB::bind_method(D_METHOD("ImGui_SliderFloat", "label", "value", "min", "max"), &native_imgui::SliderFloat);
	ClassDB::bind_method(D_METHOD("ImGui_SliderFloat2", "label", "value", "min", "max"), &native_imgui::SliderFloat2);
	ClassDB::bind_method(D_METHOD("ImGui_SliderFloat3", "label", "value", "min", "max"), &native_imgui::SliderFloat3);
	ClassDB::bind_method(D_METHOD("ImGui_SliderFloat4", "label", "value", "min", "max"), &native_imgui::SliderFloat4);
	ClassDB::bind_method(D_METHOD("ImGui_SliderInt", "label", "value", "min", "max"), &native_imgui::SliderInt);
	ClassDB::bind_method(D_METHOD("ImGui_SliderInt2", "label", "value", "min", "max"), &native_imgui::SliderInt2);
	ClassDB::bind_method(D_METHOD("ImGui_SliderInt3", "label", "value", "min", "max"), &native_imgui::SliderInt3);
	ClassDB::bind_method(D_METHOD("ImGui_SliderInt4", "label", "value", "min", "max"), &native_imgui::SliderInt4);
	ClassDB::bind_method(D_METHOD("ImGui_SmallButton", "label"), &native_imgui::SmallButton);
	ClassDB::bind_method(D_METHOD("ImGui_Spacing"), &native_imgui::Spacing);
	ClassDB::bind_method(D_METHOD("ImGui_StyleColorsClassic"), &native_imgui::StyleColorsClassic);
	ClassDB::bind_method(D_METHOD("ImGui_StyleColorsDark"), &native_imgui::StyleColorsDark);
	ClassDB::bind_method(D_METHOD("ImGui_StyleColorsLight"), &native_imgui::StyleColorsLight);
	ClassDB::bind_vararg_method(METHOD_FLAGS_DEFAULT, "ImGui_TextDisabled", &native_imgui::TextDisabled, MethodInfo("TextDisabled"));
	ClassDB::bind_vararg_method(METHOD_FLAGS_DEFAULT, "ImGui_TextDisabledV", &native_imgui::TextDisabled, MethodInfo("TextDisabled"));
	ClassDB::bind_vararg_method(METHOD_FLAGS_DEFAULT, "ImGui_Text", &native_imgui::Text, MethodInfo("Text"));
	ClassDB::bind_vararg_method(METHOD_FLAGS_DEFAULT, "ImGui_TextV", &native_imgui::Text, MethodInfo("Text"));
	ClassDB::bind_vararg_method(METHOD_FLAGS_DEFAULT, "ImGui_TextWrapped", &native_imgui::TextWrapped, MethodInfo("TextWrapped"));
	ClassDB::bind_vararg_method(METHOD_FLAGS_DEFAULT, "ImGui_TextWrappedV", &native_imgui::TextWrapped, MethodInfo("TextWrapped"));
	ClassDB::bind_vararg_method(METHOD_FLAGS_DEFAULT, "ImGui_TextColored", &native_imgui::TextColored, MethodInfo("TextColored"));
	ClassDB::bind_vararg_method(METHOD_FLAGS_DEFAULT, "ImGui_TextColoredV", &native_imgui::TextColored, MethodInfo("TextColored"));
	ClassDB::bind_method(D_METHOD("ImGui_TreeAdvanceToLabelPos"), &native_imgui::TreeAdvanceToLabelPos);
	ClassDB::bind_method(D_METHOD("ImGui_TreeNode", "label"), &native_imgui::TreeNode);
	ClassDB::bind_method(D_METHOD("ImGui_TreeNodeEx", "label", "flags"), &native_imgui::TreeNodeEx);
	ClassDB::bind_vararg_method(METHOD_FLAGS_DEFAULT, "ImGui_TreeNodeExV", &native_imgui::TreeNodeExV, MethodInfo("TreeNodeExV"));
	ClassDB::bind_vararg_method(METHOD_FLAGS_DEFAULT, "ImGui_TreeNodeV", &native_imgui::TreeNodeV, MethodInfo("TreeNodeV"));
	ClassDB::bind_method(D_METHOD("ImGui_TreePop"), &native_imgui::TreePop);
	ClassDB::bind_method(D_METHOD("ImGui_TreePush"), &native_imgui::TreePush);
	ClassDB::bind_method(D_METHOD("ImGui_Unindent", "width"), &native_imgui::Unindent);
	ClassDB::bind_method(D_METHOD("ImGui_Value", "id", "value"), &native_imgui::Value);	
	ClassDB::bind_method(D_METHOD("ImGui_VSliderFloat", "label", "size" "value", "min", "max"), &native_imgui::VSliderFloat);
	ClassDB::bind_method(D_METHOD("ImGui_VSliderInt", "label", "size", "value", "min", "max"), &native_imgui::VSliderInt); 
}

void native_imgui::process_imgui() {
	ImGuiIO &io = ImGui::GetIO();

	Vector2 godot_mouse_pos = OS::get_singleton()->get_mouse_position();
	ImVec2 mousePos(godot_mouse_pos.x, godot_mouse_pos.y);

	io.MousePos = mousePos;
	io.MouseDown[0] = OS::get_singleton()->get_mouse_button_state() == 1 ? true : false;
	io.MouseDown[1] = OS::get_singleton()->get_mouse_button_state() == 2 ? true : false;

	// This says 0, I say doubt(X)
	io.DeltaTime = 1.0 / 120.0;
	get_process_delta_time();
	 
	draw();
}
 

Vector<Array> native_imgui::extract_imgui_data() {
	ImDrawData *draw_dat = ImGui::GetDrawData();
 
	draw_dat->ScaleClipRects(ImGui::GetIO().DisplayFramebufferScale);
	for (uint32_t i = 0; i < children.size(); i++)
		VisualServer->free(children[i]);

	children.clear();

	Vector<Array> arrays;
	// How many meshes
	for (uint32_t i = 0; i < draw_dat->CmdListsCount; i++) {
		ImDrawList * list = draw_dat->CmdLists[i];
 
		Array temp;
		temp.resize(ArrayMesh::ARRAY_MAX);
		

		Vector<Vector2> vertices;
		Vector<Color> colors;
		Vector<Vector2> uvs;
		Vector<int> indices;

		for (uint32_t j = 0; j < list->CmdBuffer.Size; j++) {
			RID child = VisualServer->canvas_item_create();
			VisualServer->canvas_item_set_parent(child, get_canvas_item());
			children.push_back(child);
			// This is just temp fix, we need to smash this into a container along with the Array, probably a dict is needed
			ImDrawCmd drawCmd = list->CmdBuffer[j];
			VisualServer->canvas_item_set_custom_rect(child, true, Rect2(drawCmd.ClipRect.x,
				drawCmd.ClipRect.y, drawCmd.ClipRect.z - drawCmd.ClipRect.x,
				drawCmd.ClipRect.w - drawCmd.ClipRect.y));
		}

		// Extract information regarding verticies
		for (uint32_t j = 0; j < list->VtxBuffer.size(); j++) {
			// vertex pos
			ImVec2 im_vert = list->VtxBuffer[j].pos;
			Vector2 godot_vert(im_vert.x, im_vert.y);

			// vertex colour
			ImU32 im_col = list->VtxBuffer[j].col;
			float R = (im_col & 0xFF) / 255.0; // Bit shift magic, ImGui thinks colours are 32bit integers 0-255, Godot think they are 8 bit floats 0-1
			float G = ((im_col >> 8) & 0xFF) / 255.0;
			float B = ((im_col >> 16) & 0xFF) / 255.0;
			float A = ((im_col >> 24) & 0xFF) / 255.0;
			Color godot_col(R, G, B, A);
			// Vertex uv
			ImVec2 im_uv = list->VtxBuffer[j].uv;
			Vector2 godot_uv(im_uv.x, im_uv.y);

			uvs.push_back(godot_uv);
			vertices.push_back(godot_vert);
			colors.push_back(godot_col);
		}

		for (uint32_t j = 0; j < list->IdxBuffer.size(); j++) {
			indices.push_back(list->IdxBuffer[j]);
		}


		temp[(int)ArrayMesh::ArrayType::ARRAY_VERTEX] = vertices;
		temp[(int)ArrayMesh::ArrayType::ARRAY_INDEX] = indices;
		temp[(int)ArrayMesh::ArrayType::ARRAY_COLOR] = colors;
		temp[(int)ArrayMesh::ArrayType::ARRAY_TEX_UV] = uvs;

		arrays.push_back(temp);
	}

	return arrays;
}

void native_imgui::draw() {
	// Ugly temp fix, otherwise previous meshes will live on into next frame
	while (mesh.get_surface_count() > 0) {
		mesh.surface_remove(0);
	}
	 
	Vector<Array> arrays = extract_imgui_data();
	

	for (uint32_t i = 0; i < arrays.size(); i++) {
		Vector<Color> temp = arrays[i][ArrayMesh::ARRAY_COLOR];
		mesh.add_surface_from_arrays(Mesh::PrimitiveType::PRIMITIVE_TRIANGLES, arrays[i]);

		// This does not clear the backbuffer
		VisualServer->canvas_item_clear(children[i]);
	  
		VisualServer->canvas_item_set_clip(children[i], true); 

		// This adds the canvas to the rendering queue.
		VisualServer->canvas_item_add_mesh(children[i], mesh.get_rid(), Transform2D(), Color(), imgtex.get_rid());
	}
}

void native_imgui::RebuildFontAtlas() {
}

native_imgui::native_imgui() {
	this->VisualServer = VisualServer::get_singleton();
	context = ImGui::CreateContext();
	ImGuiIO &io = ImGui::GetIO();
	io.BackendFlags = 0;
	//ImGui::SetCurrentContext(context);
	//ImGui::StyleColorsDark();

	io.Fonts->AddFontDefault();
	io.MouseDrawCursor = false;

	int width, height, bytesPerPixel;
	unsigned char *pixels = NULL;
	io.Fonts->GetTexDataAsRGBA32(&pixels, &width, &height, &bytesPerPixel);

	PoolByteArray textureDataRaw;

	for (uint32_t i = 0; i < width * height * bytesPerPixel; i++) {
		textureDataRaw.push_back(pixels[i]);
	}

	Image img(width, height, false, Image::Format::FORMAT_RGBA8, textureDataRaw);

	imgtex.create_from_image(img.duplicate(), 0);

	io.Fonts->TexID = ImTextureID(100);

	io.Fonts->ClearTexData();

	io.DisplaySize.x = GLOBAL_GET("display/window/size/width"); // set the current display width
	io.DisplaySize.y = GLOBAL_GET("display/window/size/height"); // set current display height

	input.resize(64); // Maximum size of input
}

void native_imgui::setvalue(String field, RID parent) {

}

void native_imgui::Begin(String name, bool open) {
	ImGui::Begin(convertStringToChar(name), &open); // ImGuiWindowFlags_Popup Bör tas bort 
}

bool native_imgui::BeginChild(unsigned int ImGuiID, Vector2 vec, bool border) {
	return ImGui::BeginChild(ImGuiID, Vector2ToImVec(vec), border);
}

void native_imgui::EndChild() {
	ImGui::EndChild();
}

bool native_imgui::BeginChildFrame(unsigned int ImGuiID, Vector2 vec) {
	return ImGui::BeginChildFrame(ImGuiID, Vector2ToImVec(vec));
}

void native_imgui::EndChildFrame() {
	ImGui::EndChildFrame();
}

bool native_imgui::BeginCombo(String label, String preview) {
	return ImGui::BeginCombo(convertStringToChar(label), convertStringToChar(preview));
}

void native_imgui::EndCombo() {
	ImGui::EndCombo();
}

bool native_imgui::BeginPopup(String str_id) {
	return ImGui::BeginPopup(convertStringToChar(str_id), ImGuiWindowFlags_Popup);
}

void native_imgui::EndPopup() {
	ImGui::EndPopup();
}

bool native_imgui::BeginPopupContextItem(String str_id) {
	return ImGui::BeginPopupContextItem(convertStringToChar(str_id));
}

bool native_imgui::BeginPopupContexVoid(String str_id) {
	return ImGui::BeginPopupContextVoid(convertStringToChar(str_id));
}

bool native_imgui::BeginPopupContextWindow(String str_id) {
	return ImGui::BeginPopupContextWindow(convertStringToChar(str_id));
}

void  native_imgui::BeginGroup() {
	ImGui::BeginGroup();
}

void native_imgui::EndGroup() {
	ImGui::EndGroup();
}

bool native_imgui::BeginPopupModal(String label, bool open) {
	ImGui::BeginPopupModal(convertStringToChar(label), &open);
	return open;
}

bool native_imgui::BeginTabBar(String str_id) {
	return ImGui::BeginTabBar(convertStringToChar(str_id));
}

bool native_imgui::BeginTabBarItem(String label, bool open) {
	ImGui::BeginTabItem(convertStringToChar(label), &open);
	return open;
}

void native_imgui::EndTabBarItem() {
	ImGui::EndTabItem();
}

void native_imgui::EndTabBar() {
	ImGui::EndTabBar();
}

void native_imgui::BeginTooltip() {
	ImGui::BeginTooltip();
}


Variant native_imgui::BulletTextV(const Variant **p_args, int p_argcount, Variant::CallError &r_error) {
	String arg;
	for (uint32_t i = 0; i < p_argcount; i++) {
		if (p_args[i]->get_type() != Variant::STRING) {
			r_error.error = Variant::CallError::CALL_ERROR_INVALID_ARGUMENT;
			r_error.argument = 0;
			r_error.expected = Variant::STRING;
			return Variant();
		}
		// We conver the variant into a string and concatianate it to a godot string
		arg += (String)*p_args[i];
	}

	// We fool ImGui that we are variadic. We are converting a const char * to a char*
	//which kinda means we are praying that ImGui doens't do anything stupid
	ImGui::BulletTextV(convertStringToChar(arg), (char*)convertStringToChar(arg));
	
	r_error.error = Variant::CallError::CALL_OK;
	return Variant();
}

bool native_imgui::Button(String text, Vector2 size) {
	bool newState = ImGui::Button(convertStringToChar(text), Vector2ToImVec(size));

	return handleButtonDic(text, newState);
}

Array native_imgui::CalcListClipping(uint32_t item_count, uint32_t item_height) {
	int out_item_display_start, out_item_display_end;
	ImGui::CalcListClipping(item_count, item_height, &out_item_display_start, &out_item_display_end);

	Array result;
	result.push_back(out_item_display_start);
	result.push_back(out_item_display_end);

	return result;
}

Vector2 native_imgui::CalcTextSize(String text, String end) {
	return ImVec2ToVector2(ImGui::CalcTextSize(convertStringToChar(text), convertStringToChar(end)));
}

void native_imgui::CaptureKeyboardFromApp(bool capture) {
	ImGui::CaptureKeyboardFromApp(capture);
}

void native_imgui::CaptureMouseFromApp(bool capture) {
	ImGui::CaptureMouseFromApp(capture);
}

bool native_imgui::CheckboxFlags(String label, uint32_t flags, uint32_t flags_value) {
	return handleButtonDic(label, ImGui::CheckboxFlags(convertStringToChar(label), &flags, flags_value));
}

bool native_imgui::CollapsingHeader(String label) {
	return ImGui::CollapsingHeader(convertStringToChar(label));
}

double native_imgui::InputDouble(String label, double value, double step, double faststep, String format) {
	ImGui::InputDouble(convertStringToChar(label), &value, step, faststep, convertStringToChar(format));
	return value;
}

float native_imgui::InputScalar(String label, unsigned int datatype,  int val, unsigned int step, unsigned int faststep) {
	ImGui::InputScalar(convertStringToChar(label), datatype, (void *)&val, (const void *)&step, (const void *)&faststep);
	return val;
}

String native_imgui::InputText(String label, String val, unsigned int size) {
	input = val;

	ImGui::InputText(convertStringToChar(label), (char*)convertStringToChar(input), 64);


	return String(input);
}

String native_imgui::InputTextMultiline(String label, String val, unsigned int buf_size, Vector2 size) {
	input = val;
	ImGui::InputTextMultiline(convertStringToChar(label), (char *)convertStringToChar(input), 64, Vector2ToImVec(size));

	return input;
}

String native_imgui::InputTextWithHint(String label, String hint, String val, unsigned int buf_size) {
	input = val;

	ImGui::InputTextWithHint(convertStringToChar(label), convertStringToChar(hint), (char *)convertStringToChar(input), 64);

	return val;
}

bool native_imgui::InvisibleButton(String str_id, Vector2 size) {
	return ImGui::InvisibleButton(convertStringToChar(str_id), Vector2ToImVec(size));
}

bool native_imgui::IsAnyItemActive() {
	return ImGui::IsAnyItemActive();
}

bool native_imgui::IsAnyItemFocused() {
	return ImGui::IsAnyItemFocused();
}

bool native_imgui::IsAnyItemHovered() {
	return ImGui::IsAnyItemHovered();
}

bool native_imgui::IsAnyMouseDown() {
	return ImGui::IsAnyMouseDown();
}

bool native_imgui::IsItemActivated() {
	return ImGui::IsItemActivated();
}

bool native_imgui::IsItemClicked() {
	return ImGui::IsItemClicked();
}

bool native_imgui::IsItemDeactivated() {
	return ImGui::IsItemDeactivated();
}

bool native_imgui::IsItemDeactivatedAfterChange() {
	return ImGui::IsItemDeactivatedAfterChange(); // OBSELETE
}

bool native_imgui::IsItemDeactivatedAfterEdit() {
	return ImGui::IsItemDeactivatedAfterEdit();
}

bool native_imgui::IsItemEdited() {
	return ImGui::IsItemEdited();
}

bool native_imgui::IsItemFocused() {
	return ImGui::IsItemFocused();
}

bool native_imgui::IsItemHovered() {
	return ImGui::IsItemHovered();
}

bool native_imgui::IsItemToggledOpen() {
	return ImGui::IsItemToggledOpen();
}

bool native_imgui::IsItemVisible() {
	return ImGui::IsItemVisible();
}

bool native_imgui::IsKeyDown(unsigned int key_index) {
	return ImGui::IsKeyDown(key_index);
}

bool native_imgui::IsKeyReleased(unsigned int key_index) {
	return ImGui::IsKeyReleased(key_index);
}

bool native_imgui::IsKeyPressed(unsigned int key_index) {
	return ImGui::IsKeyPressed(key_index);
}

bool native_imgui::IsMouseClicked(unsigned int button) {
	return ImGui::IsMouseClicked(button);
}

bool native_imgui::IsMouseDoubleClicked(unsigned int button) {
	return ImGui::IsMouseDoubleClicked(button);
}

bool native_imgui::IsMouseDown(unsigned int button) {
	return ImGui::IsMouseDown(button);
}

bool native_imgui::IsMouseDragging(unsigned int button) {
	return ImGui::IsMouseDragging(button);
}

bool native_imgui::IsMouseHoveringRect(Vector2 min, Vector2 max, bool clip) {
	return ImGui::IsMouseHoveringRect(Vector2ToImVec(min), Vector2ToImVec(max), clip);
}

bool native_imgui::IsMousePosValid(Vector2 pos) {
	return ImGui::IsMousePosValid(&Vector2ToImVec(pos));
}

bool native_imgui::IsMouseReleased(unsigned int button) {
	return ImGui::IsMouseReleased(button);
}

bool native_imgui::IsPopupOpen(String str_id) {
	return ImGui::IsPopupOpen(convertStringToChar(str_id));
}

bool native_imgui::IsRectVisible(const Vector2& vec) {
	return ImGui::IsRectVisible(Vector2ToImVec(vec));
}

bool native_imgui::IsWindowAppearing() {
	return ImGui::IsWindowAppearing();
}

bool native_imgui::IsWindowCollapsed() {
	return ImGui::IsWindowCollapsed();
}

bool native_imgui::IsWindowFocused() {
	return ImGui::IsWindowFocused();
}

bool native_imgui::IsWindowHovered() {
	return ImGui::IsWindowHovered();
}

Variant native_imgui::LabelText(const Variant **p_args, int p_argcount, Variant::CallError &r_error) {
	String arg;
	for (uint32_t i = 0; i < p_argcount; i++) {
		if (p_args[i]->get_type() != Variant::STRING) {
			r_error.error = Variant::CallError::CALL_ERROR_INVALID_ARGUMENT;
			r_error.argument = 0;
			r_error.expected = Variant::STRING;
			return Variant();
		}
		// We conver the variant into a string and concatianate it to a godot string
		arg += (String)*p_args[i];
	}

	// We fool ImGui that we are variadic. We are converting a const char * to a char*
	//which kinda means we are praying that ImGui doens't do anything stupid

	ImGui::LabelText(convertStringToChar(arg), (char *)convertStringToChar(arg));

	r_error.error = Variant::CallError::CALL_OK;
	return Variant();
}

Variant native_imgui::LabelTextV(const Variant **p_args, int p_argcount, Variant::CallError &r_error) {
	String arg;
	if (p_argcount < 0) {
		r_error.error = Variant::CallError::CALL_ERROR_INVALID_ARGUMENT;
		r_error.argument = 0;
		r_error.expected = Variant::STRING;
		return Variant();
	}

	for (uint32_t i = 1; i < p_argcount; i++) {
		if (p_args[i]->get_type() != Variant::STRING) {
			r_error.error = Variant::CallError::CALL_ERROR_INVALID_ARGUMENT;
			r_error.argument = 0;
			r_error.expected = Variant::STRING;
			return Variant();
		}
		// We conver the variant into a string and concatianate it to a godot string
		arg += (String)*p_args[i];
	}

	// We fool ImGui that we are variadic. We are converting a const char * to a char*
	//which kinda means we are praying that ImGui doens't do anything stupid

	ImGui::LabelTextV(convertStringToChar((String)*p_args[0]), convertStringToChar(arg), (char *)convertStringToChar(arg));

	r_error.error = Variant::CallError::CALL_OK;
	return Variant();
}

void native_imgui::ListBox(String label, int currentItem, Array items) {
	//const char *ptr = (char *)items.ptr();
	//ImGui::ListBox(convertStringToChar(label), &currentItem, &ptr, 1);
}

void native_imgui::ListBoxFooter() {
	ImGui::ListBoxFooter();
}

bool native_imgui::ListBoxHeader(String label, Vector2 size) {
	return ImGui::ListBoxHeader(convertStringToChar(label), Vector2ToImVec(size));
}

void native_imgui::LogButtons() {
	ImGui::LogButtons();
}

void native_imgui::LogFinish() {
	ImGui::LogFinish();
}

Variant native_imgui::LogText(const Variant **p_args, int p_argcount, Variant::CallError &r_error) {
	String arg;
	for (uint32_t i = 0; i < p_argcount; i++) {
		if (p_args[i]->get_type() != Variant::STRING) {
			r_error.error = Variant::CallError::CALL_ERROR_INVALID_ARGUMENT;
			r_error.argument = 0;
			r_error.expected = Variant::STRING;
			return Variant();
		}
		// We conver the variant into a string and concatianate it to a godot string
		arg += (String)*p_args[i];
	}

	// We fool ImGui that we are variadic. We are converting a const char * to a char*
	//which kinda means we are praying that ImGui doens't do anything stupid

	ImGui::LogText(convertStringToChar(arg), (char *)convertStringToChar(arg));

	r_error.error = Variant::CallError::CALL_OK;
	return Variant();
}

void native_imgui::LogToClipboard() {
	ImGui::LogToClipboard();
}

void native_imgui::NextColumn() {
	ImGui::NextColumn();
}

void native_imgui::OpenPopup(String str_id) {
	ImGui::OpenPopup(convertStringToChar(str_id));
}

void native_imgui::OpenPopupContextItem(String str_id) {
	ImGui::OpenPopupContextItem(convertStringToChar(str_id));
}

void native_imgui::OpenPopupOnItemClick(String str_id) {
	ImGui::OpenPopupOnItemClick(convertStringToChar(str_id));
}


void native_imgui::PlotHistogram(String label, Vector<float> arr) {
	ImGui::PlotHistogram(convertStringToChar(label), (const float *)arr.ptr(), arr.size());
}

void native_imgui::PlotLines(String label, Vector<float> arr) {
	ImGui::PlotLines(convertStringToChar(label), (const float *)arr.ptr(), arr.size());
}

void native_imgui::PopAllowKeyboardFocus() {
	ImGui::PopAllowKeyboardFocus();
}

void native_imgui::PopButtonRepeat() {
	ImGui::PopButtonRepeat();
}

void native_imgui::PopClipRect() {
	ImGui::PopClipRect();
}

void native_imgui::PopFont() {
	ImGui::PopFont();
}

void native_imgui::PopID() {
	ImGui::PopID();
}

void native_imgui::PopItemWidth() {
	ImGui::PopItemWidth();
}

void native_imgui::PopStyleColor() {
	ImGui::PopStyleColor();
}

void native_imgui::PopStyleVar() {
	ImGui::PopStyleVar();
}

void native_imgui::PopTextWrapPos() {
	ImGui::PopTextWrapPos();
}

void native_imgui::ProgressBar(float fraction, Vector2 size) {
	ImGui::ProgressBar(fraction, Vector2ToImVec(size));
}

void native_imgui::PushAllowKeyboardFocus(bool allow_keyboard_focus) {
	ImGui::PushAllowKeyboardFocus(allow_keyboard_focus);
}

void native_imgui::PushButtonRepeat(bool repeat) {
	ImGui::PushButtonRepeat(repeat);
}

void native_imgui::PushClipRect(Vector2 max, Vector2 min, bool intersects_with_current_rect) {
	ImGui::PushClipRect(Vector2ToImVec(max), Vector2ToImVec(min), intersects_with_current_rect);
}

void native_imgui::PushFont() {

	//ImGui::PushFont()
}

void native_imgui::PushID(int int_id) {
	ImGui::PushID(int_id);
}

void native_imgui::PushItemWidth(float item_width) {
	ImGui::PushItemWidth(item_width);
}

void native_imgui::PushStyleColor(int idx, Color col) {

	ImVec4 _vec(col.r, col.g, col.b, col.a);

	ImGui::PushStyleColor(idx, _vec);
}

void native_imgui::PushStyleVar(int idx, Vector2 vec) {
	ImGui::PushStyleVar(idx, Vector2ToImVec(vec));
}

void native_imgui::PushTextWrapPos(float wrap_local_pos_x) {
	ImGui::PushTextWrapPos(wrap_local_pos_x);
}

bool native_imgui::RadioButton(String label, bool active) {
	return handleButtonDic(label, ImGui::RadioButton(convertStringToChar(label),
							active));
}

bool native_imgui::Selectable(String label, bool active) {
	return handleButtonDic(label, ImGui::Selectable(convertStringToChar(label), &active));
}

void native_imgui::SetClipboardText(String text) {
	ImGui::SetClipboardText(convertStringToChar(text));
}

void native_imgui::SetColorEditOptions(int flags) {
	ImGui::SetColorEditOptions(flags);
}

void native_imgui::SetColumnOffset(int column_index, int offset) {
	ImGui::SetColumnOffset(column_index, offset);
}

void native_imgui::SetColumnWidth(int column_index, float width) {
	ImGui::SetColumnWidth(column_index, width);
}

void native_imgui::SetCursorPos(Vector2 pos) {
	ImGui::SetCursorPos(Vector2ToImVec(pos));
}

void native_imgui::SetCursorPosX(float x) {
	ImGui::SetCursorPosX(x);
}

void native_imgui::SetCursorPosY(float y) {
	ImGui::SetCursorPosX(y);
}

void native_imgui::SetCursorScreenPos(Vector2 pos) {
	ImGui::SetCursorScreenPos(Vector2ToImVec(pos));
}

void native_imgui::SetItemAllowOverlap() {
	ImGui::SetItemAllowOverlap();
}

void native_imgui::SetItemDefaultFocus() {
	ImGui::SetItemDefaultFocus();
}

void native_imgui::SetKeyboardFocusHere(int offset) {
	ImGui::SetKeyboardFocusHere(offset);
}

void native_imgui::SetMouseCursor(int cursor) {
	ImGui::SetMouseCursor(cursor);
}

void native_imgui::SetNextItemOpen(bool is_open, int condition) {
	ImGui::SetNextItemOpen(is_open, condition);
}

void native_imgui::SetNextItemWidth(float width) {
	ImGui::SetNextItemWidth(width);
}

void native_imgui::SetNextTreeNodeOpen(bool open, int condition) {
	ImGui::SetNextTreeNodeOpen(open, condition);
}

void native_imgui::SetNextWindowBgAlpha(float alpha) {
	ImGui::SetNextWindowBgAlpha(alpha);
}

void native_imgui::SetNextWindowCollapsed(bool collapsed, int cond) {
	ImGui::SetNextWindowCollapsed(collapsed, cond);
}

void native_imgui::SetNextWindowContentSize(Vector2 size) {
	ImGui::SetNextWindowContentSize(Vector2ToImVec(size));
}

void native_imgui::SetNextWindowFocus() {
	ImGui::SetNextWindowFocus();
}

void native_imgui::SetNextWindowPos(Vector2 pos, int cond, Vector2 pivot) {
	ImGui::SetNextWindowPos(Vector2ToImVec(pos), cond, Vector2ToImVec(pivot));
}

void native_imgui::SetNextWindowSize(Vector2 size, int cond) {
	ImGui::SetNextWindowSize(Vector2ToImVec(size), cond);
}

void native_imgui::SetNextWindowSizeConstraints(Vector2 min, Vector2 max) {
	ImGui::SetNextWindowSizeConstraints(Vector2ToImVec(min), Vector2ToImVec(max));
}

void native_imgui::SetScrollFromPosX(float x) {
	ImGui::SetScrollFromPosX(x);
}

void native_imgui::SetScrollFromPosY(float y) {
	ImGui::SetScrollFromPosY(y);
}

void native_imgui::SetScrollHere(float center_ratio) {
	ImGui::SetScrollHere(center_ratio);
}

void native_imgui::SetScrollHereX(float center_x_ratio) {
	ImGui::SetScrollHereX(center_x_ratio);
}

void native_imgui::SetScrollHereY(float center_y_ratio) {
	ImGui::SetScrollHereX(center_y_ratio);
}

void native_imgui::SetScrollX(float x) {
	ImGui::SetScrollX(x);
}

void native_imgui::SetScrollY(float y) {
	ImGui::SetScrollY(y);
}

void native_imgui::SetTabItemClosed(String label) {
	ImGui::SetTabItemClosed(convertStringToChar(label));
}

Variant native_imgui::SetTooltip(const Variant **p_args, int p_argcount, Variant::CallError &r_error) {
	String arg;
	for (uint32_t i = 0; i < p_argcount; i++) {
		if (p_args[i]->get_type() != Variant::STRING) {
			r_error.error = Variant::CallError::CALL_ERROR_INVALID_ARGUMENT;
			r_error.argument = 0;
			r_error.expected = Variant::STRING;
			return Variant();
		}
		// We conver the variant into a string and concatianate it to a godot string
		arg += (String)*p_args[i];
	}

	// We fool ImGui that we are variadic. We are converting a const char * to a char*
	//which kinda means we are praying that ImGui doens't do anything stupid
 
	ImGui::SetTooltip(convertStringToChar(arg), (char *)convertStringToChar(arg));

	r_error.error = Variant::CallError::CALL_OK;
	return Variant();
}

Variant native_imgui::SetTooltipV(const Variant **p_args, int p_argcount, Variant::CallError &r_error) {
	String arg;
	for (uint32_t i = 0; i < p_argcount; i++) {
		if (p_args[i]->get_type() != Variant::STRING) {
			r_error.error = Variant::CallError::CALL_ERROR_INVALID_ARGUMENT;
			r_error.argument = 0;
			r_error.expected = Variant::STRING;
			return Variant();
		}
		// We conver the variant into a string and concatianate it to a godot string
		arg += (String)*p_args[i];
	}

	// We fool ImGui that we are variadic. We are converting a const char * to a char*
	//which kinda means we are praying that ImGui doens't do anything stupid

	ImGui::SetTooltipV(convertStringToChar(arg), (char *)convertStringToChar(arg));

	r_error.error = Variant::CallError::CALL_OK;
	return Variant();
}

void native_imgui::SetWindowCollapsed(bool collapsed, int cond) {
	ImGui::SetWindowCollapsed(collapsed, cond);
}

void native_imgui::SetWindowFocus() {
	ImGui::SetWindowFocus();
}

void native_imgui::SetWindowFontScale(float scale) {
	ImGui::SetWindowFontScale(scale);
}

void native_imgui::SetWindowPos(Vector2 pos, int cond) {
	ImGui::SetWindowPos(Vector2ToImVec(pos), cond);
}

void native_imgui::SetWindowSize(Vector2 size, int cond) {
	ImGui::SetWindowSize(Vector2ToImVec(size), cond);
}

void native_imgui::ShowFontSelector(String label) {
	//ImGui::ShowFontSelector(convertStringToChar(label));
}

float native_imgui::SliderAngle(String label, float angle) {
	ImGui::SliderAngle(convertStringToChar(label), &angle);
	return angle;
}

float native_imgui::SliderFloat(String label, float value, float max, float min) {
	return ImGui::SliderFloat(convertStringToChar(label), &value, min, max);
}

Vector2 native_imgui::SliderFloat2(String label, Vector2 values, float min, float max) {
	float arr[2] = { values.x, values.y };
	ImGui::SliderFloat2(convertStringToChar(label), arr, min, max);
	return Vector2(arr[0], arr[1]);
}

Vector3 native_imgui::SliderFloat3(String label, Vector3 values, float min, float max) {
	float arr[3] = { values.x, values.y, values.z };
	ImGui::SliderFloat3(convertStringToChar(label), arr, min, max);
	return Vector3(arr[0], arr[1], arr[2]);
}

Color native_imgui::SliderFloat4(String label, Color values, float min, float max) {
	float arr[4] = { values.r, values.g, values.b, values.a };
	ImGui::SliderFloat3(convertStringToChar(label), arr, min, max);
	return Color(arr[0], arr[1], arr[2], arr[3]);
}

int native_imgui::SliderInt(String label, int val, int min, int max) {
	return ImGui::SliderInt(convertStringToChar(label), &val, min, max);
}

Vector2 native_imgui::SliderInt2(String label, Vector2 val, int min, int max) {
	int _arr[2] = {val.x, val.y};
	ImGui::SliderInt2(convertStringToChar(label), _arr, min, max);
	return Vector2(_arr[0], _arr[1]);
}

Vector3 native_imgui::SliderInt3(String label, Vector3 val, int min, int max) {
	int _arr[3] = { val.x, val.y, val.z };
	ImGui::SliderInt2(convertStringToChar(label), _arr, min, max);
	return Vector3(_arr[0], _arr[1], _arr[2]);
}

Color native_imgui::SliderInt4(String label, Color val, int min, int max) {
	int _arr[4] = { val.r, val.b, val.b, val.a };
	ImGui::SliderInt2(convertStringToChar(label), _arr, min, max);
	return Color(_arr[0], _arr[1], _arr[2]);
}

bool native_imgui::SmallButton(String label) {
	return handleButtonDic(label, ImGui::SmallButton(convertStringToChar(label)));
}

void native_imgui::Spacing() {
	ImGui::Spacing();
}

void native_imgui::StyleColorsClassic() {
	ImGui::StyleColorsClassic();
}

void native_imgui::StyleColorsDark() {
	ImGui::StyleColorsDark();
}

void native_imgui::StyleColorsLight() {
	ImGui::StyleColorsLight();
}

Variant native_imgui::TextDisabled(const Variant **p_args, int p_argcount, Variant::CallError &r_error) {
	String arg;
	for (uint32_t i = 0; i < p_argcount; i++) {
		if (p_args[i]->get_type() != Variant::STRING) {
			r_error.error = Variant::CallError::CALL_ERROR_INVALID_ARGUMENT;
			r_error.argument = 0;
			r_error.expected = Variant::STRING;
			return Variant();
		}
		// We conver the variant into a string and concatianate it to a godot string
		arg += (String)*p_args[i];
	}

	// We fool ImGui that we are variadic. We are converting a const char * to a char*
	//which kinda means we are praying that ImGui doens't do anything stupid

	ImGui::TextDisabled(convertStringToChar(arg), (char *)convertStringToChar(arg));

	r_error.error = Variant::CallError::CALL_OK;
	return Variant();
}


Variant native_imgui::Text(const Variant **p_args, int p_argcount, Variant::CallError &r_error) {
	String arg;
	for (uint32_t i = 0; i < p_argcount; i++) {
		if (p_args[i]->get_type() != Variant::STRING) {
			r_error.error = Variant::CallError::CALL_ERROR_INVALID_ARGUMENT;
			r_error.argument = 0;
			r_error.expected = Variant::STRING;
			return Variant();
		}
		// We conver the variant into a string and concatianate it to a godot string
		arg += (String)*p_args[i];
	}

	// We fool ImGui that we are variadic. We are converting a const char * to a char*
	//which kinda means we are praying that ImGui doens't do anything stupid

	ImGui::Text(convertStringToChar(arg), (char *)convertStringToChar(arg));

	r_error.error = Variant::CallError::CALL_OK;
	return Variant();
}

Variant native_imgui::TextWrapped(const Variant **p_args, int p_argcount, Variant::CallError &r_error) {
	String arg;
	for (uint32_t i = 0; i < p_argcount; i++) {
		if (p_args[i]->get_type() != Variant::STRING) {
			r_error.error = Variant::CallError::CALL_ERROR_INVALID_ARGUMENT;
			r_error.argument = 0;
			r_error.expected = Variant::STRING;
			return Variant();
		}
		// We conver the variant into a string and concatianate it to a godot string
		arg += (String)*p_args[i];
	}

	// We fool ImGui that we are variadic. We are converting a const char * to a char*
	//which kinda means we are praying that ImGui doens't do anything stupid

	ImGui::TextWrapped(convertStringToChar(arg), (char *)convertStringToChar(arg));

	r_error.error = Variant::CallError::CALL_OK;
	return Variant();
}

Variant native_imgui::TextColored(const Variant **p_args, int p_argcount, Variant::CallError &r_error) {
	String arg;

	if (!(p_argcount > 0) && p_args[0]->get_type() != Variant::COLOR) {
		r_error.error = Variant::CallError::CALL_ERROR_INVALID_ARGUMENT;
		r_error.argument = 0;
		r_error.expected = Variant::STRING;
		return Variant();
	}

	ImColor _col(((Color)*p_args[0]).r, ((Color)*p_args[0]).g,
				((Color)*p_args[0]).b,
				((Color)*p_args[0]).a);

	for (uint32_t i = 1; i < p_argcount; i++) {
		if (p_args[i]->get_type() != Variant::STRING) {
			r_error.error = Variant::CallError::CALL_ERROR_INVALID_ARGUMENT;
			r_error.argument = 0;
			r_error.expected = Variant::STRING;
			return Variant();
		}
		// We conver the variant into a string and concatianate it to a godot string
		arg += (String)*p_args[i];
	}

	// We fool ImGui that we are variadic. We are converting a const char * to a char*
	//which kinda means we are praying that ImGui doens't do anything stupid

	ImGui::TextColored(_col, convertStringToChar(arg));

	r_error.error = Variant::CallError::CALL_OK;
	return Variant();
}

void native_imgui::TreeAdvanceToLabelPos() {
	ImGui::TreeAdvanceToLabelPos();
}

void native_imgui::TreeNode(String label) {
	ImGui::TreeNode(convertStringToChar(label));
}

void native_imgui::TreeNodeEx(String label, int flags) {
	ImGui::TreeNodeEx(convertStringToChar(label), flags);
}

Variant native_imgui::TreeNodeExV(const Variant **p_args, int p_argcount, Variant::CallError &r_error) {
	String arg;

	if (!(p_argcount > 1) && p_args[0]->get_type() != Variant::STRING && p_args[0]->get_type() != Variant::INT) {
		r_error.error = Variant::CallError::CALL_ERROR_INVALID_ARGUMENT;
		r_error.argument = 0;
		r_error.expected = Variant::STRING;
		return Variant();
	}
	 

	for (uint32_t i = 2; i < p_argcount; i++) {
		if (p_args[i]->get_type() != Variant::STRING) {
			r_error.error = Variant::CallError::CALL_ERROR_INVALID_ARGUMENT;
			r_error.argument = 0;
			r_error.expected = Variant::STRING;
			return Variant();
		}
		// We conver the variant into a string and concatianate it to a godot string
		arg += (String)*p_args[i];
	}

	// We fool ImGui that we are variadic. We are converting a const char * to a char*
	//which kinda means we are praying that ImGui doens't do anything stupid

	ImGui::TreeNodeExV(convertStringToChar((String)*p_args[0]), (int)*p_args[1],
		convertStringToChar(arg), (char*)convertStringToChar(arg));
	
	r_error.error = Variant::CallError::CALL_OK;
	return ImGui::TreeNodeExV(convertStringToChar((String)*p_args[0]), (int)*p_args[1],
			convertStringToChar(arg), (char *)convertStringToChar(arg));
}

Variant native_imgui::TreeNodeV(const Variant **p_args, int p_argcount, Variant::CallError &r_error) {
	String arg;

	if (!(p_argcount > 1) && p_args[0]->get_type() != Variant::STRING && p_args[0]->get_type() != Variant::INT) {
		r_error.error = Variant::CallError::CALL_ERROR_INVALID_ARGUMENT;
		r_error.argument = 0;
		r_error.expected = Variant::STRING;
		return Variant();
	}

	for (uint32_t i = 2; i < p_argcount; i++) {
		if (p_args[i]->get_type() != Variant::STRING) {
			r_error.error = Variant::CallError::CALL_ERROR_INVALID_ARGUMENT;
			r_error.argument = 0;
			r_error.expected = Variant::STRING;
			return Variant();
		}
		// We conver the variant into a string and concatianate it to a godot string
		arg += (String)*p_args[i];
	}

	// We fool ImGui that we are variadic. We are converting a const char * to a char*
	//which kinda means we are praying that ImGui doens't do anything stupid

	ImGui::TreeNodeV(convertStringToChar((String)*p_args[0]),
			convertStringToChar(arg), (char *)convertStringToChar(arg));

	r_error.error = Variant::CallError::CALL_OK;
	return ImGui::TreeNodeV(convertStringToChar((String)*p_args[0]),
			convertStringToChar(arg), (char *)convertStringToChar(arg));
}

void native_imgui::TreePop() {
	ImGui::TreePop();
}

void native_imgui::TreePush() {
	ImGui::TreePush();
}

void native_imgui::Unindent(float width) {
	ImGui::Unindent(width);
}

void native_imgui::Value(String prefix, unsigned int value) {
	ImGui::Value(convertStringToChar(prefix), value);
}

float native_imgui::VSliderFloat(String label, Vector2 size, float val, float min, float max) {
	return ImGui::VSliderFloat(convertStringToChar(label), Vector2ToImVec(size), &val, min, max);
}

int native_imgui::VSliderInt(String label, Vector2 size, int val, int min, int max) {
	return ImGui::VSliderInt(convertStringToChar(label), Vector2ToImVec(size), &val, min, max);
}
 
 
void native_imgui::BulletText(String text) {
	ImGui::BulletText(convertStringToChar(text));
}

void native_imgui::End() {
	ImGui::End();
}

void native_imgui::Separator() {
	ImGui::Separator();
}

void native_imgui::Render() {
	ImGui::Render();
	ImDrawData *draw_dat = ImGui::GetDrawData();

	// validate data
	if (!draw_dat->Valid) {
		print_error("IMGUI: DRAW DATA NOT VALID");
		return;
	}

	process_imgui();
}

void native_imgui::EndFrame() {
	ImGui::EndFrame();
}

void native_imgui::NewFrame() {
	ImGui::NewFrame();
}

void native_imgui::BeginMenu(String name) {
	ImGui::BeginMenu(convertStringToChar(name));
}

void native_imgui::BeginMainMenuBar() {
	ImGui::BeginMainMenuBar();
}

void native_imgui::EndMainMenuBar() {
	ImGui::EndMainMenuBar();
}

void native_imgui::EndMenu() {
	ImGui::EndMenu();
}

bool native_imgui::MenuItem(String label, String shortcut, bool selected, bool enabled) {
	bool newState = ImGui::MenuItem(convertStringToChar(label),
			convertStringToChar(shortcut),
			selected,
			enabled);

	return handleButtonDic(label, newState);
}

float native_imgui::InputFloat(String label, float value, float step, float fastStep, String format) {
	ImGui::InputFloat(convertStringToChar(label), &value, step, fastStep, convertStringToChar(format));
	return value;
}

Vector2 native_imgui::InputFloat2(String label, Vector2 value, String format) {
	float _vec[2] = { value.x, value.y };
	ImGui::InputFloat2(convertStringToChar(label), _vec, convertStringToChar(format));
	return Vector2(_vec[0], _vec[1]);
}

Vector3 native_imgui::InputFloat3(String label, Vector3 value, String format) {
	float _vec[3] = { value.x, value.y, value.z };
	ImGui::InputFloat3(convertStringToChar(label), _vec, convertStringToChar(format));
	return Vector3(_vec[0], _vec[1], _vec[2]);
}

Color native_imgui::InputFloat4(String label, Color value, String format) {
	float _vec[4] = { value.r, value.g, value.b, value.a };
	ImGui::InputFloat4(convertStringToChar(label), _vec, convertStringToChar(format));
	return Color(_vec[0], _vec[1], _vec[2], _vec[3]);
}

int native_imgui::InputInt(String label, int value, int step, int step_fast) {
	ImGui::InputInt(convertStringToChar(label), &value, step, step_fast);
	return value;
}

Vector2 native_imgui::InputInt2(String label, Vector2 value, int step, int step_fast) {
	int _vec[2] = {value.x, value.y};
	ImGui::InputInt2(convertStringToChar(label), _vec, step);
	return Vector2(_vec[0], _vec[1]);
}

Vector3 native_imgui::InputInt3(String label, Vector3 value, int step, int step_fast) {
	int _vec[3] = { value.x, value.y, value.z };
	ImGui::InputInt3(convertStringToChar(label), _vec, step);
	return Vector3(_vec[0], _vec[1], _vec[2]);
}
/*
int native_imgui::InputInt4(String label, Vector4 value, int step, int step_fast) {
	int _vec[4] = { value.x, value.y, value.z, value.w };
	ImGui::InputInt3(convertStringToChar(label), _vec, step);
	return Vector3(_vec[0], _vec[1], _vec[3], _vec[]);
}
*/

void native_imgui::SameLine() {
	ImGui::SameLine();
}

float native_imgui::DragFloat(String label, float value, float speed, float min, float max, float power) {
	ImGui::DragFloat(convertStringToChar(label), &value, speed, min, max, "asf", 0.0f);
	return value;
}

void native_imgui::Dummy(Vector2 vec) {
	ImGui::Dummy(Vector2ToImVec(vec));
}

String native_imgui::GetClipboardText() {
	return String(ImGui::GetClipboardText());
}

uint32_t native_imgui::GetColumnIndex() {
	return ImGui::GetColumnIndex();
}

void native_imgui::GetColumnOffset(int index) {
	ImGui::GetColumnOffset(index);
}

void native_imgui::GetColumnsCount() {
	ImGui::GetColumnsCount();
}

void native_imgui::GetColumnWidth(int index) {
	ImGui::GetColumnWidth(index);
}

Vector2 native_imgui::GetContentRegionAvail() {
	return ImVec2ToVector2(ImGui::GetContentRegionAvail());
}

float native_imgui::GetContentRegionAvailWidth() {
	return ImGui::GetContentRegionAvailWidth();
}

Vector2 native_imgui::GetContentRegionMax() {
	return ImVec2ToVector2(ImGui::GetContentRegionMax());
}

Vector2 native_imgui::GetCursorPos() {
	return ImVec2ToVector2(ImGui::GetCursorPos());
}

float native_imgui::GetCursorPosX() {
	return ImGui::GetCursorPosX();
}

float native_imgui::GetCursorPosY() {
	return ImGui::GetCursorPosY();
}

Vector2 native_imgui::GetCursorScreenPos() {
	return ImVec2ToVector2(ImGui::GetCursorScreenPos());
}

Vector2 native_imgui::GetCursorStartPos() {
	return ImVec2ToVector2(ImGui::GetCursorStartPos());
}

void native_imgui::GetFont() {
	print_line("GET FONT NOT IMPLEMENTED");
}

float native_imgui::GetFontSize() {
	return ImGui::GetFontSize();
}

Vector2 native_imgui::GetFontTexUvWhitePixel() {
	return ImVec2ToVector2(ImGui::GetFontTexUvWhitePixel());
}

float native_imgui::GetFrameCount() {
	return ImGui::GetFrameCount();
}

float native_imgui::GetFrameHeight() {
	return ImGui::GetFrameHeight();
}

float native_imgui::GetFrameHeightWithSpacing() {
	return ImGui::GetFrameHeightWithSpacing();
}

Vector2 native_imgui::GetItemRectMax() {
	return ImVec2ToVector2(ImGui::GetItemRectMax());
}

Vector2 native_imgui::GetItemRectMin() {
	return ImVec2ToVector2(ImGui::GetItemRectMin());
}

Vector2 native_imgui::GetItemRectSize() {
	return ImVec2ToVector2(ImGui::GetItemRectSize());
}

int native_imgui::GetKeyIndex(int key) {
	return ImGui::GetKeyIndex(key);
}

int native_imgui::GetKeyPressedAmount(int key, float repeat_delay, float rate) {
	return ImGui::GetKeyPressedAmount(key, repeat_delay, rate);
}

int native_imgui::GetMouseCursor() {
	return ImGui::GetMouseCursor();
}

Vector2 native_imgui::GetMouseDragDelta() {
	return ImVec2ToVector2(ImGui::GetMouseDragDelta());
}

Vector2 native_imgui::GetMousePos() {
	return ImVec2ToVector2(ImGui::GetMousePos());
}

Vector2 native_imgui::GetMousePosOnOpeningCurrentPopup() {
	return ImVec2ToVector2(ImGui::GetMousePosOnOpeningCurrentPopup());
}

float native_imgui::GetScrollMaxX() {
	return ImGui::GetScrollMaxX();
}

float native_imgui::GetScrollMaxY() {
	return ImGui::GetScrollMaxY();
}

float native_imgui::GetScrollX() {
	return ImGui::GetScrollX();
}

float native_imgui::GetScrollY() {
	return ImGui::GetScrollY();
}

int native_imgui::GetStyle() {
	print_line("GetStyle not implemented");
	return 0;
	 //ImGui::GetStyle();
}

String native_imgui::GetStyleColorName(int idx) {
	return String(ImGui::GetStyleColorName(idx));
}

Color native_imgui::GetStyleColorVec4(int idx) {
	return ImVec4ToColor(ImGui::GetStyleColorVec4(idx));
}

float native_imgui::GetTextLineHeight() {
	return ImGui::GetTextLineHeight();
}

float native_imgui::GetTextLineHeightWithSpacing() {
	return ImGui::GetTextLineHeightWithSpacing();
}

float native_imgui::GetTime() {
	return ImGui::GetTime();
}

float native_imgui::GetTreeNodeToLabelSpacing() {
	return ImGui::GetTreeNodeToLabelSpacing();
}

Vector2 native_imgui::GetWindowContentRegionMax() {
	return ImVec2ToVector2(ImGui::GetWindowContentRegionMax());
}

Vector2 native_imgui::GetWindowContentRegionMin() {
	return ImVec2ToVector2(ImGui::GetWindowContentRegionMin());
}

float native_imgui::GetWindowContentRegionWidth() {
	return ImGui::GetWindowContentRegionWidth();
}

float native_imgui::GetWindowHeight() {
	return ImGui::GetWindowHeight();
}

float native_imgui::GetWindowWidth() {
	return ImGui::GetWindowWidth();
}

Vector2 native_imgui::GetWindowPos() {
	return ImVec2ToVector2(ImGui::GetWindowPos());
}

Vector2 native_imgui::GetWindowSize() {
	return ImVec2ToVector2(ImGui::GetWindowSize());
}

int native_imgui::GetID(String id) {
	return ImGui::GetID(convertStringToChar(id));
}

void native_imgui::Indent(float indent_width) {
	ImGui::Indent();
}

Color native_imgui::ColorPicker3(String label, Color color) {
	float test[3] = { color.r, color.g, color.b };
	ImGui::ColorPicker3(convertStringToChar(label), test);
	return Color(test[0], test[1], test[2]);
}

bool  native_imgui::ArrowButton(String label, int dir) {
	return ImGui::ArrowButton(convertStringToChar(label), ImGuiDir_Right);
}

void native_imgui::Bullet() {
	ImGui::Bullet();
}

void native_imgui::CalcItemWidth() {
	ImGui::CalcItemWidth();
}

bool native_imgui::CheckBox(String label, bool val) {
	ImGui::Checkbox(convertStringToChar(label), &val);
	return val;
}

void native_imgui::CloseCurrentPopup() {
	ImGui::CloseCurrentPopup();
}

bool native_imgui::ColorButton(String desc_id, Color vec) {
	ImVec4 _vec(vec.r, vec.g, vec.b, 1.0);
	bool newState = ImGui::ColorButton(convertStringToChar(desc_id), _vec);
	return handleButtonDic(desc_id, newState);
}

Color native_imgui::ColorPicker4(String label, Color color) {
	float _col[4] = { color.r, color.g, color.b, color.a };
	ImGui::ColorPicker3(convertStringToChar(label), _col);
	return Color(_col[0], _col[1], _col[2], _col[3]);
}

Color native_imgui::ColorEdit3(String label, Color vec) {
	float _vec[3] = { vec.r, vec.g, vec.b };
	ImGui::ColorEdit3(convertStringToChar(label), _vec);

	return Color(_vec[0], _vec[1], _vec[2], 1.0);
}

Color native_imgui::ColorEdit4(String label, Color vec) {
	float _vec[4] = { vec.r, vec.g, vec.b, vec.a };
	ImGui::ColorEdit4(convertStringToChar(label), _vec);

	return Color(_vec[0], _vec[1], _vec[2], 1.0);
}
