#include "../../Doan_QLCB/lib/Library.h"

void Open(int &n)
{
    cin >> n;
}

int Recursion(int index)
{
    if (index == 0) return 0;
    else if (index == 1) return 1;
    
    return Recursion(index - 1) + Recursion(index - 2);
}

void print(int Fibo)
{
    cout << Fibo;
}

int main()
{
    int n;
    Open(n);
    int Fibo = Recursion(n);
    print(Fibo);
    return 0;
}