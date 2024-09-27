#include <bits/stdc++.h>
using namespace std;

#define LENGTH 5

void zhengFu(double *array, int left, int right)
{
    while (left <= right)
    {
        while (array[left++] < 0)
        {
        }
        while (array[right--] > 0)
        {
        }
        double temp = array[left - 1];
        array[left - 1] = array[right + 1];
        array[right + 1] = temp;
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
    double a[LENGTH] = {55.54, -59.32, 50.38, -24.09, -29.56};
    // generateArray(a);
    for (auto x : a)
        cout << x << " ";
    using clock = std::chrono::high_resolution_clock;
    auto start = clock::now();
    zhengFu(a, 0, LENGTH - 1);
    auto end = clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << endl
              << "time: " << duration.count() << " us" << std::endl;
    for (auto x : a)
        cout << x << " ";
    return 0;
}