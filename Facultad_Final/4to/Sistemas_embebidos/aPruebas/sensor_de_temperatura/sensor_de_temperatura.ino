#include <LiquidCrystal.h>
#include <DHT.h>
#include <DHT_U.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
#define PinSensor 0
#define Tipo DHT11
DHT dht(PinSensor, Tipo); 

void setup() {
  lcd.begin(16, 2);
  dht.begin();
}

void loop() {
  delay(5000);
  float humedad = dht.readHumidity();
  float temperatura = dht.readTemperature();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temper. = ");
  lcd.print(temperatura);
  lcd.setCursor(0,1);
  lcd.print("Humedad = ");
  lcd.print(humedad);
}
