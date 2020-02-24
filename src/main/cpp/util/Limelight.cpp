#include "util/Limelight.h"

namespace frc4065
{

Limelight::Limelight(const char* name)
: table_name_(name), table_(nt::NetworkTableInstance::GetDefault().GetTable(name))
{

}

double Limelight::GetHorizontalOffset()
{
    return table_->GetNumber("tx", 0.0);
}

double Limelight::GetVerticalOffset()
{
    return table_->GetNumber("ty", 0.0);
}

double Limelight::GetTargetArea()
{
    return table_->GetNumber("ta", 0.0);
}

bool Limelight::HasActiveTarget()
{
    return table_->GetNumber("tv", 0.0);
}

units::meter_t Limelight::EstimateTargetDistance(units::degree_t camera_mounting_angle, units::degree_t y_offset_to_target,
                       units::meter_t camera_height, units::meter_t target_height)
{
    return (target_height - camera_height) / std::tan((camera_mounting_angle + y_offset_to_target).to<double>());
}

}