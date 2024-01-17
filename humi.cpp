#include <DHT.h>
#define DHTPIN 7
#define DHTTYPE 22
DHT dht(DHTPIN, DHTTYPE);

void setup() {
 Serial.begin(115200);
 dht.begin();
 }

void loop() {
 
 float Temp = dht.readTemperature();
 float Humi = dht.readHumidity();

 Serial.print("temp est de ");
 Serial.println(Temp);
 Serial.print("humi est de ");
 Serial.println(Humi);
 delay(1000);


}
