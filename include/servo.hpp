

#ifndef __SERVO_HPP__
#define __SERVO_HPP__

#include <stdint.h>
 

class Servo {
    public:
        Servo(uint32_t servo_pin);
        ~Servo();

        void setDeg(int16_t val);
        void setRad(float val);

    private:
        int pigpio_handle=-1;
        uint32_t _servo_pin;
};

#endif