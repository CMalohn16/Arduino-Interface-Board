
int redPin = 10;
int greenPin = 11;
int bluePin = 12;

uint8_t redValue = 0;
uint8_t greenValue = 0;
uint8_t blueValue = 0;

void setup() {
  Serial.begin(9600);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {

  /*
  Message Format: "LED,R,G,B"
  */

  String message = "LED,0,0,0";

  if (Serial.available()) {
    Serial.println("Serial Available");
    message = Serial.readString();
    if (message.startsWith("LED")) {
      Serial.println("LED received");
      uint8_t* rgb;
      parseLED(message, rgb);
      redValue = *(rgb);
      greenValue = *(rgb + 1);
      blueValue = *(rgb + 2);

      Serial.print(redValue);
      Serial.print("  ");
      Serial.print(greenValue);
      Serial.print("  ");
      Serial.println(blueValue);
    }
  }

  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);


}

void parseLED(String s, uint8_t* output) {

  int r, g, b;
  int start = 4;
  int end = start;

  while (end < s.length() && s.charAt(end) != ',') {
    end++;
  }
  r = s.substring(start, end).toInt();
  end++;
  start = end;

  while (end < s.length() && s.charAt(end) != ',') {
    end++;
  }
  g = s.substring(start, end).toInt();
  end++;
  start = end;

  while (end < s.length() && s.charAt(end) != ',') {
    end++;
  }
  b = s.substring(start, end).toInt();
  end++;
  start = end;

  *(output) = r;
  *(output + 1) = g;
  *(output + 2) = b;
}