#include "DHT.h"

#define DHTPIN 13
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

int arrayNum[10]  = {B1000000, B1111001, B0100100, B0110000, B0011001, B0010010, B0000010, B1111000, B0000000, B0010000};         //para catodo comun
int grados[2] = {B0011100, B1000110};
//o,C/
int boton=0;
int conteo;
bool estadoantes;
int unidad;
int decena;
int tiempo=20;


void setup() {
 // Serial.begin(9600);
  DDRD = B11111111;
  DDRB = B11111111;
  dht.begin();
}

void loop() {
      
  int h = dht.readHumidity();
 // Serial.println(h);
  int t = dht.readTemperature();
    if (isnan(h) || isnan(t)) { //|| isnan(f)/)
      Serial.println(F("Failed to read from DHT sensor!"));
      return;
          }
    /*estadoInicial = digitalRead(boton);
    if(estadoInicial == HIGH){*/
    bool estadoactual = digitalRead(boton);
    if(estadoactual != estadoantes){
    if(estadoactual == HIGH){
      conteo++;
    }
    delay(10);
    estadoantes = estadoactual;
    
    }
    if(conteo % 2 ==0){
        unidad= t%10;
        decena = (t%100-t%10)/10;
        Serial.println(decena);
        for(int g=0;g<tiempo;g++){
        PORTD = grados[1];
        PORTB = B11100001;
        delay(1);
        PORTD = grados[0];
        PORTB = B11100010;
        delay(1);
        PORTD = arrayNum[unidad];
        PORTB = B11100100;
        delay(1);
        PORTD = arrayNum[decena];
        PORTB = B11110000;
        delay(1);
     }}else{
        unidad= h%10;
        decena = (h%100-h%10)/10;
        Serial.println(decena);
        for(int g=0;g<tiempo;g++){
        PORTD = grados[1];
        PORTB = B11100001;
        delay(1);
        PORTD = grados[0];
        PORTB = B11100010;
        delay(1);
        PORTD = arrayNum[unidad];
        PORTB = B11100100;
        delay(1);
        PORTD = arrayNum[decena];
        PORTB = B11110000;
        delay(1);
      }

   }
   

       

  }