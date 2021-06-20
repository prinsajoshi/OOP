#include <iostream>
using namespace std;
int main()
{
    int num;
    cout << "How many numbers of array you wanna enter?" << endl;
    cin >> num;
    float *ptr = new float(num);
    cout << "Now enter the numbers" << endl;
    for (int i = 0; i < num; i++)
    {
        cout << "number " << (i + 1) << " is ";
        cin >> ptr[i];
    }
    cout << "Displaying the entered numbers" << endl;
    for (int i = 0; i < num; i++)
    {
        cout << "number " << (i + 1) << " is ";
        cout << ptr[i] << endl;
    }
    delete[] ptr; //clear the space
}
