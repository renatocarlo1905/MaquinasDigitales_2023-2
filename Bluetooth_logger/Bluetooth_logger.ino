#include "FS.h"
#include "SD.h"
#include "SPI.h"
#include "Adafruit_BMP280.h"

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;

//Loguear la infoo del sensor barométrico y LDR
#define LDR_PIN 35
#define LED_PIN 33

File readings;
Adafruit_BMP280 bmp; //Objeto bmp

char payload [80]; //Payload de lecturas


void setup() {
  pinMode(LED_PIN,OUTPUT);
  Serial.begin(115200);
  bmp.begin(0x76);
  SerialBT.begin("Axolote_Carlo");
  SerialBT.println("Bluetooth configurado");

}

void loop() {

  //Hacer el payload de lecturas
  sprintf(payload,"%6.2f,%3.2f,%d",
          bmp.readPressure(),
          bmp.readTemperature(),
          analogRead(LDR_PIN));

  digitalWrite(LED_PIN,HIGH);
    SerialBT.println(payload);
    Serial.println(payload);
  digitalWrite(LED_PIN,LOW);

  delay(500);

}
