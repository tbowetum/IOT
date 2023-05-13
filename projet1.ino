// C++ code
//
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);


float temp;
float chut;
int tempPin = 0;
int chutPin = 1;
int buzzerPin = 7;
int buttonState = 0;

void setup()
{
  
  pinMode(2, INPUT);
  
  pinMode(buzzerPin, OUTPUT);
  
  Serial.begin(9600);
  lcd.begin(16, 2);
 
  
  

  
}

void loop()
{

  buttonState = digitalRead(2);
  if (buttonState == HIGH) {
   
    temp = analogRead(tempPin);
    chut = analogRead(chutPin);
    
    temp = (temp * 0.48828125) - 37;
    

    lcd.clear();
    lcd.print("TEMP = ");
    lcd.print(temp); 
    lcd.print("*C");
    delay(500);
    lcd.clear();
    lcd.print("Chut = ");
    lcd.print(chut); 
    delay(500);
    if(temp >= 40){
      tone(buzzerPin,1000);
    }else{
      noTone(buzzerPin);
    }
    
    
    

    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    lcd.clear();
    noTone(buzzerPin);
   
  }
  delay(10);
  
  
}