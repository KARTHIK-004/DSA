#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

// Find element with highest and lowest frequency
void findHighestLowestFrequency(int arr[], int n)
{
    // Edge case: empty array
    if (n == 0)
    {
        cout << "Array is empty!" << endl;
        return;
    }

    // Count frequencies using unordered_map
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    // Find highest and lowest frequency
    int maxFreq = INT_MIN;
    int minFreq = INT_MAX;
    int maxElement = arr[0];
    int minElement = arr[0];

    for (auto it : freq)
    {
        int element = it.first;
        int count = it.second;

        // Update maximum frequency
        if (count > maxFreq)
        {
            maxFreq = count;
            maxElement = element;
        }
        else if (count == maxFreq && element < maxElement)
        {
            // If same frequency, choose smaller element
            maxElement = element;
        }

        // Update minimum frequency
        if (count < minFreq)
        {
            minFreq = count;
            minElement = element;
        }
        else if (count == minFreq && element < minElement)
        {
            // If same frequency, choose smaller element
            minElement = element;
        }
    }

    // Display results
    cout << "Frequency Map:" << endl;
    for (auto it : freq)
    {
        cout << it.first << " -> " << it.second << endl;
    }

    cout << "\nHighest Frequency Element: " << maxElement << " (appears " << maxFreq << " times)" << endl;
    cout << "Lowest Frequency Element: " << minElement << " (appears " << minFreq << " times)" << endl;
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid array size!" << endl;
        return 0;
    }

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    findHighestLowestFrequency(arr, n);

    return 0;
}

