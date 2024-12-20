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
        bool is_palindrome(int n)
        {
            // Negative numbers cannot be palindromes
            if (n < 0) {
                return false; //edge case
            }

            // Convert the number to a string
            string temp = to_string(n);

            // Loop to compare characters from both ends
            for (int i = 0; i < temp.length() / 2; i++) {   //comparing the first half with the second half is sufficient.
                if (temp[i] != temp[temp.length() - 1 - i]) {
                    return false; // Return false if mismatch found
                }
            }

            return true; // Return true if all characters match
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
