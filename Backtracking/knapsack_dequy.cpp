#include "../../Doan_QLCB/lib/Library.h"

struct Item
{
    int weight, value;  
};

class Result 
{
    public:
        int totalWeight, totalValue, totalItem, totalChoseItem;
        bool *status;
        Result()
        {
            this->totalWeight = 0;
            this->totalValue = 0;
            this->totalItem = 0;
            this->totalChoseItem = 0;
            this->status = nullptr;
        };
        Result(int totalWeight, int totalValue, int totalItem, int totalChoseItem)
        {
            this->totalWeight = totalWeight;
            this->totalValue = totalValue;
            this->totalItem = totalItem;
            this->totalChoseItem = totalChoseItem;
            this->status = new bool[totalItem];
        }
        ~Result(){};
};

void Open(int &total_item, int &max_weight, Item *items)
{
    cin >> total_item >> max_weight;
    for (int i = 0; i < total_item; i++) 
        cin >> items[i].weight >> items[i].value;
}

void Knapsack(int index, const int total_item, bool *status, const Item *items, const int max_weight, Result &result, int totalItem)
{
    if (index == total_item)
    {
        int totalWeight = 0, totalValue = 0;
        for (int i = 0; i < total_item; i++)
            {
                totalWeight += status[i] * items[i].weight;
                totalValue += status[i] * items[i].value;
            }
        
        if (totalWeight <= max_weight)
            if (totalValue > result.totalValue || (totalValue == result.totalValue && result.totalItem < totalItem))
            {
                result.totalValue = totalValue;
                result.totalWeight = totalWeight;
                result.totalItem = 0;
                for (int i = 0; i < total_item; i ++)
                {
                    result.totalItem += status[i];
                }
                memcpy(result.status, status, total_item * sizeof(bool));
            }
        return;
    }

    for (int i = 0; i <= 1; i++)
    {
        status[index] = i;
        totalItem += i;
        Knapsack(index + 1, total_item, status, items, max_weight, result, totalItem);
        totalItem -=i;
    }
}

void Print(Result result, const int total_item)
{
    cout << result.totalValue << "\n" << result.totalItem ;
}

int main()
{
    int total_item = 0, max_weight = 0;

    Item *items = new Item[total_item];
    Open(total_item, max_weight, items);

    bool *status = new bool[total_item];
    int totalItem = 0;
    memset(status, false, total_item * sizeof(bool));

    Result result(0, 0, total_item, 0);

    Knapsack(0, total_item, status, items, max_weight, result, totalItem);
    Print(result, total_item);
    return 0;
}