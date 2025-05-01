// Pin setup for SparkFun Motor Driver Shield
const int PWMA = 11;    // Motor A speed control (must be PWM-capable pin)
const int AI1  = 13;   // Motor A direction 1
const int AI2  = 12;   // Motor A direction 2

const int PWMB = 10;   // Motor B speed control (must be PWM-capable pin)
const int BI1  = 8;    // Motor B direction 1
const int BI2  = 9;    // Motor B direction 2

// Typing test variables
unsigned long startTime;
unsigned long elapsedTime;
String typedText = "";
String targetSentence = "The fast brown fox jumps over the lazy dog.";
float wpm = 0.0;
const int fixedMotorSpeed = 150;  // Constant speed for Motor B (0–255)

void setup() {
  Serial.begin(9600);

  // Set motor pins as output
  pinMode(PWMA, OUTPUT);
  pinMode(AI1, OUTPUT);
  pinMode(AI2, OUTPUT);
  
  pinMode(PWMB, OUTPUT);
  pinMode(BI1, OUTPUT);
  pinMode(BI2, OUTPUT);

  Serial.println("Press the start button and start typing on green:");
  Serial.println(targetSentence);
  Serial.println("When you're done, press Enter.");

  startTime = millis(); // Start timing
}

void loop() {
  if (Serial.available() > 0) {
    char inputChar = Serial.read();
    if (inputChar == '\n') {
      calculateWPM();
    } else {
      typedText += inputChar;
    }

    updateMotorSpeed();  // Continuously update motor speed
  }
}

void calculateWPM() {
  elapsedTime = millis() - startTime;
  int wordCount = countWords(typedText);

  wpm = (wordCount / (elapsedTime / 1000.0)) * 60.0;

  float accuracy = calculateAccuracy();

  Serial.print("Words Per Minute: ");
  Serial.println(wpm);
  Serial.print("Typing Accuracy: ");
  Serial.print(accuracy, 2);
  Serial.println("%");
}

float calculateAccuracy() {
  int correctChars = 0;
  int minLength = min(typedText.length(), targetSentence.length());

  for (int i = 0; i < minLength; i++) {
    if (typedText.charAt(i) == targetSentence.charAt(i)) {
      correctChars++;
    }
  }

  // To avoid divide-by-zero error
  if (typedText.length() == 0) return 0.0;

  float accuracy = (correctChars / (float)typedText.length()) * 100.0;
  return accuracy;
}


void updateMotorSpeed() {
  int motorSpeed = map(wpm*1.5, 0, 150, 75, 255);  // Scale WPM to motor speed

  Serial.print("Motor Speed: ");
  Serial.println(motorSpeed);

  // Set both motors to forward direction
  digitalWrite(AI1, HIGH);
  digitalWrite(AI2, LOW);
  digitalWrite(BI1, HIGH);
  digitalWrite(BI2, LOW);

  // Set motor speed with PWM
  analogWrite(PWMA, motorSpeed);
  analogWrite(PWMB, fixedMotorSpeed);
}

int countWords(String str) {
  int count = 0;
  bool inWord = false;

  for (int i = 0; i < str.length(); i++) {
    if (str.charAt(i) == ' ' || str.charAt(i) == '\n') {
      if (inWord) {
        count++;
        inWord = false;
      }
    } else {
      inWord = true;
    }
  }

  if (inWord) count++;

  return count;
}
