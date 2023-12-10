#include "Library.h"

namespace main{
  namespace Config{
    void Setup(){
      Serial.begin(57600);
      main :: Relay :: Setup_Relay(Relay_1,Relay_2,Relay_3,Relay_4,Relay_5);
      main :: Motor :: Setup_Motor(Dir_1,Pwm_1,Dir_2,Pwm_2,Dir_3,Pwm_3);
      main :: Sensor:: Setup_Sensor(HT1,HT2,HT3,HT4,HT5,HT6);
      main :: Ps2   :: Setup_Ps2();
    }
    void Config_Main(){
      main :: Ps2 :: Control_Ps2();
    }
  }
}