#include "vex.h"
#include "vex_controller.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Intake               motor_group   1, 2            
// Controller1          controller                    
// Catapult             motor         3               
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;

// Define your motor ports
motor intakeMotor1 = motor(1, false);    // Replace with your actual intake motor port 1
motor intakeMotor2 = motor(2, false);    // Replace with your actual intake motor port 2
motor catapultMotor = motor(3, false);   // Replace with your actual catapult motor port

motor_group intakeMotors = motor_group(intakeMotor1, intakeMotor2);

int main() {
    // Initializing Robot Configuration. DO NOT REMOVE!
    vexcodeInit();

    // Set the velocity for the intake motor group
    intakeMotors.setVelocity(100, percent);  // Adjust the value (100) as needed

    // Set the velocity for the catapult motor
    catapultMotor.setVelocity(100, percent);  // Adjust the value (100) as needed

    while (1) {
        // Check if the top button is pressed
        if (Controller1.ButtonUp.pressing()) {
            // Move the intake motor group forward
            intakeMotors.spin(forward);
            // Move the catapult motor forward
            catapultMotor.spin(forward);
        }
        // Check if the bottom button is pressed
        else if (Controller1.ButtonDown.pressing()) {
            // Move the intake motor group backward
            intakeMotors.spin(reverse);
            // Stop the catapult motor (preventing reverse movement)
            catapultMotor.stop(brakeType::brake);
        }
        // If no button is pressed, stop both motor groups
        else {
            intakeMotors.stop();
            catapultMotor.stop(brakeType::brake);
        }

        // Allow other tasks to run
        this_thread::sleep_for(10);
    }
}
