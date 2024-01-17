#include "WiFi.h"
#include "HTTPClient.h"

#define url "https://..."

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32-C3!");

  WiFi.begin("Wokwi-GUEST","");

  while (WiFi.status() != WL_CONNECTED){

  }

  Serial.println("Connecté");
  Serial.println(WiFi.localIP());
}

void loop() {
  HTTPClient http;
  http.begin(url);

  int code = http.GET();
  if (code = HTTP_CODE_OK){
    String resp = http.getString();
    Serial.println((resp));
  }
  delay(1000);

}
