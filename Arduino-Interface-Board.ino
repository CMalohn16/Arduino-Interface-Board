#include "song.h"
#include "note-patterns.h"

#define MAX_SONGS 10

int redPin = 10;
int greenPin = 11;
int bluePin = 12;

int tonePin = 8;

uint8_t redValue = 0;
uint8_t greenValue = 0;
uint8_t blueValue = 0;

Song *songs[] = {
  new Song("startUp", 60, STARTUP),
  new Song("zelda", 420, ZELDA)
};

int numSongs = sizeof(songs) / sizeof(songs[0]);

void setup() 
{
  Serial.begin(9600);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  pinMode(tonePin, OUTPUT);

}

void loop() 
{

  /*
  Message Format: "LED,R,G,B"
                  "Pin,PinNumber,State(1/0)"
                  "Tone,SongName"
  */

  String message = "LED,0,0,0";

  if (Serial.available()) 
  {
    message = Serial.readString();
    if (message.startsWith("LED")) 
    {
      message = message.substring(4);
      uint8_t rgb[3];
      parseLED(message, rgb);
      redValue = rgb[0];
      greenValue = rgb[1];
      blueValue = rgb[2];

      Serial.print("LEDReceived,");
      Serial.print(redValue);
      Serial.print(",");
      Serial.print(greenValue);
      Serial.print(",");
      Serial.println(blueValue);
    } 
    else if (message.startsWith("Tone")) 
    {
      message = message.substring(5);
      parseTone(message);
    } 
    else if (message.startsWith("Pin")) 
    {
      message = message.substring(4);
      parsePin(message);
    }
    else 
    {
      Serial.println("Invalid message format");
    }
  }

  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);

}

void parseLED(String s, uint8_t output[3]) 
{
  char sArr[s.length() + 1];
  s.toCharArray(sArr, (s.length() + 1));
  char *rToken = strtok(sArr, ",");
  output[0] = atoi(rToken);
  char *gToken = strtok(NULL, ",");
  output[1] = atoi(gToken);
  char *bToken = strtok(NULL, ",");
  output[2] = atoi(bToken);

}

void parsePin(String s) 
{
  char sArr[s.length() + 1];
  s.toCharArray(sArr, (s.length() + 1));
  char *pinToken = strtok(sArr, ",");
  char *stateToken = strtok(NULL, ",");

  pinMode(atoi(pinToken), OUTPUT);
  digitalWrite(atoi(pinToken), atoi(stateToken));
}

void parseTone(String s) {
  for (int i = 0; i < numSongs; i++)
  {
    if (!s.compareTo(songs[i]->getName()))
    {
      songs[i]->playSong(tonePin);
    }
  }
}
