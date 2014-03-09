// Project 5 - LED Chase Effect
// Adapted for Hackacademy
byte ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};   // Create array for LED pins
int ledDelay = 500;  // delay between changes
int direction = 1;
int ledStep =5;
int currentLED = 0;
unsigned long changeTime;

void setup() {
  	for (int x=0; x<10; x++) {     // set all pins to output
    		pinMode(ledPin[x], OUTPUT); }
 	changeTime = millis();
 Serial.begin(112800);
}

void loop() {
            
  	if ((millis() - changeTime) > ledDelay) {      // if it has been ledDelay ms since last change
    		changeLED();
    		changeTime = millis();
  	}
}

void changeLED() {
//  Serial.print("pin=");Serial.print(currentLED);Serial.print(" direction=");Serial.println(direction <0 ? "backwards": "forwards");
//  	for (int x=0; x<10; x++) {        	// turn off all LED's
//   		 digitalWrite(ledPin[x], LOW);
//  	}
        if( direction == 1 ) {
        	digitalWrite(ledPin[currentLED], HIGH); 	// turn on the current LED
        Serial.print("TURN ON=");Serial.println(currentLED);
        } else {
          digitalWrite(ledPin[currentLED],LOW ); 
          Serial.print("TURN OFF=");Serial.println(currentLED);
        } 
//        currentLED=random(10);
//        ledDelay=random(10,1000);
	currentLED += direction; 	// increment by the direction value
 	// Uncomment the next two lines to change direction if we reach the end
  	if (currentLED == 9) {direction = -1;}
  	if (currentLED == 0) {direction = 1;}
           // The following line restarts sequence when we reach the end - comment out
           // to show “bounce” effect
//            if (currentLED > 9) { currentLED = 0; }
        ledDelay -= ledStep;
//        if(ledDelay <= 0 || ledDelay >= 500) {
//          ledStep = -ledStep;
//        }
//         Serial.print("ledDelay=");Serial.print(ledDelay);Serial.print(" ledStep=");Serial.println(ledStep);
}

