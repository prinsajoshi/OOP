/*
Problem4: Define a class Complex with members real and imag. Use constructor to construct the objects of the 
class Complex. Using friend function calculate the magnitude of the Complex number*/
#include <iostream>
#include <cmath>
using namespace std;
class Complex
{
    float real;
    float imag;

public:
    Complex(float r, float i) : real(r), imag(i) {}

    friend void magnitude(Complex c1); //friend
};
void magnitude(Complex c1) //function to calculate magnitude
{
    float a, b;
    a = pow(c1.real, 2);
    b = pow(c1.imag, 2);
    cout << "the magnitude of complex number is " << sqrt(a + b) << endl;
}
int main()
{
    float r, i;
    cout << "enter the real part" << endl;
    cin >> r;
    cout << "enter the imaginary part" << endl;
    cin >> i;
    Complex c1(r, i);
    magnitude(c1);

    return 0;
}