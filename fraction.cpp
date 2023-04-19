#include"Fraction.hpp"

int main()
{
    Fraction a(1/*denominator*//*type: unsigned int*/, 2/*Numerator*//*type: unsigned int*/);
    Fraction fal1(1, 3, false);/*negative fraction*/
    const Fraction fal2(3, 7, false);

    unsigned int d = 5;
    unsigned int n = 6;
    Fraction frax(n, d);
    const Fraction b(3 ,4);
    return 0;
}
