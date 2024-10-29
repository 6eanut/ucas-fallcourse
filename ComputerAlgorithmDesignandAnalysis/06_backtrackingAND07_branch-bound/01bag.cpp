#include <bits/stdc++.h>
using namespace std;

int bag = 30;

typedef struct item
{
    int weight;
    int value;
} item;

item items[16] = {{3, 15}, {4, 16}, {7, 3}, {9, 10}, {21, 17}, {12, 16}, {3, 3}, {54, 12}, {21, 9}, {2, 4}, {7, 3}, {8, 8}, {4, 17}, {4, 2}, {3, 3}, {9, 33}};

void compute(int number, int &now_weight, int &now_value, bool have)
{
    if (have)
    {

        now_value += items[number].value;
        now_weight += items[number].weight;
    }
    else
    {
    }
}

int main()
{
    bool have[16];
    int max_value = 0;
    int weight_sum = 0, value_sum = 0;
    for (int i = 0; i < 16; i++)
    {
        
    }
    return 0;
}