#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inisialisasi LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Definisikan pin untuk lampu merah dan hijau
const int lampuMerah = 8;
const int lampuHiaju = 9;

// Waktu nyala masing-masing lampu dalam milidetik
const unsigned long interval = 2000;

void setup()
{
  // Atur pin sebagai output
  pinMode(lampuMerah, OUTPUT);
  pinMode(lampuHiaju, OUTPUT);

  // Inisialisasi LCD
  lcd.begin();
  lcd.backlight();

  // Buat semua lampu mati di awal
  digitalWrite(lampuMerah, LOW);
  digitalWrite(lampuHiaju, LOW);
}

void loop()
{
  // Nyalakan lampu merah dan matikan lampu hijau
  digitalWrite(lampuMerah, HIGH);
  digitalWrite(lampuHiaju, LOW);
  // Tampilkan pesan di LCD
  lcd.clear();
  lcd.print("Lampu merah menyala");
  // Tunggu sesuai interval
  delay(interval);

  // Matikan lampu merah dan nyalakan lampu hijau
  digitalWrite(lampuMerah, LOW);
  digitalWrite(lampuHiaju, HIGH);
  // Tampilkan pesan di LCD
  lcd.clear();
  lcd.print("Lampu hijau menyala");
  // Tunggu sesuai interval
  delay(interval);
}