#include "Library.h"

namespace main{
  namespace Sensor{
    void Setup_Sensor(int sensor_1,int sensor_2,int sensor_3,int sensor_4,int sensor_5,int sensor_6){
      pinMode(sensor_1,INPUT_PULLUP);
      pinMode(sensor_2,INPUT_PULLUP);
      pinMode(sensor_3,INPUT_PULLUP);
      pinMode(sensor_4,INPUT_PULLUP);
      pinMode(sensor_5,INPUT_PULLUP);
      pinMode(sensor_6,INPUT_PULLUP);
    }

    bool Check_Sensor(int sensor){
      if(digitalRead(sensor)==1)
        return true ;
      return false ;  
    }
  }
}