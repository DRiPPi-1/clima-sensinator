/***********************
Artist: Hlumelo Siyo
Title: ClimaSensinator
Date: 06/06/2023
***********************/

#include <DHT.h>
#include <LiquidCrystal.h>

#define DHT_PIN 2         // Pin connected to the DHT sensor
#define DHT_TYPE DHT11    // Type of DHT sensor (DHT11, DHT21, DHT22)

DHT dht(DHT_PIN, DHT_TYPE);

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // RS, E, D4, D5, D6, D7 pins respectively

const int photoresistorPin = A1;  // Pin connected to the photoresistor

void setup() {
  Serial.begin(9600);     // Initialize serial communication at 9600 bps
  dht.begin();            // Initialize the DHT sensor
  lcd.begin(16, 2);       // Initialize the LCD module
}

void loop() {
  float temperature = dht.readTemperature();      // Read temperature in Celsius
  float humidity = dht.readHumidity();            // Read humidity

  int lightIntensity = analogRead(photoresistorPin);  // Read the light intensity

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C   Humidity: ");
  Serial.print(humidity);
  Serial.print(" %   Light Intensity: ");
  Serial.println(lightIntensity);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print(" %");

  delay(2000);  // Delay for 2 seconds before taking the next reading
}
