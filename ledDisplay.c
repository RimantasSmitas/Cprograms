//We always have to include the library
#include <LedControlMS.h>
#include <stdio.h>
IRrecv irrecv(RECV_PIN);

decode_results results;



const byte numChars = 32;
char receivedChars[numChars]; // an array to store the received data
boolean newData = false;
/*
  Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
  pin 12 is connected to the DataIn
  pin 11 is connected to the CLK
  pin 10 is connected to LOAD
  We have only a single MAX72XX.
*/
#define NBR_MTX 2
LedControl lc = LedControl(12, 11, 10, NBR_MTX);

void setup() {
  /*
    The MAX72XX is in power-saving mode on startup,
    we have to do a wakeup call
  */
  
  Serial.println("Setup");
  irrecv.enableIRIn(); // Start the receiver


  for (int i = 0; i < NBR_MTX; i++) {
    lc.shutdown(i, false);
    /*  Set the brightness to a medium values */
    lc.setIntensity(i, 8);
    /* and clear the display */
    lc.clearDisplay(i);
  }
}

void recvWithEndMarker() {
  static byte ndx = 0;
  char endMarker = '\n';
  char rc;

  while (Serial.available() > 0 && newData == false) {
    rc = Serial.read();
    if (rc != endMarker) {
      receivedChars[ndx] = rc;
      ndx++;
      if (ndx >= numChars) {
        ndx = numChars - 1;
      }
    }
    else {
      receivedChars[ndx] = '\0'; // terminate the string
      ndx = 0;
      newData = true;
    }
  }
}

void loop() {
  if (irrecv.decode(&results)) {
    switch(results.value)
  {    
  case 0x1111:  
    printMessage("Helo there ");
    break;
  case 0xFF629D:  
    break;
  }
    irrecv.resume(); // Receive the next value
  }
  delay(100);



  recvWithEndMarker();
  if (newData == true) {
    printMessage(receivedChars);
    newData = false;
  }
}

void printMessage(char phrase[numChars]) {
  printf("%s",phrase); 
  lc.writeString(0, phrase);
  lc.clearAll();
  delay(150);
}

/*
  void scrollLeft(char ch) {
  int pos = lc.getCharArrayPosition(ch);
  for (int scroll = 0; scroll < 6; scroll++) {
    for (int i = scroll; i < 6; i++) {
      lc.setRow(0, i - scroll, alphabetBitmap[pos][i]);
    }
    delay(300);
    lc.clearDisplay(0);
  }
  }
  void scrollRight(char ch) {
  int pos = lc.getCharArrayPosition(ch);
  for (int scroll = 0; scroll < 8; scroll++) {
    for (int i = 0; i < 6; i++) {
      if (scroll + i < 8) lc.setRow(0, scroll + i, alphabetBitmap[pos][i]);
    }
    delay(300);
    lc.clearDisplay(0);
  }
  }
*/
