// Usa el potenciómetro como sensor para encender o apagar el LED

#define PIN_LED 33
#define PIN_POT 32

void setup() {
  pinMode(PIN_LED,OUTPUT);
  Serial.begin(115200);
}

void loop() {
  int POT_VALUE = analogRead(PIN_POT);
  
  // ajusta el brillo (valor entre 0 y 255)
  int brightness = map(POT_VALUE, 0, 4095, 0, 255); 

  analogWrite(PIN_LED, brightness);


  Serial.print("Analog value = ");
  Serial.print(POT_VALUE);
  Serial.print(" => brightness = ");
  Serial.println(brightness);
  delay(50);
}
