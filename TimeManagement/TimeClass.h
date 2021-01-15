/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef TIME_H
#define TIME_H

#include <time.h>

class TimeClass {
public:
    // Absoluter Zeitstempel, aktuelle Uhrzeit
    TimeClass();

    // Absoluter oder relativer Zeitstempel
    TimeClass(struct tm &value, bool relative);

    TimeClass(const TimeClass &orig);

    virtual ~TimeClass();

    // Additionsoperator, kann entweder zwei relative oder
    // einen absoluten und einen relativen Zeitstempel verarbeiten
    // Wenn einer der Operatoren absolut ist, kommt ein absoluter
    // Zeitstempel heraus, sonst ein relativer
    TimeClass operator+(const TimeClass &orig) const;

    // Subtraktionsoperator, kann beliebige Kombinationen verarbeiten
    // außer relativ - absolut. Differenz zweier absoluter Zeiten ist
    // eine relative Zeit, Differenz einer absoluten und einer relativen
    // Zeit ist absolut, Differenz zweier relativer Zeiten ist wieder
    // relativ.
    TimeClass operator-(const TimeClass &orig) const;

    // In-place-Additionsoperator, kann wie x = x+y implementiert werden
    TimeClass &operator+=(const TimeClass &orig);

    // In-place-Subtraktionsoperator, kann wie x = x-y implementiert werden
    TimeClass &operator-=(const TimeClass &orig);

    friend std::ostream &operator<<(std::ostream &out, const TimeClass &time);

    friend std::istream &operator>>(std::istream &in, TimeClass &time);

    // Gibt die Anzahl aller Aufrufe der jeweiligen Konstruktoren und
    // Desktruktoren aus.
    static void dumpCalls();

private:
    struct tm value;
    bool relative;
    static unsigned long int stanCalls;
    static unsigned long int consCalls;
    static unsigned long int copyCalls;
    static unsigned long int destCalls;
    static unsigned long int plusCalls;
    static unsigned long int minusCalls;
    static unsigned long int pleqCalls;
    static unsigned long int mineqCalls;
};

TimeClass operator "" _yr(unsigned long long int);

TimeClass operator "" _mo(unsigned long long int);

TimeClass operator "" _dy(unsigned long long int);

TimeClass operator "" _hr(unsigned long long int);

TimeClass operator "" _mi(unsigned long long int);

TimeClass operator "" _se(unsigned long long int);

#endif /* TIME_H */

