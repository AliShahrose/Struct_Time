#ifndef TIME_H
#define TIME_H

#include <string>

struct Time
{
    int h{0};
    int m{0};
    int s{0};
};

bool is_valid(Time const&);

bool is_am(Time const&);

bool operator==(Time const&, Time const&);
bool operator!=(Time const&, Time const&);

bool operator>(Time const&, Time const&);
bool operator>=(Time const&, Time const&);
bool operator<(Time const&, Time const&);
bool operator<=(Time const&, Time const&);

Time operator+(Time const&, int);
Time operator-(Time const&, int);

Time& operator++(Time&);
Time operator++(Time&, int);
Time& operator--(Time&);
Time operator--(Time&, int);

std::ostream& operator<<(std::ostream&, Time const&);
std::istream& operator>>(std::istream&, Time &);

std::string to_string(Time const& t, bool format12 = false);


#endif