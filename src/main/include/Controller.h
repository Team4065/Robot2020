#include "frc/XboxController.h"
#include "subsystems/Shooter.h"

class controller{
    public: 
        frc::XboxController controller_{1};

        controller_.GetXButtonPressed(){
            if(GetXButtonPressed() == 1)
                shooter.setShooterVelocity(-0.8);
            else()
                shooter.setShooterVelocity(0);
        }        
        controller_.GetYButtonPressed(){
            if()

            else()
        }
        controller_.GetAButtonPressed(){
            if()

            else()
        }
        controller_.GetBButtonPressed(){
            if()

            else()
        }
}