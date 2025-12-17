#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str, int start, int end)
{
    // Base case: if start >= end, string is palindrome
    if (start >= end)
        return true;

    // If characters don't match, not a palindrome
    if (str[start] != str[end])
        return false;

    // Recursive call with updated indices
    return isPalindrome(str, start + 1, end - 1);
}

int main()
{
    string str;
    cout << "Enter a string: \n";
    cin >> str;

    bool result = isPalindrome(str, 0, str.length() - 1);

    if (result)
        cout << str << " is a palindrome" << endl;
    else
        cout << str << " is not a palindrome" << endl;

    return 0;
}

