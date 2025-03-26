#ifndef MECANUM_H
#define MECANUM_H

#include "motor.hpp"
#include <stdint.h>

/**
 * 
 */
class MecanumDrive {
  private:
    // FL Motor Constants
    const int FL_SPEED_PIN = 10;
    const int FL_CW_PIN = 26;
    const int FL_CCW_PIN = 28;

    // FR Motor Constants
    const int FR_SPEED_PIN = 9;
    const int FR_CW_PIN = 22;
    const int FR_CCW_PIN = 24;

    // BL Motor Constants
    const int BL_SPEED_PIN = 12;
    const int BL_CW_PIN = 7;
    const int BL_CCW_PIN = 8;

    // BR Motor Constants
    const int BR_SPEED_PIN = 11;
    const int BR_CW_PIN = 5;
    const int BR_CCW_PIN = 6;

  public:
    /**
     * Collection of Motors running the MecanumDrive
     * Should be populated {FL, FR, BL, BR}
     */
    Motor motors[];

    /**
     * @brief Constructs the MecanumDrive object;
     * Populates @see MecanumDrive::motors[] with Motor Constants defined in class.
     * @note populates motors in {FL, FR, BL, BR} order.
     */
    MecanumDrive();

    /**
     * @brief Drives the mecanum system using a Cartesian Coordinate system, akin to the Unit Circle.
     * @param xPower percentage power to be applied to the motors in the X Direction (+Forward, -Backward)
     * @param yPower percentage power to be applied to the motors in the Y Direction (+Left, -Right)
     * @param omega percentage power to be applied to the motors to rotate on the center axis (+CCW, -CW)
     */
    void driveCartesian(float xPower, float yPower, float omega);


    /**
     * @brief Runs a test on the Motors;
     * Runs all motors forward for 3 seconds, then backwards for 3 seconds.
     * @warning THIS WILL STALL THE THREAD DURING THE PROCESS, ITS A TEST!
     */
    void testConfiguration();
}

#endif // MECANUM_H
