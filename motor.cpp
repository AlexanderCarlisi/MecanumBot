#include "motor.hpp"
#include <stdint.h>
#include <Arduino.h>


Motor::Motor(uint8_t pinCW, uint8_t pinCCW, uint8_t pinSpeed, bool inverted)
      : pinCW(pinCW), pinCCW(pinCCW), pinSpeed(pinSpeed), inverted(inverted)
{
  // Setup Pin Modes
  pinMode(pinCW, OUTPUT);
  pinMode(pinCCW, OUTPUT);
  pinMode(pinSpeed, OUTPUT);
}


void Motor::setDirection(bool forward) {
  // CCW (+ & FORWARD)
  bool goCCW = forward && !this->inverted;
  digitalWrite(this->pinCCW, goCCW ? HIGH : LOW);
  digitalWrite(this->pinCW, goCCW ? LOW : HIGH);
}


void Motor::stop() {
  analogWrite(this->pinSpeed, 0);
}


void Motor::setPWM(uint8_t speed, bool forward) {
  if (speed != 0) this->setDirection(forward);

  // Set motor speed
  analogWrite(this->pinSpeed, speed);
}


void Motor::setPWM(uint16_t speed) {
  if (speed == 0) this->stop();
  else {
    bool forward = speed > 0;
    this->setPWM((forward) ? speed : speed * -1, forward);
  }
}


void Motor::set(float power) {
  if (power == 0) this->stop();
  else {
    power = constrain(power, -MOTOR_MAX_OUPUT, MOTOR_MAX_OUTPUT);
    this->setPWM((uint8_t)(power * MOTOR_MAX_PWM));
  }
}
