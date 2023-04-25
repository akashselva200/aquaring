#include <LiquidCrystal.h>
#include <EEPROM.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int outputValue=0,cc,set1,cnt;
long duration, inches, cm;
int sensorValue1;
int sensorValue;
char oc,occ;
char f1,f2,f3,f4;
int o1,o2,o3,o4;
long hl;
void setup() {
  // set up the LCD's number of columns and rows:
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("WUSN ");
  pinMode (2,OUTPUT);//attach pin 5 to GND
  pinMode (3,OUTPUT);//attach pin 5 to GND
  pinMode (4,OUTPUT);//attach pin 5 to GND
  pinMode (5,OUTPUT);//attach pin 5 to GND
  pinMode (7,OUTPUT);//attach pin 5 to GND
  pinMode (A0,INPUT_PULLUP);//attach pin 5 to GND
  pinMode (A1,INPUT_PULLUP);//attach pin 5 to GND
  pinMode (A2,INPUT_PULLUP);//attach pin 5 to GND
  pinMode (A3,INPUT_PULLUP);//attach pin 5 to GND
}
void loop() {
if(digitalRead(A0)=0)
{
  Serial.print('A');
  lcd.setCursor(0,0);
  lcd.print("Cyclone Warn ");
}
if(digitalRead(A1)=0)
{
  Serial.print('B');
  lcd.setCursor(0,0);
  lcd.print("Emergency ");
}
if(digitalRead(A2)=0)
{
  Serial.print('C');
  lcd.setCursor(0,0);
  lcd.print("Border Cross ");
}
if(digitalRead(A3)=0)
{
  Serial.print('D');
  lcd.setCursor(0,0);
  lcd.print("Food/Water ");
}
 while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == 'a') {
      lcd.setCursor(0,0);
      lcd.print("Cyclone Warn ");
    }
    if (inChar == 'b') {
      lcd.setCursor(0,0);
      lcd.print("Emergency ");
    }
    if (inChar == 'v') {
      lcd.setCursor(0,0);
      lcd.print("Border Cross ");
    }
    if (inChar == 'd') {
      lcd.setCursor(0,0);
      lcd.print("Food/Water ");
    }
 }
  delay(100);
 }   