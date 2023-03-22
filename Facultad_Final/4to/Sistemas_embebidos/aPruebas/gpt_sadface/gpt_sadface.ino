#include <DHT.h>
DHT dht(0, DHT11);

void setup() {
  // put your setup code here, to run once:
dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
float temperature = dht.readTemperature();
float humidity = dht.readHumidity();

// Muestra la temperatura y la humedad en el monitor serie
Serial.print("Temperatura: ");
Serial.print(temperature);
Serial.print(" °C\tHumedad: ");
Serial.print(humidity);
Serial.println("%");
}
