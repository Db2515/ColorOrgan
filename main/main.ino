//Assign the pins names
int analogPin = 0;
int strobePin = 2;
int resetPin = 3;

void setup() {
  //Open serial communication
  Serial.begin(9600);
  
  //Set the pin modes
  pinMode(analogPin, INPUT);
  pinMode(strobePin, OUTPUT);
  pinMode(resetPin, 3);
  analogReference(DEFAULT);
  
  //Set the equaliser to the first band
  digitalWrite(resetPin, LOW);
  digitalWrite(strobePin, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:

}
