#pragma once

#include <frc2/command/SubsystemBase.h>

#include "util/Macros.h"
#include "Constants.h"

class ControlPanelManipulator : public frc2::SubsystemBase {
public:
  static ControlPanelManipulator& GetInstance();
  DISALLOW_COPY_AND_ASSIGN(ControlPanelManipulator);

  void Periodic();
private:
  ControlPanelManipulator() = default;
};
