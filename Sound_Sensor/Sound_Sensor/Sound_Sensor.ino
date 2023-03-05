#include <LiquidCrystal.h>

const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#define LED_R A2
#define LED_G A3 
#define LED_B A4
#define BUZZER 8 
int sensorValue = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_B, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  noTone(BUZZER);
  lcd.begin(16, 2);
}

void RGB_color(int LED_R_V,int LED_G_V,int LED_B_V)
{
  analogWrite(LED_R, LED_R_V);
  analogWrite(LED_G, LED_G_V);
  analogWrite(LED_B, LED_B_V);
}

void loop()
{
  sensorValue = analogRead (A0);
  Serial.println (sensorValue, DEC);
   
  if(sensorValue>=200)
  {
    RGB_color(255, 0, 0);
    delay(100);
    RGB_color(0, 255, 0);
    delay(50);
    tone(BUZZER, 2000);
    delay(100);
    tone(BUZZER, 1800);
    delay(50);
    lcd.setCursor(0,0);
    lcd.print("ALERT!!! THERE'S");
    lcd.setCursor(0,1);
    lcd.print(" AN INTRUDER!!!");
    delay(100);

    RGB_color(255, 0, 0);
    delay(100);
    RGB_color(0, 255, 0);
    delay(50);
    tone(BUZZER, 2000);
    delay(100);
    tone(BUZZER, 1800);
    delay(50);
    lcd.setCursor(0,0);
    lcd.print("ALERT!!! THERE'S");
    lcd.setCursor(0,1);
    lcd.print(" AN INTRUDER!!!");
    delay(100);

     RGB_color(255, 0, 0);
    delay(100);
    RGB_color(0, 255, 0);
    delay(50);
    tone(BUZZER, 2000);
    delay(100);
    tone(BUZZER, 1800);
    delay(50);
    lcd.setCursor(0,0);
    lcd.print("ALERT!!! THERE'S");
    lcd.setCursor(0,1);
    lcd.print(" AN INTRUDER!!!");
    delay(100);

    RGB_color(255, 0, 0);
    delay(100);
    RGB_color(0, 255, 0);
    delay(50);
    tone(BUZZER, 2000);
    delay(100);
    tone(BUZZER, 1800);
    delay(50);
    lcd.setCursor(0,0);
    lcd.print("ALERT!!! THERE'S");
    lcd.setCursor(0,1);
    lcd.print(" AN INTRUDER!!!");
    delay(100);

    RGB_color(255, 0, 0);
    delay(100);
    RGB_color(0, 255, 0);
    delay(50);
    tone(BUZZER, 2000);
    delay(100);
    tone(BUZZER, 1800);
    delay(50);
    lcd.setCursor(0,0);
    lcd.print("ALERT!!! THERE'S");
    lcd.setCursor(0,1);
    lcd.print(" AN INTRUDER!!!");
    delay(100);
  }
  else
  {
    RGB_color(0, 0, 0);
    noTone(BUZZER);
    lcd.setCursor(0,0);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.clear();
  }
}
