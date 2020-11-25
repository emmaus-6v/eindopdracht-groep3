#include <Servo.h>

int i = 0;

Servo servo_10;
Servo servo_11;

void setup() {
  // stel ledpin in als output:
  pinMode(ledPin, OUTPUT);

  pinMode(7, INPUT);
  servo_10.attach(10);

  pinMode(4, INPUT);
  servo_11.attach(11);
}

void loop() {
  
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
//hola
