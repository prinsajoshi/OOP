#include <iostream>
#include <fstream>
#include <limits>
#include <conio.h>
#include <windows.h>
#include <iomanip>
#include <string>
//#include <bits/stdc++.h>
#include <time.h>
using namespace std;
void login_ask();
void menu();
void show();

class covid
{
    /*using string(class) as data member seems cause the problem , use array of characters as string*/
    //string phone;
    int age;
    char name[30];
    char profession[20];
    char address[20];
    int mobile_number;
    char gender;

public:
    covid()
    {
    

        age = 0;
        mobile_number = 0;
    }
    void frontpage();

    void add_new();
    void delte_record();
    void search_data();
    void modify_data();
    void setdata();
    void search_by_address();
    void search_by_age();
    void search_by_profession();
    void search_by_phone();
    void search_by_gender();
    void showdata();
    void show_list();
    bool search(int r)
    {
        if (age == r)
        {
            return true;
        }
        else
            return false;
    }

    bool search1(int c)
    {

        if (mobile_number == c)
        {
            return true;
        }
        else
            return false;
    }
};

//user defined function to get string with space, you can alsouse gets from cstring.h library
void getstring(char* a)
{
    char b;
    b =' ';
    int i = 0;
    while (b != '\n')
    {
        b = getchar();
        a[i] = b;
        i++;
    }
    a[i - 1] = '\0';
}

void covid::frontpage()
{
}
void login_ask()
{
    char username[30], password[20];
    int choice;
    cout << "\n\n\t\t\t\t*********************************************";
    cout << "\n\t\t\t\tWELCOME TO THE COVID MANAGEMENT SYSTEM\n";
    cout << "\t\t\t\t*********************************************\n";

    cout << "\n\n\n\t\t\t1: ENTER AS ADIM\n\n\n\t\t\t2: ENTER AS LOCAL\n\n\n\t\t\tYour choice:";
    cin >> choice;
    if (choice == 2)
    {
        covid obj;
        system("cls");
        obj.search_data();
    }
    if (choice == 1)
    {
        cout << "\n\n\t\t\t\t*********************************************";
        cout << "\n\t\t\t\t\tEnter User name and Password\n";
        cout << "\t\t\t\t*********************************************\n";

        char cname[30], pass[20];
        int ch, i = 0, cap = 0, capt = 0;
        cout << "\n\n\t\t\t\t\tUSER NAME:  ";
        fflush(stdin);
        cin >> cname;
        cout << "\n\t\t\t\t\tPASSWORD:    ";
        while ((ch = _getch()) != 13)
        {
            cout << "*";
            pass[i] = ch;
            i++;
        }
        pass[i] = '\0';
        srand(time(0));
        cap = rand();
        cout << "\n\t\t\t\t\t CODE:->  " << cap << endl;
        cout << " Please enter the valid capture :-   ";
        cin >> capt;
        if ((strcmp(cname, "admin") == 0) && (strcmp(pass, "admin") == 0) && cap == capt)
        {

            cout << "successfull";
        }
        else
        {
            system("cls");
            cout << "\n\t\t\t\t\tSORRY WRONG PASSWORD!!!";
            cout << "\n\t\t\t\t\t\n\n\n";
            Sleep(3000);
            exit(0);
        }
    }
}

void menu()
{
    system("cls");
    cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 COVID MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
        << endl;
    cout << "\t\t\t\t\t\t Powered By:-  COVID HELP AND RESCUE" << endl
        << endl;
    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\t\tMENU";
    cout << "\n\t\t\t*****************************************\n";
    cout << "\n\t\t1: Add NEW Record\t\t\t 2: DELETE RECORD" << endl;
    cout << "\n\t\t3: SEARCH   \t\t\t\t 4: MODIFY" << endl;
    cout << "\n\t\t5: EXIT" << endl;
}
void covid::add_new()
{
    covid obj;
    ofstream in;
    in.open("covid_record1.txt", ios::out | ios::binary | ios::app);
    obj.setdata();
    in.write((char*)&obj, sizeof(obj));
    /*      fstream fout;
              fout.write( (char *) &obj, sizeof(obj) );*/
    if (!in.good())
    {
        cout << "\nerror writing data\n";
    }
    cout << "YOUR DATA HAS BEEN SUCCESSFULLY INSERTED " << endl;
    _getch();
    in.close();
}

void covid::delte_record()
{
    covid obj;

    ifstream in;
    in.open("covid_record1.txt");

    ofstream ion;
    ion.open("covid_record2.txt");


    char name1[20];

    in.seekg(0, in.beg);
    int flag = 0;

    cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 COVID MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
        << endl;
    cout << "\t\t\t\t\t\t Powered By:- COVID HELP AND RESCUE " << endl
        << endl;
    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\t ADDRESS SEARCHING ";
    cout << "\n\t\t\t*****************************************\n\n";
    fflush(stdin);

    cin.ignore();
    cout << "Enter the name of patient  in the list " << endl;
    getstring(name1);

    show();
    in.read((char*)&obj, sizeof(obj));
    while (!in.eof())
    {
        if (strcmp(obj.name, name1) == 0)
        {
            obj.show_list();
            cout << "This record has been deleted" << endl;
            flag = 1;
            _getch();
        }
        else
        {
         
            ion.write((char*)&obj, sizeof(obj));
           
        }
        //in.seekg(0, in.cur);

        in.read((char*)&obj, sizeof(obj));
    }
    if (flag == 0)
    {
        cout << "Name  was  not found " << endl;
    }

    in.close();
    ion.close();
    remove("covid_record1.txt");
    rename("covid_record2.txt", "covid_record1.txt");
}

void covid::modify_data()
{
    covid obj;

    fstream in;
    in.open("covid_record1.txt", ios::in | ios::out | ios::binary);
    char name1[20];

    in.seekg(0, in.beg);
    int flag = 0;

    cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 COVID MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
        << endl;
    cout << "\t\t\t\t\t\t Powered By:- COVID HELP AND RESCUE " << endl
        << endl;
    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\t ADDRESS SEARCHING ";
    cout << "\n\t\t\t*****************************************\n\n";
    fflush(stdin);
    cin.ignore();
    cout << "Enter the name of patient  in the list " << endl;
    getstring(name1);
   

    in.read((char*)&obj, sizeof(obj));
    while (!in.eof())
    {
        if (strcmp(obj.name, name1) == 0)
        {
            cout << "\n\t\t Enter name of patient :-  ";
            // cin>>name;
            getstring(obj.name);
            fflush(stdin);
            cout << "\n\t\t Enter your permanent address :-  ";
            // cin>>address;
            getstring(obj.address);
            fflush(stdin);
            cout << "\n\t\t Enter age of patient:- ";
            cin >> obj.age;
            fflush(stdin);
            cin.ignore();
            cout << "\n\t\t Enter profession of patient :-  ";
            // cin>>profession;
            getstring(obj.profession);
            fflush(stdin);

            cout << "\n\t\t Enter gender (M|F)of patient :-  ";
            // gender=getchar();
            cin >> obj.gender;
            fflush(stdin);

            cout << "\n\t\t Enter your Mobile number :- ";
            cin >> obj.mobile_number;
            _getch();
          
            in.seekp(in.tellp() - sizeof(*this));
            in.write((char*)&obj, sizeof(obj));
        }

        //in.seekg(0, in.cur);

        in.read((char*)&obj, sizeof(obj));
    }
    if (flag == 0)
    {
        cout << "Name  was  not found " << endl;
    }

    in.close();
}
void covid::setdata()
{
    cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 COVID MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
        << endl;
    cout << "\t\t Powered By:- COVID HELP AND RESCUE " << endl
        << endl;
    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\t RECORDING INFORMATION ";
    cout << "\n\t\t\t*****************************************\n\n";

    fflush(stdin);
    cin.ignore();
    cout << "\n\t\t Enter name of patient :-  ";
   
    getstring(name);
   
    cout << "\n\t\t Enter your permanent address :-  ";
    
   
    //cin >> address;
    getstring(address);
 
    fflush(stdin);
    cout << "\n\t\t Enter age of patient:- ";
    fflush(stdin);
    cin >> age;
    cin.ignore();
    fflush(stdin);
    cout << "\n\t\t Enter profession of patient :-  ";
    fflush(stdin);
   
    cin>>profession;
  
    fflush(stdin);
    cin.ignore();

    cout << "\n\t\t Enter gender (M|F)of patient :-  ";
    gender=getchar();

    fflush(stdin);


    cout << "\n\t\t Enter your Mobile number :- ";
    cin >> mobile_number;
}
void covid::search_data()
{

    cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 COVID MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
        << endl;
    cout << "\t\t\t\t\t\t Powered By:- Coding Halt " << endl
        << endl;
    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\tSEARCHING STATISTICS";
    cout << "\n\t\t\t*****************************************\n\n";
    cout << "From which option you want to perform searching " << endl;
    cout << "\n\t\t 1. By address \t\t\t 2. By Age " << endl;
    cout << "\n\t\t 3. By profession \t\t 4. By gender " << endl;
    cout << "\n\t\t 5. By phone number" << endl;
    cout << "\n\n\t\tEnter your choice ...............";
    int ch;
    cin >> ch;
    switch (ch)
    {
    case 1:
        system("cls");
        search_by_address();
        _getch();
        break;
    case 2:
        system("cls");
        search_by_age();
        _getch();
        break;
    case 3:
        system("cls");
        search_by_profession();
        _getch();
        break;
    case 4:
        system("cls");
        search_by_gender();
        _getch();
        break;
    case 5:
        system("cls");
        search_by_phone();
       _getch();
        break;
    default:
        system("cls");
        cout << "ENTER VALID OPTION" << endl;
        menu();
    }
}
void covid::search_by_address()
{
    int no_of_obj;
    fstream in;
    in.open("covid_record1.txt", ios::in | ios::out | ios::binary);
    in.seekg(0, in.end);
    no_of_obj = in.tellg() / sizeof(covid);
    covid obj;
    in.seekg(0, in.beg);
    std::cout << "\n no of data: " << no_of_obj << "\n";
    //std::cout << sizeof(in) << "\n";
    int flag = 0;
    char address_num[20];
    cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 COVID MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
        << endl;
    cout << "\t\t\t\t\t\t Powered By:- COVID HELP AND RESCUE " << endl
        << endl;
    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\t ADDRESS SEARCHING ";
    cout << "\n\t\t\t*****************************************\n\n";
    fflush(stdin);
    cin.ignore();
    cout << "Enter your Address " << endl;
    getstring(address_num);
    show();
    in.read((char*)&obj, sizeof(obj));
    while (!in.eof())
    {
        if (strcmp(obj.address, address_num) == 0)
        {
            obj.show_list();
            flag = 1;
        }
        //in.seekg(0, in.cur);

        in.read((char*)&obj, sizeof(obj));
    }
    if (flag == 0)
    {
        cout << "Address was  not found " << endl;
    }
    in.close();
}

void covid::search_by_age()
{
    int no_of_obj;
    fstream in;
    in.open("covid_record1.txt", ios::in | ios::binary);
    in.seekg(0, in.end);
    no_of_obj = in.tellg() / sizeof(covid);
    covid obj;
    in.seekg(0, in.beg);
    std::cout << "\n no of data: " << no_of_obj << "\n";
    int flag = 0;
    int a, p = 0;
    cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 COVID MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
        << endl;
    cout << "\t\t\t\t\t\t Powered By:- COVID HELP AND RESCUE " << endl
        << endl;
    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\t AGE SEARCHING ";
    cout << "\n\t\t\t*****************************************\n\n";
    cout << "enter Age by which you want to search " << endl;
    cin >> a;
    show();
    do
    {
        if (obj.search(a))
        {
            obj.show_list();
            flag = 1;
            p++;
        }

    } while (in.read((char*)&obj, sizeof(obj)));

    if (flag == 0)
    {
        cout << "Age you entered is not found" << endl;
    }
    cout << "\n\n\n\nNO of patient by this age: " << p;
    in.close();
}
void covid::search_by_phone()
{
    int no_of_obj;
    fstream in;
    in.open("covid_record1.txt", ios::in | ios::binary);
    in.seekg(0, in.end);
    no_of_obj = in.tellg() / sizeof(covid);
    covid obj;
    in.seekg(0, in.beg);
    std::cout << "\n no of data: " << no_of_obj << "\n";
    int flag = 0;
    int b, p = 0;
    cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 COVID MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
        << endl;
    cout << "\t\t\t\t\t\t Powered By:- COVID HELP AND RESCUE " << endl
        << endl;
    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\t AGE SEARCHING ";
    cout << "\n\t\t\t*****************************************\n\n";
    cin.ignore();
    cout << "enter phone by which you want to search " << endl;
    cin >> b;
    show();
    do
    {
        if (obj.search1(b))
        {
            obj.show_list();
            flag = 1;
            p++;
        }

    } while (in.read((char*)&obj, sizeof(obj)));

    if (flag == 0)
    {
        cout << "Age you entered is not found" << endl;
    }
    cout << "\n\n\n\nNO of patient by this age: " << p;
    in.close();
}
void covid::search_by_profession()
{
    int no_of_obj;
    fstream in;
    in.open("covid_record1.txt", ios::in | ios::out | ios::binary);
    in.seekg(0, in.end);
    no_of_obj = in.tellg() / sizeof(covid);
    covid obj;
    in.seekg(0, in.beg);
    std::cout << "\n no of data: " << no_of_obj << "\n";
    //std::cout << sizeof(in) << "\n";
    int flag = 0;
    char profession[20];
    cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 COVID MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
        << endl;
    cout << "\t\t\t\t\t\t Powered By:- COVID HELP AND RESCUE " << endl
        << endl;
    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\t PROFESSION SEARCHING ";
    cout << "\n\t\t\t*****************************************\n\n";
    fflush(stdin);
    cin.ignore();
    cout << "Enter your profession" << endl;
   
    getstring(profession);
    show();
    in.read((char*)&obj, sizeof(obj));
    while (!in.eof())
    {
        if (strcmp(obj.profession, profession) == 0)
        {
            obj.show_list();
            flag = 1;
        }
        //in.seekg(0, in.cur);

        in.read((char*)&obj, sizeof(obj));
    }
    if (flag == 0)
    {
        cout << "Address was  not found " << endl;
    }
    in.close();
}
void covid::search_by_gender()
{

    fstream in("covid_record1.txt");
    // in.open("covid_record1.txt", ios::in | ios::binary);
    //covid obj;
    in.seekg(0, in.beg);

    int flag = 0;
    char g;
    int p = 0;
    cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 COVID MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
        << endl;
    cout << "\t\t\t\t\t\t Powered By:- Coding Halt " << endl
        << endl;
    cout << "\n\t\t\t*****************************************\n";
    cout << "\t\t\t\t GENDER SEARCHING ";
    cout << "\n\t\t\t*****************************************\n\n";
    cout << "Enter gender by which you want to search " << endl;
    cin >> g;
    show();
    in.read((char*)this, sizeof(covid));
    while (!in.eof())
    {
        if (toupper(g) == toupper(gender))
        {
            show_list();
            flag = 1;
            p++;
        }
        in.read((char*)this, sizeof(covid));
    }
    if (flag == 0)
    {
        cout << "The gender you entered does not exist " << endl;
    }
    cout << "\n\n\n NO. of people vaccinated by this gender " << p << endl;
    in.close();
}

void covid::show_list()
{
    cout << "\n";
    cout << setw(20) << setiosflags(ios::left) << name;
    cout << setw(20) << address;
    cout << setw(10) << age;
    cout << setw(18) << profession;
    cout << setw(7) << gender;
    cout << setw(15) << mobile_number;
}
void show()
{
    cout << setw(20) << setiosflags(ios::left) << "Name ";
    cout << setw(20) << "Address";
    cout << setw(10) << "Age";
    cout << setw(18) << "Profession";
    cout << setw(7) << "gender";
    cout << setw(15) << "Mobile No.";
}

int main()
{
    covid obj;
    int ch;
    cout << "\n\n\t\t\t\t\xB3\xB2=\xB2=\xB2-\xB3 COVID MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
        << endl;
    cout << "\t\t\n\n\n Powered By:- COVID HELP AND RESCUE " << endl;
    cout << "\t\t\n\n\n\t\t\tHEY WELCOME TO THE SYSTEM PRESS ANY THING TO CONTINUE..." << endl;
    _getch();
    system("cls");
    login_ask();
    do
    {
        cout << "\n\n\t\t\xB3\xB2=\xB2=\xB2-\xB3 COVID MANAGEMENT SYSTEM  \xB3\xB2=\xB2=\xB2-\xB3\n\n"
            << endl;
        cout << "\t\t\n\n\n Powered By:- COVID HELP AND RESCUE  " << endl;
        menu();
        cout << "\n\t\n\tChoose according to your need : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            system("cls");
            obj.add_new();
            break;
        case 2:
            system("cls");
            obj.delte_record();
            break;
        case 3:
            system("cls");
            obj.search_data();
            break;
        case 4:
            system("cls");
            obj.modify_data();
            break;
        case 5:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\tTHANK YOU!!";
            Sleep(3000);
            exit(0);
        default:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\tTHANK YOU!!";
            Sleep(3000);
            exit(0);
        }
    } while (ch != 0);
}