#include "Time.h"
#define ledPin 13


void initTimer()
{
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;

  OCR1A = 62500;            // compare match register 16MHz/256/1Hz
  TCCR1B |= (1 << WGM12);   // CTC mode
  TCCR1B |= (1 << CS12);    // 1024 prescaler 
  TIMSK1 |= (1 << OCIE1A);  // enable timer compare interrupt  
}

void setup()
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);      // open the serial port at 9600 bps:    
  // initialize timer1 
  noInterrupts();           // disable all interrupts
  initTimer();
  interrupts();             // enable all interrupts
}

ISR(TIMER1_COMPA_vect)          // timer compare interrupt service routine
{
  incrementSecond();
  digitalWrite(ledPin, digitalRead(ledPin) ^ 1);   // toggle LED pin
}

void loop()
{
  unsigned short sec = 0;
  timeFormat userTime = {19,29,00};
  
  setTime(userTime);

  while(1)
  {
    noInterrupts();           // disable all interrupts
    update_time();
    interrupts();             // enable all interrupts

    if (sec != getSecond())
    {
      printTime();
      sec = getSecond();
    }
  }
}
