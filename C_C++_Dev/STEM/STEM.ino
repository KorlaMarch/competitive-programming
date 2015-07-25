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
int i;
void track(){
 if(analog(1)<REF){
    fw2(-20,70);
    i = 3;
  }else if(analog(4)<REF){ 
    fw2(70,-20);
    i = 4;
  }else if(analog(2)<REF&&analog(3)<REF){
      fw2(70,70);
  }else if(analog(2)>=REF&&analog(3)<REF){
      fw2(70,50);
      i = 1;
  }else if(analog(2)<REF&&analog(3)>=REF){
      fw2(50,70);
      i = 2;
  }else{
      switch(i){
       case 1: fw2(70,20); break;
        case 2: fw2( 20,70); break;
        case 3: fw2(-50,50); break;
        case 4: fw2(50,-50); break;
      }
  }
}
void trackCanR(){
  while(analog(4)>=REF) track();
  turnR90();
  while(analog(1)>=REF&&analog(4)>=REF) track();
  fw2(55,55);
  delay(500);
  bw2(-80,-80);
  delay(770);
  fw2(100,100);
  delay(50);
  motor_stop(ALL);
  turnL90();
}
void trackCanL(){
  while(analog(1)>=REF) track();
  turnL90();
  while(analog(1)>=REF&&analog(4)>=REF) track();
  fw2(55,55);
  delay(500);
  bw2(-80,-80);
  delay(770);
  fw2(100,100);
  delay(50);
  motor_stop(ALL);
  turnR90();
}
int co = 0;
void setup(){
  OK();
}


void loop()
{
  fw2(70,70);
  delay(2000);
  motor_stop(ALL);
  OK();
}
