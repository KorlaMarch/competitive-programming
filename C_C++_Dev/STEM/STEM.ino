#include <ipst.h>

#define REF 600

void fw2(int a, int b){
 motor(1,a);
 motor(2,b); 
}
void turnR90(){
  /*fw2(70,70);
  delay(10);*/
  fw2(60,-60);
  delay(150);
  while(analog(3)>=REF);
  fw2(-100,100);
  delay(50);
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
void setup(){
  OK();
}


void loop()
{
  while(analog(4)>=REF) track();
  turnR90();
  while(analog(1)>=REF&&analog(4)>=REF) track();
  fw2(55,55);
  delay(500);
  fw2(-80,-80);
  delay(600);
  fw2(100,100);
  delay(50);
  motor_stop(ALL);
  OK();
  glcd(0,0,"%d %d    ",analog(1),analog(2));
  glcd(1,0,"%d %d    ",analog(3),analog(4));
}
