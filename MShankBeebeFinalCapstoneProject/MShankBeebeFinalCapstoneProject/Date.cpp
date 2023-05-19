#include "Date.h"

int Date::getDay() 
{
	return day;
}

void Date::setDay(int d)
{
	day = d;
}

int Date::getMonth()
{
	return month;
}

void Date::setMonth(int m)
{
	month = m;
}

bool Date::isDateValid(int d, int m)
{
    if ((m == 4) || (m == 6) || (m == 9) || (m == 11))
        if (d >= 1 && d <= 30)
            return true;
        else
            return false;
    else if (month == 2)
        if (d >= 1 && d <= 28)
            return true;
        else
            return false;
    //check
    else if ((m == 1) || (m == 3) || (m == 5) || (m == 7) || (m == 8) || (m == 10) || (m == 12))
        if (d >= 1 && d <= 31)
            return true;
        else
            return false;
    else
        return false;
}

Date::Date(int d, int m)
{
    day = d;
    month = m;
}
