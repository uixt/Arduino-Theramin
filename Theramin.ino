#define trigPin 8
#define echoPin 9
#define LEDlampWhite 2
#define LEDlampBlue 3
#define LEDlampGreen 4
#define  LEDlampYellow 5
#define LEDlampRed 6 
#define range1 15
#define range2 12
#define range3 9 
#define range4 6
#define range5 3
#define soundbuzzer 7
int sound  = 500;


void setup() {
  Serial.begin (9600);
  pinMode(trigPin,  OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LEDlampRed, OUTPUT);
  pinMode(LEDlampYellow,  OUTPUT);
  pinMode(LEDlampGreen, OUTPUT);  
  pinMode(soundbuzzer, OUTPUT);
}
void  loop() {
  long durationindigit, distanceincm;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  durationindigit = pulseIn(echoPin, HIGH);
  distanceincm = (durationindigit/5) / 29.1;
 
    if (range1 >= distanceincm && distanceincm > range2) {
      digitalWrite(LEDlampWhite,HIGH);
      digitalWrite(LEDlampBlue,LOW);
      digitalWrite(LEDlampGreen, LOW);
      digitalWrite(LEDlampYellow,LOW);
      digitalWrite(LEDlampRed,LOW);
      tone(soundbuzzer, 262, sound);
  } else if (range2 >= distanceincm && distanceincm > range3) {
      digitalWrite(LEDlampWhite,LOW);
      digitalWrite(LEDlampBlue,HIGH);
      digitalWrite(LEDlampGreen, LOW);
      digitalWrite(LEDlampYellow,LOW);
      digitalWrite(LEDlampRed,LOW);
      tone(soundbuzzer, 294, sound);
  } else if (range3 >= distanceincm && distanceincm > range4) {
      digitalWrite(LEDlampWhite,LOW);
      digitalWrite(LEDlampBlue,LOW);
      digitalWrite(LEDlampGreen, HIGH);
      digitalWrite(LEDlampYellow,LOW);
      digitalWrite(LEDlampRed,LOW);
      tone(soundbuzzer, 330, sound);
  } else if (range4 >= distanceincm && distanceincm > range5) {
      digitalWrite(LEDlampWhite,LOW);
      digitalWrite(LEDlampBlue,LOW);
      digitalWrite(LEDlampGreen,  LOW);
      digitalWrite(LEDlampYellow, HIGH);
      digitalWrite(LEDlampRed,LOW);
      tone(soundbuzzer, 349, sound);
  } else if (distanceincm <= range5) {
      digitalWrite(LEDlampWhite,LOW);
      digitalWrite(LEDlampBlue, LOW);
      digitalWrite(LEDlampGreen,  LOW);
      digitalWrite(LEDlampYellow, LOW);
      digitalWrite(LEDlampRed, HIGH);
      tone(soundbuzzer, 392, sound);

  }

  if (distanceincm > range1 ||  distanceincm <= range5) {
    Serial.println("Outside the permissible range of distances");
    noTone(soundbuzzer);
  } else {
    Serial.print(distanceincm);
    Serial.println("  cm");
  }

  
  delay(300);
}