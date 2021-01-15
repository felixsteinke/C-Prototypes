/*
 * Gruppe: Felix Steinke und Florian Grabowski
 */

#include <iostream>
#include "TimeClass.h"

using namespace std;

unsigned long int TimeClass::stanCalls;
unsigned long int TimeClass::consCalls;
unsigned long int TimeClass::copyCalls;
unsigned long int TimeClass::destCalls;
unsigned long int TimeClass::plusCalls;
unsigned long int TimeClass::minusCalls;
unsigned long int TimeClass::pleqCalls;
unsigned long int TimeClass::mineqCalls;


int getMonth(int yearDay);

int getMonthDay(int yearDay);

int getWeekDay(int originWeekDay, int dayDifference);

int addMonthsToYearDays(int months);


TimeClass::TimeClass() {
    time_t now = time(NULL);
    this->value = *localtime(&now);
    this->relative = false;
    stanCalls++;
}

TimeClass::TimeClass(struct tm &value, bool relative) {
    this->value = value;
    this->relative = relative;
    consCalls++;
}

TimeClass::TimeClass(const TimeClass &orig) {
    this->value = orig.value;
    this->relative = orig.relative;
    copyCalls++;
}

TimeClass::~TimeClass() {
    destCalls++;
}

TimeClass TimeClass::operator+(const TimeClass &orig) const {
    plusCalls++;
    //absolute + absolute
    if (!this->relative && !orig.relative) {
        throw std::invalid_argument("Operator + : One of the TimeValues need to be relative!");
    }
    //relative + relative
    if (this->relative && orig.relative) {
        tm value{};
        value.tm_sec = this->value.tm_sec + orig.value.tm_sec;
        value.tm_min = this->value.tm_min + orig.value.tm_min;
        value.tm_hour = this->value.tm_hour + orig.value.tm_hour;
        value.tm_mon = this->value.tm_mon + orig.value.tm_mon;
        value.tm_year = this->value.tm_year + orig.value.tm_year;
        value.tm_yday = this->value.tm_yday + orig.value.tm_yday;
        return TimeClass(value, true);
    }
    //absolute + relative OR relative + absolute
    //info: mday, wday, isdst
    tm value{};
    value.tm_sec = this->value.tm_sec + orig.value.tm_sec;
    value.tm_min = this->value.tm_min + orig.value.tm_min;
    value.tm_hour = this->value.tm_hour + orig.value.tm_hour;
    value.tm_mon = this->value.tm_mon + orig.value.tm_mon;
    value.tm_year = this->value.tm_year + orig.value.tm_year;
    value.tm_yday = this->value.tm_yday + orig.value.tm_yday;

    //Normalisierung der Sekunden (0-59)
    value.tm_min += value.tm_sec / 60;
    value.tm_sec = value.tm_sec % 60;
    //Normalisierung der Minuten (0-59)
    value.tm_hour += value.tm_min / 60;
    value.tm_min = value.tm_min % 60;
    //Normalisierung der Stunden (0-23)
    value.tm_yday += value.tm_hour / 24;
    value.tm_hour = value.tm_hour % 24;
    //Normalisierung der Monate (0-11)
    value.tm_year += value.tm_mon / 12;
    value.tm_mon = value.tm_mon % 12;
    //Normaliserung der YearDays (0-364)
    value.tm_year += value.tm_yday / 364;
    value.tm_yday = value.tm_yday % 364;
    //Jahre sind schon normalisiert

    //Berechnung des Monats (0-11)
    value.tm_mon = getMonth(value.tm_yday);
    //Berechnung des MonthDay (1-31)
    value.tm_mday = getMonthDay(value.tm_yday);
    //Berechnung des Wochentags (0-6)
    if (!orig.relative) {
        value.tm_wday = getWeekDay(orig.value.tm_wday,
                                   ((value.tm_yday - orig.value.tm_yday) + (value.tm_year - orig.value.tm_year) * 365));
    } else {
        value.tm_wday = getWeekDay(this->value.tm_wday, ((value.tm_yday - this->value.tm_yday) +
                                                         (value.tm_year - this->value.tm_year) * 365));
    }
    return TimeClass(value, false);
}

TimeClass TimeClass::operator-(const TimeClass &orig) const {
    minusCalls++;
    //relative - absolute
    if (this->relative && !orig.relative) {
        throw std::invalid_argument("Operator - : Input was absolute with a relative base.");
    }
    //absolute - relative
    if (!this->relative && orig.relative) {
        tm value{};
        value.tm_sec = this->value.tm_sec - orig.value.tm_sec;
        value.tm_min = this->value.tm_min - orig.value.tm_min;
        value.tm_hour = this->value.tm_hour - orig.value.tm_hour;
        value.tm_mon = this->value.tm_mon - orig.value.tm_mon;
        value.tm_year = this->value.tm_year - orig.value.tm_year;
        value.tm_yday = this->value.tm_yday - orig.value.tm_yday;

        //Normalisierung der Sekunden (0-59)
        while (value.tm_sec < 0) {
            value.tm_min--;
            value.tm_sec += 60;
        }
        //Normalisierung der Minuten (0-59)
        while (value.tm_min < 0) {
            value.tm_hour--;
            value.tm_min += 60;
        }
        //Normalisierung der Stunden (0-23)
        while (value.tm_hour < 0) {
            value.tm_yday--;
            value.tm_hour += 24;
        }
        //Normalisierung der Monate (0-11)
        while (value.tm_mon < 0) {
            value.tm_year--;
            value.tm_mon += 12;
        }
        //Normaliserung der YearDays (0-364)
        while (value.tm_yday < 0) {
            value.tm_year--;
            value.tm_yday += 365;
        }
        //Jahre sind schon normalisiert

        //Berechnung des Monats (0-11)
        value.tm_mon = getMonth(value.tm_yday);
        //Berechnung des MonthDay (1-31)
        value.tm_mday = getMonthDay(value.tm_yday);
        //Berechnung des Wochentags (0-6)
        value.tm_wday = getWeekDay(this->value.tm_wday, ((value.tm_yday - this->value.tm_yday) +
                                                         (value.tm_year - this->value.tm_year) * 365));
        return TimeClass(value, false);
    }
    //relative - relative OR absolute - absolute
    tm value{};
    value.tm_sec = this->value.tm_sec - orig.value.tm_sec;
    value.tm_min = this->value.tm_min - orig.value.tm_min;
    value.tm_hour = this->value.tm_hour - orig.value.tm_hour;
    value.tm_yday = this->value.tm_yday - orig.value.tm_yday;
    value.tm_mon = this->value.tm_mon - orig.value.tm_mon;
    value.tm_year = this->value.tm_year - orig.value.tm_year;
    return TimeClass(value, true);
}

TimeClass &TimeClass::operator+=(const TimeClass &orig) {
    pleqCalls++;
    TimeClass temp = this->operator+(orig);
    this->value = temp.value;
    this->relative = temp.relative;
    return *this;
}

TimeClass &TimeClass::operator-=(const TimeClass &orig) {
    mineqCalls++;
    TimeClass temp = this->operator-(orig);
    this->value = temp.value;
    this->relative = temp.relative;
    return *this;
}

void TimeClass::dumpCalls() {
    cout << "All in all, the following methods were called:" << endl;
    cout << "Stan: " << stanCalls << endl;
    cout << "Cons: " << consCalls << endl;
    cout << "Copy: " << copyCalls << endl;
    cout << "Dest: " << destCalls << endl;
    cout << "Plus: " << plusCalls << endl;
    cout << "Minus: " << minusCalls << endl;
    cout << "PlusEq: " << pleqCalls << endl;
    cout << "MinusEq: " << mineqCalls << endl;
}

std::ostream &operator<<(std::ostream &out, const TimeClass &time) {
    if (time.relative) {
        return out << time.value.tm_mday << '-' << time.value.tm_mon << '-' << time.value.tm_year << ' '
                   << time.value.tm_hour << ':' << time.value.tm_min << ':' << time.value.tm_sec;
    }
    string s;
    switch (time.value.tm_wday) {
        case 1:
            s = "Montag";
            break;
        case 2:
            s = "Dienstag";
            break;
        case 3:
            s = "Mittwoch";
            break;
        case 4:
            s = "Donnerstag";
            break;
        case 5:
            s = "Freitag";
            break;
        case 6:
            s = "Samstag";
            break;
        default:
            s = "Sonntag";
    }
    return out << s << " der " << time.value.tm_mday << '.' << time.value.tm_mon + 1 << '.' << time.value.tm_year + 1900
               << ", " << time.value.tm_hour << ':' << time.value.tm_min << ':' << time.value.tm_sec;
}

std::istream &operator>>(std::istream &in, TimeClass &time) {
    char c;
    in >> time.value.tm_mday >> c >> time.value.tm_mon >> c >> time.value.tm_year >> c >> time.value.tm_hour >> c
       >> time.value.tm_min >> c >> time.value.tm_sec;
    time.value.tm_mon -= 1;
    time.value.tm_year -= 1900;
    return in;
}

TimeClass operator "" _yr(unsigned long long int time) {
    tm value{};
    value.tm_year = time;
    return TimeClass(value, true);
}

TimeClass operator "" _mo(unsigned long long int time) {
    tm value{};
    value.tm_mon = time;
    return TimeClass(value, true);
}

TimeClass operator "" _dy(unsigned long long int time) {
    tm value{};
    value.tm_yday = time;
    return TimeClass(value, true);
}

TimeClass operator "" _hr(unsigned long long int time) {
    tm value{};
    value.tm_hour = time;
    return TimeClass(value, true);
}

TimeClass operator "" _mi(unsigned long long int time) {
    tm value{};
    value.tm_min = time;
    return TimeClass(value, true);
}

TimeClass operator "" _se(unsigned long long int time) {
    tm value{};
    value.tm_sec = time;
    return TimeClass(value, true);
}


int getMonth(int yearDay) {
    if (yearDay < 31) {
        return 0;
    } else if (yearDay < 59) {
        return 1;
    } else if (yearDay < 90) {
        return 2;
    } else if (yearDay < 120) {
        return 3;
    } else if (yearDay < 151) {
        return 4;
    } else if (yearDay < 181) {
        return 5;
    } else if (yearDay < 212) {
        return 6;
    } else if (yearDay < 242) {
        return 7;
    } else if (yearDay < 273) {
        return 8;
    } else if (yearDay < 303) {
        return 9;
    } else if (yearDay < 334) {
        return 10;
    } else {
        return 11;
    }
}

int getMonthDay(int yearDay) {
    if (yearDay < 31) {
        return yearDay;
    } else if (yearDay < 59) {
        return yearDay - 31;
    } else if (yearDay < 90) {
        return yearDay - 59;
    } else if (yearDay < 120) {
        return yearDay - 90;
    } else if (yearDay < 151) {
        return yearDay - 120;
    } else if (yearDay < 181) {
        return yearDay - 151;
    } else if (yearDay < 212) {
        return yearDay - 181;
    } else if (yearDay < 242) {
        return yearDay - 212;
    } else if (yearDay < 273) {
        return yearDay - 242;
    } else if (yearDay < 303) {
        return yearDay - 273;
    } else if (yearDay < 334) {
        return yearDay - 303;
    } else {
        return yearDay - 333;
    }
}

int getWeekDay(int originWeekDay, int dayDifference) {
    return (originWeekDay + dayDifference) % 7;
}