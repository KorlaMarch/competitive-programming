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
  SR(70);
  while(encoder(2)<45);
  SL(100);
  delay(50);
  AO();
}

void turnL90EN(){
  resetEnc3();
  SL(70);
  while(encoder(3)<52);
  SR(100);
  delay(50);
  AO();
}
void matrix(){
  turnL90EN();
  FD(80); delay(200);
  BK(100); delay(80); AO();
  turnR90EN();
  delay(100);
  FD(80); delay(500);
  BK(100); delay(80); AO();
  turnR90EN();
  delay(100);
  FD(80); delay(200);
  BK(100); delay(80); AO();
}

void rescu(){
   FD(60);  while(analog(4)<100);
   BK(100); delay(100); AO();
   turnR90EN();
   FD(60); while(analog(4)<100);
   BK(100); delay(100); AO();
   turnR90EN();
   FD(60); while(analog(4)<100);
   BK(100); delay(100); AO();
   turnR90EN();
   FD(60); while(isW(1)&&isW(4));
   delay(100); AO();
   //room 1
   
   BK(60); delay(150); AO();
   turnR90EN();
   FD(60); while(isW(1)&&isW(4));
   delay(100); AO();
   //room 2
   
   BK(60); delay(150); AO();
   turnL90EN();
   
   
}
char s1,s2,s3,s4,i=0;
void tack(){
    s1 = isW(1),s2 = isW(2),s3 = isW(3),s4 = isW(4);
    if(s1&&!s2&&!s3&&s4){
      FD(70);
    }else if(s1&&!s2&&s3&&s4){
      FD2(40,70);
      i=1;
    }else if(s1&&s2&&!s3&&s4){
      FD2(70,40);
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

void track21(){
 int r,l;
 FD(70);
 delay(400);
 BK(100); delay(50); AO();
 out(27,1); delay(200); out(27,0);
 turnL90EN(); 
 out(27,1); delay(200); out(27,0);
 FD(50); delay(500);
 while(analog(4)<270){
   if(analog(5)>250) FD2(30,65);
   else if(analog(5)<150) FD2(65,30);
 }
 BK(100); delay(50); AO(); delay(400);
 turnR90EN();
 out(27,1); delay(200); out(27,0);
 FD(80); delay(300); AO();
}

void bridge(){
    unsigned long t = millis();
    while(millis()-t<5000) tack();
    while(isW(4)) tack();
    out(27,1);
    t = millis();
    while(millis()-t<700) tack();
    FD(70); delay(500); AO();
}

void setup()
{
  int k;
  while(!sw_OK()){
    k = knob(2)+1;
    glcd(0,0,"%d   ",k);
  }
  //servo(1,60);
  //tack();
  //track2();
  //bridge();
  //SL(90);
  switch(k){
    case 1:
      bridge();
      break;
    case 2:
      SL(70);
      break;
    case 3:
      track21();
      break;
  }
}


void loop()
{
  /*glcd(0,0,"%d    ",knob(70));
  if(sw_OK()) turnL90EN();*/
  //SL(60);
  //tack();
  //glcd(0,0,"%d    ",analog(5));
}
