/*Problem1 : Write a program to store information of students in files and retrieve that 
information to display from the program of the choice of user(Suppose, you store records
of N students(name, address, program etc.) in a file and you want to know all the information
about student those name is Ram, then you can show the students details in proper format
by entering student name).Your program must use manipulators to store and to show the
information in proper formats.*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <string>
using namespace std;
class record
{
public:
    string name, address, program;
    void store();
    void show_data();
    void show();
    void enter();
};
void record::store()
{
    fstream in;
    in.open("std_record2.txt", ios::in | ios::out | ios::app);
    int n;
    cout << "\n\t\t\t\t\t\t***********************\n";
    cout << "\t\t\t\t\t\t\tAdd record";
    cout << "\n\t\t\t\t\t\t***********************\n";
    cout << "\n\t\tHow many records do you wanna make?: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\n\t\t\tRECORD:";
        enter();
        in.write((char *)this, sizeof(*this));
    }
    in.close();
}
void record::enter()
{
    fflush(stdin);
    cout << "\n\t\t\tEnter the name of the student: ";
    getline(cin, name);
    fflush(stdin);
    cout << "\n\t\t\tEnter the address of the student: ";
    getline(cin, address);
    fflush(stdin);
    cout << "\n\t\t\tEnter the program of the student: ";
    getline(cin, program);
    fflush(stdin);
}
void record::show()
{
    fstream in;
    in.open("std_record2.txt", ios::in | ios::out);
    string name1;
    int flag;
    flag = 0;
    cout << "\n\t\t\t\t\t\t***********************\n";
    cout << "\t\t\t\t\t\t\tSearch record";
    cout << "\n\t\t\t\t\t\t***********************\n";
    cout << "\n\t\t\t\t\t";
    fflush(stdin);
    cout << "\n\tEnter the name of the student to get the record: ";
    getline(cin, name1);
    fflush(stdin);

    in.read((char *)this, sizeof(*this));
    in.seekg(0, ios::beg); //manipulator //go to the start
    while (!in.eof())
    {
        if (this->name.compare(name1) == 0)
        {
            this->show_data();
            flag = 1;
            break;
        }
        in.read((char *)this, sizeof(*this));
    }
    if (flag == 0)
    {
        cout << "\n\t\t\t\t\tName was not found " << endl;
    }
    in.close();
}
void record::show_data()
{
    cout << "\n\t\t";
    cout << setw(20) << setiosflags(ios::left) << "Name ";
    cout << setw(20) << "Address";
    cout << setw(10) << "Program" << endl;
    cout << "\n\t\t";
    cout << setw(20) << setiosflags(ios::left) << name;
    cout << setw(20) << address;
    cout << setw(10) << program;
}

int main()
{
    int ch;
    record r1;
    while (1)
    {
        cout << "\n\t\t\t\t\t\t\tSTUDENT RECORD SYSTEM";
        cout << "\n\t\t\t\t\t\t---------------------------------------\n";
        cout << "\n\t\t\t\t 1: ADD RECORD" << endl;
        cout << "\n\t\t\t\t 2:SEARCH BY NAME" << endl;
        cout << "\n\t\t\t\t 3.EXIT" << endl;
        cout << "\n\t\n\tChoose according to your need : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            r1.store();

            break;
        case 2:
            r1.show();

            break;
        case 3:
            exit(0);

            break;

        default:
            exit(0);
            break;
        }
    }
}
