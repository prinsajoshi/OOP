/*Problem3: Define a class Item1 with data members code, qty and price and class Item2 with data members code and value.
(Hint: code = code, value = qty*price). Use the constructor in Item2 class to change the Item1 type data to Item2 type.
Your code should be able to execute the statement I2=I1 (where I1 and DI2 are objects of respective item class).*/
#include <iostream>
using namespace std;
class Item1
{
    float code, qty, price;

public:
    Item1()
    {
        code = 0;
        qty = 0;
        price = 0;
    }
 
    void input()
    {
        cout << "Enter the code" << endl;
        cin >> code;
        cout << "Enter the qty" << endl;
        cin >> qty;
        cout << "Enter the price" << endl;
        cin >> price;
    }
    void display()
    {
        cout << "code is" << code << "\n";
        cout << "qty is" << qty << "\n";
        cout << "price is" << price << "\n";
    }
    operator float() { return qty * price; }
    float getcode() { return code; }
    float getqty() { return qty; }
    float getprice() { return price; }
};

class Item2
{
    float code, value;

public:
    Item2()
    {
        code = 0;
        value = 0;
    }
    Item2(Item1 a)
    {
        code = a.getcode();
        value = a.getqty() * a.getprice();
    }
    void display()
    {
       cout << "Code is  : " << code << "\n";
       cout << "Value is  : " << value << "\n";
    }
};

int main()
{
    Item1 I1;
    Item2 I2;
    I1.input();
    I2=I1;   //data type conversion from user-deined to user-defined 
    I2.display();
}

