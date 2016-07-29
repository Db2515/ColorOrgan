//Assign the pins names
int analogPin = 0;
int strobePin = 2;
int resetPin = 3;
int lowPin = 9;
int midPin = 10;
int highPin = 11; 

void setup() {
  //Open serial communication
  Serial.begin(9600);
  
  //Set the pin modes
  pinMode(analogPin, INPUT);
  pinMode(strobePin, OUTPUT);
  pinMode(resetPin, 3);
  pinMode(lowPin, OUTPUT);
  pinMode(midPin, OUTPUT);
  pinMode(highPin, OUTPUT);
  analogReference(DEFAULT);
  
  //Ready the equaliser for use
  digitalWrite(resetPin, LOW);
  digitalWrite(strobePin, HIGH);

}

void loop() {
 //Reset the equaliser to the first band
  digitalWrite(resetPin, HIGH);
  digitalWrite(resetPin, LOW);
  
  int frequencyVolume[7];
  
  for(int i = 0; i < 7; i++){
    //Change frequency band
    digitalWrite(strobePin, LOW);
    delayMicroseconds(150);
    //Store the "volume" of the frequency
    frequencyVolume[i] = analogRead(analogPin);
    int averageVolume;
    
    //TODO: Implement averages
    switch(i){
       case 1:
         //Light the "low frequency" LED to the "frequencyVolume"
         averageVolume = (frequencyVolume[0]);
         analogWrite(lowPin, averageVolume);
         break;
       case 4:
         averageVolume = (frequencyVolume[1] + frequencyVolume[2] + frequencyVolume[3]) / 3;
         analogWrite(midPin, averageVolume);
         break;
       case 6:
         averageVolume = (frequencyVolume[4] + frequencyVolume[5]) / 2;
         analogWrite(highPin, averageVolume);
         break;
    }
    
    //Print the value for dubugging
    Serial.print(" ");
    Serial.print(frequencyVolume[i]);
    
    //Move to the next band of frequencies
    digitalWrite(strobePin, HIGH);
      
  }
  
  Serial.println("\n");

}
