#include <bits/stdc++.h>
using namespace std;

#define LENGTH 5

void ModInsertSort(int *array, int left, int right)
{
    for (int i = left + 1; i <= right; ++i)
    {
        // cout << "!" << endl;
        int now = array[i];
        int front = 0, end = i - 1;
        while (front <= end)
        {
            int middle = (front + end) / 2;
            if (now >= array[middle])
                front = middle + 1;
            else
                end = middle - 1;
        }
        // cout << front << " " << end << endl;
        if (front != i)
            for (int j = i; j >= front + 1; j--)
            {
                array[j] = array[j - 1];
                // cout << "set " << j << "-" << array[j - 1] << endl;
            }
        array[front] = now;
        // cout << "set " << front << "-" << now << endl;
        // for (int t = 0; t < LENGTH; t++)
        // cout << array[t] << " ";
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
    int a[LENGTH] = {5554, 5932, 5038, 2409, 2956};
    generateArray(a);
    for (auto x : a)
        cout << x << " ";
    using clock = std::chrono::high_resolution_clock;
    auto start = clock::now();
    ModInsertSort(a, 0, LENGTH - 1);
    auto end = clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << endl
              << "time: " << duration.count() << " us" << std::endl;
    for (auto x : a)
        cout << x << " ";
    return 0;
}