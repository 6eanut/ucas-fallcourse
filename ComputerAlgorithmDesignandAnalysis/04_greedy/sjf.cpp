#include <bits/stdc++.h>
using namespace std;

// 快速排序
int Partition(int *array, int left, int right)
{
    int tleft = left, tright = right;
    int pivot = array[left];
    while (tleft < tright)
    {
        while (array[tleft] <= pivot)
            tleft++;
        while (array[tright] > pivot)
            tright--;
        if (tleft < tright)
        {
            int temp = array[tleft];
            array[tleft] = array[tright];
            array[tright] = temp;
        }
    }
    array[left] = array[tright];
    array[tright] = pivot;
    return tright;
}

void QuickSort(int *array, int left, int right)
{
    if (left <= right)
    {
        int pi = Partition(array, left, right);
        QuickSort(array, left, pi - 1);
        QuickSort(array, pi + 1, right);
    }
}

// Shortest Job First (SJF) 或者 Shortest Processing Time first (SPT)
// 按照服务时间的非降序（即从最短到最长）来安排服务顺序
int main()
{
    int a[5] = {5, 3, 2, 4, 1};
    QuickSort(a, 0, 4);
    int arrange[5];
    arrange[0] = a[0];
    for (int i = 1; i < 5; ++i)
    {
        arrange[i] = arrange[i - 1] + a[i];
    }
    int result = 0;
    for (auto x : arrange)
    {
        result += x;
    }
    cout << result;
    return 0;
}

// 如果按照上述算法得到的解f不是最优解
// 则最优解f0必定存在两个相邻的顾客i和j，满足i在j之前，且i的服务时间大于j的服务时间，即a[i]>a[j]
// 假定i之前有k个顾客完成了服务，arrange[m]表示第m+1个顾客所等待的时间
// 对于解f0有，arrange[k+1]=arrange[k]+a[i] arrange[k+2]=arrange[k+1]+a[j] arrange[k+1]+arrange[k+2]=arrange[k]+a[i]+arrange[k]+a[i]+a[j]
// 对于解f有，arrange[k+1]=arrange[k]+a[j] arrange[k+2]=arrange[k+1]+a[i] arrange[k+1]+arrange[k+2]=arrange[k]+a[j]+arrange[k]+a[j]+a[i]
// 因为对于f和f0，arrange[k+1]+arrange[k+2]，前者小于后者，所以解f比解f0要快