#include <DHT.h>

DHT dht(12, DHT11);

int temp, hum;
bool esAnt;
int modo;

int num[10] = {
  B00111111,  // 0
  B00000110,  // 1
  B01011011,  // 2
  B01001111,  // 3
  B01100110,  // 4
  B01101101,  // 5
  B01111101,  // 6
  B00000111,  // 7
  B01111111,  // 8
  B01101111   // 9
};
int simbolos[4] = {
  B01100011,  // GRADOS
  B00111001,  // CELCIUS
  B01110110   // HUMEDAD
};

int ubDisplay, numero;

void setup() {
  dht.begin();
  temp = 0;
  hum = 0;
  modo = 0;
  esAnt = LOW;
  DDRB = B00001111;
  DDRD = B01111111;
  ubDisplay = 0;
  numero = 0;
}

void loop() {
  temp = dht.readTemperature();
  hum = dht.readHumidity();

  bool esAct = digitalRead(13);
  if (esAct > esAnt) {
    if (modo == 1) {
      modo = 0;
    } else {
      modo = 1;
    }
  }

  esAnt = esAct;

  PORTB = B00001111;
  if (modo == 0) {
    mostrarTemp();
  } else {
    mostrarHum();
  }


  multiplexearDisplay();
}



void mostrarHum() {
  switch (ubDisplay) {
    case 2:
      PORTD = num[hum % 10];
      break;
    case 3:
      PORTD = num[(hum / 10) % 10];
      break;
    case 1:
      PORTD = simbolos[0];
      break;
    case 0:
      PORTD = simbolos[2];
      break;
  }
}

void mostrarTemp() {
  switch (ubDisplay) {
    case 2:
      PORTD = num[temp % 10];
      break;
    case 3:
      PORTD = num[(temp / 10) % 10];
      break;
    case 1:
      PORTD = simbolos[0];
      break;
    case 0:
      PORTD = simbolos[1];
      break;
  }
}

void multiplexearDisplay() {
  switch (ubDisplay) {
    case 0: PORTB = B00001110; break;
    case 1: PORTB = B00001101; break;
    case 2: PORTB = B00001011; break;
    case 3: PORTB = B00000111; break;
  }
  ubDisplay++;
  if (ubDisplay > 3)
    ubDisplay = 0;
}
