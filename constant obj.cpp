/*Problem2: Modify above program for constant object. */

#include <iostream>
using namespace std;
class complex
{
    const float real;
    float imag;

public:
    complex(float r, float i) : real(r), imag(i) {}

    float real1() const
    {
        return real;
    }
    float imag1()
    {
        return imag;
    }
    void display() const;
};
void complex::display() const
{
    cout << " the real part is" << endl;
    cout << real1() << endl;
    cout << "the imaginary part is" << endl;
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
    const complex c1(r, i); //constant object
    c1.display();

    return 0;
}