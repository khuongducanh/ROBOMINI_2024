#include "Library.h"

namespace main{
  void(* resetFunc) (void) = 0;//cài đặt hàm reset
  namespace Reset{
    void Reset_Board(int button ){
      if(button){
        delay(20);
        resetFunc();//tiến hành reset
      }
    }  
  }
}