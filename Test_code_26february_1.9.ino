
#include <Keyboard.h> // Klaviatuuri funktsionaalsus

int buttonPin = 2; // Nupp
int switchPin = 4; // Slaider
int sensorPin = A0; // Valgussensor

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

  pinMode(buttonPin, INPUT); // Nupp
  pinMode(switchPin, INPUT); // Slaider
  pinMode(sensorPin, INPUT); // Valgussensor
  pinMode(LED, OUTPUT); // Sinine valgus
}



void loop()
{ // Koodi algus

  // Sinine LED
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


  // Nupp
  if (digitalRead(buttonPin) == HIGH)
  {
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press('A'); // Mute-Unmute
    delay(250);
    Keyboard.releaseAll();
    delay(250);
  }


  // Slaider
  switchState = digitalRead(switchPin);
  
  if (switchState != lastSwitchState) {
    if (switchState == HIGH) {
          Keyboard.press(KEY_LEFT_GUI);
          Keyboard.press(KEY_LEFT_SHIFT);
          Keyboard.press('V'); // Video On-Off
          delay(250);
          Keyboard.releaseAll();
          delay(250);          
    } else if (switchState == LOW) {
          Keyboard.press(KEY_LEFT_GUI);
          Keyboard.press(KEY_LEFT_SHIFT);
          Keyboard.press('V'); // Video On-Off
          delay(250);
          Keyboard.releaseAll();
          delay(250); 
    }
  } lastSwitchState = switchState;


  // Valgussensor
  int value = analogRead(A0);
  
  if (analogRead(A0) < 300)
  {
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press('V'); // Ajutiselt video
    Keyboard.releaseAll();
    delay(5000);
  } else if (analogRead(A0) > 300) {
  }
    
} // Koodi lõpp
