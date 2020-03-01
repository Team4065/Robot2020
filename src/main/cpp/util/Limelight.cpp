#include "util/Limelight.h"

namespace frc4065
{

Limelight::Limelight(const char* name)
: table_name_(name), table_(nt::NetworkTableInstance::GetDefault().GetTable(name))
{

}

void Limelight::SetPipeline(int pipe_id)
{
    table_->PutNumber("pipeline", pipe_id);
}

void Limelight::SetLEDMode(LEDMode mode)
{
    switch(mode)
    {
        case LEDMode::OFF:
            table_->PutNumber("ledMode", 1);
            break;
        case LEDMode::BLINKING:
            table_->PutNumber("ledMode", 2);
            break;
        case LEDMode::ON:
            table_->PutNumber("ledMode", 3);
            break;
    }
    led_mode_ = mode;
}
void Limelight::SetCamMode(CamMode mode)
{
    switch(mode)
    {
        case CamMode::PROCESSING:
            table_->PutNumber("camMode", 0);
            break;
        case CamMode::DRIVER:
            table_->PutNumber("camMode", 1);
            break;
    }
    cam_mode_ = mode;
}
bool Limelight::IsProcessing() const
{
    return cam_mode_ == CamMode::PROCESSING;
}
Limelight::LEDMode Limelight::GetLEDMode() const
{
    return led_mode_;
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