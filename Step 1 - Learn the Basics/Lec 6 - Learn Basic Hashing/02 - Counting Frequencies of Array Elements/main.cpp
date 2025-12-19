#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

// Method 1: Using unordered_map (Best for most cases)
void countFrequenciesUnorderedMap(int arr[], int n)
{
    unordered_map<int, int> freq;

    // Count frequencies
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    // Display frequencies
    cout << "Element -> Frequency" << endl;
    for (auto it : freq)
    {
        cout << it.first << " -> " << it.second << endl;
    }
}

// Method 2: Using map (When sorted output is needed)
void countFrequenciesMap(int arr[], int n)
{
    map<int, int> freq;

    // Count frequencies
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    // Display frequencies (sorted by key)
    cout << "Element -> Frequency (Sorted)" << endl;
    for (auto it : freq)
    {
        cout << it.first << " -> " << it.second << endl;
    }
}

// Method 3: Using array (When range is small and known)
void countFrequenciesArray(int arr[], int n, int maxVal)
{
    // Create hash array
    int hash[maxVal + 1] = {0};

    // Count frequencies
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }

    // Display frequencies
    cout << "Element -> Frequency (Array Method)" << endl;
    for (int i = 0; i <= maxVal; i++)
    {
        if (hash[i] > 0)
        {
            cout << i << " -> " << hash[i] << endl;
        }
    }
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "\n=== Using Unordered Map ===" << endl;
    countFrequenciesUnorderedMap(arr, n);

    cout << "\n=== Using Map ===" << endl;
    countFrequenciesMap(arr, n);

    // For array method, find max value
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    cout << "\n=== Using Array ===" << endl;
    countFrequenciesArray(arr, n, maxVal);

    return 0;
}

