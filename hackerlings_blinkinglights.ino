// Project 5 - LED Chase Effect
// Adapted for Hackacademy
byte ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};   // Create array for LED pins
int maxLedDelay = 250;
int ledDelay = maxLedDelay;  // delay between changes
int direction = 1;
int ledStep =5;
int currentLED = 0;
unsigned long changeTime;

void setup() {
  for (int x=0; x<10; x++) {   // set all pins to output
    pinMode(ledPin[x], OUTPUT);
  }
  changeTime = millis();
  Serial.begin(112800);
}

void loop() {
  if ((millis() - changeTime) > ledDelay) {    // if it has been ledDelay ms since last change
    changeLED();
    changeTime = millis();  
  }
}

void turnAll(int setting){
    Serial.println(">>TURNING");
    for (int x=0; x<10; x++) {      // turn off all LED's
      digitalWrite(ledPin[x], setting);
    }
}

void debugOutput() {
  Serial.print("currentLED=");Serial.print(currentLED);Serial.print(" direction=");Serial.print(direction);Serial.print(" ledDelay=");Serial.print(ledDelay);
  Serial.println();
}
void changeLED() {
//  Serial.print("pin=");Serial.print(currentLED);Serial.print(" direction=");Serial.println(direction <0 ? "backwards": "forwards");

    if( direction == 1 ) {
      digitalWrite(ledPin[currentLED], HIGH);   // turn on the current LED
      Serial.print("TURN ON=");debugOutput();
    } else {
      digitalWrite(ledPin[currentLED],LOW ); 
      Serial.print("TURN OFF=");debugOutput();
    } 
//    currentLED=random(10);
//    ledDelay=random(10,1000);
   // Uncomment the next two lines to change direction if we reach the end
    if (currentLED == 9 && direction == 1) {
      direction = -1;
    } else if (currentLED == 0 && direction == -1) {
      direction = 1;
    } else {
      currentLED += direction;   // increment by the direction value
    }
       // The following line restarts sequence when we reach the end - comment out
       // to show “bounce” effect
//      if (currentLED > 9) { currentLED = 0; }
    ledDelay -= ledStep;
    if(ledDelay <= 0 || ledDelay >= maxLedDelay) {
      ledStep = -ledStep;
    }
    if(ledDelay<= 0) {
      for(int flashes = 0; flashes <5; flashes++){
        turnAll(LOW);
        delay(110);
        turnAll(HIGH);
        delay(110);
      }
    }
}

