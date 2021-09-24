/*Problem1 : Write a program to find the square root of given number using template.
Check all possible exceptions and handle those exceptions using try and catch block.*/
#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;

template <typename T> //class template
class square_root
{
public:
    void input();
    void display(int a);
};

template <typename T>
void square_root<T>::display(int a)
{
    try //exception handling constructs
    {
        if (a >= 0)
            cout << "Square root of the entered number is :  " << sqrt(a) << endl;
        else
            throw(a);
    }
    catch (int a)
    {
        int x = abs(a);
        cout << "Square root of the entered number is : " << sqrt(x) << "i" << endl;
    }
};
int main()
{
    long double a;
    char b;
    bool run = true;
    while (run)
    {
        square_root<float> s1;
        cout << "\nEnter the number to find square root:  ";
        cin >> a;
        cout << "-------------------------------------------" << endl;
        s1.display(a);
        cout << "\nDo you still want to calculate?[Y/N]" << endl;
        cin >> b;
        if (b == 'N' || b == 'n')
        {
            run = false;
        }
    }
}