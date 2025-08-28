// Pin definitions
const int pirPin = 4;    // PIR sensor output connected to GPIO 14
const int buzzerPin = 22; // Buzzer connected to GPIO 27

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(115200);
  Serial.println("Motion-Activated Doorbell Started");
}

void loop() {
  int motionState = digitalRead(pirPin);

  if (motionState == HIGH) {
    Serial.println("Motion Detected! Ringing buzzer...");
    digitalWrite(buzzerPin, HIGH);  // Turn buzzer ON
    delay(250); 
                       // Buzzer rings for 1 second
    digitalWrite(buzzerPin, LOW);   // Turn buzzer OFF
    delay(250);                    // Wait before checking again
  }
  else {
   Serial.println("No Motion Detected!!");
    digitalWrite(buzzerPin, LOW);   // Ensure buzzer is OFF
    delay(250); 
  }
}
