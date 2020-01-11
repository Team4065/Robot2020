#pragma once

#include <frc2/command/SubsystemBase.h>

class ControlPanelManipulator : public frc2::SubsystemBase {
public:
  ControlPanelManipulator& GetInstance();

  void Periodic();
private:
  ControlPanelManipulator() = default;
};
