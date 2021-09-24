/*THEORY TO BE COVERED:

Constructor
Default Constructor
Parameterized Constructor
Copy Constructor
Destructor
Problem:

Define a class Time with attributes hr, min and sec. 
Define different types of constructors to initialize the object of Time. 
Default constructor should initialize the time with 12 hr, 0 min and 0 sec.
Parameterized constructor should initialize the time accordingly as user 
inputs the time in seconds. (Suppose user input time as 100 secs then
constructor should initialize the object with 0 hr 1 min 40 secs.
Also define 2nd object of time to copy value of 1st object to new object 
using copy constructor.*/

#include<iostream>
using namespace std;
class Time{
    int hr , min, sec;
    public:
    Time(){       //Default constructor
        hr = 12;
        min = 0;
        sec = 0;
    }

    Time(int input_time) //Parameterized constructor
    {
     hr = input_time / (60*60);
     min = (input_time/ (60))%60;
     sec = input_time % 60;
    }
    Time(Time &input_time)    //copy constructor
    {
        hr = input_time.hr;
        min = input_time.min;
        sec = input_time.sec;
    }
    void display(){
        cout << "Exact time you have entered is" << endl;
        cout << "Hour  :" << hr << "\nMinute  :" << min << "\nSecond  :" << sec << endl;

    }
    ~Time(){               //destructor
        cout << "Therefore the time is calculated in hour minutes and second" << endl;
    }
};
int main(){
    int input;
    cout << "Enter the time" << endl;
    cin >> input;
    Time t1(input);    //passing a parameter through an object
    t1.display();
    cout <<"\t COPYING OBJECT"<<endl;
    Time t2(t1);   ////Copies content of t1 to t2
    t2.display();
    return 0;
}
