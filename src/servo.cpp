


#include "servo.hpp"
#include <iostream>
#include <pigpiod_if2.h>



Servo::Servo(uint32_t servopin) :  _servo_pin(servopin) {
    std::cout << "Constructed" << std::endl;
    pigpio_handle=pigpio_start(NULL,NULL);
    if (pigpio_handle < 0) {
        std::cout << "Can not connect to pigpio daemon. Is it running?" << std::endl;
    }
}

Servo::~Servo() {
    pigpio_stop(pigpio_handle);
}

void Servo::setDeg(int16_t deg) {
    std::cout << "Set to " << _servo_pin << " to " << deg << " dregrees" << std::endl;
    //Assume -90= 1000,  0=1500, 90=2000
    //-> 180deg = 1000  -> 1deg (1000/180) steps
    uint32_t pwmValue = (uint32_t)(deg * (1000.0/180.0) +1500.0);

    set_servo_pulsewidth(pigpio_handle,_servo_pin, pwmValue);
}

void Servo::setRad(float rad) {
    uint16_t deg = (uint16_t) (rad * (180.0/3.141592653589793238463));
    this->setDeg(deg);
}

