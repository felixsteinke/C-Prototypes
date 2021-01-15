//Gruppe: Felix Steinke und Florian Grabowski


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Peter Heusch
 *
 * Created on 8. Mai 2018, 10:49
 */

#include <cstdlib>

#undef NDEBUG

#include <assert.h>
#include <istream>
#include <ostream>
#include <iostream>
#include "Fraction.h"
#include <vector>

using namespace std;

int main(int argc, char **argv) {
    Fraction two = 2;
    Fraction three = 3;
    Fraction pie = 3.1415926;

    assert(two == Fraction(4, 2));
    assert(pie == Fraction(22, 7));
    assert(two + two == Fraction(4));
    assert((double) (three / two) == 1.5);
    assert((double) Fraction(1, 2) == 0.5);
    assert(Fraction(1, 2) == Fraction(-2, -4) + Fraction(0));

    Fraction a(10, 5);
    a -= a;
    assert(a == Fraction(0));
    Fraction b(12, 7);
    Fraction *bPtr = &(b /= b);
    assert(b == Fraction(1));
    assert(bPtr == &b);
    Fraction fracs[5];
    for (int i = 0; i < 5; i++) {
        fracs[i] = Fraction(i + 1);
    }
    typedef Fraction(Fraction::*Meth)(const Fraction &) const;
    Meth x = &Fraction::operator+;
    Fraction result = fracs[0];
    for (int i = 1; i < 5; i++) {
        result = (result.*x)(fracs[i]);
    }
    std::cout << result;
    return 0;
}

