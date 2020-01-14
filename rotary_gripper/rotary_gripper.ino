#define mot1 1
#define mot2 2
int valg;
void setup() {
  pinMode(mot1,OUTPUT);
  pinMode(mot2,OUTPUT);
  Serial.begin(9600);
}

void loop() {
else if(valg=='w')
{
  digitalWrite(mot1,HIGH);
  digitalWrite(mot2,LOW);
}
else if(valg=='v')
{
  digitalWrite(mot1,LOW);
  digitalWrite(mot2,HIGH);
}
}
