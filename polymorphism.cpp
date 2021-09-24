/*Problem1 : Write a program having Polygon as an abstract class with Length and 
Height as its data member.Create derived class Rectangle and Triangle.Make Area() as
pure virtual function and redefine it in derived class to calculate respective area*/
#include <iostream>
using namespace std;
class polygon
{
protected:
    float length, height;

public:
    polygon()
    {
        length = 0;
        height = 0;
    }
    void get_data()
    {
        cout << "Enter the length:\t" << endl;
        cin >> length;
        cout << "Enter the Height:\t" << endl;
        cin >> height;
    }
    virtual void Area() = 0; //pure virtual function
};
class rectangle : public polygon
{
public:
    void Area()
    {
        get_data();
        cout << "The area of the rectangle is " << length * height << "\n\n"<< endl;
    }
};
class triangle : public polygon
{
public:
    void Area()
    {
        get_data();
        cout << "The area of the triangle is " << length * height * 0.5 << endl;
    }
};
int main()
{
    polygon *ptr;
    rectangle rect;
    triangle tri;
    cout << "Area of rectangle \n"<< endl;
    ptr = &rect;
    ptr->Area();   //pointer to derived class
    cout << "Area of Triangle \n"<< endl;
    ptr = &tri;
    ptr->Area(); //pointer to derived class
    return 0;
}