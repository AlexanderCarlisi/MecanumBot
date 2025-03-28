#include "motor.hpp"
#include <stdint.h>
#include <Arduino.h>


Motor::Motor(uint8_t dioCW, uint8_t dioCCW, uint8_t pwm, bool inverted)
      : PIN_DIO_CW(dioCW), PIN_DIO_CCW(dioCCW), PIN_PWM(pwm), inverted(inverted)
{
  // Setup Pin Modes
  pinMode(PIN_DIO_CW, OUTPUT);
  pinMode(PIN_DIO_CCW, OUTPUT);
  pinMode(PIN_DIO_CCW, OUTPUT);
}


void Motor::setDirection(bool forward) {
  // CCW (+ & FORWARD)
  bool goCCW = forward && !this->inverted;
  digitalWrite(this->PIN_DIO_CCW, goCCW ? HIGH : LOW);
  digitalWrite(this->PIN_DIO_CW, goCCW ? LOW : HIGH);
}


void Motor::stop() {
  analogWrite(this->PIN_PWM, 0);
}


void Motor::setPWM(uint8_t signal, bool forward) {
  if (speed != 0) this->setDirection(forward);

  // Set motor speed
  analogWrite(this->PIN_PWM, signal);
}


void Motor::setPWM(uint16_t signal) {
  if (speed == 0) this->stop();
  else {
    bool forward = signal > 0;
    this->setPWM((forward) ? signal : signal * -1, forward);
  }
}


void Motor::set(float dutyCycle) {
  if (power == 0) this->stop();
  else {
    power = constrain(dutyCycle, -MOTOR_MAX_OUPUT, MOTOR_MAX_OUTPUT);
    this->setPWM((uint8_t)(dutyCycle * MOTOR_MAX_PWM));
  }
}
