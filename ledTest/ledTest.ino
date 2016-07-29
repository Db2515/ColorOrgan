void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  analogReference(DEFAULT);

}

void loop() {
  for(int i = 0; i <= 250; i += 25){
     analogWrite(9, i);
     delay(500);
     analogWrite(9, 0);
     
     analogWrite(10, i);
     delay(500);
     analogWrite(10, 0);
     
     analogWrite(11, i);
     delay(500);
     //analogWrite(9, 0);
     //analogWrite(10, 0);
     analogWrite(11, 0);
  } 

}
