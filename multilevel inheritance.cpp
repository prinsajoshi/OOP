/*Problem1: Write a program with three classes Student, Test and Result by 
using multilevel inheritance. Assume necessary data members and functions 
with input information, input data and calculate marks total and display result.*/
#include <iostream>
using namespace std;
class Student
{
protected:
    string name;
    int roll_num;
    string faculty;

public:
    void Enter()
    {
        cout << "Please do enter name of the student:  ";
        getline(cin, name);
        cout << "Please do enter Faculty of the student:  ";
        getline(cin, faculty);
        cout << "Please do enter Roll number of the student:  ";
        cin >> roll_num;
    }
    void display()
    {
        cout << "*************************************" << endl;
        cout << "Name of the student is:   "
             << name << endl;
        cout << "Roll of the student is:   "
             << roll_num << endl;
        cout << "Faculty of the student is:   "
             << faculty << endl;
    }
};
class Test : public Student
{
protected:
    float Science, Math, English;

public:
    void Enter()
    {
        cout << "------------------------------------------" << endl;
        cout << "Enter your marks in Science:  ";
        cin >> Science;
        cout << "Enter your marks in Math:  ";
        cin >> Math;
        cout << "Enter your marks in English:  ";
        cin >> English;
    }
    void display()
    {
        Student::display();
        cout << "------------------------------------------" << endl;
        cout << "marks in Science is :  "
             << Science << endl;
        cout << "marks in Math is :   "
             << Math << endl;
        cout << "marks in English is :  "
             << English << endl;
        cout << "------------------------------------------" << endl;
    }
};
class Result : public Test
{
protected:
    float total, percentage;

public:
    void calculate()
    {
        total = (Science + Math + English);
        percentage = (total / 300) * 100;
    }
    void Display()
    {
        cout << " Total marks :" << total << endl;
        cout << " Percentage scored :" << percentage << endl;
    }
};
int main()
{
    Result R1;
    R1.Student::Enter();
    R1.Test::Enter();
    R1.calculate();
    R1.Test::display();
    R1.Display();

    return 0;
}
