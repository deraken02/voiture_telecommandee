#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>
#define button 4
RF24 radio(7, 8); // CE, CSN
const byte addresses[][6] = {"00001", "00002"};
int angleV= 0;
Servo myServo;
boolean buttonState = 0;
int AVANT = 2;
int ARRIERE = 3;
int enA = 6;
void setup() {
  pinMode(button, INPUT);
  pinMode(AVANT, OUTPUT);
  pinMode(ARRIERE, OUTPUT);
  pinMode(enA, OUTPUT);
  myServo.attach(5);
  radio.begin();
  radio.openWritingPipe(addresses[0]); // 00001
  radio.openReadingPipe(1, addresses[1]); // 00002
  radio.setPALevel(RF24_PA_MIN);
}
void loop() {
  delay(5);
  radio.startListening();
  if ( radio.available()) {
    while (radio.available()) {
      radio.read(&angleV, sizeof(angleV));
      if (angleV == 0) {
        digitalWrite(AVANT, LOW);
        digitalWrite(ARRIERE, LOW);
      }
      else if (angleV > 0) {
        digitalWrite(AVANT, HIGH);
        digitalWrite(ARRIERE, LOW);
        analogWrite(enA, angleV);
      }
      else {
        digitalWrite(AVANT, LOW);
        digitalWrite(ARRIERE, HIGH);
        analogWrite(enA, angleV);
      }
    }
    delay(5);
    radio.stopListening();
    buttonState = digitalRead(button);
    radio.write(&buttonState, sizeof(buttonState));
  }
}
