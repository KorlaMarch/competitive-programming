#include <ATX2.h>
#define REF1 400
#define REF2 400
#define REF3 400
#define REF4 400
char isW(int port){
  switch(port){
    case 1: return analog(1)>REF1;
    case 2: return analog(2)>REF2;
    case 3: return analog(3)>REF3;
    case 4: return analog(4)>REF4;
  } 
}
void tack(){
  char s1,s2,s3,s4,i=0;
  while(1){
    s1 = isW(1),s2 = isW(2),s3 = isW(3),s4 = isW(4);
    /*if(s1&&!s2&&!s3&&s4){
      FD(50);
    }else if(!s4){
      FD2(60,-40);
      st = 4;
    }else if(!s1){
      FD2(-40,60); 
      st = 3;
    }else if(s2){
      FD2(80,40);
      st = 1;
    }else if(s3){
      FD2(40,80);
      st = 2;
    }else if(s1&&s2&&s3&&s4){
      if(st == 1){
        FD2(80,-60);
      }else if(st == 2){
        FD2(-60,80);
      }else if(st == 3){
        SL(65);
      }else if(st == 4){
        SR(65);
      }
    }*/
    if(s1&&!s2&&!s3&&s4){
      FD(50);
    }else if(s1&&!s2&&s3&&s4){
      FD2(30,50);
      i=1;
    }else if(s1&&s2&&!s3&&s4){
      FD2(50,30);
      i=2;
    }else if(s1&&s2&&s3&&s4){
      if(i==1){
        FD2(-50,60);
      }else if(i==2){
        FD2(60,-50);
      }else if(i==3){
        SL(65);
      }else if(i==4){
        SR(65);
      }
    }
    else if(!s1){
      FD2(-40,60);
      i=3;
    }else if(!s4){
      FD2(60,-40);
      i=4;
    }
  }
}

void setup()
{
  delay(200);
  while(in(18)==1);
  //servo(1,60);
  tack();
}


void loop()
{
  /*if(in(18)==0){
    if(i){
      servo(1,60);
      i = 0;
    }else{
      servo(1,90);
      i = 1;
    }
    delay(1000);
  }*/
}
