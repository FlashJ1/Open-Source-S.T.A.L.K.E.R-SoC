#include "pch_script.h"
#include "UIStatic.h"

using namespace luabind;

#pragma optimize("s",on)
void CUIStatic::script_register(lua_State *L)
{
	module(L)
	[
		class_<CUIStatic, CUIWindow>("CUIStatic")
		.def(						constructor<>())

		.def("SetText",					(void (CUIStatic::*)(LPCSTR)) (&CUIStatic::SetText) )
		.def("SetTextST",				(void (CUIStatic::*)(LPCSTR)) (&CUIStatic::SetTextST) )
		.def("GetText",					&CUIStatic::GetText)

		.def("SetTextX",				&CUIStatic::SetTextX)
		.def("SetTextY",				&CUIStatic::SetTextY)
		.def("GetTextX",				&CUIStatic::GetTextX)
		.def("GetTextY",				&CUIStatic::GetTextY)
		
		.def("SetTextureColor",			&CUIStatic::SetTextureColor)
		.def("GetTextureColor",			&CUIStatic::GetTextureColor)
		.def("SetBaseTextureColor",		&CUIStatic::SetBaseTextureColor)
		.def("GetBaseTextureColor",		&CUIStatic::GetBaseTextureColor)
		.def("SetTextColor",			&CUIStatic::SetTextColor_script)
		.def("SetBaseTextColor",		&CUIStatic::SetBaseTextColor_script)
		.def("Init",					(void(CUIStatic::*)(float,float,float,float))&CUIStatic::Init )
		.def("Init",					(void(CUIStatic::*)(LPCSTR,float,float,float,float))&CUIStatic::Init )
		.def("InitTexture",				&CUIStatic::InitTexture )
		.def("SetTextureOffset",		(void(CUIStatic::*)(float, float))&CUIStatic::SetTextureOffset )
		.def("SetBaseTextureOffset",	(void(CUIStatic::*)(float, float))&CUIStatic::SetBaseTextureOffset )
		.def("GetTextureOffset",		&CUIStatic::GetTextureOffset )
		.def("GetBaseTextureOffset",	&CUIStatic::GetBaseTextureOffset )


		.def("SetOriginalRect",			(void(CUIStatic::*)(float,float,float,float))&CUIStatic::SetOriginalRect)
		.def("SetStretchTexture",		&CUIStatic::SetStretchTexture)
		.def("GetStretchTexture",		&CUIStatic::GetStretchTexture)

		.def("SetTextAlign",			&CUIStatic::SetTextAlign_script)
		.def("GetTextAlign",			&CUIStatic::GetTextAlign_script)

		.def("SetHeading",				&CUIStatic::SetHeading)
		.def("GetHeading",				&CUIStatic::GetHeading)
	
		.def("ClipperOn",				&CUIStatic::ClipperOn)
		.def("ClipperOff",				(void(CUIStatic::*)(void))&CUIStatic::ClipperOff )
		.def("GetClipperState",			&CUIStatic::GetClipperState)
	];
}