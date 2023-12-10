//Library
#include <PS2X_lib.h> 
//Motor_1
#define Dir_1 22
#define Pwm_1 2
//Motor_2
#define Dir_2 24
#define Pwm_2 3
//Motor_3
#define Dir_3 A0
#define Pwm_3 4
//Cong_tac_hanh_trinh
#define HT1 23
#define HT2 25
#define HT3 27
#define HT4 29
#define HT5 31
#define HT6 33
//Relay
#define Relay_1 50
#define Relay_2 48
#define Relay_3 46
#define Relay_4 44
#define Relay_5 42
//Ps2
#define Dat 30
#define Cmd 32
#define Cs  34
#define Clk 36

namespace main{
  namespace Motor{
    void Setup_Motor(int Dir1,int Pwm1,int Dir2,int Pwm2,int Dir3 , int Pwm3);
    void Control_Motor(int Dir , int Status, int Pwm , int x);
    void Up   (int Pwm_A , int Pwm_B);
    void Down (int Pwm_A , int Pwm_B);
    void Left (int Pwm_A , int Pwm_B);
    void Right(int Pwm_A , int Pwm_B);
    void Stop();
  }

  namespace Ps2{
    void Setup_Ps2();
    void Couter();
    void Read_Ps2();   
    void Control_Ps2();
  }

  namespace Relay{
    void Setup_Relay  (int relay_1 , int relay_2 , int relay_3 , int relay_4 , int relay_5);
    void Control_Relay(int relay , int status);
  }
  namespace Reset{
    void Reset_Board(int button);
  }
  namespace Sensor{
    void Setup_Sensor(int sensor_1,int sensor_2,int sensor_3,int sensor_4,int sensor_5,int sensor_6);
    bool Check_Sensor(int sensor);
  }
  namespace Config{
    void Setup();
    void Config_Main();
  }
}
