#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace chrono;

void maxHeapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void maxHeapSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

void minHeapify(vector<int> &arr, int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void minHeapSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }

    reverse(arr.begin(), arr.end());
}

int main()
{
    int n;

    cout << "Enter number of employees: ";
    cin >> n;

    vector<int> original(n);

    cout << "Enter employee salaries:\n";
    for (int i = 0; i < n; i++)
        cin >> original[i];

    vector<int> maxHeapArray = original;
    vector<int> minHeapArray = original;

    auto startMax = high_resolution_clock::now();
    maxHeapSort(maxHeapArray);
    auto endMax = high_resolution_clock::now();

    auto startMin = high_resolution_clock::now();
    minHeapSort(minHeapArray);
    auto endMin = high_resolution_clock::now();

    auto nanoMax = duration_cast<nanoseconds>(endMax - startMax);
    auto microMax = duration_cast<microseconds>(endMax - startMax);

    auto nanoMin = duration_cast<nanoseconds>(endMin - startMin);
    auto microMin = duration_cast<microseconds>(endMin - startMin);

    cout << "\nSorted Salaries (Max Heap):\n";
    for (int x : maxHeapArray)
        cout << x << " ";

    cout << "\n\nSorted Salaries (Min Heap):\n";
    for (int x : minHeapArray)
        cout << x << " ";

    cout << "\n\n========== MAX HEAP SORT ==========\n";
    cout << "Nanoseconds  : " << nanoMax.count() << " ns\n";
    cout << "Microseconds : " << microMax.count() << " us\n";

    cout << "\n========== MIN HEAP SORT ==========\n";
    cout << "Nanoseconds  : " << nanoMin.count() << " ns\n";
    cout << "Microseconds : " << microMin.count() << " us\n";

    return 0;
}

Enter number of employees: 5
Enter employee salaries:
50000
60000
100000
25000
45000

Sorted Salaries (Max Heap):
25000 45000 50000 60000 100000 

Sorted Salaries (Min Heap):
25000 45000 50000 60000 100000 

========== MAX HEAP SORT ==========
Nanoseconds  : 660 ns
Microseconds : 0 us

========== MIN HEAP SORT ==========
Nanoseconds  : 790 ns
Microseconds : 0 us


=== Code Execution Successful ===