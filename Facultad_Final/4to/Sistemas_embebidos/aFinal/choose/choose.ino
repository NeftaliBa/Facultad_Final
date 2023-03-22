#include <LiquidCrystal.h>

//Crear el objeto LCD con los números correspondientes (rs, en, d4, d5, d6, d7)
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
int boton0;
int boton1;
int led1 = 12;
int led2 = 11;
int led3 = 10;
int p, l1, l2, l3;



void setup() {
  // Inicializar el LCD con el número de  columnas y filas del LCD
  lcd.begin(16, 2);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  p = 0;
  l1 = 0;
  l2 = 0;
  l3 = 0;


  lcd.print("Menu");
}

void loop() {



  if (digitalRead(2) == HIGH) {
    lcd.print("             ");
    lcd.setCursor(0, 0);
    lcd.print("Menu");




    p = p + 1;
    delay(250);
    if (p > 2) {
      p = 0;
    }
  }


  switch (p) {
    case 0:
      digitalWrite(led3, LOW);
      if (digitalRead(3) == HIGH) {
        lcd.print("             ");
        lcd.setCursor(0, 0);
        lcd.print("Seleccionaste");
        
        l1 = l1 + 1;
        delay(250);
        if (l1 > 1) {
         l1 = 0;        
      }
      if(l1 == 1){
        digitalWrite(led1, HIGH);
      }
      }
      medir();
      break;

    case 1:
      digitalWrite(led1, LOW);
      if (digitalRead(3) == HIGH) {
        lcd.print("             ");
        lcd.setCursor(0, 0);
        lcd.print("Seleccionaste");
        
        l2 = l2 + 1;
        delay(250);
        if (l2 > 1) {
         l2 = 0;        
      }
      if(l2 == 1){
        digitalWrite(led2, HIGH);
      }
      }
      calibrar();

      break;

    case 2:
      digitalWrite(led2, LOW);
      if (digitalRead(3) == HIGH) {
        lcd.print("             ");
        lcd.setCursor(0, 0);
        lcd.print("Seleccionaste");
        
        l3 = l3 + 1;
        delay(250);
        if (l3 > 1) {
         l3 = 0;        
      }
      if(l3 == 1){
        digitalWrite(led3, HIGH);
      }
      }
      inicializar();
      break;
  }
}



void medir() {
  lcd.print("             ");
  lcd.setCursor(0, 1);
  lcd.print("Medir");
}

void calibrar() {
  lcd.print("             ");
  lcd.setCursor(0, 1);
  lcd.print("Calibrar");
}

void inicializar() {
  lcd.print("             ");
  lcd.setCursor(0, 1);
  lcd.print("Inicializar");
}
