#include "../../Doan_QLCB/lib/Library.h"

void print(int N, int *a)
{
    for (int i = 0; i < N; i ++ ) 
        cout << a[i];
    cout << '\n';
}

void recursion(int index, const int N, int *a)
{
    for (int i = 0; i <= 1; i ++)
    {
        a[index] = i;
        if (index == N) 
        {
            print(N, a);
            return;
        }
        else if (index < N) recursion(index + 1, N, a);
    }
}

int main()
{
    int N;
    cin >> N;
    int *a = new int[N];
    recursion(0, N, a);
    return 0;
}