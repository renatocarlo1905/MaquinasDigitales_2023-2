// Presión enn una columna, temperatura en otra
// Ejemplo:
//7000, 23.5

#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp; // Object bmp
char payload[80]; //Payloads de lecturas

void setup() {
  Serial.begin(115200); 
  bmp.begin(0x76); //Inicializa bpm

}

void loop() {
  //Imprimir a dos columnas
  sprintf(payload, "%6.2f, %f3.2",
          bmp.readPressure()/1000,
          bmp.readTemperature());
  
  Serial.println(payload);  

  delay(200);
}
