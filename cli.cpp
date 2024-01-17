#define RED 7
#define BUT 6

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(BUT, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(BUT) == LOW) {
    // Si le bouton est enfoncé, clignoter rapidement
    digitalWrite(RED, HIGH);
    delay(200);
    digitalWrite(RED, LOW);
    delay(200);
    digitalWrite(RED, HIGH);
  } else {
    // Si le bouton est relâché, clignoter lentement
    digitalWrite(RED, HIGH);
    delay(500);
    digitalWrite(RED, LOW);
    delay(500);
    digitalWrite(RED, HIGH);
  }
}
