#include <LiquidCrystal.h>
int STATE=0;
int rank=0;
// LiquidCrystal(rs,enable,d4,d5,d6,d7)
LiquidCrystal lcd(11,10,9,8,7,6,5,4,3,2); //rw brancher sur gnd

void setup() {
  lcd.begin(40,4);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  
}

/**
 * Affiche le menu du logiciel
 */
void menu(){
  lcd.setCursor(10,0);
  lcd.print("Menu Principal");
}

void loop() {
  digitalWrite(13,HIGH);
  lcd.display();
  lcd.print("Hello World");
  
}
