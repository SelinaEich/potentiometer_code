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

Servo myServo;                      // compass servo

/*Potentiometer Variables*/
int startingBlock; // notes starting block position 0 or 1

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);

  pinMode(PotPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  startingBlock = analogRead(PotPin) / 513; 
  Serial.print("Potentiometer:"); Serial.print("\t"); Serial.println(PotPin);
}
