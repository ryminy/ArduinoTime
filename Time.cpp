#include <HardwareSerial.h>
#include<stdio.h>

#include "Time.h"

timeFormat::timeFormat(unsigned short hour, unsigned short min, unsigned short sec)
{
  this->second = sec;
  this->minute = min;
  this->hour = hour;  
}

timeFormat::timeFormat()
{
  this->second = 0;
  this->minute = 0;
  this->hour = 0;
}

timeFormat::~timeFormat()
{
  this->second = 0;
  this->minute = 0;
  this->hour = 0;  
}

void timeFormat::init()
{
  // initialize timer1 
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;

  OCR1A = 62500;            // compare match register 16MHz/256/1Hz
  TCCR1B |= (1 << WGM12);   // CTC mode
  TCCR1B |= (1 << CS12);    // 1024 prescaler 
  TIMSK1 |= (1 << OCIE1A);  // enable timer compare interrupt 
}

void timeFormat::updateTime()
{
  if (this->second >= 60)
  {
    this->minute++;
    this->second = 0;
  }

  if (this->minute >= 60)
  {
    this->hour++;
    this->minute = 0;
  }

  if (this->hour >= 24)
  {
    this->hour = 0;
  }  
}

void timeFormat::setTime(timeFormat inputTime)
{
  this->hour = inputTime.hour;
  this->minute = inputTime.minute;
  this->second = inputTime.second;    
}

void timeFormat::printTime()
{
  char buff[9];
  sprintf(buff,"%02d:%02d:%02d\n", this->hour, this->minute, this->second);
  Serial.print(buff);  
}

bool timeFormat::compareTime(timeFormat userTime)
{
  if ((userTime.hour == this->hour) && (userTime.minute == this->minute) && (userTime.second == this->second))
    return true;

  return false;  
}

unsigned short timeFormat::getSecond()
{
  return this->second;  
}

unsigned short timeFormat::getMinute()
{
  return this->minute;  
}

unsigned short timeFormat::getHour()
{
  return this->hour;  
}

void timeFormat::incrementSecond()
{
  this->second ++;  
}




