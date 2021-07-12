#include <SHT1x.h>
#define dataPin  10
#define clockPin 11
#define GasSensor A0
SHT1x sht1x(dataPin, clockPin);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(GasSensor , INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  float temp_c;
  //float temp_f;
  float humidity;
  float gas;
  // Read values from the sensor
  temp_c = sht1x.readTemperatureC();
  //temp_f = sht1x.readTemperatureF();
  humidity = sht1x.readHumidity();
  gas = analogRead(GasSensor);
  // Print the values to the serial port
  Serial.print("Temperature: ");
  Serial.print(temp_c, DEC);
  Serial.print(" ");
  //Serial.print(temp_f, DEC);
  Serial.print(" Humidity: ");
  Serial.print(humidity);
  Serial.print(" .");
  Serial.print("Gas Sensor Reading: ");
  Serial.println(gas);
  delay(2000);
}
