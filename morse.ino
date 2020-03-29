#define led LED_BUILTIN
#define speed 10
const char dict[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
const String morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"};

String string = "sos";

void setup() {
  pinMode(led, OUTPUT);    // sets the digital pin 13 as output
  string.toLowerCase();
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < string.length(); i++) {
    if (string[i] != "") {
      for (int j = 0; j < sizeof(dict) / sizeof(dict[0]); j++) {
        if (dict[j] == string[i]) {
          for (int k = 0; k < morse[j].length(); k++) {
            digitalWrite(led, HIGH);
            Serial.println(morse[j][k]);
            if (morse[j][k] == '.') {
              delay(1000 / speed);
            } else {
              delay(3000 / speed);
            }
            digitalWrite(led, LOW);
          }
        }
      }
      delay(5000 / speed);
    }
  }
  delay(7000 / speed);
}
