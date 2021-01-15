//Gruppe: Felix Steinke und Florian Grabowski


#include <iostream>
#include "TimeClass.h"

using namespace std;

void work();

class Guard {
public:
    ~Guard() {
        TimeClass::dumpCalls();
    }
} x;

int main(int argc, char *argv[]) {
    work();
}

void work() {
    TimeClass now;
    cout << now << endl;
    now += 7_dy;
    cout << now << endl;
    now += 12_mo;
    cout << now << endl;
    now += 27_hr;
    cout << now << endl;
    now += 28_mi;
    cout << now << endl;
    cout << "-------------" << endl;
    TimeClass then = now;
    cout << then << endl;
    then = then - now;
    cout << then << endl;
    then -= 12_mo;
    cout << then << endl;
    then -= 28_mi;
    cout << then << endl;
}
