/* 
  Configure pins for joystick and buttons. Map to default MAME/RetroPI settings
 */
const int buttonPin4 = 4;          // input pin for pushbutton
const int buttonPin3 = 3;          // input pin for pushbutton
const int buttonPin2 = 2;          // input pin for pushbutton
const int buttonPin5 = 5;          // input pin for pushbutton

int previousButtonState = HIGH;   // for checking the state of a pushButton
int previousButtonState3 = HIGH;   // for checking the state of a pushButton
int previousButtonState2 = HIGH;   // for checking the state of a pushButton
int previousButtonState5 = HIGH;   // for checking the state of a pushButton

int counter = 0;                  // button push counter

void setup() {                     // make the pins as an input:
  pinMode(buttonPin4, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin5, INPUT_PULLUP);
  Keyboard.begin(); // initialize control over the keyboard:
}

void loop() {
  // read the pushbutton:
  int buttonState = digitalRead(buttonPin4);
  int buttonState3 = digitalRead(buttonPin3);
  int buttonState2 = digitalRead(buttonPin2);
  int buttonState5 = digitalRead(buttonPin5);
    
  // Get the button pressed
    //if ((buttonState != previousButtonState) && (buttonState == HIGH)) {
    //Keyboard.press(KEY_DOWN_ARROW);
    //delay(50);
    //Keyboard.release(KEY_DOWN_ARROW);  
    
  // Have the joystick buttons been pressed
  if (buttonState == LOW ) {
    Keyboard.press(KEY_DOWN_ARROW);
    delay(50);
  }else  
      Keyboard.release(KEY_DOWN_ARROW);
  
  if (buttonState3 == LOW) {
      Keyboard.press(KEY_UP_ARROW);
      delay(50);
  }else
      Keyboard.release(KEY_UP_ARROW);
  
  if (buttonState2 == LOW) {
      Keyboard.press(KEY_RIGHT_ARROW);
      delay(50);
  } else 
       Keyboard.release(KEY_RIGHT_ARROW);
  
  if (buttonState5 == LOW) {
    Keyboard.press(KEY_LEFT_ARROW);
    delay(50);
  }else  
     Keyboard.release(KEY_LEFT_ARROW);
  
  // save the current button state for comparison next time:
  previousButtonState = buttonState;
  previousButtonState3 = buttonState3;
  previousButtonState2 = buttonState2;
  previousButtonState5 = buttonState5;
}
