const int buttonPin = 2;
const int redPin    = 8;
const int yellowPin = 9;
const int greenPin  = 10;

int lastButtonState = HIGH;  // track previous state (HIGH = not pressed)

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);      // Configure pushbutton with internal pull-up
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  // Initialize all LEDs off:
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, LOW);
}

void loop() {
  int currentState = digitalRead(buttonPin);

  // Check for a falling edge (HIGH->LOW transition)
  if (lastButtonState == HIGH && currentState == LOW) {
    // Debounce delay:
    delay(20);
    // Read again to confirm stable press
    if(digitalRead(buttonPin) == LOW) {
      // === Run the LED sequence ===
      digitalWrite(redPin, HIGH);
      delay(1000);                      // red on for 1 sec
      digitalWrite(redPin, LOW);

      digitalWrite(yellowPin, HIGH);
      delay(1000);                      // yellow on for 1 sec
      digitalWrite(yellowPin, LOW);

      digitalWrite(greenPin, HIGH);
      delay(1000);                      // green on for 1 sec
      digitalWrite(greenPin, LOW);
      // (Sequence done)
    }
  }

  // Remember the button state for next loop iteration
  lastButtonState = currentState;
}

