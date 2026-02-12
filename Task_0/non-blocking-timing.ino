/*
  Task 01 – Heartbeat and Non-Blocking Timing
  Board  : Teensy 4.1
  Purpose: Learn cooperative multitasking using millis()
*/

unsigned long lastBlink = 0;   // Last LED toggle time
unsigned long lastPrint = 0;   // Last serial print time

const unsigned long blinkInterval = 500;   // LED heartbeat interval (ms)
const unsigned long printInterval = 1000;  // Serial uptime print interval (ms)

void setup() {
  pinMode(13, OUTPUT);          // Built-in LED on Teensy 4.1
  Serial.begin(115200);

  while (!Serial && millis() < 3000) {
    // Optional: wait for Serial Monitor (timeout safe)
  }

  Serial.println("Task 01: Heartbeat and Timing Started");
}

void loop() {
  unsigned long now = millis();   // Current system uptime

  // ---- LED Heartbeat Task ----
  if (now - lastBlink >= blinkInterval) {
    digitalWrite(13, !digitalRead(13));  // Toggle LED
    lastBlink = now;
  }

  // ---- Serial Logging Task ----
  if (now - lastPrint >= printInterval) {
    Serial.print("Uptime: ");
    Serial.print(now);
    Serial.println(" ms");
    lastPrint = now;
  }
}
