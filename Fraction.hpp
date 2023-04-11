//Fraction.hpp
//Create Score Object(Fraction)

#pragma once
#include<iostream>
#include"lea_com_mul.hpp"
typedef unsigned int uint;
//using namespace std;

class Fraction
{
private:
    uint deno;//denominator
    uint num;//numeractor
    double value;
public:
    Fraction(uint d, uint m);
    ~Fraction();
    void univ_sc(uint x);
    void app_sc();
    void reciprocal();//reciprocal
    uint ret_deno();//return denominator
    uint ret_num();//return numeractor
    const uint const_ret_deno() const;
    const uint const_ret_num() const;
    double ref_value();//refresh and return value
    const double const_ref_value() const;//const object return value
    friend Fraction operator+(const Fraction &lhs, const Fraction &rhs);
    friend Fraction operator-(const Fraction &lhs, const Fraction &rhs);
    friend Fraction operator*(const Fraction &lhs, const Fraction &rhs);
    friend Fraction operator/(const Fraction &lhs, const Fraction &rhs);
    friend std::ostream & operator<<(std::ostream &out, Fraction &A);
    friend std::ostream & operator<<(std::ostream &out, const Fraction &A);
};

Fraction::Fraction(uint m, uint d): num(m), deno(d), value( (double)m / d )
{
}

Fraction::~Fraction()
{
}

std::ostream & operator<<(std::ostream &out, Fraction &A)
{
    Fraction B = A;
    B.app_sc();
    out << B.num << "/" << B.deno;
    return out;
}

std::ostream & operator<<(std::ostream &out, const Fraction &A)
{
    uint de = A.const_ret_deno();
    uint nm = A.const_ret_num();
    out << de << "/" << nm;
    return out;
}

void Fraction::univ_sc(uint x)//Universal score
{
    this->deno *= x;
    this->num *= x;
}

void Fraction::app_sc()//Approximate score
{
    uint mcf = max_com_fact(this->deno, this->num);
    this->deno /= mcf;
    this->num /= mcf;
}

void Fraction::reciprocal()//
{
    uint temp = deno;
    this->deno = num;
    this->num = temp;
}

double Fraction::ref_value()
{
    this->value = (double)this->num / this->deno;
    return this->value;
}

const double Fraction::const_ref_value() const
{
    return (const double)this->value;
}

uint Fraction::ret_deno()
{
    uint d = this->deno;
    return d;
}

uint Fraction::ret_num()
{
    uint n = this->num;
    return n;
}
const uint Fraction::const_ret_deno() const
{
    uint d = this->deno;
    return d;
}

const uint Fraction::const_ret_num() const
{
    uint n = this->num;
    return n;
}

Fraction operator+(const Fraction &lhs, const Fraction &rhs)
{
    uint lde = lhs.deno;
    uint rde = rhs.deno;
    uint mcf = max_com_fact(lde, rde);
    uint lnm = lhs.num * (rde / mcf);
    uint rnm = rhs.num * (lde / mcf);
    uint lcm = lea_com_mul(lde, rde);
    Fraction res(lnm + rnm, lcm);
    return res;
    //
}

Fraction operator-(const Fraction &lhs, const Fraction &rhs)
{
    uint lde = lhs.deno;
    uint rde = rhs.deno;
    uint mcf = max_com_fact(lde, rde);
    uint lnm = lhs.num * (rde / mcf);
    uint rnm = rhs.num * (lde / mcf);
    uint lcm = lea_com_mul(lde, rde);
    Fraction res(lnm - rnm, lcm);
    return res;
    //
}

Fraction operator*(const Fraction &lhs, const Fraction &rhs)
{
    uint lde = lhs.deno;
    uint rde = rhs.deno;
    uint lnm = lhs.num;
    uint rnm = rhs.num;
    Fraction res(lnm * rnm, lde * rde);
    return res;
}

Fraction operator/(const Fraction &lhs, const Fraction &rhs)
{
    Fraction rhsr = rhs;
    rhsr.reciprocal();
    Fraction lhsr = lhs;
    Fraction res = lhsr * rhsr;
    return res;
}

