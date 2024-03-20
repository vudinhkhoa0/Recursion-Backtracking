#include "../../Doan_QLCB/lib/Library.h"

void Open(int &n)
{
    cout << "Enter the number: "; 
    cin >> n;
}

int recursion(int n)
{
    if (n == 0) return 1;

    return n * recursion(n - 1);
}

void print(int factorial, int n)
{
    cout << n << "! = " << factorial;
}

int main()
{
    int n;
    Open(n);
    int factorial = recursion(n);
    print(factorial, n);
    return 0;
}