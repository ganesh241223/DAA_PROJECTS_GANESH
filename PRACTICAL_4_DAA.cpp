#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function for Iterative Power
// Time Complexity: O(n)
// Space Complexity: O(1)
unsigned long long powerIterative(int base, int exp) {
    unsigned long long result = 1;

    for (int i = 1; i <= exp; i++) {
        result *= base;
    }

    return result;
}

// Function for Recursive Power
// Time Complexity: O(n)
// Space Complexity: O(n)
unsigned long long powerRecursive(int base, int exp) {
    if (exp == 0)
        return 1;

    return base * powerRecursive(base, exp - 1);
}

int main() {
    int base, exp;

    cout << "Enter Base: ";
    cin >> base;

    cout << "Enter Exponent: ";
    cin >> exp;

    if (exp < 0) {
        cout << "Please enter a non-negative exponent." << endl;
        return 1;
    }

    // Measure Iterative Implementation
    auto startIter = high_resolution_clock::now();
    unsigned long long resIter = powerIterative(base, exp);
    auto endIter = high_resolution_clock::now();

    duration<double, nano> durationIter = endIter - startIter;

    // Measure Recursive Implementation
    auto startRec = high_resolution_clock::now();
    unsigned long long resRec = powerRecursive(base, exp);
    auto endRec = high_resolution_clock::now();

    duration<double, nano> durationRec = endRec - startRec;

    // Output Results
    cout << "\n--- Results ---" << endl;
    cout << "Iterative Result : " << resIter << endl;
    cout << "Iterative Time   : " << durationIter.count() << " ns" << endl;
    cout << "-------------------------" << endl;
    cout << "Recursive Result : " << resRec << endl;
    cout << "Recursive Time   : " << durationRec.count() << " ns" << endl;

    return 0;
}