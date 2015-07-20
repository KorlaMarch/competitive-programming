#include <ipst.h>

#define REF 700

void fw2(int a, int b){
 motor(1,a);
 motor(2,b); 
}
void track(int n){
 if(analog(1)<REF){
    fw2(-20,80);
    i = 3;
    if(n==1) return;
  }else if(analog(4)<REF){ 
    fw2(80,-20);
    i = 4;
    if(n==4) return;
  }else if(analog(2)<REF&&analog(3)<REF){
      fw2(70,70);
  }else if(analog(2)>=REF&&analog(3)<REF){
      fw2(80,50);
      i = 1;
  }else if(analog(2)<REF&&analog(3)>=REF){
      fw2(50,80);
      i = 2;
  }else{
      switch(i){
       case 1: fw2(80,20); break;
        case 2: fw2( 20,80); break;
        case 3: fw2(-50,50); break;
        case 4: fw2(50,-50); break;
      }
  }
}
void setup(){
  OK();
}
int i;
void loop(){
  
}
