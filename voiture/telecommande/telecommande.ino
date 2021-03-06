/*Réception*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN
const byte address[][6] = {"00001","00002"};
boolean buttonState=0;

void setup() {
  pinMode(12,OUTPUT);
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address[1]);
  radio.openReadingPipe(1,address[0]);
  radio.setPALevel(RF24_PA_MIN);
}

void loop() {
  delay(5);

  radio.stopListening();
  int X=analogRead(A0);
  int angleX=map(X,0,1023,0,255);
  radio.write(&angleX,sizeof(angleX));
  Serial.println(X);
  delay(5);
  radio.startListening();
  while (!radio.available());
  radio.read(&buttonState, sizeof(buttonState));
}
