/*Problem1 : Write a C++ program that calculates the area of the cube(length in integer value and default length is 10 meter), circle(radius in decimal value) and rectangle(length and breadth in decimal values).You must provide options to enter the inputs dimension of above solids.(Use function overloading with default arguments.make one the defined functions as inline function).*/
#include <iostream>
#define pi 3.14
																																								 using namespace std;
inline double area(int side = 10)
{ //area of cube
	return (6 * side * side);
}
double area(double R)
{ //area of circle
	return (pi * R * R);
}
double area(double L, double B)
{ //area of rectangle
	return (L * B);
}
int main()
{
	double print;
	int length;
	cout << "Do enter the side of the cube." << endl; //user enters
	cin >> length;
	if (length == NULL)
	{
		print = area(); //function call
		cout << "Area of cube : " << print << endl;
	}
	else
	{
		print = area(length); //function call
		cout << "Area of cube : " << print << endl;
	}
	double R;
	cout << "Do enter the radius" << endl; //user enters
	cin >> R;
	double print1;
	print1 = area(R); //function call
	cout << "Area of circle : " << print1 << endl;
	double L, B;
	cout << "Do enter the length" << endl; //user enters
	cin >> L;
	cout << "Do enter the breadth" << endl;
	cin >> B;
	double print3;
	print3 = area(L, B); //function call
	cout << "Area of rectangle : " << print3 << endl;
}