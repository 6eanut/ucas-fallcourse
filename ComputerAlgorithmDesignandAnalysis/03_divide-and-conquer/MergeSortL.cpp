#include <bits/stdc++.h>
using namespace std;

#define LENGTH 5

void MergeSortL(int *array, int left, int right)
{
    if (left < right)
    {
        int b[LENGTH];
        int middle = (left + right) / 2;
        MergeSortL(array, left, middle);
        MergeSortL(array, middle + 1, right);
        int i = left, j = middle + 1, k = 0;
        for (; i <= middle & j <= right; k++)
        {
            if (array[i] > array[j])
            {
                b[k] = array[j];
                j++;
            }
            else
            {
                b[k] = array[i];
                i++;
            }
        }
        for (; i <= middle; i++, k++)
            b[k] = array[i];
        for (; j <= right; j++, k++)
            b[k] = array[j];
        for (int t = left, kt = 0; t <= right; t++, kt++)
        {
            array[t] = b[kt];
        }
    }
}

int main()
{
    int a[LENGTH] = {6, 9, 3, 2, 1};
    MergeSortL(a, 0, LENGTH - 1);
    for (auto x : a)
    {
        cout << x << " ";
    }
    return 0;
}