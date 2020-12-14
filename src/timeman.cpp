#include "timeman.h"

bool checkforleap(int y)
{
    if (y % 4 == 0)
    {
        if (y % 100 == 0)
        {
            if (y % 400 == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}

int getmonthlen(int m)
{
    switch (m)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
            break;

        default:
            return 28;
            break;
    }
}

bool operator<(tm a, tm b)
{
    if (a.tm_year == b.tm_year)
    {
        if (a.tm_mon == b.tm_mon)
        {
            if (a.tm_mday == b.tm_mday)
            {
                if (a.tm_hour == b.tm_hour)
                {
                    if (a.tm_min == b.tm_min)
                    {
                        return a.tm_sec < b.tm_sec;
                    }
                    else
                    {
                        return a.tm_min < b.tm_min;
                    }
                }
                else
                {
                    return a.tm_hour < b.tm_hour;
                }
                    
            }
            else
            {
                return a.tm_mday < b.tm_mday;
            }
                
        }
        else
        {
            return a.tm_mon < b.tm_mon;
        }
    }
    else
    {
        return a.tm_year < b.tm_year;
    }
}

int operator-(tm a, tm b)
{
    int ans = 0;
    b.tm_hour = a.tm_hour;
    b.tm_min = a.tm_min;
    b.tm_sec = a.tm_sec;

    while (b < a)
    {
        b.tm_mday++;
        ans++;
        if (b.tm_mday > getmonthlen(b.tm_mon))
        {
            b.tm_mday = 1;
            b.tm_mon++;
            if (b.tm_mon > 12)
            {
                b.tm_year++;
                b.tm_mon = 1;
            }
        }
    }
    return ans;
}

tm gettime()
{
    time_t tt = time(NULL);
    tm t;
    t = *localtime(&tt);
    t.tm_year += 1900;
    t.tm_mon++;
    return t;
}