#include <Servo.h>
Servo myservo1; //  thruster 1 right
Servo myservo2; //  thruster 2 left
Servo myservo3; //  thruster 3 right
Servo myservo4; //  thruster 4 left
#define thraster1 9
#define thraster2 10
#define thraster3 11
#define thraster4 6  
#define SPEED1 1590 
#define SPEED2 1630
#define SPEED3 1700 
#define SPEED4 1820 
#define SPEED1F 1400
#define SPEED2F 1370
#define SPEED3F 1200
#define SPEED1L 1560
#define SPEED2L 1610
#define SPEED3L 1710
#define SPEED1Lx 1420
#define SPEED2Lx 1350
#define SPEED3Lx 1210

char val ; 
void fr_fastx();
void fr_fast();
void fr_low();
void fr_midlle();
void back_fastx();
void back_low();
void back_midll();
void up_fast();
void up_low();
void up_midll();
void up_fastx();
void down_fast();
void down_midll();
void down_low();
void lateral_left_fast();
void lateral_left_midll();
void lateral_left_low();
void lateral_right_fast();
void lateral_right_midll();
void lateral_right_low();
void rotat_right_fast();
void rotat_right_midll();
void rotat_right_low();
void rotat_left_fast();
void rotat_left_midll();
void rotat_left_low();

void setup() {
myservo1.attach(thraster1);   //pin thruster1 
myservo2.attach(thraster2);  //pin thruster2  
myservo3.attach(thraster3);  //pin thruster3 
myservo4.attach(thraster4);   
  Serial.begin(9600);
}

void loop() {
     val=Serial.read();
      switch(val)
      {
           case'a':
           Serial.println("ya sayee3");
           break;
      }
  
}
void fr_low()
{
 myservo1.writeMicroseconds(SPEED1);
 myservo2.writeMicroseconds(SPEED1);
}
void fr_fastx()
{
 myservo1.writeMicroseconds(SPEED4);
 myservo2.writeMicroseconds(SPEED4); 
}
void fr_midll()
{
 myservo1.writeMicroseconds(SPEED2);
 myservo2.writeMicroseconds(SPEED2); 
}
 void fr_fast()
 {
  myservo1.writeMicroseconds(SPEED3);
 myservo2.writeMicroseconds(SPEED3); 
 }
void back_fast()
{
 myservo1.writeMicroseconds( SPEED3F);
 myservo2.writeMicroseconds( SPEED3F);
}
void back_low()
{
 myservo1.writeMicroseconds( SPEED1F);
 myservo2.writeMicroseconds( SPEED1F);
}
void back_midll()
{
  myservo1.writeMicroseconds(SPEED2F);
 myservo2.writeMicroseconds(SPEED2F);
}
void up_fastx()
{
 myservo3.writeMicroseconds(SPEED4);
 myservo4.writeMicroseconds(SPEED4);
}
void up_low()
{
  myservo3.writeMicroseconds(SPEED1);
 myservo4.writeMicroseconds(SPEED1); 
}
void up_midll()
{
  myservo3.writeMicroseconds(SPEED2);
 myservo4.writeMicroseconds(SPEED2); 
}
void up_fast()
{
  myservo3.writeMicroseconds(SPEED3);
 myservo4.writeMicroseconds(SPEED3); 
}
void down_fast()
{
   myservo3.writeMicroseconds( SPEED3F);
 myservo4.writeMicroseconds( SPEED3F);
}
void down_midll()
{
  myservo3.writeMicroseconds(SPEED2F);
 myservo4.writeMicroseconds(SPEED2F); 
}
void down_low()
{
 myservo3.writeMicroseconds(SPEED1F);
 myservo4.writeMicroseconds(SPEED1F);
}
void lateral_left_fast()
{
  myservo3.writeMicroseconds(SPEED3L);
 myservo4.writeMicroseconds(SPEED3Lx); 
}
void lateral_left_midll()
{
  myservo3.writeMicroseconds(SPEED2L);
 myservo4.writeMicroseconds(SPEED2Lx); 
}
void lateral_left_low()
{
  myservo3.writeMicroseconds(SPEED1L);
 myservo4.writeMicroseconds(SPEED1Lx); 
}
void lateral_right_fast()
{
   myservo3.writeMicroseconds(SPEED3Lx);
 myservo4.writeMicroseconds(SPEED3L); 
}
void lateral_right_midll()
{
   myservo3.writeMicroseconds(SPEED2Lx);
 myservo4.writeMicroseconds(SPEED2L); 
}
void lateral_right_low()
{
   myservo3.writeMicroseconds(SPEED1Lx);
 myservo4.writeMicroseconds(SPEED1L); 
}
void rotat_right_fast()
{
 myservo1.writeMicroseconds(SPEED3Lx);
 myservo2.writeMicroseconds(SPEED3L); 
}
void rotat_right_midll()
{  
 myservo1.writeMicroseconds(SPEED2Lx);
 myservo2.writeMicroseconds(SPEED2L); 
}
void rotat_right_low()
{
 myservo1.writeMicroseconds(SPEED1Lx);
 myservo2.writeMicroseconds(SPEED1L); 
}
void rotat_left_fast()
{
  myservo1.writeMicroseconds(SPEED3L);
 myservo2.writeMicroseconds(SPEED3Lx);
}
void rotat_left_midll()
{
  myservo1.writeMicroseconds(SPEED2L);
 myservo2.writeMicroseconds(SPEED2Lx); 
}
void rotat_left_low()
{ 
 myservo1.writeMicroseconds(SPEED1L);
 myservo2.writeMicroseconds(SPEED1Lx); 
}

