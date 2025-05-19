// Define pin numbers
const int buttonPin = 6;     
const int ledPin1 = 2;       
const int ledPin2 = 3;      
const int ledPin3 = 4;      

// Variable to store the time when the button is first pressed
unsigned long buttonPressStartTime = 0;

void setup() {
  // Set LED pins as OUTPUT
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  // Set button pin as INPUT 
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  bool isButtonPressed = digitalRead(buttonPin) == LOW;

  if (isButtonPressed) {
    if (buttonPressStartTime == 0) {
      buttonPressStartTime = millis();
    }

    unsigned long pressDuration = millis() - buttonPressStartTime;

    if (pressDuration >= 3000) {
      digitalWrite(ledPin1, HIGH); delay(300); digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, HIGH); delay(300); digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, HIGH); delay(300); digitalWrite(ledPin3, LOW);
    } else {
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
    }
  } else {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    buttonPressStartTime = 0;
  }
}
