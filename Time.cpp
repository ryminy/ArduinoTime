#include <HardwareSerial.h>
#include<stdio.h>

#include "Time.h"

timeFormat time = {0,0,0};

void update_time()
{
  if (time.second >= 60)
  {
    time.minute++;
    time.second = 0;
  }

  if (time.minute >= 60)
  {
    time.hour++;
    time.minute = 0;
  }

  if (time.hour >= 24)
  {
    time.hour = 0;
  }  
}

void setTime(timeFormat inputTime)
{
  time.hour = inputTime.hour;
  time.minute = inputTime.minute;
  time.second = inputTime.second;   
}

void printTime()
{
  char buff[9];
  sprintf(buff,"%02d:%02d:%02d\n", time.hour, time.minute, time.second);
  Serial.print(buff);
}

bool compareTime(timeFormat userTime)
{
  if ((userTime.hour == time.hour) && (userTime.minute == time.minute) && (userTime.second == time.second))
    return true;

  return false;
}

unsigned short getSecond()
{
  return time.second;
}

unsigned short getMinute()
{
  return time.minute;
}

unsigned short getHour()
{
  return time.hour;
}

void incrementSecond()
{
  time.second ++;
}

