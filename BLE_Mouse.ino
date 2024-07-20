// Download the BleMouse Library from the provided link.
// https://github.com/T-vK/ESP32-BLE-Mouse

#include <BleMouse.h>

#define Red_Led 26    // BLE not Connected
#define Green_Led 27  // Blink on Button is pressed

#define U_Button 32  // Up side button
#define D_Button 33  // Down side button
#define R_Button 34  // Right side button
#define L_Button 35  // Left side button
#define C_Button 25  // Center(Ok) button

// BLEMOUSE global declatation
BleMouse bleMouse;

// Check BLE connection status
bool status = true;

void setup() {
  // Initialize Serial monitor
  Serial.begin(115200);
  // Define Pinmode (INPUT/OUTPUT)
  pinMode(Red_Led, OUTPUT);
  pinMode(Green_Led, OUTPUT);
  pinMode(U_Button, INPUT);
  pinMode(D_Button, INPUT);
  pinMode(R_Button, INPUT);
  pinMode(L_Button, INPUT);
  pinMode(C_Button, INPUT);
  // Initialize BLE
  Serial.println("Start BLE!");
  bleMouse.begin();  // Connect to another BLE/Bluetooth device
}
// main Loop
void loop() {
  // Check is BLE connected ?
  if (bleMouse.isConnected()) {
    if (status == true) {
      digitalWrite(Green_Led, HIGH);
      delay(1000);
      status = false;
    }
    digitalWrite(Green_Led, LOW);
    mouse_connected();
  } else {
    not_connected();
  }
}
void mouse_connected() {
  if (digitalRead(U_Button) == 1) {
    bleMouse.move(0, 0, 1);
    button_pressed();
    Serial.println("Scrolling Up");
    scroll_delay();
  }
  if (digitalRead(D_Button) == 1) {
    bleMouse.move(0, 0, -1);
    button_pressed();
    Serial.println("Scrolling Down");
    scroll_delay();
  }
  if (digitalRead(R_Button) == 1) {
    bleMouse.click(MOUSE_RIGHT);
    button_pressed();
    Serial.println("Click Right");
    delay(250);
  }
  if (digitalRead(L_Button) == 1) {
    bleMouse.click(MOUSE_LEFT);
    button_pressed();
    Serial.println("Click Left");
    delay(250);
  }
  if (digitalRead(C_Button) == 1) {
    bleMouse.click(MOUSE_LEFT);
    button_pressed();
    Serial.println("Click Center");
    delay(250);
  } else {
    digitalWrite(Green_Led, LOW);
  }
}
// Blink the green LED when any button is pressed
void button_pressed() {
  digitalWrite(Green_Led, HIGH);
}
// delay between data
void scroll_delay() {
  delay(15.5);
}
// when bluetooth is not connected
void not_connected() {
  digitalWrite(Red_Led, HIGH);
  delay(500);
  digitalWrite(Red_Led, LOW);
  delay(500);
}