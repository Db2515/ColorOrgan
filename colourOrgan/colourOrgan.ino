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
  
  //Ready the equaliser for use
  digitalWrite(resetPin, LOW);
  digitalWrite(strobePin, HIGH);

}

void loop() {
  int spectrumVolume[7];
 //Reset the equaliser to the first band
  digitalWrite(resetPin, HIGH);
  digitalWrite(resetPin, LOW);
  
  for(int i = 0; i < 7; i++){
    //Change frequency band
    digitalWrite(strobePin, LOW);
    delayMicroseconds(30);
    //Store the "volume" of the frequency
    spectrumVolume[i] = analogRead(analogPin);
    
    //Print the value for dubugging
    Serial.print(" ");
    Serial.print(spectrumVolume[i]);
    
    //Move to the next band of frequencies
    digitalWrite(strobePin, HIGH);
      
  }
  
  Serial.println("\n");

}
