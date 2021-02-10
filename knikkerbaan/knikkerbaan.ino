#include <Servo.h>

const unsigned long moveSensorInterval =  random(3000, 6000 + 1);
unsigned long previousTime = 0;

int i = 0;

const int pinServo10 = 7;
const int pinServo11 = 4;
// const int pinMarbleCount = A1;

int marbleCount = 0; 

Servo servo_10;
Servo servo_11;

void setup() {

  Serial.begin(9600);

  pinMode(pinServo10, INPUT);
  servo_10.attach(10);

  pinMode(pinServo11, INPUT);
  servo_11.attach(11);
}

void loop() {
<<<<<<< HEAD
  // tijd van nu
  
  /* Updates frequently */
unsigned long currentTime = millis();
  
  /* This is the event*/
  if( currentTime - previousTime >= moveSensorInterval){
    
    if(moveSensorInterval <= 4500){
      servo_11.write(90);
    }
    else {
      servo_11.write(0);
    }
    
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    digitalWrite(ledPin, ledState);

    previousTime = currentTime;

  }
  
   

     

 if (digitalRead(pinServo10) == HIGH) {
    servo_10.write(90);
  } else {
    servo_10.write(0);
  }
  /*if (digitalRead(pinServo11) == LOW) {
    servo_11.write(90);

  } else {
    servo_11.write(0); */
  }
  delay(10); //Voor simulatie verbeteren 
    // geef de pin de waarde van de status


 /*
 if (digitalRead(pinMarbleCount) == HIGH) {
   marbleCount = marbleCount + 1;
 }
 Serial.println(marbleCount);  

 */   
}



