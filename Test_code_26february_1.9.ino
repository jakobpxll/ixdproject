#include <Keyboard.h> // Keyboard functionality

int buttonPin = 2; // Button
int switchPin = 4; // Slider
int sensorPin = A0; // Light sensor

int LED = 6;
int stateLED = LOW;
int stateButton;
int previous = LOW;
long time = 0;
long debounce = 200;

boolean switchState = 0;
boolean lastSwitchState = 0;


void setup()
{
  Serial.begin(9600);
  Keyboard.begin();

  pinMode(buttonPin, INPUT); // Button
  pinMode(switchPin, INPUT); // Slider
  pinMode(sensorPin, INPUT); // Light sensor
  pinMode(LED, OUTPUT); // Blue LED light
}


void loop()
{ // Beginning

  // Blue LED light
  stateButton = digitalRead(buttonPin);  
  if(stateButton == HIGH && previous == LOW && millis() - time > debounce) {
    if(stateLED == HIGH){
      stateLED = LOW; 
    } else {
       stateLED = HIGH; 
    }
    time = millis();
  }
  digitalWrite(LED, stateLED);
  previous == stateButton;

  // Button
  if (digitalRead(buttonPin) == HIGH)
  {
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press('A'); // Voice mute-unmute
    delay(250);
    Keyboard.releaseAll();
    delay(250);
  }

  // Slider
  switchState = digitalRead(switchPin);
  
  if (switchState != lastSwitchState) {
    if (switchState == HIGH) {
          Keyboard.press(KEY_LEFT_GUI);
          Keyboard.press(KEY_LEFT_SHIFT);
          Keyboard.press('V'); // Video on-off
          delay(250);
          Keyboard.releaseAll();
          delay(250);          
    } else if (switchState == LOW) {
          Keyboard.press(KEY_LEFT_GUI);
          Keyboard.press(KEY_LEFT_SHIFT);
          Keyboard.press('V'); // Video on-off
          delay(250);
          Keyboard.releaseAll();
          delay(250); 
    }
  } lastSwitchState = switchState;

  // Light sensor
  int value = analogRead(A0);
  
  if (analogRead(A0) < 300)
  {
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('W'); // Leave meeting
    Keyboard.releaseAll();
    delay(5000);
  } else if (analogRead(A0) > 300) {
  }
    
} // End of code
