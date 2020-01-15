#pragma once

#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableEntry.h>
#include <networktables/NetworkTableInstance.h>
#include <memory>

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
    void IsProcessing() const;
    void GetLEDMode() const;
private:
    LEDMode led_mode_ = LEDMode::OFF;
    CamMode cam_mode_ = CamMode::PROCESSING;
    const char* table_name_;
    const std::shared_ptr<nt::NetworkTable> table_;
};

}