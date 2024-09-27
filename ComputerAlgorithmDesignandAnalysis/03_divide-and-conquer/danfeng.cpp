#include <bits/stdc++.h>
using namespace std;

#define LENGTH 5

int danfeng(double *array, int length)
{
    int left = 0, right = length - 1;
    int middle;
    while (left <= right)
    {
        middle = (left + right) / 2;
        // cout << left << " " << right << " " << middle << endl;
        if (middle == 0 || middle == length - 1)
            return middle;
        else if (array[middle] > array[middle - 1])
            if (array[middle] > array[middle + 1])
                return middle;
            else
                left = middle + 1;
        else
            right = middle - 1;
    }
}

int main()
{
    double a[LENGTH] = {1, 2, 6, 5, 4};
    for (auto x : a)
        cout << x << " ";
    cout << endl;
    int position = danfeng(a, LENGTH);
    cout << position << " " << a[position];
    return 0;
}