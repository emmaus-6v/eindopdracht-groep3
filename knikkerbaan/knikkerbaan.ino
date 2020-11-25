#include <Servo.h>

const int ledPin =  LED_BUILTIN;

int i = 0;

// globale variabelen
int ledState = LOW;               // status van de LED

Servo servo_10;

Servo servo_11;


unsigned long millisVorigeVerandering = 0; // bewaard tijd van laatste LED-verandering

// andere constanten
const long interval = 1000;           // interval in milliseconden

void setup() {
  // stel ledpin in als output:
  pinMode(ledPin, OUTPUT);

  pinMode(7, INPUT);
  servo_10.attach(10);

  pinMode(4, INPUT);
  servo_11.attach(11);
<<<<<<< HEAD

=======
>>>>>>> 233906f5f37d28b0780d7ef392387b274b4e1f8c
}

void loop() {
  // tijd van nu
  unsigned long millisNu = millis();

  // is de verstreken tijd sinds de laatste verandering langer dan de interval?
  if (millisNu - millisVorigeVerandering >= interval) {    
    // bewaar tijdstip van de verandering die we hierna gaan doen
    millisVorigeVerandering = millisNu;
  }
    // zet de status van de LED om
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

        if (digitalRead(7) == HIGH) {
            servo_10.write(90);
          }
          if (digitalRead(7) == LOW) {
            servo_10.write(0);
          }

          if (digitalRead(4) == HIGH) {
            servo_11.write(90);
          }
          if (digitalRead(4) == LOW) {
            servo_11.write(0);
          }
          delay(10); //Voor simulatie verbeteren 
    // geef de pin de waarde van de status
    digitalWrite(ledPin, ledState);

   if (digitalRead(7) == HIGH) {
    servo_10.write(90);
   }
   if (digitalRead(7) == LOW) {
    servo_10.write(0);
   }

   if (digitalRead(4) == HIGH) {
    servo_11.write(90);
   }
   if (digitalRead(4) == LOW) {
    servo_11.write(0);
   }
   delay(10); //Voor simulatie verbeteren 

  
}


//hoii
