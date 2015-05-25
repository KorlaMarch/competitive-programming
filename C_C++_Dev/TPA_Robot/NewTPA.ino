#include <ATX2.h>

int POWL = 50;
int POWR = 50;
char canS;
int k;
#define REFL 200
#define REFR 200

void waitDis(int st){
  encCnt = 0; 
  while(encCnt<st){
    if(encCnt%4==0&&canS) servo(5,150);
  }
}
void debug(){
  stopM(5);
  sound(1000,100);
  delay(500);
}

////////////////////////////////////////////////////
//////////// ---- SERVO Controller ---- ////////////
////////////////////////////////////////////////////
#define SERVO_U 8
#define UDOWN 130
#define UUP 30
#define SERVO_G 4
#define GOPEN 100
#define GCLOSE 160


void canUp(){
  servo(SERVO_G,GOPEN); delay(300);
  servo(SERVO_U,UDOWN); delay(300);
  servo(SERVO_G,GCLOSE); delay(300);
  servo(SERVO_U,UUP); delay(300);
  canS = 1;
}
void canDown(){
  servo(SERVO_U,UDOWN);
  delay(500);
  servo(SERVO_G,GOPEN); 
  delay(300);
  servo(SERVO_U,UUP); 
  delay(300);
  canS = 0;
}
void sHome(){
  servo(SERVO_G,GCLOSE);
  servo(SERVO_U,UUP);
}

////////////////////////////////////////////////////
///////////// ---- BASIC Movement ---- /////////////
////////////////////////////////////////////////////
void stopM(int i){
  BK(100); 
  delay(i);
  AO();
}
void fw(){
  FD2(POWL,POWR);
}
void fww(int n){
  fw(); waitDis(n);
}
void bw(){
  BK2(POWL,POWR); 
}
void turnL(){
  motor(12,-POWL);
  motor(34,POWR);
}
void turnR(){
  motor(12,POWL);
  motor(34,-POWR);
}
void turnL90(){
  int Tl=POWL,Tr=POWR;
  POWL=POWR=80;
  turnL();
  while(analog(4)<REFR);
  while(analog(5)<REFR);
  while(analog(5)>=REFR);
  stopM(5);
  POWL = Tl;
  POWR = Tr;
}
void turnR90(){
  int Tl=POWL,Tr=POWR;
  POWL=POWR=80;
  turnR();
  while(analog(5)<REFR);
  while(analog(4)<REFR);
  while(analog(4)>=REFR);
  stopM(5);
  POWL = Tl;
  POWR = Tr;
}
void turnL90EN(){
  int Tl=POWL,Tr=POWR;
  POWL=POWR=80;
  turnL();
  waitDis(55);
  stopM(5);
  POWL = Tl;
  POWR = Tr;
}

void turnR90EN(){
  int Tl=POWL,Tr=POWR;
  POWL=POWR=80;
  turnR();
  waitDis(100);
  stopM(5);
  POWL = Tl;
  POWR = Tr;
}
void turnL90C(){
  fww(10);
  stopM(12);
  turnL90(); 
}
void turnR90C(){
  fww(10);
  stopM(12);
  turnR90(); 
}
int sonar2(){
  int i,sum=0;
  for(i = 0; i < 7; i++){
     sum += sonar();
  }
  return sum/7;
}
void adjRot(){
  int Tl=POWL,Tr=POWR;
  POWL=POWR=100;
  bw();
  while(in(27)==1&&in(26)==1);
  while(in(27)==1||in(26)==1);
  AO();
  POWL = Tl;
  POWR = Tr;
}
void trackSM(int n){
  int c=0,s=0;
  while(1){
    int L = analog(5);
    int R = analog(4);
    if(canS) servo(5,150);
    if(L<REFL&&R<REFR){
      if(s){
        fw();
      }else{
        c++;
        s = 1;
        if(c>=n) break;
      }
    }
    else if(L<REFL){
      turnL();
      delay(30);
    }
    else if(R<REFR){
      turnR();
      delay(30);
    }
    else{
      s = 0;
      fw();
    }
  }
}
void trackSM_EN(int n){
  encCnt = 0; 
  while(1){
    int L = analog(5);
    int R = analog(4);
    if(canS) servo(5,150);
    if((L<REFL&&R<REFR)||encCnt>=n){
      break;
    }
    else if(L<REFL){
      turnL();
      delay(30);
    }
    else if(R<REFR){
      turnR();
      delay(30);
    }
    else{
      fw();
    }
  }
}
void setup()
{
  OK();// Wait for OK button
  glcdClear();
  /*while(sw_OK()==0){
    k = knob(1,5);
    glcd(0,0,"KNOB:%d     ",k);
  }*/
  /*delay(200);
  if(k==5)
  while(sw_OK()==0){
    t = knob(50,300);
    glcd(0,0,"Turn:%d     ",t);
  }*/
}
void loop()
{
  if(in(27)==0){
    canUp();
  }else if(in(26)==0){
    canDown();
  }
}    
