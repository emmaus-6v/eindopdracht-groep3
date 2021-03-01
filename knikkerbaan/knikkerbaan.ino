#include <Servo.h>


unsigned long previousTime = 0;

int i = 0;

const int pinServo10 = 7;
const int pinServo11 = 4;
const int pinMarbleCount = 2;

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

const unsigned long moveSensorInterval =  random(2000, 4000 + 1);
  
  /* Updates frequently */
unsigned long currentTime = millis();
  
  /* This is the event*/
  if( currentTime - previousTime >= moveSensorInterval){
    
    servo_11.write(90);
    Serial.println("Status servo 1:");
    Serial.println("HIGH"); 
    previousTime = currentTime;
    if (currentTime - previousTime >= 2000) {
      servo_11.write(0);
      Serial.println("Status servo 1:");
      Serial.println("LOW");
    }
    previousTime = currentTime;

   /*
    if(moveSensorInterval <= 3000){
      servo_11.write(90);
      Serial.println("Status servo 1:");
      Serial.println("HIGH");  
    }
    else {
      servo_11.write(0);
      Serial.println("Status servo 1:");
      Serial.println("LOW");
    }

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


 if (digitalRead(pinMarbleCount) == HIGH) {
   marbleCount = marbleCount + 1;
 }
 Serial.println(marbleCount);  

    int red, green, blue;
    GroveColorSensor colorSensor;
    colorSensor.ledStatus = 1;            // Wanneer de color sensor LED aangaat gaat de ledStatus = 1; en wanneer uit naar ledStatus = 0;.
    while(1){
        colorSensor.readRGB(&red, &green, &blue);    //leest RGB waarde naar variabelen.
        delay(300);
        Serial.print("The RGB value are: RGB( ");
        Serial.print(red,DEC);
        Serial.print(", ");
        Serial.print(green,DEC);
        Serial.print(", ");
        Serial.print(blue,DEC);
        Serial.println(" )");
        colorSensor.clearInterrupt();
    }
    var colorsensor.statuts = no.color; // omdat hij nog niks scanned word ->geen kleur
  if(colorSensor.ledStatus = 1){
    if(colorSensor.ledStatus = 1 & colorsensor.readRGB = red){
      colorsensor.status = red; // als hij rood balletje ziet dan geeft hij rode status omdat door te geven aan scherm om daar de kleur te tonen
    }
    if(colorSensor.ledStatus = 1 & colorsensor.readRGB = green){
      colorsensor.status = green; // zelfde geld hier maar dan groen
    }
    if(colorSensor.ledStatus = 1 & colorsensor.readRGB = bleu){
      colorsensor.status = bleu; // hier ook maar dan blauw
    }
     if(colorSensor.ledStatus = 1 & colorsensor.readRGB = bleu & red & bleu){
      colorsensor.status = white; // omdat wit alle kleuren weg kaatst moeten alle kleuren worden opgevangen en daarom wit
    }
  }
  else{
    colorsensor.status = no.color; //als die geen groen of of rood of blauw balletje ziet dan is dr geen color
  }
  /*dit moest verbonden worden aan schermpje maar dat wilt niet werken dus gaat niet en thomas heeft geen arduino stuf om te testen of het wel werkt
  maar dat gaat ook moeilijk zonder scherm*/
}



