void setup() {
}

void loop() {
  for(int i=50;i<255;i+=5)
  {
    analogWrite(10,i);
    delay(200);
  }
  
}

