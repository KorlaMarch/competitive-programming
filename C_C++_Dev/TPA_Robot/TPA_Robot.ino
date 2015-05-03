#include <ATX2.h>

int POWL = 50;
int POWR = 50;
int ca,k;
#define REFL 200
#define REFR 200

void waitDis(int st){
  encCnt = 0; 
  while(encCnt<st){
    if(encCnt%4==0&&ca) servo(5,150);
  }
}
void debug(){
  stopM(5);
  sound(1000,100);
  delay(500);
}
void canUp(){
  stopM(5);
  servo(5,65); delay(300);
  servo(6,160); delay(300);
  servo(5,150); delay(300);
  servo(6,20); delay(300);
  ca = 1;
}
void canDown(){
  int i;
  stopM(5);
  for(i = 30; i <= 160; i++) servo(6,160); 
  delay(100);
  servo(5,65); 
  delay(300);
  servo(6,20); 
  delay(300);
  ca = 0;
}
void sHome(){
  servo(6,20);
  servo(5,150);
}
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
    if(ca) servo(5,150);
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
    if(ca) servo(5,150);
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
void track1(){
  trackSM(1);
  turnR90C();
  trackSM(6);
  turnR90C();
}
void track2(){
  POWL = 48;
  POWR = 50;
  trackSM(1);
  turnR90C();
  trackSM(1);
  bw();
  waitDis(10);
  canUp();
  bw();
  waitDis(27);
  
  turnL90();
  trackSM(1);
  turnR90C();
  trackSM(1);
  bw();
  waitDis(10);
  canDown();
  bw();
  waitDis(27);
 
  turnL90();
  trackSM(1);
  turnR90C();
  trackSM(1);
  bw();
  waitDis(10);
  canUp();
  bw();
  waitDis(27);
  turnL90();
}
void track3(){
  POWL = POWR = 30;
  trackSM_EN(40);
  POWR = 80;
  POWL = 79;
  fw();
  waitDis(450);
  //debug();
}
void track4(){
   POWR = 60;
   POWL = 60;
   trackSM(1);
   turnR90C();
   POWL = POWR = 50;
   trackSM(1);
   turnR90C();
   trackSM(1);
   bw();
   waitDis(10);
   canDown();
   canUp();
   servo(5,65);
   delay(300);
   ca = 0;
}
void track5(){
  servo(5,150);
  fw();
  while(sonar2()>7){ fw(); }
  delay(300);
  stopM(5);
  bw();
  waitDis(10);
  turnL90EN();
  while(sonar2()>4){ fw(); }
  stopM(5);
  turnR90EN();
  fw();
  waitDis(25);
  k = 1;
}
void setup()
{
  sHome();
  ca = 0;
  OK();// Wait for OK button
  glcdClear();
  while(sw_OK()==0){
    k = knob(1,5);
    glcd(0,0,"KNOB:%d     ",k);
  }
  /*delay(200);
  if(k==5)
  while(sw_OK()==0){
    t = knob(50,300);
    glcd(0,0,"Turn:%d     ",t);
  }*/
  glcdClear();
}
void loop()
{
  switch(k){
    case 1:
    track1();
    case 2:
    track2();
    case 3:
    track3();
    case 4:
    track4();
    case 5:
    track5();
  }
  /*sw_OK_press();
  if(in(27)==0){
    canUp();
  }
  if(in(26)==0){
    canDown();
  }*/
}    

