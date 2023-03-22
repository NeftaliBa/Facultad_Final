#include <LiquidCrystal.h>

//Crear el objeto LCD con los números correspondientes (rs, en, d4, d5, d6, d7)
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

byte cara[8] = {
B00000,
B10001,
B00000,
B00000,
B10001,
B01110,
B00000,
};
byte cuerpo[8] = {
B01110,
B01110,
B00100,
B11111,
B00100,
B01010,
B10001,
B00000,
};


void setup() {
  lcd.createChar (0,cara);
  lcd.createChar (1,cuerpo);
  // Inicializar el LCD con el número de  columnas y filas del LCD
  lcd.begin(16, 2);
  lcd.setCursor(5, 0);
  lcd.print("Luis Esteban Alcaraz Martinez");
  lcd.setCursor(5, 1);
  lcd.print("Neftali Barrera Rodriguez");

  lcd.setCursor(35, 0);
  lcd.write (byte (1));
  lcd.setCursor(31, 1);
  lcd.write (byte (1));

  lcd.setCursor(3, 0);
  lcd.write (byte (0));
  lcd.setCursor(3, 1);
  lcd.write (byte (0));

}

void loop() {
  lcd.scrollDisplayLeft(); 
  delay(400);
}