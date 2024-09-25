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

void generateArray(int *array)
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed);
    std::uniform_int_distribution<int> distribution(0, 10000);
    for (int i = 0; i < LENGTH; ++i)
    {
        array[i] = distribution(generator);
    }
}

int main()
{
    int a[LENGTH];
    generateArray(a);
    using clock = std::chrono::high_resolution_clock;
    auto start = clock::now();
    QuickSort(a, 0, LENGTH - 1);
    auto end = clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << endl
              << "time: " << duration.count() << " us" << std::endl;
    // for (auto x : a)
    //   cout << x << " ";
    return 0;
}