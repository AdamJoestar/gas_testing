#include <LiquidCrystal.h>

// Inisialisasi pin LCD: (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int mq2Pin = A0;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Deteksi Polusi");
  delay(2000);
  lcd.clear();
}

void loop() {
  int sensorValue = analogRead(mq2Pin);
  
  lcd.setCursor(0, 0);
  lcd.print("Gas: ");
  lcd.print(sensorValue);

  lcd.setCursor(0, 1);
  if (sensorValue < 200) {
    lcd.print("Aman");
  } else if (sensorValue < 400) {
    lcd.print("Waspada");
  } else {
    lcd.print("Berbahaya!");
  }

  delay(1000);
}
