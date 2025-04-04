#include <stdint.h>

#ifndef MOTOR_H
#define MOTOR_H

#define MOTOR_MAX_PWM 255   // Max PWM Signal, uint8
#define MOTOR_MAX_OUTPUT 1  // Percentage to PWM

/**
 * Motor type shit
 */
class Motor {
  private:
    const uint8_t PIN_DIO_CW;    // Pin that Spins the Wheel Clock-wise
    const uint8_t PIN_DIO_CCW;   // Pin that Spins the Wheel Counter-Clock-wise
    const uint8_t PIN_PWM;   // PWM Pin for controlling Motor power

  public:
    bool inverted;  // CCW Positive

    /**
     * @brief Constructs a Motor object;
     * Member Initializer and performs all the necessary setup for the pins
     * @param pinCW Pin that controls the Clockwise direction of the Wheel
     * @param pinCCW Pin that controls the Counter-Clockwise direction of the Wheel
     * @param pinSpeed Pin that controls the Speed of the Motor
     * @param inverted Whether the CW/CCW directions need to be inverted to move Forwards
     * @attention inverted is mutable, so it can be changed during runtime!
     */
    Motor(uint8_t dioCW, uint8_t dioCCW, uint8_t pwm, bool inverted);

    /**
     * @brief Sets the Motors Speed, inverts for Forward/Backwards
     * @param signal The PWM value [0, 255]
     * @param forward Boolean to decide which Dir Pin to use, affected by @see Motor::inverted
     */
    void setPWM(uint8_t signal, bool forward);

    /**
     * @brief Set the Motors Speed, +/- Forwards/Backwards
     * @param signal The PWM Value [-255, 255]
     * @note Affected by @see Motor::inverted
     */
    void setPWM(uint16_t signal);

    /**
     * @brief Set the Motors Power, +/- Forwards/Backwards
     * @param (+/-) percentage of pulse to apply HIGH/LOW signal [-1, 1] 
     * @note Affected by @see Motor::inverted
     * @attention Values are lossy (converted to PWM [0, 255])
     */
    void set(float dutyCycle);

    /**
     * @brief Set the Motors direction
     * @attention affected by Motor::inverted
     */
    void setDirection(bool forward);

    /**
     * Sets motor pwm value to zero
     */
    void stop();
}


#endif // MOTOR_H
