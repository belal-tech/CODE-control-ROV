#include <Servo.h>
#define pinx A0
#define piny A1
int val1,val2;
int sw;
Servo myservo1; //  thruster 1
Servo myservo2; //  thruster 2
Servo myservo3; //  thruster 3
Servo myservo4; //  thruster 4                                 //declaration :)
void setup() {
pinMode(pinx,INPUT);// for x position
pinMode(piny,INPUT); // for y position 
myservo1.attach(9);   //pin thruster1 
myservo2.attach(10);  //pin thruster2  
myservo3.attach(11);  //pin thruster3 
myservo4.attach(6);   //pin thruster4 
Serial.begin(9600);   
}

void loop() {
val1=analogRead(pinx);// pin for y 
                                                        //calebrationnnnnnnnnnnnnnnnnnnnnnnnnn side 
val2=analogRead(piny); // pin for x                                                                                  
sw=digitalRead(7);
if((val1>=0)&&(val1<10)) //condition if the joystic UP "calebrtion"
{ 
   myservo1.writeMicroseconds(1500);
   myservo2.writeMicroseconds(1500);
   
}
else if((val1>=670)&&(val1<=685)) //condition if the joystic down "calebration"
{ 
   myservo1.writeMicroseconds(1100);
   myservo2.writeMicroseconds(1100);
}
else if ((val2>=0)&&(val2<10))
{
  myservo3.writeMicroseconds(1500);
   myservo4.writeMicroseconds(1500); 
}
else if ((val2>=670)&&(val2<685))
{
 myservo3.writeMicroseconds(1100);
  myservo4.writeMicroseconds(1100);  
}

/*
Serial.println("val2=");
Serial.println(val2);
delay(1000);
Serial.println("\n val1");
Serial.println(val1);
delay(1000);
Serial.println("\n swich=");                                           for calebrations "monitor"
Serial.println(sw);
delay(500);
 myservo1.writeMicroseconds(1500);
 */
}
