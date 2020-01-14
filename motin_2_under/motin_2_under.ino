#include <Servo.h>
#include <Wire.h>
#include "MS5837.h"
MS5837 sensor;
Servo myservo1; //  thruster 1 right
Servo myservo2; //  thruster 2 left
Servo myservo3; //  thruster 3 right
Servo myservo4; //  thruster 4 left
#define rainSensor  A0
#define sensortrigger  600
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
#define mot1 1
#define mot2 2
#define DCV1 3
#define DCV2 4
#define led1 13
#define led2 12
int val,x,y;
void setup() {
myservo1.attach(thraster1);   //pin thruster1 
myservo2.attach(thraster2);  //pin thruster2  
myservo3.attach(thraster3);  //pin thruster3 
myservo4.attach(thraster4); //thrusters 4 
 pinMode(mot1,OUTPUT);
  pinMode(mot2,OUTPUT);
  pinMode(DCV1,OUTPUT);
  pinMode(DCV2,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(mot1,OUTPUT);
  pinMode(mot2,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(rainSensor, INPUT);
   Serial.begin(9600);
  
  Serial.println("Starting");
  
  Wire.begin();

  sensor.init();
  
  sensor.setFluidDensity(997);

  establish();
  
}

void loop() {
  if(Serial.available()>=1)
  {
     val=Serial.read();
      switch(val)
      {
           case'B':
          fr_low();
           break;
           case'E':
           fr_fastx();
           break;
           case'C':
           fr_midll();
           break;
           case'd':
           fr_fast();
           break;
           case'H':
           back_fast();
           break;
           case'F':
           back_low();
           break;
           case'G':
           back_midll();
           break;
           case'X':
           up_fastx();
           break;
           case'U':
           up_low();
           break;
           case'V':
           up_midll();
           break;
           case'W':
           up_fast();
           break;
           case 1:
           down_fast();
           break;
           case'Z':
           down_midll();
           break;
           case'Y':
           down_low();
           break;
           case'K':
           lateral_left_fast();
           break;
           case'J':
           lateral_left_midll();
           break;
           case'I':
           lateral_left_low();
           break;
           case'N':
           lateral_right_fast();
           break;
           case'M':
           lateral_right_midll();
           break;
           case'L':
           lateral_right_low();
           break;
           case'Q':
           rotat_right_fast();
           break;
           case'P':
           rotat_right_midll();
           break;
           case'O':
           rotat_right_low();
           break;
           case'T':
           rotat_left_fast();
           break;
           case'S':
           rotat_left_midll();
           break;
           case'R':
           rotat_left_low();
           break; 
           case 2:
            dcv1();
           break;
           case 4:
           dcv2();
           break;
           case 8:
           led1_on();
           break;
           case 9:
           led1_of();
           break;
           case 6:
           led2_on();
           break;
           case 7:
           led2_of();
           break;
           case 5:
           bledg_right();
           break;
           case 3:
           bledg_left();
           break;
           
      }
      //leakage_sensor();
      depth_sensor();
    
  }
  Serial.println(val);
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
void bledg_right()
{
  digitalWrite(mot1,HIGH);
  digitalWrite(mot2,LOW);
}
void bledg_left()
{
  digitalWrite(mot1,LOW);
  digitalWrite(mot2,HIGH);
}
void dcv1()
{
  x++;
      digitalWrite(DCV1,0);
      digitalWrite(7,1);
   
    if(x%2==0)
    {
      digitalWrite(DCV1,1);
       digitalWrite(7,0);
    }
}
void dcv2()
{
  y++;
    digitalWrite(DCV2,HIGH);
   if(y%2==0)
    {
     digitalWrite(DCV2,LOW);
     }
}
void led1_on()
{
  digitalWrite(led1,HIGH);
}
void led1_of()
{
  digitalWrite(led1,LOW);
}
void led2_on()
{
  digitalWrite(led2,HIGH);
}
void led2_of()
{
  digitalWrite(led2,LOW);
}
void establish()
{
  while(Serial.available()<=0)
  {
    Serial.println("A");
    delay(50);
  }
  
}
void depth_sensor()
{
  Serial.print("Pressure: "); 
  Serial.print(sensor.pressure()); 
  Serial.println(" mbar");
  Serial.print("Temperature: "); 
  Serial.println(" deg C");
  Serial.print("Depth: "); 
  Serial.print(sensor.depth()); 
  Serial.println(" m");
  Serial.print("Altitude: "); 
  Serial.print(sensor.altitude()); 
  Serial.println(" m above mean sea level");
  delay(1000);
}
/*
void leakage_sensor()
{
   int sensorVal = analogRead(rainSensor);
  Serial.println(sensorVal);
  if(sensorVal < sensortrigger){
    Serial.println("Water Detected!");
  }
  else {
    Serial.println("No Water Detected!");
  }
  delay(750);                            
}
*/
