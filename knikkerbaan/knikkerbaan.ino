#include <Servo.h>

int i = 0;

Servo servo_10;
Servo servo_11;

void setup() {

  pinMode(7, INPUT);
  servo_10.attach(10);

  pinMode(4, INPUT);
  servo_11.attach(11);
}

void loop() {
<<<<<<< HEAD
  // tijd van nu
  unsigned long millisNu = millis();

  // is de verstreken tijd sinds de laatste verandering langer dan de interval?
  if (millisNu - millisVorigeVerandering >= interval) {    
    // bewaar tijdstip van de verandering die we hierna gaan doen
    millisVorigeVerandering = millisNu;

    // zet de status van de LED om
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

     digitalWrite(ledPin, ledState);

        if (digitalRead(7) == HIGH) {
    servo_10.write(90);
  } else {
    servo_10.write(0);
  }
  if (digitalRead(4) == HIGH) {
    servo_11.write(90);
  } else {
    servo_11.write(0);
  }
  delay(10); //Voor simulatie verbeteren 
    // geef de pin de waarde van de status
   
}



