#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

// Demonstrate array-based hashing (for small range of numbers)
void arrayHashing(int arr[], int n)
{
    cout << "\n=== Array-Based Hashing ===" << endl;

    // Assuming numbers are in range [0, 12]
    int hash[13] = {0}; // Initialize all to 0

    // Store frequencies
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }

    // Display hash table
    cout << "Hash Table (Index -> Frequency):" << endl;
    for (int i = 0; i < 13; i++)
    {
        if (hash[i] > 0)
        {
            cout << i << " -> " << hash[i] << endl;
        }
    }
}

// Demonstrate map-based hashing (ordered)
void mapHashing(int arr[], int n)
{
    cout << "\n=== Map-Based Hashing (Ordered) ===" << endl;

    map<int, int> hashMap;

    // Store frequencies
    for (int i = 0; i < n; i++)
    {
        hashMap[arr[i]]++;
    }

    // Display hash map (automatically sorted by key)
    cout << "Hash Map (Key -> Frequency):" << endl;
    for (auto it : hashMap)
    {
        cout << it.first << " -> " << it.second << endl;
    }
}

// Demonstrate unordered_map-based hashing (faster)
void unorderedMapHashing(int arr[], int n)
{
    cout << "\n=== Unordered Map-Based Hashing (Faster) ===" << endl;

    unordered_map<int, int> hashMap;

    // Store frequencies
    for (int i = 0; i < n; i++)
    {
        hashMap[arr[i]]++;
    }

    // Display hash map (unordered)
    cout << "Hash Map (Key -> Frequency):" << endl;
    for (auto it : hashMap)
    {
        cout << it.first << " -> " << it.second << endl;
    }
}

// Query frequencies
void queryFrequencies(int arr[], int n)
{
    cout << "\n=== Query Frequencies ===" << endl;

    // Using unordered_map for O(1) queries
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    int q;
    cout << "Enter number of queries: ";
    cin >> q;

    while (q--)
    {
        int num;
        cout << "Enter number to query: ";
        cin >> num;
        cout << "Frequency of " << num << " = " << freq[num] << endl;
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

    // Demonstrate all three hashing methods
    arrayHashing(arr, n);
    mapHashing(arr, n);
    unorderedMapHashing(arr, n);

    // Query frequencies
    queryFrequencies(arr, n);

    return 0;
}

