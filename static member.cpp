/*Problem3: Define a class Complex with members real and imag. Use constructor to construct the objects of 
the class Complex. Using static data member and static function, display the total number of object created
 before terminating the program.*/
#include <iostream>
using namespace std;
class complex
{
    float real;
    float imag;
    static int count; //static data member

public:
    complex(float real1,float imag1)
    {
        real=real1;
        imag=imag1;

        count++;
    }
 
    void display()
    {
        cout << "the real part is" << endl;
        cout << real << endl;
        cout << "the imaginary part is" << endl;
        cout << imag << endl;
        cout << "In Complex number format :"
             << " " << real << "+" << imag << "j" << endl;
        cout << "*******************************************" << endl;
    }
    static void showcount() //static function
    {
        cout << "\n.................................." << endl;
        cout << "count" << count << endl;
        cout << ".................................." << endl;
    }
};
int complex::count;

int main()
{

    complex c1(2,4);
    c1.display();

    complex c2(4,8);
    c2.display();

    complex c3(3,4);
    c3.display();

    complex::showcount(); ////static function to show total number of object
    return 0;
}
