#include "Library.h"

namespace main{
  namespace Relay{
    void Setup_Relay(int relay_1 , int relay_2 , int relay_3 , int relay_4 , int relay_5){
      pinMode(relay_1,OUTPUT);
      pinMode(relay_2,OUTPUT);
      pinMode(relay_3,OUTPUT);
      pinMode(relay_4,OUTPUT);
      pinMode(relay_5,OUTPUT);
    }

    void Control_Relay(int relay , int status){
      digitalWrite(relay,status);
    }
  }
}