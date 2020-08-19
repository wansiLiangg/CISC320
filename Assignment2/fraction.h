/*
* A head file for CISC320 assignment 2
*
* Author: Wansi Liang
* Student number: 20067725
*/
#pragma once
#include <iostream>
using namespace std;

class Fraction {
public:
  //Constructors of Fraction
  Fraction();
  Fraction(int a);
  Fraction(int a, int b);

  //Return numerator and denominator
  int numerator() const;
  int denominator() const;

  //Operators
  Fraction& operator+=(const Fraction& RHS);
  Fraction& operator++();
  Fraction operator++(int a);

  //Compare the values of two fractions
  int compare(const Fraction& RHS) const;

private:
  //Algorithm to get the greatest common divisor
  int gcd(int n, int m);

  //Define the sign of the numerator and there is no common divisor for numerator and denominator
  void normalize();

  //Numerator and denominator
  int numer;
  int deno;
};

//Exception class
class FractionException {
public:
  FractionException(const string&);
  string& what();

private:
  string message;
};

//Binary operators
Fraction operator+(const Fraction& LHS, const Fraction& RHS);
Fraction operator-(const Fraction& LHS, const Fraction& RHS);
Fraction operator*(const Fraction& LHS, const Fraction& RHS);
Fraction operator/(const Fraction& LHS, const Fraction& RHS);
Fraction operator-(const Fraction& num);
ostream& operator<<(ostream& out, const Fraction& num);
istream& operator>>(istream& input, Fraction& inp);

//comparison operators
bool operator<(const Fraction& LHS, const Fraction& RHS);
bool operator<=(const Fraction& LHS, const Fraction& RHS);
bool operator==(const Fraction& LHS, const Fraction& RHS);
bool operator!=(const Fraction& LHS, const Fraction& RHS);
bool operator>=(const Fraction& LHS, const Fraction& RHS);
bool operator>(const Fraction& LHS, const Fraction& RHS);
