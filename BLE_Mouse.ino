#include <BleMouse.h>

#define Red_Led 26
#define Green_Led 27

#define U_Button 32
#define D_Button 33
#define R_Button 34
#define L_Button 35
#define C_Button 25

// BLEMOUTS global declatation
BleMouse bleMouse;

bool status = true;

void setup() {
  Serial.begin(115200);
  pinMode(Red_Led, OUTPUT);
  pinMode(Green_Led, OUTPUT);
  pinMode(U_Button, INPUT);
  pinMode(D_Button, INPUT);
  pinMode(R_Button, INPUT);
  pinMode(L_Button, INPUT);
  pinMode(C_Button, INPUT);
  Serial.println("Starting BLE work!");
  bleMouse.begin();
}

void loop() {
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
void button_pressed() {
  digitalWrite(Green_Led, HIGH);
}
// delay between data
void scroll_delay() {
  delay(150);
}
// when bluetooth is not connected1
void not_connected() {
  digitalWrite(Red_Led, HIGH);
  delay(500);
  digitalWrite(Red_Led, LOW);
  delay(500);
}