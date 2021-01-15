//Gruppe: Felix Steinke und Florian Grabowski

#ifndef FRACTION_H
#define FRACTION_H

class Fraction {
public:
    explicit Fraction(int counter = 0, int denominator = 1);

    Fraction(double value, int maxdenom = 100);

    ~Fraction();

    Fraction operator+(const Fraction &other) const;

    Fraction &operator+=(const Fraction &other);

    Fraction operator-(const Fraction &other) const;

    Fraction &operator-=(const Fraction &other);

    Fraction operator*(const Fraction &other) const;

    Fraction &operator*=(const Fraction &other);

    Fraction operator/(const Fraction &other) const;

    Fraction &operator/=(const Fraction &other);

    bool operator==(const Fraction &other) const;

    operator double() const;

    friend std::ostream &operator<<(std::ostream &stream, const Fraction &fract);

    friend std::istream &operator>>(std::istream &stream, Fraction &fract);

private:
    void reduce();

    static int gcd(int a, int b);

    int counter;
    int denominator;
};

#endif /* FRACTION_H */

