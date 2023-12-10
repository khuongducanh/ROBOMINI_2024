#include "Library.h"

namespace main{
  namespace Motor{
    void Setup_Motor(int Dir1,int Pwm1,int Dir2,int Pwm2 , int Dir3, int Pwm3){
      pinMode(Dir1,OUTPUT);
      pinMode(Pwm1,OUTPUT);
      pinMode(Dir2,OUTPUT);
      pinMode(Pwm2,OUTPUT);
      pinMode(Dir3,OUTPUT);
      pinMode(Pwm3,OUTPUT);
    }

    void Control_Motor(int Dir , int Status, int Pwm , int x){
      digitalWrite(Dir,Status);
      analogWrite (Pwm,x);
    }

    void  Right(int Pwm_A , int Pwm_B){
      main :: Motor :: Control_Motor(Dir_1,0x00,Pwm_1,Pwm_A);
      main :: Motor :: Control_Motor(Dir_2,0x01,Pwm_2,Pwm_B);
    }

    void Left(int Pwm_A , int Pwm_B){
      main :: Motor :: Control_Motor(Dir_1,0x01,Pwm_1,Pwm_A);
      main :: Motor :: Control_Motor(Dir_2,0x00,Pwm_2,Pwm_B);
    }

    void Up(int Pwm_A , int Pwm_B){
      main :: Motor :: Control_Motor(Dir_1,0x00,Pwm_1,Pwm_A);
      main :: Motor :: Control_Motor(Dir_2,0x00,Pwm_2,Pwm_B);
    }

    void Down(int Pwm_A , int Pwm_B){
      main :: Motor :: Control_Motor(Dir_1,0x01,Pwm_1,Pwm_A);
      main :: Motor :: Control_Motor(Dir_2,0x01,Pwm_2,Pwm_B);
    }

    void Stop(){
      main :: Motor :: Control_Motor(Dir_1,0x01,Pwm_1,0);
      main :: Motor :: Control_Motor(Dir_2,0x01,Pwm_2,0);
    }
  }
}