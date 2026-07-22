#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

// Bubble Sort
void bubbleSort(vector<int> &a)
{
    for (int i = 0; i < a.size() - 1; i++)
        for (int j = 0; j < a.size() - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
}

// Selection Sort
void selectionSort(vector<int> &a)
{
    for (int i = 0; i < a.size() - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < a.size(); j++)
            if (a[j] < a[min])
                min = j;

        swap(a[i], a[min]);
    }
}

// Insertion Sort
void insertionSort(vector<int> &a)
{
    for (int i = 1; i < a.size(); i++)
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

// Merge Function
void merge(vector<int> &a, int l, int m, int r)
{
    vector<int> temp;
    int i = l;
    int j = m + 1;

    while (i <= m && j <= r)
    {
        if (a[i] < a[j])
            temp.push_back(a[i++]);
        else
            temp.push_back(a[j++]);
    }

    while (i <= m)
        temp.push_back(a[i++]);

    while (j <= r)
        temp.push_back(a[j++]);

    for (int k = 0; k < temp.size(); k++)
        a[l + k] = temp[k];
}

// Merge Sort
void mergeSort(vector<int> &a, int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;

        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);

        merge(a, l, m, r);
    }
}

// Partition Function
int partition(vector<int> &a, int low, int high)
{
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);
    return i + 1;
}

// Quick Sort
void quickSort(vector<int> &a, int low, int high)
{
    if (low < high)
    {
        int p = partition(a, low, high);

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int main()
{
    vector<int> arr(1000);

    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = rand() % 100000;
    }

    vector<int> temp;
    int n = arr.size();

    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();

    temp = arr;
    start = high_resolution_clock::now();
    bubbleSort(temp);
    stop = high_resolution_clock::now();
    cout << "Bubble Sort    : "
         << duration_cast<milliseconds>(stop - start).count()
         << " ms" << endl;

    temp = arr;
    start = high_resolution_clock::now();
    selectionSort(temp);
    stop = high_resolution_clock::now();
    cout << "Selection Sort : "
         << duration_cast<milliseconds>(stop - start).count()
         << " ms" << endl;

    temp = arr;
    start = high_resolution_clock::now();
    insertionSort(temp);
    stop = high_resolution_clock::now();
    cout << "Insertion Sort : "
         << duration_cast<milliseconds>(stop - start).count()
         << " ms" << endl;

    temp = arr;
    start = high_resolution_clock::now();
    mergeSort(temp, 0, n - 1);
    stop = high_resolution_clock::now();
    cout << "Merge Sort     : "
         << duration_cast<milliseconds>(stop - start).count()
         << " ms" << endl;

    temp = arr;
    start = high_resolution_clock::now();
    quickSort(temp, 0, n - 1);
    stop = high_resolution_clock::now();
    cout << "Quick Sort     : "
         << duration_cast<milliseconds>(stop - start).count()
         << " ms" << endl;

    return 0;
}