#include <iostream>

using namespace std;

void Open(int &n, int *a)
{
    cout << "n = ";
    cin >> n;
    for (int i = 0; i < n; i ++)
    {
        cout << "a["  << i << "] = ";
        cin >> a[i];
    }
}

void backtracking(int i, int sum, int &max_sum, int n, int *a)
{
    if (i == n)
    {
        if (sum > max_sum) max_sum = sum;
        return;
    }

    backtracking(i + 1, sum, max_sum, n, a);
    backtracking(i + 1, sum + a[i], max_sum, n, a);
}

void Print(int n, int *a, int max_sum)
{
    cout << n << "\n";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n" << "Max sum: " << max_sum;
}

int main()
{
    int n, max_sum = -1e9;
    int *a = new int[n];
    Open(n, a);
    backtracking(0, 0, max_sum, n, a);
    Print(n, a, max_sum);
    return 0;
}