#include "../../Doan_QLCB/lib/Library.h"
class Tuple
{
    public:
        int first, second, third;
        Tuple(int first, int second, int third)
        {
            this->first = first;
            this->second = second;
            this->third = third;
        };
        ~Tuple(){};
};

Tuple best_sum(-1e9, 0, 0);
int n, W, *v = new int[n], *w = new int [n];

void Open()
{
    cin >> n >> W;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
    }
}

void Backtracking(int i, Tuple sum)
{
    if (sum.second > W) return ;
    if (i == n) 
        {
            cout << sum.first << " ";
            if (sum.second <= W)
            {    
                if (best_sum.first < sum.first) best_sum = sum;
                else if (best_sum.first == sum.first && sum.third > best_sum.third) best_sum = sum;
            }
            return;
        }
    Backtracking(i + 1, {sum.first + (v[i] * 0), sum.second + (w[i] * 0), sum.third});
    Backtracking(i + 1, {sum.first + v[i], sum.second + w[i], sum.third + 1});
}\

void Print()
{
    cout << best_sum.first << "\n" << best_sum.third;
}

int main()
{
    Open();
    Backtracking(0, {0, 0, 0});
    Print();
    return 0;
}