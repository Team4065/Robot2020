#include "util/Tunable.h"

namespace frc4065
{

Tunable::Tunable(const char* name, const double& value)
{

    name_ = name;
    value_ = value;

    frc::SmartDashboard::PutNumber(name_, value_);
}

double Tunable::Get()
{
    value_ = frc::SmartDashboard::GetNumber(name_, 0.0);
    return value_;
}

void Tunable::Set(const double& newState)
{
    value_ = newState;
}

}