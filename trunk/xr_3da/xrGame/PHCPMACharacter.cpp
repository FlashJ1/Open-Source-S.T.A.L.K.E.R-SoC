#include "stdafx.h"

#include "PHCPMACharacter.h"

// Debug stuff
#include "xrUICore/ui_base.h"
#include "xrEngine/GameFont.h"
#include "xrCore/log.h"

CPHCPMACharacter::CPHCPMACharacter(bool singleplayer)
    : CPHActorCharacter(singleplayer)
{
}

void CPHCPMACharacter::SetAcceleration(Fvector accel)
{
    if (!b_exist)
        return;

    if (!dBodyIsEnabled(m_body))
        if (!fsimilar(0.f, accel.magnitude()))
            Enable();

    m_true_accel = accel;
}

void CPHCPMACharacter::PhTune(dReal step)
{
    //SetVelocity({m_true_accel[0] * 10.f, 0.f, m_true_accel[2] * 10.f});

    Fvector wish_dir = m_true_accel.normalize_safe();

    Accelerate(step, wish_dir, 4.7f, air_accelerate);

    SetVelocity(m_velocity);

    CGameFont* pFontStat = UI().Font().pFontStat;
    u32 color = pFontStat->GetColor();
    pFontStat->SetColor(0xffffffff);
    pFontStat->OutSet(170, 530);

    Fvector player_velocity;
    GetVelocity(player_velocity);
    pFontStat->OutNext("Accel:                [%3.2f, %3.2f, %3.2f]", VPUSH(m_true_accel));
    pFontStat->OutNext("Velocity:             [%3.2f, %3.2f, %3.2f]", VPUSH(player_velocity));
    pFontStat->OutNext("Speed:                %3.2f", player_velocity.magnitude());
}

void CPHCPMACharacter::Accelerate(const float delta_time, const Fvector wish_dir, const float wish_speed, const float in_air_accelerate)
{
    float currentspeed = m_velocity.dotproduct(wish_dir);
    float addspeed = wish_speed - currentspeed;
    if (addspeed <= 0)
    {
        return;
    }

    float accelspeed = in_air_accelerate * delta_time * wish_speed;
    if (accelspeed > addspeed)
    {
        accelspeed = addspeed;
    }
    
    m_velocity[0] += accelspeed * wish_dir[0];
    m_velocity[2] += accelspeed * wish_dir[2];
}

