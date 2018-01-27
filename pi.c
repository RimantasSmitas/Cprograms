
// max7219_two
// Based on https://gist.github.com/nrdobie/8193350
#include <wiringPi.h>
#define SS_PIN 10

// MAX7219 SPI LED Driver
#define MAX7219_TEST 0x0f // in real code put into a .h file
#define MAX7219_BRIGHTNESS 0x0a // in real code put into a .h file
#define MAX7219_SCAN_LIMIT 0x0b // in real code put into a .h file
#define MAX7219_DECODE_MODE 0x09 // in real code put into a .h file
#define MAX7219_SHUTDOWN 0x0C // in real code put into a .h file

void maxTransferCMD(int address, int value) {  
int i;

  digitalWrite(SS_PIN, LOW);   
  SPI.transfer(address);      // Send address.
  SPI.transfer(value);        // Send the value.
  SPI.transfer(address);      // Send address. 
  SPI.transfer(value);        // Send the value.
  digitalWrite(SS_PIN, HIGH); // Finish transfer.
}

void maxTransferDATA(int address,int value, int v2) {  
int i;

  digitalWrite(SS_PIN, LOW);   

  SPI.transfer(address);      // Send address.
  SPI.transfer(value);        // Send the value.
  SPI.transfer(address);      // Send address. 
  SPI.transfer(v2);           // Send the value.

  digitalWrite(SS_PIN, HIGH); // Finish transfer.
}

void setup() {

  int wiringPiSPISetup (int 1, int 50);

  printf("Debug Max7219");

  pinMode(SS_PIN, OUTPUT);

  SPI.setBitOrder(MSBFIRST);   // Reverse the SPI Data o/p. 
  SPI.begin();                 // Start SPI


  // Run test - All LED segments lit. 
  maxTransferCMD(MAX7219_TEST, 0x01);  delay(1000);  
  maxTransferCMD(MAX7219_TEST, 0x00);        // Finish test mode.
  maxTransferCMD(MAX7219_DECODE_MODE, 0x00); // Disable BCD mode. 
  maxTransferCMD(MAX7219_BRIGHTNESS, 0x00);  // Use lowest intensity. 
  maxTransferCMD(MAX7219_SCAN_LIMIT, 0x0f);  // Scan all digits.
  maxTransferCMD(MAX7219_SHUTDOWN, 0x01);    // Turn on chip.

}

void main() {  
setup();
int row=0;
int i=0,ud=1; // Need signed numbers.

   for(;;) {      

      i += ud; 

      if (i>255) {ud=-1;i=255;}

      if (i<0)   {ud=1 ;i=0;}

      if (row++>8) row=1;  
     
      maxTransferDATA(row, random(0,255), random(0,255));             
      maxTransferCMD(MAX7219_BRIGHTNESS,i>>4);

      delay(10); 

      Serial.print(" i ");
      Serial.print(i);
      Serial.print(" ud ");
      Serial.println(ud);
   }
}








