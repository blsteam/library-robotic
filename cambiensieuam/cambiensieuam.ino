const int trig = 8;     
const int echo = 7;    
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20, 16, 2);
void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("khoangcach:");
  lcd.setCursor(13, 0);
  lcd.print("cm");
  pinMode(trig,OUTPUT);   
  pinMode(echo,INPUT);    
}

void loop()
{
    unsigned long thoigian;
    int khoangcach;           
    digitalWrite(trig,0);  
    delayMicroseconds(5);
    digitalWrite(trig,1); 
    delayMicroseconds(10);  
    digitalWrite(trig,0);   
    thoigian = pulseIn(echo,HIGH);  
    khoangcach = int(thoigian/2/29.412);
    lcd.setCursor(10, 0);
    lcd.print(khoangcach);
    if (khoangcach < 10) {
    lcd.setCursor(11, 0);
    lcd.print("  ");
    }
     else if (khoangcach < 100) {
    lcd.setCursor(12, 0);
    lcd.print(' ');
  }
  delay(200);
}
