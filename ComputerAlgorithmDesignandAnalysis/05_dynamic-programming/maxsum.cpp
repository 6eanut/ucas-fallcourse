#include <bits/stdc++.h>
using namespace std;

#define LENGTH 5

int maxsum(int *a, int length)
{
    int dp[length];
    dp[0] = a[0];
    int result = dp[0];
    for (int i = 1; i < length; ++i)
    {
        if (dp[i - 1] > 0)
        {
            dp[i] = dp[i - 1] + a[i];
        }
        else
        {
            dp[i] = a[i];
        }
        if (dp[i] > result)
        {
            result = dp[i];
            // cout << result << " ";·
        }
        else
        {
        }
    }
    return result;
}

int main()
{
    int a[LENGTH] = {-1, 2, 3, 4, -5};
    cout << maxsum(a, LENGTH);
    return 0;
}