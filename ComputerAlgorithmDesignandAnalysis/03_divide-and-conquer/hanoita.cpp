#include <bits/stdc++.h>
using namespace std;

#define N 5

int hanoita(int num)
{
    if (num != 1)
    {
        int step1 = hanoita(num - 1);
        int step2 = 1;
        int step3 = hanoita(num - 1);
        return step1 + step2 + step3;
    }
    else
        return 1;
}

int main()
{
    int num = N;

    int output = hanoita(N);

    cout << output;

    return 0;
}