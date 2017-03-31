
int waitTime = 2;


void setup() {
  // put your setup code here, to run once:
  pinMode (12, INPUT_PULLUP);
  pinMode (2, OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:

  int timeSec = 0;
  while (digitalRead(12) == HIGH){
    delay(1000);
    timeSec++;

    if (timeSec > waitTime){
      //alarm(on);
      digitalWrite(2,HIGH); 
      while(digitalRead(12) == HIGH){
        digitalWrite(2,HIGH);
        delay(1000);
        digitalWrite(2,LOW);
        delay(2000);
      }
    }
    
  }
  //alarm(off);
  digitalWrite(2,LOW);
  timeSec = 0;






/*
  if (digitalRead(12) == LOW){
   digitalWrite(2,HIGH);
    
  }

  digitalWrite(2,LOW);
  
  */
  
}
