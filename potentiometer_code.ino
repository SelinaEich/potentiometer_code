#include <Servo.h>
#include <Wire.h>
#include <avr/sleep.h>

#define address 0x1E  //0011110b, I2C 7bit address of HMC5883
#define ServoPin 10
#define SolenoidPin 9
#define Reed 2 
#define Switch 2
#define deltaSw 2.4737 // (in inches per reed trigger) Circumference/#Magnets or 2*pi*wheelRaduis/numMagnets, MUST BE A DECIMAL NUMBER!
#define PotPin A0
#define buttPin 5 //Button to start executing code is in pin 5
#define startPin 0
Servo myServo;                      // compass servo

/*Potentiometer Variables*/
int startingBlock; // notes starting block position 0 or 1
int buttonState;
float startingPosX; // starting x-position (will vary depending on selected starting position) (NEW)
float startingPosY; // starting y-position (will vary depending on selected starting position) (NEW)

void setup() {
  Serial.begin(9600);
  pinMode(startPin,INPUT_PULLUP);
  pinMode(PotPin, INPUT);
}

void loop() {
  buttonState = digitalRead(startPin);
  startingBlock = floor(analogRead(PotPin) / 129);
  Serial.print("Button State:"); Serial.print("\t"); Serial.println(buttonState);
  Serial.print("Starting Block:"); Serial.print("\t"); Serial.println(startingBlock);
  start();
  Serial.print("startingPosX:"); Serial.print("\t"); Serial.println(startingPosX);
  Serial.print("startingPosY:"); Serial.print("\t"); Serial.println(startingPosY);
  delay(2000);
}

/************** Potentiometer/Starting Position Base Code *************/
void start() {
  if (buttonState == 1){ 
    if (startingBlock == 0){ // Position A1
      startingPosX = -99;
      startingPosY = 154;
      Serial.println("I am in state 1");
    }
    else if (startingBlock == 1){ // Position A2
      startingPosX = -121;
      startingPosY = 132;
    }
    else if (startingBlock == 2){ // Position A3
      startingPosX = -99;
      startingPosY = 110;
    }
    else if (startingBlock == 3){ // Position A4
      startingPosX = -77;
      startingPosY = 132;
    }
    else if (startingBlock == 4){ // Position B1
      startingPosX = -33;
      startingPosY = 154;
    }
    else if (startingBlock == 5){ // Position B2
      startingPosX = -55;
      startingPosY = 132;
    }
    else if (startingBlock == 6){ // Position B3
      startingPosX = -33;
      startingPosY = 110;
    }
    else if (startingBlock == 7){ // Position B4
      startingPosX = -11;
      startingPosY = 132;
    }
  }
  else if(buttonState == 0) {
    if (startingBlock == 0){ // Position C1
      startingPosX = -99;
      startingPosY = -110;
    }
    else if (startingBlock == 1){ // Position C2
      startingPosX = -121;
      startingPosY = -132;
    }
    else if (startingBlock == 2){ // Position C3
      startingPosX = -99;
      startingPosY = -154;
    }
    else if (startingBlock == 3){ // Position C4
      startingPosX = -77;
      startingPosY = -132;
    }
    else if (startingBlock == 4){ // Position D1
      startingPosX = -33;
      startingPosY = -110;
    }
    else if (startingBlock == 5){ // Position D2
      startingPosX = -55;
      startingPosY = -132;
    }
    else if (startingBlock == 6){ // Position D3
      startingPosX = -33;
      startingPosY = -154;
    }
    else if (startingBlock == 7){ // Position D4
      startingPosX = -11;
      startingPosY = -132;
    }
  }
  }

