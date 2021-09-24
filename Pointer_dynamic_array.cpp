/*Pointers and Dynamic Array*/
#include <iostream>
#include <conio.h>
using namespace std;
class array1
{
    int n = 2, num = 0;
    int *arr = new int[n];   //dynamic memory allocation
public:
    array1(){
      for (int i = 0; i < n; i++)
    {
        arr[i] = 0;
    }
    }
    
    int copy();
    void print();
    void add();
    void delete1();
    void size();
    void switch1();
};
int array1::copy()
{
    int *arr1;
    for (int i = 0; i < n; i++)
    {
        arr1[i] = arr[i];
    }
    delete[] arr;
    return *arr1;
}
void array1::print()    //print
{
    if (arr[0] != '\0')
    {
        cout << "\t\t\t\t\t";
        for (int x = 0; x < (n ); x++)
        {
            if (arr[x] != '\0')
            {
                cout << arr[x] << " , ";
            }
        }
    }
    else
    {
        cout << "\t\t\t\t\tNo elements present" << endl;
    }
}
void array1::add()   //add
{
    int *arr2;
    if (num == n)
    {
        n = n * 2;
        cout << "\t\t\t\t\tArray Expanded" << endl;
        int *arr1 = new int[n];
        for (int i = 0; i < ((n / 2) + 1); i++)
        {
            arr1[i] = arr[i];
        }
        delete[] arr;
        arr = new int[n];
        for (int i = 0; i < n; i++)
        {
        arr[i] = 0;
        }
        for (int i = 0; i < ((n / 2) + 1); i++)
        {
            arr[i] = arr1[i];
        }
        delete[] arr1;
    }
    cout << "\t\t\t\t\tEnter Element : ";
    cin >> arr[num];
    num++;
}
void array1::delete1()   //delete
{
    int a = 0, found = 0;
    cout << "\t\t\t\t\tEnter the number to be deleted : ";
    cin >> a;
    for (int i = 0; i < (n); i++)
    {
        if (arr[i] == a)
        {
            for (int j = i; j < (n - 1); j++)
                arr[j] = arr[j + 1];
                arr[n-1]='\0';
            found++;
            i--;
        }
    }
    if (found == 0)
        cout << "\t\t\t\t\tElement not found in the Array!";
    else{
        cout << "\t\t\t\t\tElement Deleted Successfully!";
        num--;
    }
    cout << endl;
    int c = 0, b = 0;

    for (int i = 0; i <= n; i++)
    {
        if (arr[i] != '\0')
        {
            c++;
        }
    }
    b = n / 2;
    if (c == b)
    {
        n = (n / 2);
        cout << "\t\t\t\t\tArray Shrinked!";
        int *arr1 = new int[n];
        for (int i = 0; i < (n); i++)
        {
            arr1[i] = arr[i];
        }
        delete[] arr;
        arr = new int[n];
        for (int i = 0; i < (n); i++)
        {
            arr[i] = arr1[i];
        }
        delete[] arr1;
    }
}
void array1::size()   //return size
{
    int no = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != '\0')
        {
            no++;
        }
    }
    cout << "\t\t\t\t\tSize:" << n << endl;

    cout << "\t\t\t\t\tElements:" << no << endl;
}
void array1::switch1()
{
    char ch;
    cout << "\n\n\n\t\t\t\t (p): Print elements" << endl;
    cout << "\n\t\t\t\t (a): Add elements" << endl;
    cout << "\n\t\t\t\t (d):Delete elements" << endl;
    cout << "\n\t\t\t\t (f):Return size" << endl;
    cout << "\n\t\t\t\t (e):Exit" << endl;
    cout << "\n\t\t\n\t\t\t\t\tEnter Option : ";
    cin >> ch;
    switch (ch)
    {
    case 'p':
        this->print();
        break;
    case 'a':
        this->add();
        break;
    case 'd':
        this->delete1();
        break;
    case 'f':
        this->size();
        break;
    case 'e':
        delete[] arr;
        exit(0);
        break;
    default:
        delete[] arr;
        exit(0);
        break;
    }
}
int main()
{
    array1 PD;
    cout << "\n\t\t\t\t\t\t\tPOINTER AND DYNAMIC ARRAYS";
    cout << "\n\t\t\t\t\t\t---------------------------------------\n";
    while (1)
    {
        PD.switch1();
    }

    return 0;
}