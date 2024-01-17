bool show_message = true;
String message = "Le code est :";
int code_secret = 1234;
// S'execute une fois
void setup() { Serial.begin(115200);
pinMode(4, INPUT);
// Entrée
pinMode(3, INPUT_PULLUP); // Entrée avec pull-up
pinMode(5, OUTPUT);
}
// Sortie
// S'execute en boucle
void loop() {
if (show_message == true && digitalRead(3) == LOW) {
Serial.print(message);
Serial.println(code_secret);
}
else {
Serial.println("Tu n'auras pas le code secret !");
digitalWrite(5, HIGH);
}
delay(1000);
}
