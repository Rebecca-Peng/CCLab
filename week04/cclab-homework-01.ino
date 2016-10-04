int ledPin = 9;
int buttonPin = 5;

bool ledState = true;
int blinkTime = 10;
unsigned long lastBlinkTime = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:
  int oldbuttonState ;
  int newbuttonState ;

  oldbuttonState = digitalRead(buttonPin);
  delay(50);
  newbuttonState = digitalRead(buttonPin);

  if(newbuttonState != oldbuttonState){

    if(newbuttonState = LOW){

      if((millis() - lastBlinkTime) > blinkTime){
        ledState = !ledState;
        lastBlinkTime = millis();
        }
      }
    }

   if (ledState) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
