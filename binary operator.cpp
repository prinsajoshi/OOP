/*Problem1: Overload the binary operator - to multiply the 2x2 matrix. 
Define a class Matrix with 2-D integer type array with equal size 2.
Initialize one object of Matrix M1 with predefined values.
Initialize another object of Matrix M2 with user’s values.
Similarly, create another object M3 with 0 values to store the result. 
Now define an operator function to make the expression M3 = M1-M2 executable.*/
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
             << " Elements of  matrix1: " << endl;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cout << "The element a" << i + 1 << j + 1 << " : ";
                cout << this->a[i][j] << endl;
            }
        }
    }
    void set();
    void show();

    matrix operator-(matrix x);
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
    cout << "\nMultiplication of 2*2 matrix1 * matrix2 is=\n";
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << a[i][j] << "  ";
        }
        cout << endl;
    }
}

matrix matrix::operator-(matrix x)
{
    matrix c;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            // c.a[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                c.a[i][j] = c.a[i][j] + a[i][k] * x.a[k][j];  //multiplication of 2*2 matrix
            }
        }
    }
    return (c);
}
int main()
{
    matrix m1(1, 2, 3, 4), m2, m3;
    m2.set();
    m3 = m1 - m2;
    m3.show();
    return 0;
}
