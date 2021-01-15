//Gruppe: Felix Steinke und Florian Grabowski

#include <istream>
#include <ostream>
#include <iostream>
#include "Fraction.h"


Fraction::Fraction(int counter, int denominator) {
    this->counter = counter;
    this->denominator = denominator;
    reduce();
}

Fraction::Fraction(double value, int maxdenom) {
    this->counter = (int) (value * maxdenom);
    this->denominator = maxdenom;
    reduce();
}

Fraction::~Fraction() {
    //The only time you have to worry about deallocating things is when you use new (C++) or malloc() (C).
}

Fraction Fraction::operator+(const Fraction &other) const {
    return Fraction(this->counter * other.denominator + other.counter * this->denominator,
                    this->denominator * other.denominator);
}

Fraction &Fraction::operator+=(const Fraction &other) {
    this->counter = this->counter * other.denominator + other.counter * this->denominator;
    this->denominator = this->denominator = this->denominator * other.denominator;
    reduce();
    return *this;
}

Fraction Fraction::operator-(const Fraction &other) const {
    return Fraction(this->counter * other.denominator - other.counter * this->denominator,
                    this->denominator * other.denominator);
}

Fraction &Fraction::operator-=(const Fraction &other) {
    this->counter = this->counter * other.denominator - other.counter * this->denominator;
    this->denominator = this->denominator * other.denominator;
    reduce();
    return *this;
}

Fraction Fraction::operator*(const Fraction &other) const {
    return Fraction(this->counter * other.counter,
                    this->denominator * other.denominator);
}

Fraction &Fraction::operator*=(const Fraction &other) {
    this->counter = this->counter * other.counter;
    this->denominator = this->denominator * other.denominator;
    reduce();
    return *this;
}

Fraction Fraction::operator/(const Fraction &other) const {
    return Fraction(this->counter * other.denominator,
                    this->denominator * other.counter);
}

Fraction &Fraction::operator/=(const Fraction &other) {
    int oldCounter = this->counter;
    int oldDenominator = this->denominator;
    int oldOtherCounter = other.counter;
    int oldOtherDenominator = other.denominator;
    this->counter = oldCounter * oldOtherDenominator;
    this->denominator = oldDenominator * oldOtherCounter;
    reduce();
    return *this;
}

bool Fraction::operator==(const Fraction &other) const {
    Fraction a = (double) *this;
    Fraction b = (double) other;
    return a.denominator == b.denominator && a.counter == b.counter;
}

Fraction::operator double() const {
    return 1.0 * this->counter / this->denominator;
}

void Fraction::reduce() {
    int gcd = Fraction::gcd(this->counter, this->denominator);
    if (gcd != 0) {
        counter /= gcd;
        denominator /= gcd;
    }
    if (denominator < 0) {
        counter *= -1;
        denominator *= -1;
    }
}

int Fraction::gcd(int a, int b) {
    int h;
    if (a == 0) return abs(b);
    if (b == 0) return abs(a);

    do {
        h = a % b;
        a = b;
        b = h;
    } while (b != 0);

    return abs(a);
}

std::ostream &operator<<(std::ostream &stream, const Fraction &fract) {
    return stream << '(' << fract.counter << "," << fract.denominator << ')';
}

std::istream &operator>>(std::istream &stream, Fraction &fract) {
    char ignore;
    return stream >> ignore >> fract.counter >> ignore >> fract.denominator >> ignore;
}