//
// Created by user on 11/9/17.
//


#ifndef TIME_H
#define TIME_H

class Time
{
private:
    int m_year;
    int m_month;
    int m_day;

public:
    Time(int year, int month, int day);

    void SetDate(int year, int month, int day);

    int getYear() { return m_year; }
    int getMonth() { return m_month; }
    int getDay()  { return m_day; }
};

#endif