#include <bits/stdc++.h>
using namespace std;

#define LENGTH 5

void QuickSort(int *array, int left, int right)
{
    if (left < right)
    {
        int pivot = array[left];
        int leftpart[LENGTH], rightpart[LENGTH];
        int leftlength = 0, rightlength = 0;
        for (int i = left + 1; i <= right; ++i)
        {
            if (array[i] < pivot)
                leftpart[leftlength++] = array[i];
            if (array[i] >= pivot)
                rightpart[rightlength++] = array[i];
        }
        QuickSort(leftpart, 0, leftlength - 1);
        QuickSort(rightpart, 0, rightlength - 1);
        for (int i = left; i <= right; ++i)
            if (i < leftlength)
                array[i] = leftpart[i];
            else if (i == leftlength)
                array[i] = pivot;
            else
                array[i] = rightpart[i - leftlength - 1];
    }
}

int main()
{
    int a[LENGTH] = {6, 9, 3, 2, 1};
    QuickSort(a, 0, LENGTH - 1);
    for (auto x : a)
    {
        cout << x << " ";
    }
    return 0;
}