#define RED 9
#define LUM A0

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(RED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int Value = analogRead(LUM);
  int Lumi = map(Value, 0, 1023, 255, 0);

  analogWrite(RED, Lumi);
  Serial.print("la lumiere de la led est de  : ");
  Serial.println(Lumi);
  delay(1000);


}
