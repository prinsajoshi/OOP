/* Problem1: Define a class Complex with attributes real(constant) and imag and a constant member function to 
return the real value and normal function to return the imaginary value of complex number. Display the complex
 number outside the class using constant functions.*/

#include <iostream>
using namespace std;
class complex
{
    const float real; //constant variable
    float imag;

public:
    complex(float r, float i) : real(r), imag(i) {}

    float real1() const  //constant member function
    {
        return real;
    }
    float imag1()
    {
        return imag;
    }
    void display() const; //constant member function
};
void complex::display() const
{
    cout << "The real part is" << endl;
    cout << real1() << endl;
    cout << "The imaginary part is" << endl;
    cout << const_cast<complex *>(this)->imag1() << endl;
    cout << "\n****************************************" << endl;
    cout << "In Complex number format :"
         << " " << real1() << "+" << const_cast<complex *>(this)->imag1() << "j" << endl;
}
int main()
{
    float r, i;
    cout << "Enter the real part" << endl;
    cin >> r;
    cout << "Enter the imaginary part" << endl;
    cin >> i;
    cout << "****************************************" << endl;
    complex c1(r, i);
    c1.display();

    return 0;
}