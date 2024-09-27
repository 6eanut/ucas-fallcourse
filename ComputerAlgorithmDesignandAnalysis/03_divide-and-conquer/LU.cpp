#include <bits/stdc++.h>
using namespace std;

#define LENGTH 5

int findxiao(double *array, int length, int n, int da, int L)
{
    int left = 0, right = length - 1;
    int middle;
    while (left <= right)
    {
        middle = (left + right) / 2;
        if (da)
            if (array[middle] < n)
                left = middle + 1;
            else if (array[middle] > n)
                right = middle - 1;
            else if (L)
                left = middle + 1;
            else
                right = middle - 1;
        else if (array[middle] < n)
            right = middle - 1;
        else if (array[middle] > n)
            left = middle + 1;
        else if (L)
            right = middle - 1;
        else
            left = middle + 1;
    }
    return left;
}

void LU(double *array, int length, int L, int U)
{
    int da;
    if (array[0] < array[1])
        da = 1;
    else
        da = 0;
    int pL = findxiao(array, length, L, da, 1);
    int pU = findxiao(array, length, U, da, 0);
    cout << "pL:" << pL << ",pU:" << pU << endl;
    if (da)
        for (int i = pL; i <= pU - 1; i++)
            cout << array[i] << " ";
    else
        for (int i = pU; i <= pL - 1; i++)
            cout << array[i] << " ";
}

int main()
{
    // double a[LENGTH] = {1, 2, 4, 5, 6};
    double a[LENGTH] = {6, 5, 4, 2, 1};
    int L = 1, U = 6;
    cout << "L:" << L << ", U:" << U << endl;
    for (auto x : a)
        cout << x << " ";
    cout << endl;
    LU(a, LENGTH, L, U);
    return 0;
}