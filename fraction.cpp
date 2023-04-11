#include"Fraction.hpp"

int main()
{
    Fraction a(1/*denominator*//*type: unsigned int*/, 2/*Numerator*//*type: unsigned int*/);
    unsigned int d = 5;
    unsigned int n = 6;
    Fraction dm(n, d);
    const Fraction b(3 ,4);
    Fraction c = a;
    const Fraction d = b;
    return 0;
}
