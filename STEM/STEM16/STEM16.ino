#include <ipst.h>
#include <compass.h>

#define REF 700
#define ALLDE 350

#define ISCOM false

void fw2(int a, int b) {
  motor(1, a);
  motor(2, b-1);
}
void bw2(int a, int b) {
  motor(1, a+2);
  motor(2, b);
}
void tu2(int a, int b) {
  motor(1, a);
  motor(2, b);
}
void fwt(int t, int spl, int spr){
  fw2(spl,spr);
  unsigned long st = millis();
  compass_set_heading();
  /*while (millis()-st < t){
    if(spl==spr){
      int hd = compass_read_heading();
      if(hd>0) fw2(spl-5,spl);
      else if(hd<0) fw2(spl,spl-5);
      else fw2(spl, spl);
    }
  }*/
  delay(t);
  bw2(-95, -95);
  delay(75);
  motor_stop(ALL);
  delay(ALLDE);
}

void fwt(int t){
  bwt(t,55,55);
}

void bwt(int t, int spl, int spr){
  bw2(spl,spr);
  unsigned long st = millis();
  compass_set_heading();
  /*while (millis()-st < t){
    if(spl==spr){
      int hd = compass_read_heading();
      if(hd>0) bw2(spl-5,spl);
      else if(hd<0) bw2(spl,spl-5);
      else bw2(spl, spr); 
    }
  }*/
  delay(t);
  fw2(95, 95);
  delay(75);
  motor_stop(ALL);
  delay(ALLDE);
}

void bwt(int t){
  bwt(t,-55,-55);
}

int time;

void turnR90() {
  fw2(60, -60);
  delay(248);
  fw2(-95, 95);
  delay(25);
  motor_stop(ALL);
  delay(ALLDE);
}
void turnL90() {
  fw2(-40, 40);
  delay(315);
  fw2(95, -95);
  delay(25);
  motor_stop(ALL);
  delay(ALLDE);
}

void fwUntilSw() {
  compass_set_heading();
  
  fw2(50, 50);
  while (in(17) == 1 || in(18) == 1){
    int hd;
    if(ISCOM) hd = compass_read_heading();
    else hd = 0;
    if(in(17)==1&&in(18)==1){
      if(hd>0) fw2(40,45);
      else if(hd<0) fw2(45,40);
      else fw2(40, 40); 
    }else if(in(17)==0){
      fw2(45,-30); 
    }else{
      fw2(-30,45);
    }
  }
  fw2(30, 30);
  delay(100);
  bw2(-95, -95);
  delay(20);
  motor_stop(ALL);
  delay(ALLDE);
  fw2(20, 20);
  delay(800);
  motor_stop(ALL);
}

void bwUntilSw() {
  compass_set_heading();
  
  bw2(-50, -50);
  while (in(19) == 1 || in(30) == 1){
    int hd;
    if(ISCOM) hd = compass_read_heading();
    else hd = 0;
    if(in(19)==1&&in(30)==1){
      if(hd>0) bw2(-45,-40);
      else if(hd<0) bw2(-40,-45);
      else bw2(-40, -40); 
    }else if(in(19)==0){
      bw2(-45,25); 
    }else{
      bw2(25,-45);
    }
  }
  bw2(-30, -30);
  delay(100);
  fw2(95, 95);
  delay(20);
  motor_stop(ALL);
  delay(ALLDE);
  bw2(-20, -20);
  delay(800);
  motor_stop(ALL);
}

int readBarcode(){
  int tlist[20];
  bool isW[20];
  int li;
  bw2(-25,-25);
  delay(500);
  fw2(15,15);
  int i;
  while(analog(0)<REF);
  unsigned long st = millis();
  delay(5);
  for(i = 0; i < 100; i++){
    li = 0;
    isW[i] = analog(0)>=REF;
    while(millis()-st<600||isW[i]){
      if(analog(0)<REF){
        if(li==2){
          break;
        }
        li = 1;
      }else{
        if(li==1){
          break;
        }
        li = 2;
      }
    }
    if(millis()-st>=600&&!isW[i]) break;
    tlist[i] = millis()-st;
    st = millis();
    delay(5);
  }
//  for(int j = 0; j < i; j++){
//    glcd(j,0,"%d  ", tlist[j]);
//  }
//  motor_stop(ALL);
//  while(1);
    switch(i){
      case 1: return 0;
      case 3: 
        if(tlist[0]<350) return 1;  
        else if(tlist[0]<800) return 2;
        else return 4;
      case 5:
        if(tlist[0]>350) return 6;
        else if(tlist[2]>350) return 5;
        else return 3;
      case 7: return 7;
    }
}

int i;
bool trackL() {
  if(analog(1) > REF && analog(4) > REF){
    return false;
  }else if (analog(1) > REF) {
    fw2(-20, 45);
    i = 3;
  } else if (analog(4) > REF) {
    fw2(45, -20);
    i = 4;
  } else if (analog(2) > REF && analog(3) > REF) {
    fw2(45, 45);
    i = 5;
  } else if (analog(2) <= REF && analog(3) > REF) {
    fw2(45, 20);
    i = 1;
  } else if (analog(2) > REF && analog(3) <= REF) {
    fw2(20, 45);
    i = 2;
  }else{
    switch (i) {
      case 1: fw2(40, -10); break;
      case 2: fw2(-10, 40); break;
      case 3: fw2(-45, 45); break;
      case 4: fw2(45, -45); break;
      default: fw2(45, 45); break;
    }
  }
  return true;
}

bool trackR() {
  if(analog(1) > REF && analog(4) > REF){
    return false;
  }else if (analog(4) > REF) {
    fw2(45, -20);
    i = 4;
  } else if (analog(1) > REF) {
    fw2(-20, 45);
    i = 3;
  } else if (analog(2) > REF && analog(3) > REF) {
    fw2(45, 45);
    i = 5;
  } else if (analog(2) <= REF && analog(3) > REF) {
    fw2(45, 20);
    i = 1;
  } else if (analog(2) > REF && analog(3) <= REF) {
    fw2(20, 45);
    i = 2;
  }else{
    switch (i) {
      case 1: fw2(40, -10); break;
      case 2: fw2(-10, 40); break;
      case 3: fw2(-45, 45); break;
      case 4: fw2(45, -45); break;
      default: fw2(45, 45); break;
    }
  }
  return true;
}

void trackT(int t) {
  i = 0;
  unsigned long st = millis();
  while(millis() - st < t) trackL();
}
void trackTR(int t) {
  i = 0;
  unsigned long st = millis();
  while(millis() - st < t) trackR();
}

void trackI(){
  i = 0;
  while(trackL()); 
}

void turnCompess(int deg){
  int cdeg = compass_read();
  int diff1,diff2,sp=45;
  unsigned long st = millis();
  while(millis() - st < 3000){
    cdeg = compass_read();
    if(deg >= cdeg){
      diff1 = deg-cdeg;
      diff2 = cdeg+360-deg;
    }else{
      diff1 = deg+360-cdeg;
      diff2 = cdeg-deg;
    }
    
    if(diff1<diff2){
      //cw
      // speed will vary from 10 to 50
      sp = diff1*40/180+10;
      tu2(sp,-sp);
    }else if(diff1>diff2){
      //ccw
      sp = diff2*30/180+15;
      tu2(-sp,sp);
    }else motor_stop(ALL);
  }
}

void getEgg1(){
  //fwt(400,40,50);
  //fwt(400,50,40);
  //get 1
  fwUntilSw();
  bwt(675,-55,-60);
  turnL90();
  bwUntilSw();
  fwt(1000);
  turnL90();
  //get 2
  fwUntilSw();
  bwUntilSw();
  fwt(500);
  turnL90();
  fwUntilSw();
  //out of 2 , to 3
  bwUntilSw();
  fwt(200);
  turnL90();
  fwUntilSw();
  bwt(200);
  turnL90();
  //get 3
  bwUntilSw();
  fwUntilSw();
  
  //bwt
  bwt(100,-46,-50);
  bwUntilSw();
  fwt(150);
  turnL90();
  fwUntilSw();
  bwt(150);
  turnL90();
  fwt(450);
  turnL90();
  fwUntilSw();
  // to second
  bwUntilSw();
  fwt(20);
  turnL90();
  bwUntilSw();
  fwt(2100,40,42);
  turnL90();
  fwUntilSw();
  //get 4
  bwUntilSw();
  fwUntilSw();
  bwt(150);
  turnL90();
  bwUntilSw();
  fwt(100);
  turnL90();
  //get 5
  bwUntilSw();
  fwUntilSw();
  turnL90();
  bwt(1500,40,40);
  turnL90();
  //getout
  fwt(2000);
}

void getEgg2(){
  fwUntilSw();
  bwt(20);
  turnL90();
  fwUntilSw();
  bwt(20);
  turnL90();
  //get 5
  fwUntilSw();
  bwUntilSw();
  fwt(10);
  turnL90();
  fwt(600);
  turnL90();
  bwUntilSw();
  //get 4
  fwUntilSw();
  bwUntilSw();
  fwt(20);
  turnL90();
  bwUntilSw();
  fwt(20);
  turnL90();
  fwUntilSw();
  //to section 1
  bwUntilSw();
  fwt(20);
  turnL90();
  bwUntilSw();
  fwt(20);
  turnL90();
  bwUntilSw();
  fwUntilSw();
  bwt(40);
  turnL90();
  bwUntilSw();
  //get 3
  fwUntilSw();
  bwUntilSw();
  fwt(20);
  turnL90();
  fwUntilSw();
  bwt(20);
  turnL90();
  bwUntilSw();
  fwUntilSw();
  bwt(20);
  turnL90();
  //get 2
  fwUntilSw();
  bwUntilSw();
  fwt(20);
  turnL90();
  bwUntilSw();
  fwt(20);
  turnL90();
  //get 1
  bwUntilSw();
  fwt(2000);
}

void moveTo(int num){
  switch(num){
    case 1: turnCompess(0);
    case 2: turnCompess(90);
    case 3: turnCompess(180);
    case 4: turnCompess(270);
  }
  fwt(400);
  //fan
  //out();
  delay(2000);
  while(analog(2)<REF) bw2(-50,-50);
  fw2(50,50);
  delay(10);
  motor_stop(ALL);
} 

void doFire(){
  turnCompess(177);
  int b = readBarcode();
  //display
  //glcd(1,0,"%d  ",b);
  
  while(analog(2)<REF) fw2(40,40);
  bw2(-50,-50);
  delay(10);
  motor_stop(ALL);
  
  switch(b){
    case 2:
      glcd(0,0,"1,2 ");
      LED8(0b00000011);
      break;
    case 3:
      glcd(0,0,"1,3 ");
      LED8(0b00000101);
      break;
    case 4:
      glcd(0,0,"1,4 ");
      LED8(0b00001001);
      break;
    case 5:
      glcd(0,0,"2,3 ");
      LED8(0b00000110);
      break;
    case 6:
      glcd(0,0,"2,4 ");
      LED8(0b00001010);
      break;
    case 7:
      glcd(0,0,"3,4 ");
      LED8(0b00001100);
      break;
    default:  
      glcd(0,0,"error");
      LED8(0b11111111);
      break;
  }
  turnCompess(272);
  fwt(1000);
}

void testTurn(){
  int v;
  while(in(19)==1){
    v = knob(500)+100;
    glcd(0,0,"%d  ", v);
  }
  time = v;
  turnL90();
}

void setup() {
  OK();
  //pinSegment(16);
  glcdClear();
  glcdMode(0);
  setTextSize(2);
  pinLED8(16);
  compass_writeConfig(-496,594,-749,435);
  compass_enableAutoTuning();
  compass_read();
//  while(1){
//    glcd(0,0,"%d  ", compass_read()); 
//  }
}

void loop() {
  //trackT(20000);
//  glcd(0,0,"%d  ", analog(1));
//  glcd(1,0,"%d  ", analog(2));
//  glcd(2,0,"%d  ", analog(3));
//  glcd(3,0,"%d  ", analog(4));
//    glcd(4,0,"%d ", analog(0));
  //fwt(20000);
  //testTurn();
  
  trackI();
  int b = readBarcode();
  trackI();
  if(1){
    // get egg first
    //fwt(20);
    fw2(40,-40);
    delay(220);
    trackT(13000);
    turnCompess(275);
    getEgg1();
    
  }else{
    //fan first
    //fwt(20);
    fw2(-40,40);
    delay(220);
    trackTR(1000);
    trackI();
    doFire();
    
  }
  motor_stop(ALL);
  sw_OK_press();
  glcdClear();
}
