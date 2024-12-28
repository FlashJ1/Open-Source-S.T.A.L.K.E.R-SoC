#pragma once

#include "PHActorCharacter.h"

class CPHCPMACharacter : public CPHActorCharacter
{
    typedef CPHActorCharacter super;

public:
    CPHCPMACharacter(bool singleplayer);

    void SetAcceleration(Fvector accel);
    virtual void PhTune(dReal step) override;

private:
    void Accelerate(const float delta_time, const Fvector wish_dir, const float wish_speed, const float in_air_accelerate);

    Fvector m_true_accel = {0.f, 0.f, 0.f};

    Fvector m_velocity = {0.f, 0.f, 0.f};

    float air_accelerate = 1.f;
};
