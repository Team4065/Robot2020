#pragma once

#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableEntry.h>
#include <networktables/NetworkTableInstance.h>
#include <memory>
#include <units/units.h>

namespace frc4065
{

class Limelight
{
public:
    enum LEDMode { ON, BLINKING, OFF };
    enum CamMode { DRIVER, PROCESSING };
    Limelight(const char* name);
    void SetLEDMode(LEDMode mode);
    void SetCamMode(CamMode mode);
    void SetPipeline(int pipe_id);
    bool IsProcessing() const;
    LEDMode GetLEDMode() const;
    double GetHorizontalOffset();
    double GetVerticalOffset();
    double GetTargetArea();
    bool HasActiveTarget();
    static units::meter_t EstimateTargetDistance(units::degree_t camera_mounting_angle, units::degree_t y_offset_to_target,
                                                units::meter_t camera_height, units::meter_t target_height);
private:
    LEDMode led_mode_ = LEDMode::OFF;
    CamMode cam_mode_ = CamMode::PROCESSING;
    const char* table_name_;
    const std::shared_ptr<nt::NetworkTable> table_;
};

}