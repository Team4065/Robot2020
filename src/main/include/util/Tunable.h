#pragma once

#include <type_traits>

#include <frc/smartdashboard/smartdashboard.h>

namespace frc4065
{
class Tunable
{
public:
    // Initializes SmartDashboard values.
    Tunable(const char* name, const float& value);

    // Non-const getter; updates value with respect to SmartDashboard and then returns that value.
    float Get();

    // Manually change the tunable variable and update SmartDashboard.
    void Set(const float& newState);

    ~Tunable() {}
private:
    const char* name_;
    float value_;
};

}
