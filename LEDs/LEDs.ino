#define led1 1
#define led2 2
 char val;
 int x,y ;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  val=Serial.read();
  

    if(val=='c'){
      x++;
      
      if(x%2==1){
      digitalWrite(led1,HIGH);
      }
    
    if(x%2==0)
    {
      digitalWrite(led1,LOW);
    }
    }
    else if(val=='d'){
     y++;
    }
    if(y%2==1)
    {
    digitalWrite(led2,HIGH);
    }
    
    if(y%2==0)
    {
     digitalWrite(led2,LOW);
    }
    }


