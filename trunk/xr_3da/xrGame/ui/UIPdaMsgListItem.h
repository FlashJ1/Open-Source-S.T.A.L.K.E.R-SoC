//////////////////////////////////////////////////////////////////////
// UIPdaMsgListItem.h: ������� ���� ������ � �������� 
// ������ ��� ��������� PDA
//////////////////////////////////////////////////////////////////////

#pragma once
#include "UIStatic.h"
#include "..\InventoryOwner.h"

class CUIPdaMsgListItem : public CUIStatic
{
public:
	virtual void		Init							(float x, float y, float width, float height);
	virtual void		InitCharacter					(CInventoryOwner* pInvOwner);
	virtual void		SetTextColor					(u32 color);
	virtual void		SetFont							(CGameFont* pFont);
	virtual void		SetTextureColor					(u32 color);
	virtual void		SetBaseTextureColor				(u32 color);
	
	//���������� � ���������
	CUIStatic			UIIcon;
	CUIStatic			UIName;
	CUIStatic			UIMsgText;
};