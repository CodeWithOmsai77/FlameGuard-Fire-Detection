#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

// I2C LCD address
LiquidCrystal_I2C lcd(0x27, 16, 2);

// HC-05: Arduino RX, TX
SoftwareSerial BT(10, 11);

// Flame sensor digital output
const int flamePin = 5;

// Most flame sensors output LOW when flame is detected
const int FLAME_ACTIVE = LOW;

void setup() {
  pinMode(flamePin, INPUT);

  Serial.begin(9600);
  BT.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("FIRE DETECTOR");
  lcd.setCursor(0, 1);
  lcd.print("System Starting");

  Serial.println("Fire Detector Ready");
  BT.println("Fire Detector Ready");

  delay(1500);
  lcd.clear();
}

void loop() {
  int sensorValue = digitalRead(flamePin);
  bool fireDetected = (sensorValue == FLAME_ACTIVE);

  // Display sensor reading
  lcd.setCursor(0, 0);
  lcd.print("Sensor DO = ");
  lcd.print(sensorValue);
  lcd.print("   ");

  // Display detection status
  lcd.setCursor(0, 1);

  if (fireDetected) {
    lcd.print("FIRE DETECTED!  ");
  } else {
    lcd.print("System Normal   ");
  }

  // Serial Monitor output
  Serial.print("DO = ");
  Serial.print(sensorValue);
  Serial.print(" | ");
  Serial.println(fireDetected ? "FIRE DETECTED!" : "NO FIRE");

  // Mobile Bluetooth output
  BT.println(fireDetected ? "FIRE DETECTED!" : "NO FIRE");

  delay(1000);
}
