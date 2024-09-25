#include <bits/stdc++.h>
using namespace std;

#define LENGTH 10000

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
    // for (auto x : a)
    //  cout << x << " ";
    using clock = std::chrono::high_resolution_clock;
    auto start = clock::now();
    MergeSortL(a, 0, LENGTH - 1);
    auto end = clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << endl
              << "time: " << duration.count() << " us" << std::endl;
    // for (auto x : a)
    //  cout << x << " ";
    return 0;
}