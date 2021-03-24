#include "Time.h"
#include <sstream>
#include <iomanip>

bool is_valid(Time const& t)
{
    return ((t.h >= 0 && t.h < 24) && (t.m >= 0 && t.m < 60) && (t.s >= 0 && t.s < 60));
}

bool is_am(Time const& t)
{
    return ((t.h < 12));
}

std::string to_string(Time const& t, bool format12)
{
    std::ostringstream os{};
    os << std::setw(2) << std::setfill('0');
    if (format12)
    {
        if (t.h == 0)
        {
            os << 12;
        }
        else if (is_am(t) or t.h == 12)
        {
            os << t.h;
        }
        else
        {
            os << t.h - 12;
        }
    }
    else
    {
        os << t.h;
    }
    
    os << ":" << std::setw(2) << t.m << ":" << std::setw(2) << t.s;
    if (format12)
    {
        os << "[";
        if (is_am(t))
        {
            os << "am";
        }
        else
        {
            os << "pm";
        }
        os << "]";
    }
                       
    return os.str();
}


bool operator==(Time const& t1, Time const& t2)
{
    return ((t1.h == t2.h) && (t1.m == t2.m) && (t1.s == t2.s));
}

bool operator!=(Time const& t1, Time const& t2)
{
    return (!(t1 == t2));
}

bool operator>(Time const& t1, Time const& t2)
{
    return ((t1.h > t2.h) || ((t1.h == t2.h) && (t1.m > t2.m))
            || ((t1.h == t2.h) && (t1.m == t2.m) && (t1.s > t2.s)));
}

bool operator>=(Time const& t1, Time const& t2)
{
    return (t1 > t2 || t1 == t2);
}

bool operator<(Time const& t1, Time const& t2)
{
    return ((t1.h < t2.h) || ((t1.h == t2.h) && (t1.m < t2.m))
            || ((t1.h == t2.h) && (t1.m == t2.m) && (t1.s < t2.s)));
}

bool operator<=(Time const& t1, Time const& t2)
{
    return (t1 < t2 || t1 == t2);
}


Time operator+(Time const& t, int n)
{
    Time b{t};
    b.s = t.s + n;
    if (b.s >= 60)
    {
        b.m += b.s / 60;
        b.s %= 60;
    }
    
    if (b.m >= 60)
    {
        b.h += b.m / 60;
        b.m %= 60;
    }
    
    if (b.h >= 24)
    {
        b.h %= 24;
    }

    return b;
}

Time operator-(Time const& t, int n)
{
    Time b{t};
    b.s = t.s - n;
    
    if (b.s < 0)
    {
        b.m -= -b.s / 60 + 1;
        b.s = ((b.s % 60) + 60 ) % 60;
    }
    
    if (b.m < 0)
    {
        b.h -= -b.m / 60 + 1;
        b.m = ((b.m % 60) + 60) % 60;
    }
    
    if (b.h < 0)
    {
        b.h = ((b.h % 24) + 24) % 24;
    }
    
    return b;
}


Time& operator++(Time& t)
{
    t = t + 1;
    return t;
}

Time operator++(Time& t, int)
{
    Time temp{t};
    ++t;
    return temp;
}

Time& operator--(Time& t)
{
    t = t - 1;
    return t;
}

Time operator--(Time& t, int)
{
    Time temp{t};
    --t;
    return temp;
}

std::ostream& operator<<(std::ostream& os, Time const& t)
{
    os << to_string(t, false);
    return os;
}

std::istream& operator>>(std::istream& is, Time & t)
{
    is >> t.h;
    is.ignore(1, ':');
    is >> t.m;
    is.ignore(1, ':');
    is >> t.s;
    if (not is_valid(t))
    {
    is.setstate(std::ios_base::failbit);
    }
    return is;
}