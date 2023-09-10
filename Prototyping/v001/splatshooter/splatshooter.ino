//identify pins
const int triggerPin = 4;
const int laserPin = 8;

//intialize variables
bool currentTriggerState = false;
bool lastTriggerState = false;

void setup() {
  //set pin modes
  pinMode(triggerPin, INPUT);
  pinMode(laserPin, OUTPUT);

  //explicitly establish the laser low
  digitalWrite(laserPin, LOW);
}

void loop() {
  //store the previous frame's trigger state
  lastTriggerState = currentTriggerState;

  //read the current trigger state
  currentTriggerState = digitalRead(triggerPin);

  //detect the moment the trigger is pulled, and if it is, flash the laser once
  if (lastTriggerState==false && currentTriggerState==true) {
    digitalWrite(laserPin, HIGH);
    delay(100);
    digitalWrite(laserPin, LOW);
  }

  delay(10);
}
