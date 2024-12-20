#include <bits/stdc++.h>
using namespace std;

/*

learnings
-> to_string(n) is to convert iinto string type, TC is O(n)
Loop for Comparison: O(n).
Total: O(n).

-> a [0] = a [n-1] ,
   a [i] = a [n-(i+1)]
   
*/

class Solution
{
    public:
        string is_palindrome(int n)
        {
            // Convert the number to a string
            string temp = to_string(n);

            // Loop to compare characters from both ends
            for (int i = 0; i < temp.length(); i++) {
                if (temp[i] != temp[temp.length() - 1 - i]) {
                    return "No"; // Return "No" if mismatch found
                }
            }

            return "Yes"; // Return "Yes" if all characters match
        }
};

int main()
{
    Solution obj;
    int number;

    // Input the number to check
    cout << "Enter a number: ";
    cin >> number;

    // Call the function and display the result
    string result = obj.is_palindrome(number);
    cout << "Is the number a palindrome? " << result << endl;

    return 0;
}
