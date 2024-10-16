// Longest Increment Sequence
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int array[7] = {2, 8, 4, -4, 5, 9, 11};
    // dp[i]表示以array[i]结尾的序列的长度
    int dp[7] = {1, 1, 1, 1, 1, 1, 1};
    // front[i]记录i的前面的数是多少
    int front[7] = {0, 1, 2, 3, 4, 5, 6};
    int result = 1, pos = 0;
    for (int i = 1; i < 7; ++i)
    {
        int small = i, length = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (array[i] > array[j])
            {
                if (dp[j] > length)
                {
                    small = j;
                    length = dp[j];
                }
            }
        }
        if (small != i)
        {
            dp[i] = dp[small] + 1;
            front[i] = small;
            if (dp[i] > result)
            {
                result = dp[i];
                pos = i;
            }
        }
    }

    for (int i = 0; i < 7; i++)
        cout << front[i] << " ";
    cout << endl;
    cout << result << " : " << array[pos] << " ";
    while (front[pos] != pos)
    {
        cout << array[front[pos]] << " ";
        pos = front[pos];
    }
    return 0;
}