#include <LiquidCrystal.h>

int red = 10;
int yellow = 9;
int green = 8;
int contrast = 75;

const int rs = 12, en = 13, d4 = 2, d5 = 3, d6 = 4, d7 = 5; 
//initializing the lcd: lcd(rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  // Tells the board that you will be using these pins as the output
  // Need this for the lights to function
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);

  // Initializing the LCD screen:
  lcd.begin(16,2);
  analogWrite(6, contrast);
}

void loop() {
  // put your main code here, to run repeatedly
  changeLights();
  delay(1500);
}

void changeLights() {
  // green off, yellow on for 3 seconds - active high
  digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("SLOW");
  delay(3000);

  // turn off yellow, turn red on for 5 seconds
  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("STOP");
  delay(5000);

  // red and yellow on for 2 seconds:
  digitalWrite(yellow, HIGH);
  lcd.setCursor(0,0);
  delay(2000);

  // green on
  digitalWrite(yellow, LOW);
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("GO");
  delay(3000);
}
