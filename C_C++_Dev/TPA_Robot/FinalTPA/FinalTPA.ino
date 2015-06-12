#include <ATX2.h>
#include <ATX2_enc.h>
#define REF1 400
#define REF2 400
#define REF3 400
#define REF4 400
char isW(int port){
  switch(port){
    case 1: return analog(8)>REF1;
    case 2: return analog(9)>REF2;
    case 3: return analog(10)>REF3;
    case 4: return analog(11)>REF4;
  }  
}

int sonar2(){
  int i,sum=0;
  for(i = 0; i < 20; i++){
     sum += sonar();
  }
  return sum/7;
}

void turnR90EN(){
  resetEnc2();
  SR(80);
  while(encoder(2)<52);
  SL(100);
  delay(50);
  AO();
}

void turnL90EN(){
  resetEnc3();
  SL(80);
  while(encoder(3)<52);
  SR(100);
  delay(50);
  AO();
}
void matrix(){
  turnL90EN();
  FD(80);
  delay(200);
  turnR90EN();
  FD(80);
  delay(500);
  turnR90EN();
  FD(80);
  delay(200);
  AO(); 
}
void bridge(){
  char s1,s2,s3,s4,i=0,ls,j=0;
  while(j<3){
    s1 = isW(1),s2 = isW(2),s3 = isW(3),s4 = isW(4);
    if(s1&&!s2&&!s3&&s4){
      FD(60);
      ls = 0;
    }else if(s1&&!s2&&s3&&s4){
      FD2(30,60);
      i=1;
      ls = 0;
    }else if(s1&&s2&&!s3&&s4){
      FD2(60,30);
      i=2;
      ls = 0;
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
      ls = 0;
    }
    else if(!s1){
      FD2(-40,60);
      i=3;
    }else if(!s4){
      if(!ls){
        j++;
      }
      ls = 1;
      //FD2(60,-40);
      //i=4;
    }
  }
}

void tack(){
  char s1,s2,s3,s4,i=0;
  while(1){
    s1 = isW(1),s2 = isW(2),s3 = isW(3),s4 = isW(4);
    if(s1&&!s2&&!s3&&s4){
      FD(60);
    }else if(s1&&!s2&&s3&&s4){
      FD2(30,60);
      i=1;
    }else if(s1&&s2&&!s3&&s4){
      FD2(60,30);
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

void track2(){
 int r,l;
 FD(80);
 delay(300);
 turnL90EN();
 FD(80);
 delay(300);
 while(sonar2()>10){
    l = analog(4),r = analog(5);
    if(l<r){
      FD2(20,70);
    }else if(l>r){
      FD2(70,20);
    }else{
      FD(50); 
    }
  }
  turnR90EN();
  AO();
}

void setup()
{
  sw_OK_press();
  //servo(1,60);
  //tack();
  track2();
  //bridge();
  //matrix();
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
  //SL(60);
}
