#include "Library.h"

namespace main {
  namespace Ps2 {
  PS2X ps2x;

  int up, down, right, left, green, blue, red, pink, r1, r2, l1, l2, l3, r3;  //button
  int LY, LX , RY, RX;                                                        //joystick
  int error = 0;
  byte type = 0;
  byte vibrate = 0;

  int couter_red   = 0;
  int couter_green = 0;
  int couter_blue  = 0;
  int couter_pink  = 0;
  int couter_l1_r1 = 0;
  int couter_LY = 0;

  void Read_Ps2() {
    ps2x.read_gamepad(false, vibrate);
    up = ps2x.Button(PSB_PAD_UP);
    down = ps2x.Button(PSB_PAD_DOWN);
    right = ps2x.Button(PSB_PAD_RIGHT);
    left = ps2x.Button(PSB_PAD_LEFT);
    r1 = ps2x.Button(PSB_R1);
    r2 = ps2x.Button(PSB_R2);
    l1 = ps2x.Button(PSB_L1);
    l2 = ps2x.Button(PSB_L2);
    l3 = ps2x.Button(PSB_L3);
    r3 = ps2x.Button(PSB_R3);
    green = ps2x.Button(PSB_GREEN);
    blue = ps2x.Button(PSB_BLUE);
    red = ps2x.Button(PSB_RED);
    pink = ps2x.Button(PSB_PINK);

    LY   =  ps2x.Analog(PSS_LY);    // read left stick
    LX  =  ps2x.Analog(PSS_LX);    // read left stick
    RY  =  ps2x.Analog(PSS_RY);    // read right stick
    RX =  ps2x.Analog(PSS_RX);    // read right stick

    LY   = map(LY, 0, 255, 1023, -1023);
    LX  = map(LX, 0, 255, 1023, -1023);
    RY  = map(LY, 0, 255, 1023, -1023);
    RX = map(RX, 0, 255, 1023, -1023);
 }
  void Setup_Ps2() {
    error = ps2x.config_gamepad(Clk, Cmd, Cs, Dat, false, false);  //setup pins and settings:  GamePad(clock, command, attention, data, Pressures?, Rumble?) check for error
    type = ps2x.readType();
    switch (type) {
      case 0:
        Serial.println("Disconected");
      break;

      case 1:
        Serial.println("Conected : PS2");
      break;
    }
  }

  void Control_Ps2() {
    if (error == 1) {
      return;
    } else {

      main ::Ps2::Read_Ps2();
      ps2x.read_gamepad(false, vibrate);

      //move
      if (up    and !down and !right and !left  and !green and !red and !pink and !blue) {main ::Motor ::Up   (170,170);} 
      if (down  and !up   and !right and !left  and !green and !red and !pink and !blue) {main ::Motor ::Down (170,170);}  
      if (left  and !down and !right and !up    and !green and !red and !pink and !blue) {main ::Motor ::Left (180,180);}  
      if (right and !down and !left  and !left  and !green and !red and !pink and !blue) {main ::Motor ::Right(180,180);}  
      if (!up   and !down and !left  and !right and !green and !red and !pink and !blue) {main ::Motor ::Stop ();}
      
      //reset_board
      main ::Reset::Reset_Board(l3 and r3);  

      //gắp và nhả cây
      if (green and !red and !pink and !blue){
        while (green) {
          couter_green++;
          while (green) {
            main ::Ps2 ::Read_Ps2();
            if (couter_green % 2 == 0) {
              main ::Relay ::Control_Relay(Relay_5, 0x00);
            }else {
              main ::Relay ::Control_Relay(Relay_5, 0x01);
            }
            if (couter_green > 99) couter_green = 0;
          }
        }
      }

      //gắp và nhả bóng
      if (red and !green and !pink and !blue){
        while (red) {
          couter_red++;
          while (red) {
            main ::Ps2 ::Read_Ps2();
            if (couter_red % 2 == 0) {
              main ::Relay ::Control_Relay(Relay_2, 0x00);
            } else {
              main ::Relay ::Control_Relay(Relay_2, 0x01);
            }
            if (couter_red > 99) couter_red = 0;
          }
        }
      }

      //hạ và nâng để trồng cây
      if (blue and !red and !pink and !green){
        while (blue) {
          couter_blue++;
          while (blue) {
            main ::Ps2 ::Read_Ps2();
            if (couter_blue % 2 == 0) {
              main ::Relay ::Control_Relay(Relay_3, 0x00);
            } else {
              main ::Relay ::Control_Relay(Relay_3, 0x01);
            }
            if (couter_blue > 99) couter_blue = 0;
          }
        }
      }

      //hạ và nâng xilanh cần trục
      if (pink and !red and !green and !blue){
        while (pink) {
          couter_pink++;
          while (pink) {
            main ::Ps2 ::Read_Ps2();
            if (couter_pink % 2 == 0) {
              main ::Relay ::Control_Relay(Relay_4, 0x00);
            } else {
              main ::Relay ::Control_Relay(Relay_4, 0x01);
            }
            if (couter_pink > 99) couter_pink = 0;
          }
        }
      }

      //bắn bóng
      if (l1 and r1){
        while (l1 and r1) {
          couter_l1_r1++;
          while (l1 and r1) {
            main ::Ps2 ::Read_Ps2();
            if (couter_l1_r1 % 2 == 0) {
              main ::Relay ::Control_Relay(Relay_1, 0x00);
            } else {
              main ::Relay ::Control_Relay(Relay_1, 0x01);
            }
            if (couter_l1_r1 > 99) couter_l1_r1 = 0;
          }
        }
      }
      
      //điều khiển kéo bóng 
      if(LY>= -1023 and LY<-200 and LX == 5 and !l3 and !r3 ){ main ::Motor:: Control_Motor(Dir_3,0x01,Pwm_3,160);}
      if(LY<=  1023 and LY> 200 and LX == 5 and !l3 and !r3 ){ main ::Motor:: Control_Motor(Dir_3,0x00,Pwm_3,230);}
      if(LX > 0 and LX < 10 and LY> -10 and LY< 0 and !l3 and !r3){main ::Motor:: Control_Motor(Dir_3,0x01,Pwm_3,0);}
    }
      delay(50);
    }
  }
}