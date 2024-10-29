#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int level;   // 当前处理到第几个物品
    int weight;  // 当前重量
    int value;   // 当前价值
    float bound; // 边界值（上界）
};

float Bound(Node u, int n, int W, vector<int> &w, vector<int> &v)
{
    if (u.weight >= W)
        return 0;
    float profit_bound = u.value;
    int j = u.level + 1;
    int totweight = u.weight;
    while ((j < n) && (totweight + w[j] <= W))
    {
        totweight += w[j];
        profit_bound += v[j];
        j++;
    }
    if (j < n)
    {
        profit_bound += (W - totweight) * v[j] / float(w[j]);
    }
    return profit_bound;
}

int Knapsack(int n, int W, vector<int> &w, vector<int> &v)
{
    queue<Node> Q;
    Node u, u1, u2;
    u.level = -1;
    u.weight = 0;
    u.value = 0;
    u.bound = Bound(u, n, W, w, v);
    Q.push(u);

    int maxprofit = 0;

    while (!Q.empty())
    {
        u = Q.front();
        Q.pop();

        if (u.level == -1)
        { // 初始节点
            u1 = u;
            u2 = u;
            u1.level = 0;
            u1.weight = 0;
            u1.value = 0;
            u2.weight = w[0];
            u2.value = v[0];
            u1.bound = Bound(u1, n, W, w, v);
            u2.bound = Bound(u2, n, W, w, v);
            if (u2.weight <= W && u2.value > maxprofit)
                maxprofit = u2.value;
            if (u1.bound > maxprofit)
                Q.push(u1);
            if (u2.bound > maxprofit)
                Q.push(u2);
        }
        else
        {
            if (u.level == n - 1)
                continue;
            u1 = u;
            u2 = u;
            u1.level = u.level + 1;
            u2.level = u.level + 1;
            u2.weight = u.weight + w[u1.level];
            u2.value = u.value + v[u1.level];
            u1.bound = Bound(u1, n, W, w, v);
            u2.bound = Bound(u2, n, W, w, v);
            if (u2.weight <= W && u2.value > maxprofit)
                maxprofit = u2.value;
            if (u1.bound > maxprofit)
                Q.push(u1);
            if (u2.bound > maxprofit)
                Q.push(u2);
        }
    }

    return maxprofit;
}

int main()
{
    int n = 16;                                                                       // 物品数量
    int W = 100;                                                                      // 背包容量
    vector<int> w = {10, 20, 30, 40, 50, 60, 70, 80, 90, 10, 20, 30, 40, 50, 60, 70}; // 物品重量
    vector<int> v = {20, 30, 66, 40, 60, 70, 80, 10, 30, 20, 60, 50, 40, 30, 20, 10}; // 物品价值

    int maxProfit = Knapsack(n, W, w, v);
    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}