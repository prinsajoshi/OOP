/*Problem2: Modify above program for friend function.*/
#include <iostream>
using namespace std;
class matrix
{
private:
    int a[2][2];

public:
    matrix()
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                a[i][j] = 0;
            }
        }
    }
    matrix(int a, int b, int c, int d)
    {
        this->a[0][0] = a;
        this->a[0][1] = b;
        this->a[1][0] = c;
        this->a[1][1] = d;
        cout << endl
             << "the elements of  matrix1: " << endl;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cout << "Enter element a" << i + 1 << j + 1 << " : ";
                cout << this->a[i][j] << endl;
            }
        }
    }
    void set();
    void show();

     friend matrix operator-(matrix x,matrix y);   //friend function
};
void matrix::set()
{
    cout << endl
         << "Enter elements of  matrix2: " << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "Enter element b" << i + 1 << j + 1 << " : ";
            cin >> a[i][j];
        }
    }
}
void matrix::show()
{
    cout << "\n Multiplication of 2*2 matrix1 and matrix2  is=\n";
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << a[i][j] << "  ";
        }
        cout << endl;
    }
}

matrix operator-(matrix x,matrix y)
{
    matrix c;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
             c.a[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                c.a[i][j] = c.a[i][j] +x.a[i][k] * y.a[k][j];
            }
        }
    }
    return (c);
}
int main()
{
    matrix m1(1, 3, 4, 5), m2, m3;
    m2.set();
    m3 = m1 - m2;
    m3.show();
    return 0;
}
