// flow meter project
// uses doppler effect and ultrasonic sensor
unsigned long time = 0;

void myISR() {

  switch (digitalRead(3))
  {
    case HIGH:
      time = micros();        
      break; 
    case LOW:
      Serial.println(micros() - time);
      break;
  }
}

void setup() {
  Serial.begin(9600);
  Serial.println("setup");  
  pinMode(8, OUTPUT);
  pinMode(3, INPUT);
  attachInterrupt(digitalPinToInterrupt(3), myISR, CHANGE);
}


// ping triggers on high to low
void loop() {
  digitalWrite(8, HIGH);
  delayMicroseconds(50);
  digitalWrite(8, LOW);
  delay(100);
}

