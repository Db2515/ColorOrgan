//Assign the pins names
int analogPin = 0;
int strobePin = 2;
int resetPin = 3;
int lowPin = 9;
int midPin = 10;
int highPin = 11; 

int lowFilter = 100;

void setup() {
  //Open serial communication
  Serial.begin(9600);
  
  //Set the pin modes
  pinMode(analogPin, INPUT_PULLUP);
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
  
  //Strobe to Strobe delay
  delayMicroseconds(72);
  
  int fallingEdgeTime = 0;
  
  for(int i = 0; i < 7; i++){
    //Change frequency band
    digitalWrite(strobePin, LOW);
    fallingEdgeTime = micros();
    //Store the "volume" of the frequency
    frequencyVolume[i] = map(constrain(analogRead(analogPin), lowFilter, 1023),
                              lowFilter, 1023, 0, 255);
    int averageVolume;
    
    //Print the value for dubugging
    Serial.print(" ");
    Serial.print(frequencyVolume[i]);
    
    switch(i){
       case 1:
         //Light the "low frequency" LED to the "frequencyVolume"
         averageVolume = (frequencyVolume[0]);
         analogWrite(lowPin, averageVolume);
         break;
       case 4:
         averageVolume = (frequencyVolume[2] + frequencyVolume[3]) / 2;
         analogWrite(midPin, averageVolume);
         break;
       case 6:
         averageVolume = (frequencyVolume[4] + frequencyVolume[5]) / 2;
         analogWrite(highPin, averageVolume);
         break;
    }
    
   
    
    //Move to the next band of frequencies
    delayMicroseconds(40);
    digitalWrite(strobePin, HIGH);
      
  }
  
  Serial.println("\n");

}
