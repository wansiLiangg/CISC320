/*
* A cpp file for CISC320 assignment 2
*
* Author: Wansi Liang
* Student number: 20067725
*/
#include <iostream>
using namespace std;
#include "fraction.h"

//Constructors of Fraction
Fraction::Fraction() : numer(0), deno(1) {}
Fraction::Fraction(int a) : numer(a), deno(1) {}
Fraction::Fraction(int a, int b) : numer(a), deno(b) {
  //When denominator is zero
  if (deno == 0)
    throw FractionException("Denominator is zero!");
  normalize();
}

//Exception class
FractionException::FractionException(const string& message) : message(message) {}
string& FractionException::what() {
  return message;
}

//Return the value of numerator
int Fraction::numerator() const {
  return numer;
}

//Return the value of denominator
int Fraction::denominator() const {
  return deno;
}

//Algorithm to get the greatest common divisor
int Fraction::gcd(int n, int m) {
  if (m <= n && n%m == 0)
    return m;
  else if (n < m)
    return gcd(m, n);
  else
    return gcd(m, n%m);
}

//Define the sign of the numerator and there is no common divisor for numerator and denominator
void Fraction::normalize() {
  int sign = 1;
  if (numer < 0) {
    sign = -1;
    numer = -numer;
  }

  if (deno < 0) {
    sign = -sign;
    deno = -deno;
  }

  int cd = 1;
  if (numer > 0)
    cd = gcd(numer, deno);
  numer = sign * (numer / cd);
  deno = deno / cd;
}

//Operator -- negation
Fraction operator-(const Fraction& num) {
  return Fraction (-num.numerator(), num.denominator());
}

//Operator -- post-increment
Fraction Fraction::operator++(int a) {
  Fraction clone(numer, deno);
  numer += deno;
  return clone;
}

//Operator -- pre-increment
Fraction& Fraction::operator++() {
  numer += deno;
  return *this;
}

//Operator -- addition
Fraction operator+(const Fraction& LHS, const Fraction& RHS) {
  return Fraction (LHS.numerator() * RHS.denominator() + RHS.numerator() * LHS.denominator(), LHS.denominator() * RHS.denominator());
}

//operator -- subtraction
Fraction operator-(const Fraction& LHS, const Fraction& RHS) {
  return Fraction (LHS.numerator() * RHS.denominator() - RHS.numerator() * LHS.denominator(), LHS.denominator() * RHS.denominator());
}

//Operator -- multiplication
Fraction operator*(const Fraction& LHS, const Fraction& RHS) {
  return Fraction (LHS.numerator() * RHS.numerator(), LHS.denominator() * RHS.denominator());
}

//Operator -- division
Fraction operator/(const Fraction& LHS, const Fraction& RHS) {
  return Fraction (LHS.numerator() * RHS.denominator(), LHS.denominator() * RHS.numerator());
}

//Operator -- addition and assignment
Fraction& Fraction::operator+=(const Fraction& RHS) {
  numer = numer * RHS.denominator() + deno * RHS.numerator();
  deno *= RHS.denominator();
  normalize();
  return *this;
}

//Operator -- smaller
bool operator<(const Fraction& LHS, const Fraction& RHS) {
  return LHS.compare(RHS) < 0;
}

//Operator -- smaller and equal
bool operator<=(const Fraction& LHS, const Fraction& RHS) {
  return LHS.compare(RHS) <= 0;
}

//Operator -- eqaul
bool operator==(const Fraction& LHS, const Fraction& RHS) {
  return LHS.compare(RHS) == 0;
}

//Operator -- not equal
bool operator!=(const Fraction& LHS, const Fraction& RHS) {
  return LHS.compare(RHS) != 0;
}

//Operator -- larger and equal
bool operator>=(const Fraction& LHS, const Fraction& RHS) {
  return LHS.compare(RHS) >= 0;
}

//Operator -- larger
bool operator>(const Fraction& LHS, const Fraction& RHS) {
  return LHS.compare(RHS) > 0;
}

//Operator -- used with cout
ostream& operator<<(ostream& out, const Fraction& num) {
   out << num.numerator() << "/" << num.denominator();
   return out;
}

//Operator -- used with cin
istream& operator>>(istream& input, Fraction& inp) {
  int numer, deno;
  char nextFrac;
  input >> numer;
  if (input.peek() != 10) {
    input >> nextFrac;
    if (nextFrac == '/')
      input >> deno;
    else
      deno = 1;
    inp = Fraction(numer, deno);
  }
  else
    inp = Fraction(numer);
  return input;
}

//Compare the values of two fractions
int Fraction::compare(const Fraction& RHS) const {
  return numer * RHS.denominator() - deno * RHS.numerator();
}
