int lampu1 = 12;
int lampu2 = 13;// choose the pin for the LED
int pir1 = 2;
int pir2 = 4; // choose the input pin (for PIR sensor)
int pirState1 = LOW;             // we start, assuming no motion detected
int pirState2 = LOW;
int val1 = 0;                    // variable for reading the pin status
int val2 = 0;

void setup() {
  pinMode(lampu1, OUTPUT);      // declare LED as output
  pinMode(pir1, INPUT);     // declare sensor as input

  pinMode(lampu2, OUTPUT);      // declare LED as output
  pinMode(pir2, INPUT);     // declare sensor as input

  Serial.begin(9600);
}

void loop() {
  val1 = digitalRead(pir1);  // read input val1ue
  val2 = digitalRead(pir2);  // read input val1ue
  if (val1 == HIGH) {            // check if the input is HIGH
    digitalWrite(lampu1, LOW);  // turn LED ON
    if (pirState1 == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      pirState1 = HIGH;
    }
  }

  if (val2 == HIGH) {            // check if the input is HIGH
    digitalWrite(lampu2, LOW);  // turn LED ON
    if (pirState2 == LOW) {
      // we have just turned on
      Serial.println("Motion detected 2!");
      // We only want to print on the output change, not state
      pirState2 = HIGH;
    }
  }

  if (val1 == LOW) {
    digitalWrite(lampu1, HIGH); // turn LED OFF
    if (pirState1 == HIGH) {
      // we have just turned of
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState1 = LOW;
    }
  }

  if (val2 == LOW) {
    digitalWrite(lampu2, HIGH); // turn LED OFF
    if (pirState2 == HIGH) {
      // we have just turned of
      Serial.println("Motion ended 2!");
      // We only want to print on the output change, not state
      pirState2 = LOW;
    }
  }
}

