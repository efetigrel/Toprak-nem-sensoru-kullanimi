  #include <LiquidCrystal_I2C.h>

  LiquidCrystal_I2C lcd(0x27,16,2);

  const int prob = A0;
  int nem_sonucu;

  int KirmiziLed=2;
  int SariLed=3; 
  int YesilLed=4; 

void setup() 
{
  pinMode(KirmiziLed, OUTPUT); 
  pinMode(SariLed, OUTPUT); 
  pinMode(YesilLed, OUTPUT); 
  
  pinMode(prob, INPUT);
  lcd.init();
  lcd.backlight();
}
void loop() {
  nem_sonucu = analogRead(prob);  
  nem_sonucu = map(nem_sonucu,1023,450,0,100);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Toprak Nemi:");
  lcd.setCursor(12, 0);
  lcd.print(nem_sonucu);
  
  if( 0 <= nem_sonucu)
  {
    digitalWrite(KirmiziLed, HIGH); 
    digitalWrite(SariLed, LOW);     
    digitalWrite(YesilLed, LOW);
  }
  
   if( 30 <= nem_sonucu)
  {
    digitalWrite(KirmiziLed, LOW);
    digitalWrite(SariLed, HIGH); 
    digitalWrite(YesilLed, LOW); 
  } 


   if( 60 <= nem_sonucu)
  {
    digitalWrite(KirmiziLed, LOW); 
    digitalWrite(SariLed, LOW); 
    digitalWrite(YesilLed, HIGH); 
  }
}
