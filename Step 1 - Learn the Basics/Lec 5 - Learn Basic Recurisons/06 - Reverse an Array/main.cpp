#include <iostream>
using namespace std;

void reverseArray(int arr[], int start, int end)
{
    // Base case: when start >= end, array is reversed
    if (start >= end)
        return;

    // Swap elements at start and end
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    // Recursive call with updated indices
    reverseArray(arr, start + 1, end - 1);
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the size of array: \n";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Original array: ";
    printArray(arr, n);

    reverseArray(arr, 0, n - 1);

    cout << "Reversed array: ";
    printArray(arr, n);

    return 0;
}
