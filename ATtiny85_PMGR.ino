//=========================================================================================================
//
// Description: Power and charging script for RPi
//  
// Author      : APPSB 22/05/2015
//
// License     : GPL
//
//=========================================================================================================
bool isUSBPower = false;
bool isCharging = false;
bool isRPI_on = false;
bool isSwitchPressed = false;
bool isRPI_soft_poweredDown = false;
int switchPressedCounter = 0;
//=========================================================================================================
void setup() {                
//=========================================================================================================
  pinMode(0, OUTPUT); // switch on relay for powering the RPi
  pinMode(1, INPUT);  // test for +5v from RPi
  pinMode(4, INPUT);  // test for switch pressed  
  pinMode(3, OUTPUT); // switch on relay for charging the li-ion battery   
  pinMode(2, OUTPUT); // send signal to RPi to shutdown the RPi
  pinMode(5, INPUT);  // receive signal from RPi to indicate it has shut down
}
//=========================================================================================================
void loop() {
//=========================================================================================================  
  isUSBPower = digitalRead(1); //Returns HIGH or LOW (true or false / 1 or 0).
  isRPI_soft_poweredDown = digitalRead(5); 
  
  // Determine if the RPi is powered via a USB hub, if so start charging the li-ion battery
  if (isUSBPower == true) {
    isCharging = true; 
    isRPI_on = true;          // The RPi is already on or booting from external USB hib
    digitalWrite(0, HIGH);    // turn the LED on (HIGH is the voltage level)
    delay(2000);
  } else {
    isCharging = false; 
    digitalWrite(0, LOW);    // turn the LED off by making the voltage LOW
    delay(2000);               
  }
  
  if (isCharging) {
     // set pinout to +5v and switch relay to disconnect battery and start charging it 
     digitalWrite(3, HIGH);   // switch on relay for charging the li-ion battery   

  }
  
  //
  // if the switch has been pressed and is not charging and the RPi is not on, power the RPI via the battery
  //
  if (isSwitchPressed && !isCharging && !isRPI_on) {    
     // set pinout to +5v and switch relay on to power RPi via battery
     if (switchPressedCounter <= 0) { 
        digitalWrite(0, HIGH);   //  switch on relay for powering the RPi
        isRPI_on = true;
        switchPressedCounter++;  // increment the number of times the switch has been pressed        
     } 
   }    
 
  //
  // if the switch has been pressed and is not charging and the RPi is on, powerdown the RPI via signal to RPi
  // 
  if (isSwitchPressed && !isCharging && isRPI_on) {    
     // set pinout to +5v and switch relay on to power RPi via battery
     if (switchPressedCounter >= 1) {
        digitalWrite(2, HIGH);     //  send signal to shutdown the RPi
        switchPressedCounter = 0;  //  reset the number of times the button has been pressed
     }    
  }

  //
  // if the RPi has powerd down disconnect the battery from the RPi
  //
  if (isRPI_on && switchPressedCounter == 0 && isRPI_soft_poweredDown) {
           digitalWrite(0, LOW);   //  switch off the relay for powering the RPi
  } 
  
}
//=========================================================================================================

