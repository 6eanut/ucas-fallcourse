#include <bits/stdc++.h>
using namespace std;

#define LENGTHA 16
#define LENGTHB 4

void generateArray(int *array, int length)
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed);
    std::uniform_int_distribution<int> distribution(0, 20);
    for (int i = 0; i < length; ++i)
    {
        array[i] = distribution(generator);
    }
}

void QuickSort(int *array, int left, int right, int length)
{
    if (left < right)
    {
        int pivot = array[left];
        int leftpart[length], rightpart[length];
        int leftlength = 0, rightlength = 0;
        for (int i = left + 1; i <= right; ++i)
        {
            if (array[i] < pivot)
                leftpart[leftlength++] = array[i];
            if (array[i] >= pivot)
                rightpart[rightlength++] = array[i];
        }
        QuickSort(leftpart, 0, leftlength - 1, leftlength);
        QuickSort(rightpart, 0, rightlength - 1, rightlength);
        for (int i = left; i <= right; ++i)
            if (i < leftlength)
                array[i] = leftpart[i];
            else if (i == leftlength)
                array[i] = pivot;
            else
                array[i] = rightpart[i - leftlength - 1];
    }
}

int find(int *array, int length, int target)
{
    int left = 0, right = length - 1;
    int middle;
    while (left <= right)
    {
        middle = (left + right) / 2;
        if (array[middle] == target)
            return middle;
        else if (array[middle] < target)
            left = middle + 1;
        else
            right = middle - 1;
    }
    return -1;
}

int main()
{
    int A[LENGTHA] = {
        9,
        0,
        8,
        11,
        1,
        2,
        3,
        4,
        5,
        6,
        7,
        19, 15, 16, 17, 18};
    int B[LENGTHB] = {9, 0, 8, 11};
    // generateArray(A, LENGTHA);
    // generateArray(B, LENGTHB);
    for (auto x : A)
        cout << x << " ";
    cout << endl;
    for (auto x : B)
        cout << x << " ";
    cout << endl;

    QuickSort(B, 0, LENGTHB - 1, LENGTHB);

    for (int i = 0; i < LENGTHA; ++i)
    {
        int result = find(B, LENGTHB, A[i]);
        if (result != -1)
            cout << A[i] << " ";
    }

    return 0;
}