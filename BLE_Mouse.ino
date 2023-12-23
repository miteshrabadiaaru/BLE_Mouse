#include <BleMouse.h>

#define U_Button
#define D_Button
#define R_Button
#define L_Button
#define C_Button

// BLEMOUTS global declatation
BleMouse bleMouse;

bool status = true;

void setup() {
  Serial.begin(115200);
  pinMode(U_Button,INPUT);
  pinMode(D_Button,INPUT);
  pinMode(R_Button,INPUT);
  pinMode(L_Button,INPUT);
  pinMode(C_Button,INPUT);
  Serial.println("Starting BLE work!");
  bleMouse.begin();
}

void loop() {
  if(bleMouse.isConnected()) {
    if(status == true){
      status = false;
    }
    mouse_connected();
  }else{
    not_connected();
  }
}

void mouse_connected(){

}
void not_connected(){
  
}