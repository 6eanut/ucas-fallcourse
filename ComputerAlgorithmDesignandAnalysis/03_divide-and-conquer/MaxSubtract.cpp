#include <bits/stdc++.h>
using namespace std;

int dijixiao(int *S, int left, int right)
{
    int pivot = S[left];
    int xiao = left + 1, da = right;
    while (xiao <= da)
    {
        while (S[xiao] < pivot)
        {
            xiao++;
        }
        while (S[da] >= pivot)
        {
            da--;
        }
        if (xiao < da)
        {
            int temp = S[xiao];
            S[xiao] = S[da];
            S[da] = temp;
        }
    }
    S[left] = S[xiao - 1];
    S[xiao - 1] = pivot;
    cout << left << "  " << right << endl;
    for (int i = 0; i < 16; ++i)
    {
        cout << S[i] << " ";
    }
    cout << endl;
    return xiao;
}

// S中的数均为正整数，n为S的长度，且为偶数
// 返回差的最大值
int MaxSubtract(int *S, int n)
{
    int line = n / 2;
    int left = 0, right = n - 1;
    int result = dijixiao(S, left, right);
    while (line != result & left < right)
    {
        if (line < result)
        {
            right = result - 1;
            result = dijixiao(S, left, right);
        }
        else
        {
            left = result + 1;
            result = dijixiao(S, left, right);
        }
    }
    int Sub = 0;
    for (int i = 0; i < n / 2; ++i)
    {
        Sub += S[i + n / 2] - S[i];
    }
    return Sub;
}

int main()
{
    int S[16] = {1, 6, 16, 9, 3, 8, 2, 13, 10, 11, 12, 7, 5, 14, 4, 15};
    for (int i = 0; i < 16; ++i)
    {
        cout << S[i] << " ";
    }
    cout << endl
         << endl;
    // cout << dijixiao(S, 0, 15);
    cout << MaxSubtract(S, 16);
    return 0;
}