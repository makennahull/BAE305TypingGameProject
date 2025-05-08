# BAE305TypingGameProject
Repository for our BAE305 Final Project. Spring 2025. 
# BAE 305 Project: Typing Game
Group members: Elizabeth Frericks, Leah Moylan, Makenna Hull

Date: April 30th, 2025

# Summary 
For our BAE305 final project, we designed a typing game. For this game, the player will be racing against a computer, which races at a set motor speed every race. The code for our game prompts the user to press the start button, which is a push button on an Arduino uno. Once this button is pressed, a red, yellow, a green light sequence runs, signaling the start of the game. The user then continues to follow the directions on the screen, typing the given sentence into the serial monitor. Once the player hits enter, the words per minute (WPM) and accuracy of the users typing will be displayed. Using your typing accuracy and WPM, the motor connected to your car will be given a motor speed. The goal of the game is to type quick enough and accurate enough to beat the computer in the race. 

# Project Design

## Track Design

The physical design of this project includes an angled track, two cars, and strings connecting the cars to the motors in the circuit. The following materials were used in the construction of the physical design: 

**Materials**

* One 24in x 18in x 18in collapsed cardboard box
* Pine green Valspar interior paint
* Hot glue gun 
* Three sticks of hot glue 
* Box cutter
* Approximately 10ft of clear fishing line
* Two Hot Wheels cars (Approximately 3in length and 1in width, but can vary by a couple of inches)

**Design Description**

1. To begin the physical construction of our project, we cut the cardboard pieces that we used to build the track. We cut eleven pieces of cardboard outlined below: 

* The first piece was used as the base of the track. This piece is a rectangle that is approximately 1ft wide and 2.5ft long. 

* Next, we cut three equally sized pieces. These pieces were used as the walls of the lanes on the track. One was placed on the left edge of the track, one in the middle, and one on the right edge. These were about 2.5ft long and 3in tall. 

* Next, we added two trapezoidal pieces of cardboard to incorporate a slightly upwards slant into the track. These pieces were about 4in long and the tallest height was 3 in. The slant between the two heights was at about a 15 degree angle to add a 15 degree slant to our design. 

* Next, we added four pieces of cardboard to make a box at the end of our track (the side that was slanted upwards), so the two motors from the circuit could be placed at the same level as the track. 

* Finally, the last piece of cardboard acted as a stabilizer for the track. We glued the track to it to account for cardboard deformation from the paint. This piece is about 1.2ft wide and 2.7ft long, so it is slightly bigger than the base of the track. 

2. The next step was to paint each of these cardboard segments. We painted one side of each segment and let it dry, then we painted the other side and let that dry. We left the last cardboard piece and the two trapezoidal pieces unpainted. 

3. After every piece of cardboard was cut and painted, we glued the pieces together together to assemble. After plugging the hot glue gun in for about two minutes, it was warm enough to add glue to our pieces. First, we glued the three walls of the lanes of the track to the base of the track. Next, we glued the trapezoidal pieces to each side of the back, bottom of the track to incorporate the slant. Next, we glued together the four small pieces that made the box to support the motors and attached that to the back of the track. Finally, we glued the track to the last piece of cardboard to stabilize it. 

4. The final step of the physical design of our game was attaching the cars to a piece of string that pulled the cars based on the speed of the motor. We glued about 5 ft of fishing line to the bottom of each car with a hot glue gun. We wrapped the side of the string that was not attached to the car around the wheel until there was no slack. The wheel was attached to the motor, so it turned with the motor and wound up the string, pulling the car across the track. 

![image](https://github.com/user-attachments/assets/82993d22-85fb-4f27-b399-600b6727c3ce)

_Figure 1: Back View of the Track (circuit end)_

![image](https://github.com/user-attachments/assets/5f2be81d-7264-443c-9511-728770d4a0e5)

_Figure 2: Side view of the track_

## Circuit Design

For this project, the required electrical materials can be found in the Sparkfun inventor's kit. There are two circuits to build: one for the red, yellow, green start LEDs, and one to control the DC motors.

**LED Circuit**

Materials
* One Red LED
* One Yellow LED
* One Green LED
* Three 330 ohm resistors
* One Push Button
* One Arduino Uno with breadboard
* Computer able to run Arduino IDE

Design Description:
This circuit was built using the materials from the EGR102 circuit kits. The push button controls all three LEDs. 

<p align="center">
<img width=50% src="https://github.com/makennahull/BAE305TypingGameProject/blob/main/LEDcircuit.jpg">
</p>
<p align="center">
  <em>Figure 3. LED Circuit Build</em>
</p>


**DC Motor Circuit**

Materials
* Two DC Motors
* One RedBoard with breadboard
* One Motor Driver
* Jumper Wires
* Computer able to run Arduino IDE

Design Description:
This circuit was built the same as the circuit in Lab 6. Schematic and actual build shown below.
<p align="center">
<img width=50% src="https://github.com/makennahull/BAE305TypingGameProject/blob/main/Screenshot 2025-04-30 212722.png">
</p>
<p align="center">
  <em>Figure 4. DC motor circuit schematic (taken from Lab 6 manual)</em>
</p>

<p align="center">
<img width=50% src="https://github.com/makennahull/BAE305TypingGameProject/blob/main/circuit close up.jpg">
</p>
<p align="center">
  <em>Figure 5. DC motor circuit build</em>
</p>

**Connecting the Pieces**

One Sparkfun wheel was connected to each DC motor. The motors were connected with velcro to the stand on the carboard game device as shown in the below picture. Fishing line was tied to each wheel, wound around the wheel, and the loose end was hot glue to the bottom of each car. Carboard circles with a diameter of about 1" greater than the Sparkfun wheels were glued to each side of each wheel (4 cardboard circles in total) so that the fishing line did not slip off the sides. This created a pulley system where the spinning of the motors would cause the fishing line to wrap around the wheels and pull the cars closer to the finish line. This is shown below.

<p align="center">
<img width=50% src="https://github.com/makennahull/BAE305TypingGameProject/blob/main/circuit and motors.jpg">
</p>
<p align="center">
  <em>Figure 6. Game Device with Motors Attached</em>
</p>


**Code**

Our system contains two different codes: one for controlling the red, yellow and green LED start lights. The other pertains to the typing game itself, showing the instructions to the user, calculating the motor speed, running the motors, and showing the user their WPM and accuracy. 

The following is the code for the LED start lights:
```c++
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

```


The following is the code for the game:
```c++
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

```
In the above code, make sure to set PWMA, PWMB, AI1, AI2, BI1, and BI2 to the pins that match your circuit if they are not the same pins that we used.

## Design Decision Discussion

### Track
Throughout the process of constructing the physical design for our project, many design decisions were made. Below, there is a step by step discussion of the decision making process when designing each part of the physical design, 

1. First, we needed to decide what material to use to build the track. Cardboard was chosen because it is sturdy and easy to cut into various shapes. 

2. Next, we decided to make our track have two lanes because we wanted one car to represent the speed of the person playing the typing game, and we wanted one other car to be set at a constant speed to be the "competitor" for the player. 

3. Next, we decided to paint our track green to replicate Keeneland green; we thought Keeneland would be a good theme for our game since it involves racing and is well known in Lexington. 

4. Next, we decided to incorporate a slant in our design to prevent the cars from rolling towards the finish line. This ensured that the only variable controlling the cars' speed was the speed of the motor. 

5. We also chose to use Hot Wheels as our cars because they are light weight and were easily pulled by the motor. 
 
 
### Circuits

**LED Circuit**

We chose to use the LEDs from the EGR102 circuit kit, since red, yellow, and green LEDs can be found in the kit. We chose to use only one start button, as we wanted the red, yellow, then green light sequence to happen all at once. 

**DC Motor Circuit**

We chose to use the two DC motor circuit from Lab 6 because two motors would allow our game to have one human player and one computer controlled player. This would allow the human user to play against a consistent speed each time.



### Code

**LED Code**

This code is run separately from the DC motor/typing game code. After initializing the pins used, the code runs once the push button is hit. First, the red LED turns on for a designated period of time. Then, there is a pause before the yellow LED lights up. Finally, the green LED turns on, before turning off as well. 

**DC Motor/Typing Game Code**

We chose to make the typing game self-contained within Arduino IDE for ease of use and reducing applications involved. We did this by designing the code so that WPM and accuracy were calculated from user input into the serial monitor. This calculated WPM and accuracy was then converted into a motor speed. One DC motor would then be assigned this speed, while the other DC motor was set to a constant speed so that the user would be playing against a consistent opponent each time. The code did not trigger the motors to run until the user completed the sentence they were prompted to type and pressed enter. The serial monitor then displayed the user's WPM, accuracy, and motor speed, and the computer set motor speed so the user could determine how well they did compared to the computer. Additionally, when converted WPM to motor speed, we multiplied WPM by 1.5 so that the car would still move fast enough for slower typers. We also constrained the motor speed to 75 to 255 so that the motor would at least spin at a speed fast enough to make the car move.



# Testing 

To ensure that our project was successful, we tested our physical design, circuit, and code many times throughout the design process. 

To test our physical design, we ensured that it maintained stability for cars of various different weights. This involved tweaking the slanted cardboard pieces so the design was stable. 

We also tested that all parts worked together smoothly by running the game multiple times. 

To test that the player's car moved faster at faster typing speeds and higher accuracies and slower at slower typing speeds and lower accuracies, we ran multiple test runs at different WPMs and recorded the results. We manually set the WPM to 20, 40, 60, and 80 by  changing line 54 in the code (wpm = (wordCount / (elapsedTime / 1000.0)) * 60.0;) to wpm = one of the values specified above at a time. With this, we recorded the motorSpeed output by the serial monitor and whether or not the user car beat the fixed speed computer car. The accuracy is not directly calculated into motor speed; however, accuracy affects WPM calculation, so the less accurate you are, the lower your WPM, and in turn the lower the motor speed. We tested accuracies of 30, 60, and 100 and recorded wins/losses against the computer. We set the accuracy to these approximate values by manually getting 1/3 of the words wrong, 2/3 of the words wrong, and then all of the words correct.


# Test Results

**Tested Physical Design Slant Heights**

|Height (in)|Success/Fail|Reason|
|------|-------|---------|
|0|Fail|No slant, so the cars rolled to the finish  and were not solely pulled by the motor|
|4|Fail|Slant was too high making cars too heavy|
|3.5|Fail|Slant was too high making cars too heavy|
|3|Success|This height was just right for the motors to pull the cars|

**Tested WPM and Motor Speed**

|WPM|Motor Speed|Win/Loss against Computer|
|------|-------|---------|
|20|111|Loss|
|40|147|Tie|
|60|183|Win|
|80|219|Win|

**Tested Accuracy and Motor Speed**

|Accuracy|Win/Loss against Computer|
|------|-------|
|30|Loss|
|60|Loss|
|100|Win|


# Test Results Discussion
One limitation of our testing is that at higher speeds of the DC motors (above about 180), all of the motor speeds look very similar and produce very similar results in terms of car speed. This means that it is hard to tell if higher typing speeds are actually making your car move faster. Therefore, our games' capabilities are best seen at WPM below 60. Another limitation is the impact of accuracy. Since accuracy is not directly account for in motor speed and instead just affects WPM, which in turn affects motor speed, the game is limited in providing users a clear idea of how their accuracy is affecting their speed. It is hard to know if your car speed has decreased because of accuracy mistakes. Overall, the system works well for the intended use of racing cars based on a user's typing speed and accuracy. The results are consistent and predictable since the computer's car runs at the same speed each time, providing a reliable standard to compare the user against. This game is only designed to test WPM on one sentence, as the user is prompted to type the same sentence each time. A true typing test that comprehensively assessed user typing speed would require a longer passage, and one with varied sentences. This limits our device to just a fun game, rather than a true measure of typing ability.

Another limitation of our testing is that it is hard to measure the exact impact of the slant on the speed of the cars. After our testing, we were able to find a slant that was large enough to add slack in the fishing line but small enough so the cars were not to heavy for the motor. The two hot wheels are slightly different weights, so we did not measure the exact impact of the changes in the slant of our track on the speed of the individual cars. In the future, it would be easier to control the car speed relative to the slant of the track and the motor power if the cars were the same weight. 
