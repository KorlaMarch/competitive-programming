#include <IRremote.h>
#include <ipst.h>

#define POW_MIX 20
#define POW_PUMP 100

#define KEY_POWER 2704
#define KEY_ENTER 2672
#define KEY_FORWARD 752
#define KEY_RIGHT 3280
#define KEY_LEFT 720
#define KEY_1 16
#define KEY_2 2064

//0 = off
//1 = right
//2 = left
//3 = both
char es,pump,mixer;
IRrecv irrecv(25);
decode_results results;

void setup()
{
  irrecv.enableIRIn();
  irrecv.blink13(true);
}

void loop()
{
   int i,j; 
   //remote recive
   if(irrecv.decode(&results)) {
    /*glcd(4,1,"%d   ",results.decode_type);
    glcd(2,1,"%d   ", results.value);*/
    i = 1;
    switch(results.value){
      case KEY_POWER:
      case KEY_ENTER:
        es = !es;
        break;
      case KEY_FORWARD:
        if(es) es = 3;
        break;
      case KEY_RIGHT:
        if(es) es = 1;
        break;
      case KEY_LEFT:
        if(es) es = 2;
        break;
      case KEY_1:
        pump = !pump;
        break;
      case KEY_2:
        mixer = !mixer;
        break;
      default:
        i = 0;
    }
      if(i){
        glcd(1,1,"OK    ");
        sound(18,2500,150);
      }else{
        glcd(1,1,"ERROR    ");
        sound(18,500,300);  
      }
      irrecv.resume(); // Receive the next value
  }
  //motor controls
  if(es&1) motor(1,100);
  else motor(1,0);
  
  if(es&2) motor(2,10 0);
  else motor(2,0);
  
  if(pump) out(16,1);
  else out(16,0);
  
  if(mixer) out(17,1);
  else out(17,0);
  
  //sensor
  glcd(3,1,"%d     ", analog(2));
  j = analog(3);
  glcd(4,1,"%d     ", j);
  LED8(19,(1<<((j/64)%9))-1);
  if(analog(2)>=560){
    sound(18,5000,500);
  }
  delay(200);
}
