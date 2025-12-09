#include <bits/stdc++.h>
using namespace std;

// Function to print a square pattern of stars
void pattern1(int N)
{
    // Outer loop to handle rows
    for (int i = 0; i < N; i++)
    {
        // Inner loop to handle columns for each row
        for (int j = 0; j < N; j++)
        {
            // Print a star followed by a space
            cout << "* ";
        }
        // After printing stars in a row, move to the next line
        cout << endl;
    }
}

int main()
{
    int N;
    cin >> N;
    pattern1(N); // Call the function to print the pattern
    return 0;
}
