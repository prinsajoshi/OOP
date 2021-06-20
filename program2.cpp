//Problem2: Write a program to swap sides of rectangle and to change the longer side.

#include<iostream>
using namespace std;

void swap(int &x, int &y){
	int z;
	z=x;
	x=y;
    y=z;
}
int& change(int &L1,int &B1){
		if(L1>B1){
	      return L1;}
	else {
		return B1;}
	}

int main(){
    int L,B;
    cout<<"enter the length of rectangle"<<endl;              //user enters
	cin>>L;
	cout<<"enter the breadth of rectangle"<<endl;
	cin>>B;
	cout<<"the sides of rectangle before swapping"<<endl;       //before swapping
	cout<<"Length: "<<L<<endl;
	cout<<"Breadth: "<<B<<endl;
	
	swap(L,B);                               //function call
	
	cout<<"the sides of rectangle after swapping"<<endl;          //after swapping
	cout<<"Length: "<<L<<endl;
	cout<<"Breadth: "<<B<<endl;

	int c; //changing the longer side
	cout<<"enter the new side"<<endl;
	cin>>c;
	change(L, B) = c;
	cout << "the sides of rectangle after changing" << endl; //changing the value
	cout << "Length: " << L << endl;
	cout << "Breadth: " << B << endl;
}



