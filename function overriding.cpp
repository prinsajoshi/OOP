/*Problem2: Define a class named Course. Derive three classes from this class named: Mathematics, 
Science and Engineering. Then, derive two classes from Science named: Physics and Chemistry. 
Define data members and member functions as appropriate. Illustrate the concept of member function
overriding and accessing overridden member from the derived class in your program.*/

#include <iostream>
using namespace std;
class Course
{
protected:
    int marks;

public:
    int input_marks()
    {
        cin >> marks;
        return marks;
    }
};
class Mathematics : virtual public Course
{
protected:
    float marks;

public:
    void set_marks()
    {
        cout << "Enter the marks obatained in mathematics : ";
        marks = input_marks();
    }
    void display()
    {
        cout << "Marks obtained in mathematics : " << marks << endl;
    }
};
class Science : virtual public Course
{
public:
    void display()
    {
        cout << "Marks in  Science includes physics and chemistry are" << endl;
    }
    void display1()
    {
        cout << "The Marks obatained in Science are : " << endl;
    }
};
class Physics : virtual public Science
{
protected:
    float marks;

public:
    void set_marks()
    {
        cout << "    Enter the marks obatained in physics : ";
        marks = input_marks();
    }
    void display()
    {
        cout << "    Marks obtained in Physics: " << marks << endl;
    }
};
class Chemistry : virtual public Science
{
protected:
    float marks;

public:
    void set_marks()
    {
        cout << "    Enter the marks obatained in chemistry : ";
        marks = input_marks();
    }
    void display()
    {
        cout << "    Marks obtained in chemistry : " << marks << endl;
    }
};
class Engineering : virtual public Course
{
protected:
    float marks;

public:
    void set_marks()
    {
        cout << "Enter the marks obatained in Engineering : ";
        marks = input_marks();
    }
    void display()
    {
        cout << "Marks obtained in Engineering : " << marks << endl;
    }
};
class derived : public Engineering, public Mathematics, public Physics, public Chemistry
{
protected:
    float total, percentage;

public:
    void display()
    {
        cout << "****************************************" << endl;
    }
    void total_all()
    {
        cout << "The total marks obatained is : ";
        total = Engineering::marks + Mathematics::marks + Physics::marks + Chemistry::marks;
        cout << total << endl;
        percentage = (total / 400) * 100;
        cout << "Total obtained percentage is : " << percentage << "%" << endl;
    }
};

int main()
{
    derived D1;
    cout << "Enter the marks obtained in respective subjects" << endl;
    D1.display();
    D1.Mathematics::set_marks();
    D1.Science::display();
    D1.Physics::set_marks();
    D1.Chemistry::set_marks();
    D1.Engineering::set_marks();
    D1.display();
    D1.Mathematics::display(); //accessing overridden function
    D1.Science::display1();
    D1.Physics::display();
    D1.Chemistry::display();
    D1.Engineering::display();
    D1.display(); //Function overriding
    D1.total_all();
    return 0;
}
