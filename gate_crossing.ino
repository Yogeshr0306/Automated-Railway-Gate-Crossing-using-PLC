#include <Servo.h>  // Include the Servo library

// Define pin numbers for sensors, signals, and buzzer
const int IRsensor1 = 2;    // input for IR sensor 1
const int IRsensor2 = 3;    // input for IR sensor 2
const int trainSignal = 13;  // output for train signal (obstacle detected)
const int roadSignal1 = 5;  // output for road signal 1 (Red light)
const int roadSignal2 = 6;  // output for road signal 2 (Green light)
const int buzzer = 8;       // output for buzzer/alarm

// Servo motors for the gates
Servo gate1;  // Servo for gate 1
Servo gate2;  // Servo for gate 2

// Define gate positions
const int gateOpenPosition = 90;   // Gate open (90 degrees)
const int gateClosedPosition = 0;  // Gate closed (0 degrees)

// Timer variables
unsigned long timerStart = 0;  // Store the start time for the timer
bool trainArrived = true;      // Flag to track if the train has arrived
bool timerRunning = true;      // Flag to track if the timer is running

void setup() {
  // Set up pin modes
  pinMode(IRsensor1, INPUT);
  pinMode(IRsensor2, INPUT);
  pinMode(trainSignal, OUTPUT);
  pinMode(roadSignal1, OUTPUT);
  pinMode(roadSignal2, OUTPUT);
  pinMode(buzzer, OUTPUT);

  // Attach the servos to the pins
  gate1.attach(9);   // Attach gate 1 servo to pin 7
  gate2.attach(10);  // Attach gate 2 servo to pin 8

  // Initialize all outputs to LOW
  digitalWrite(trainSignal, LOW);
  digitalWrite(roadSignal1, LOW);
  digitalWrite(roadSignal2, LOW);
  digitalWrite(buzzer, LOW);

  // Initialize servos to the open position
  gate1.write(gateOpenPosition);  // Gates start open
  gate2.write(gateOpenPosition);
}

void loop() {
  delay(10000);
  digitalWrite(trainSignal, HIGH);
  digitalWrite(roadSignal1, HIGH);
  digitalWrite(roadSignal2, HIGH);
  digitalWrite(buzzer, HIGH);       // Turn on buzzer (alarm)
  gate1.write(gateClosedPosition);  // Keep gate 1 closed
  gate2.write(gateClosedPosition);  // Keep gate 2 closed

  delay(10000);
    digitalWrite(trainSignal, 0);
  digitalWrite(roadSignal1, LOW);
  digitalWrite(roadSignal2, LOW);
  gate1.write(gateOpenPosition);  // Keep gate 1 closed
  gate2.write(gateOpenPosition);  // Keep gate 2 closed
  digitalWrite(buzzer, LOW);     // Turn on buzzer (alarm)
  timerRunning = false;           // Stop the timer after 30 seconds
  // Rung 4: Outputs activated by timer done bit
}
