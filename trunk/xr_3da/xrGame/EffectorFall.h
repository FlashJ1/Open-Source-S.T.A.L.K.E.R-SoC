#pragma once

#include "../Effector.h"

// ���������� ����� �������
class CEffectorFall : public CEffectorCam
{
	float	fPower;
	float	fPhase;
public:
					CEffectorFall	(float power, float life_time=1);
	virtual BOOL	ProcessCam		(SCamEffectorInfo& info);
};
