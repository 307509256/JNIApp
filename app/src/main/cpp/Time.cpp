//
// Created by user on 11/9/17.
//

#include "Time.h"

// Time constructor
Time::Time(int year, int month, int day)
{
    SetDate(year, month, day);
}

// Time member function
void Time::SetDate(int year, int month, int day)
{
    m_month = month;
    m_day = day;
    m_year = year;
}

