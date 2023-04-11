#include<iostream>
#include"Fraction.hpp"
using namespace std;

int main()
{
    Fraction a(1, 2);
    const Fraction b(3, 4);
    cout << a << endl;
    cout << b << endl;
}
