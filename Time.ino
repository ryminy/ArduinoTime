#include "Time.h"
#define ledPin 13

timeFormat time;

void setup()
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);      // open the serial port at 9600 bps:   
  noInterrupts();           // disable all interrupts
  time.init();
  interrupts();             // enable all interrupts  
}

ISR(TIMER1_COMPA_vect)          // timer compare interrupt service routine
{
  time.incrementSecond();
  digitalWrite(ledPin, digitalRead(ledPin) ^ 1);   // toggle LED pin
}

void loop()
{
  unsigned short sec = 0;
  timeFormat userTime(19,29,00);
  
  time.setTime(userTime);

  while(1)
  {
    noInterrupts();           // disable all interrupts
    time.updateTime();
    interrupts();             // enable all interrupts

    if (sec != time.getSecond())
    {
      time.printTime();
      sec = time.getSecond();
    }
  }
}
