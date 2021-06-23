#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK1 2
#define DIO1 3

#define CLK2 4
#define DIO2 5

#define bp1Up 6
#define bp1Down 7

#define bp2Up 8
#define bp2Down 9

// The amount of time (in milliseconds) between tests
#define DELAY   200
int score1;
int score2;

TM1637Display display1(CLK1, DIO1);
TM1637Display display2(CLK2, DIO2);

void setup()
{
   display1.clear();
   display1.setBrightness(0x0f);
   score1 = 0;
   score2 = 0;
   pinMode(bp1Up, INPUT_PULLUP);
   pinMode(bp1Down, INPUT_PULLUP);
   pinMode(bp2Up, INPUT_PULLUP);
   pinMode(bp2Down, INPUT_PULLUP);
}

void loop()
{
  
 if(digitalRead(bp1Up) == LOW){
   display1.clear();
   score1 = score1 + 1;
 } else if(digitalRead(bp1Down) == LOW){
   display1.clear();
   score1 = score1 - 1;
 }
 if(digitalRead(bp2Up) == LOW){
   display2.clear();
   score2 = score2 + 1;
 } else if(digitalRead(bp2Down) == LOW){
   display2.clear();
   score2 = score2 - 1;
 }

  display1.showNumberDec(score1);
  display2.showNumberDec(score2);
  delay(DELAY);



}
