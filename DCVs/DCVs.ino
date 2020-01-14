#define DCV1 1
#define DCV2 2
 char val;
 int x,y ;
void setup() {
  
}

void loop() {
  
  val=Serial.read();
  
  /*
 if(val=='n')
  {
    digitalWrite(DCV1,HIGH);  
  }
  else if(val=='y')
  {
  digitalWrite(DCV1,LOW);
  }
   else if(val=='x')
   {
   digitalWrite(DCV2,HIGH); 
   }
    else if(val=='z')
    {
    digitalWrite(DCV2,LOW);
  }
  */
    if(val=='a'){
      x++;
      digitalWrite(DCV1,HIGH);
    
    if(x%2==0)
    {
      digitalWrite(DCV1,LOW);
    }
    }
    else if(val=='b'){
     y++;
    digitalWrite(DCV2,HIGH);
    
   if(y%2==0)
    {
     digitalWrite(DCV2,LOW);
    }
    }
    
}
    
    

