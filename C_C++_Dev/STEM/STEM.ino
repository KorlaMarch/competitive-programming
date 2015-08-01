#include <ipst.h>

#define REF 600

void fw2(int a, int b){
 motor(1,a-4);
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
void trackT(int t){
 unsigned long st = millis();
  while(millis()-st<t) track();
}
///////////////////////////////////////////////////////////////////

void pushCan(){
  while(analog(1)>=REF&&analog(4)>=REF) track();
  bw2(-80,-80);
  delay(100);
  while(1){
    if(analog(1)<REF) bw2(-20,5);
    else if(analog(4)<REF) bw2(5,-20);
    else break; 
  }
  motor_stop(ALL); delay(200);
  fw2(55,55); delay(300);
}
void trackCanR(){
  while(analog(4)>=REF) track();
  turnR90();
  pushCan();
  bw2(-60,-65); delay(500);
  while(analog(1)>=REF) bw2(-60,-60);
  trackT(900);
}
void trackCanS(){
  while(analog(4)>=REF) track();
  fw2(60,60); delay(200);
  pushCan();
  bw2(-60,-65); delay(500);
  while(analog(1)>=REF) bw2(-60,-60);
  trackT(900);
}
void trackCanL(){
  unsigned long st;
  while(analog(1)>=REF) track();
  turnL90();
  pushCan();
  bw2(-65,-60); delay(500);
  while(analog(4)>=REF) bw2(-60,-60);
  st = millis();
  while(millis()-st<=900) trackI();
}

void setup(){
  OK();
}


void loop()
{
  fw2(70,70); delay(300);
  trackT(400);
  trackCanR();
  trackCanR();
  trackT(5000);
  trackCanR();
  trackCanS();
  trackCanL();
  trackCanR();
  trackT(7500);
  while(analog(4)>=REF) track();
  turnR90();
  pushCan();
  bw2(-60,-60); delay(500);
  while(analog(1)>=REF) bw2(-60,-60);
  fw2(100,100); delay(50);
  fw2(-60,60); delay(180);
  fw2(60,60); delay(600);
  motor_stop(ALL);
  OK();
}
