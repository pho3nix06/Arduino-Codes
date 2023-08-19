/*Pho3niX
 * Date: 11/07/2021
 */

#include<LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);  //parameters (rs,enable,d4,d5,d6,d7)

const int trig = 0;
const int echo = 1;
long duration;
int disCM , disINCH;

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  lcd.print("Start:");
}

void loop() {
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(12);
  digitalWrite(trig,LOW);
  
  duration = pulseIn (echo,HIGH);
  disCM = (duration*0.034)/2;  //note
  disINCH = (duration*0.0133)/2; //note
  
  lcd.setCursor(0,0);
  lcd.print("Distance ");
  lcd.print(disCM);
  lcd.print(" cm");
  delay(100);
  lcd.setCursor(0,1);
  lcd.print("Distance: ");
  lcd.print(disINCH);
  lcd.print(" inch");
  delay(100);
}
