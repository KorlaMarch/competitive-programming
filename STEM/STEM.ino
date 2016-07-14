#include <dsp4s.h>
#include <ipst.h>

#define REF 600

void fw2(int a, int b){
 motor(1,a-2);
 motor(2,b); 
}
void bw2(int a, int b){
 motor(1,a+4);
 motor(2,b); 
}
void turnR90(){
  fw2(60,-60);
  delay(150);
  while(analog(3)>=REF);
  fw2(-96,100);
  delay(75);
  motor_stop(ALL);
}
void turnL90(){
  fw2(-60,60);
  delay(150);
  while(analog(2)>=REF);
  fw2(100,-100);
  delay(75);
  motor_stop(ALL);
}
///////////////////////////////////////////////////////////////////
int i;
void track(){
 if(analog(1)<REF){
    fw2(-20,60);
    i = 3;
  }else if(analog(4)<REF){ 
    fw2(60,-20);
    i = 4;
  }else if(analog(2)<REF&&analog(3)<REF){
      fw2(60,60);
  }else if(analog(2)>=REF&&analog(3)<REF){
      fw2(60,40);
      i = 1;
  }else if(analog(2)<REF&&analog(3)>=REF){
      fw2(40,60);
      i = 2;
  }else{
      switch(i){
       case 1: fw2(60,20); break;
        case 2: fw2(20,60); break;
        case 3: fw2(-50,50); break;
        case 4: fw2(50,-50); break;
        default: fw2(50,50); break;
      }
  }
}
void trackG(){
 if(analog(1)<REF){
    fw2(-20,60);
    i = 3;
  }else if(analog(2)<REF&&analog(3)<REF){
      fw2(60,60);
  }else if(analog(2)>=REF&&analog(3)<REF){
      fw2(60,40);
      i = 1;
  }else if(analog(2)<REF&&analog(3)>=REF){
      fw2(40,60);
      i = 2;
  }else{
      switch(i){
       case 1: fw2(60,20); break;
        case 2: fw2(20,60); break;
        case 3: fw2(-50,50); break;
      }
  }
}
void trackSL(){
 if(analog(1)<REF){
    fw2(-20,50);
    i = 3;
  }else if(analog(4)<REF){ 
    fw2(50,-20);
    i = 4;
  }else if(analog(2)<REF&&analog(3)<REF){
      fw2(30,30);
  }else if(analog(2)>=REF&&analog(3)<REF){
      fw2(40,20);
      i = 1;
  }else if(analog(2)<REF&&analog(3)>=REF){
      fw2(20,40);
      i = 2;
  }else{
      switch(i){
       case 1: fw2(40,20); break;
        case 2: fw2(20,40); break;
        case 3: fw2(-50,50); break;
        case 4: fw2(50,-50); break;
      }
  }
}
void trackSM(){
 if(analog(1)<REF){
    fw2(-20,40);
    i = 3;
  }else if(analog(4)<REF){ 
    fw2(40,-20);
    i = 4;
  }else if(analog(2)<REF&&analog(3)<REF){
      fw2(50,50);
  }else if(analog(2)>=REF&&analog(3)<REF){
      fw2(53,50);
      i = 1;
  }else if(analog(2)<REF&&analog(3)>=REF){
      fw2(50,53);
      i = 2;
  }else{
      switch(i){
       case 1: fw2(55,45); break;
        case 2: fw2(45,55); break;
        case 3: fw2(-50,50); break;
        case 4: fw2(50,-50); break;
        default: fw2(50,50); break;
      }
  }
}
void trackI(){
 if(analog(4)<REF){ 
    fw2(60,-20);
    i = 4;
  }else if(analog(1)<REF){
    fw2(-20,60);
    i = 3;
  }else if(analog(2)<REF&&analog(3)<REF){
      fw2(60,60);
  }else if(analog(2)>=REF&&analog(3)<REF){
      fw2(60,40);
      i = 1;
  }else if(analog(2)<REF&&analog(3)>=REF){
      fw2(40,60);
      i = 2;
  }else{
      switch(i){
       case 1: fw2(60,20); break;
        case 2: fw2(20,60); break;
        case 3: fw2(-50,50); break;
        case 4: fw2(50,-50); break;
      }
  }
}
void trackIG(){
 if(analog(4)<REF){ 
    fw2(60,-20);
    i = 4;
  }else if(analog(2)<REF&&analog(3)<REF){
      fw2(60,60);
  }else if(analog(2)>=REF&&analog(3)<REF){
      fw2(60,40);
      i = 1;
  }else if(analog(2)<REF&&analog(3)>=REF){
      fw2(40,60);
      i = 2;
  }else{
      switch(i){
       case 1: fw2(60,20); break;
        case 2: fw2(20,60); break;
        case 4: fw2(50,-50); break;
      }
  }
}
void trackT(int t){
 unsigned long st = millis();
  while(millis()-st<t) track();
}
void trackSP(int t){
  unsigned long st = millis();
  i = 3; 
  while(millis()-st<t) trackG();
}
void trackSPI(int t){
  unsigned long st = millis();
  i = 4;
  while(millis()-st<t) trackIG();
}
///////////////////////////////////////////////////////////////////
#define N 250
int note[] = {784,659,523,0,784,698,587,0,698,587,493,0,698,659,523,
              0,523,587,659,783,880,
            987,784,698,784};
int time[] = {N,N/2,N/2,N,N,N,N/2,N*2,N,N/2,N/2,N,N,N,N/2,
              N*2,N/2,N/2,N/2,N/2,N*2,
            N/2,N/2,N/2,N*4};
void pushCan(){
  while(analog(1)>=REF&&analog(4)>=REF) trackSL();
  bw2(-80,-80);
  delay(100);
  while(1){
    if(analog(1)<REF) bw2(-20,5);
    else if(analog(4)<REF) bw2(5,-20);
    else break; 
  }
  motor_stop(ALL); delay(200);
  for(int j = 0; j < 25; j++){
    sound(17,note[j],time[j]);
    delay(time[j]); 
  }
  fw2(30,30); delay(700);
}
void trackCanR(int T){
  while(analog(4)>=REF) track();
  turnR90();
  pushCan();
  bw2(-60,T); delay(500);
  while(analog(1)>=REF) bw2(-60,-60);
  trackSP(400);
  trackT(500);
}
void trackCanS(){
  while(analog(4)>=REF) track();
  fw2(60,60); delay(200);
  pushCan();
  bw2(-60,-65); delay(500);
  while(analog(1)>=REF) bw2(-60,-60);
  trackSP(400);
  trackT(500);
}
void trackCanL(){
  unsigned long st;
  while(analog(1)>=REF) track();
  turnL90();
  pushCan();
  bw2(-65,-60); delay(500);
  while(analog(4)>=REF) bw2(-60,-60);
  trackSPI(400);
  st = millis();
  while(millis()-st<=500) trackI();
}
char s[5];
unsigned long t[9];
void readBarCode(){
  unsigned long st,ls=(analog(1)>=REF);
  SegmentByte(0);
  fw2(50,50);
  for(int i = 0; i < 8; i++){
    st = millis();
    while((analog(5)>=REF)==ls) trackSM();
    ls = (analog(5)>=REF);
    t[i] = millis()-st;
  }
  motor_stop(ALL);
  s[0] = (t[1]<100)+'0';
  s[1] = (t[3]<100)+'0';
  s[2] = (t[5]<100)+'0';
  s[3] = '\0';
  //Segment(s);
  Segment("%d",(t[1]<100)*4+(t[3]<100)*2+(t[5]<100));
}

void setup(){
  pinSegment(16);
  OK();
  glcdClear();
  glcdMode(0);
  setTextSize(1);
}

void loop()
{
  
  while(analog(4)>=REF) fw2(50,50);
  delay(130);  
  //readBarCode();
  trackT(400);
  trackCanR(-65);
  trackCanR(-65);
  trackT(5000);
  trackCanR(-63);
  //////////////////////////////////////
  trackCanS();
  trackCanL();
  trackCanR(-63);
  trackT(7500);
  while(analog(4)>=REF) track();
  turnR90();
  pushCan();
  bw2(-60,-60); delay(500);
  while(analog(1)>=REF) bw2(-60,-60);
  fw2(100,100); delay(50);
  fw2(-60,60); delay(230);
  fw2(60,60); delay(600);
  motor_stop(ALL);
  glcd(0,0,s);
  for(int j = 0; j < 8; j++){
    glcd(j+1,0,"%d   ", t[j]);
  }
  sw_OK_press();
  glcdClear();
}
