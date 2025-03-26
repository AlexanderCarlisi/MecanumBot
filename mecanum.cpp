#include "mecanum.hpp"
#include <Arduino.h>

MecanumDrive::MecanumDrive() {
  this->motors = {
    Motor(this->FL_CW_PIN, this->FL_CCW_PIN, this->FL_SPEED_PIN, false),
    Motor(this->FR_CW_PIN, this->FR_CCW_PIN, this->FR_SPEED_PIN, false),
    Motor(this->BL_CW_PIN, this->BL_CCW_PIN, this->BL_SPEED_PIN, true),
    Motor(this->BR_CW_PIN, this->BR_CCW_PIN, this->BR_SPEED_PIN, true)
  };
}

void MecanumDrive::driveCartesian(float xPower, float yPower, float omega) {

}


void MecanumDrive::testConfiguration() {
  for (int i = 0; i < 4; i++) {
    this->motors[i].set(1);
  }
  delay(3000);
  for (int i = 0; i < 4; i++) {
    this->motors[i].stop();
  }
  delay(1000);
  for (int i = 0; i < 4; i++) {
    this->motors[i].set(-1);
  }
  delay(3000);
  for (int i = 0; i < 4; i++) {
    this->motors[i].stop();
  }
}

