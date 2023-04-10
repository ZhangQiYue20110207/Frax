#include<iostream>
#include"Fraction.hpp"
using namespace std;

int main()
{
    Fraction a(1, 2);
    const Fraction b(3, 4);
    Fraction c = a + b;
    Fraction d = b - a;
    Fraction e = a * b;
    Fraction f = a / b;
    cout << c << endl;
    cout << d << endl;
    cout << e << endl;
    cout << f << endl;
    return 0;
}
