#ifndef _TIME_H
#define _TIME_H

typedef struct _timeFormat
{
  unsigned short hour;
  unsigned short minute;
  unsigned short second;
}timeFormat;

void update_time();
void setTime(timeFormat inputTime);
void printTime();
bool compareTime(timeFormat userTime);
unsigned short getHour();
unsigned short getMinute();
unsigned short getSecond();
void incrementSecond();


#endif /* _TIME_H */
