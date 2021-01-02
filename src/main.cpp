
#include <boost/thread.hpp>
#include <iostream>
#include <stdint.h>

#include "servo.hpp"

//Definition of Pin
int ServoPin = 23;             //Pin for PWM

Servo *servo;

/** Servo test */
int main()
{

  servo=new Servo(ServoPin);
  

  std::cout << "Servo Test test" << std::endl;
  while(1)
  {

  
  std::cout << "Yoyo" << std::endl;
    //1.5ms is = 15
    for (int16_t i=-90; i<90; i+=15) {
          servo->setDeg(i);
          boost::this_thread::sleep_for(boost::chrono::milliseconds{200});
    }
    boost::this_thread::sleep_for(boost::chrono::milliseconds{500});

  }
 return 0;
}

