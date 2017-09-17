#ifndef _TIME_H
#define _TIME_H

using namespace std;

class timeFormat
{
private:
  unsigned short hour;
  unsigned short minute;
  unsigned short second; 
public:
  timeFormat();
  timeFormat(unsigned short, unsigned short, unsigned short);
  ~timeFormat();
  void init();
  void updateTime();
  void setTime(timeFormat);
  void printTime();
  bool compareTime(timeFormat);
  unsigned short getHour();
  unsigned short getMinute();
  unsigned short getSecond();
  void incrementSecond();  
};




#endif /* _TIME_H */
