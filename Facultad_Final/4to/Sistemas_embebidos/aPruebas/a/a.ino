#include "DHT.h" 
#define PinSensor 2   // Pin digital al que se conecta el sensor
#define Tipo DHT11    // Tipo de sensor
DHT dht(PinSensor, Tipo);
void setup() {
  Serial.begin(9600); 
  dht.begin();
}
void loop(){
  delay(1000);   
  float humedad = dht.readHumidity();
  float temperatura = dht.readTemperature();
  Serial.print("Humedad: "); 
  Serial.println(humedad);
  Serial.print("Temperatura:"); 
  Serial.println(temperatura);
}
