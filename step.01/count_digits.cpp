#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity: O(d), where d is the number of digits in N.
- Converting the number to a string takes O(d).
- Iterating through each digit takes O(d).

Space Complexity: O(d), to store the string representation of the number.
*/

class Solution {
public:
    int evenlyDivides(int N) {
        // Convert the number to a string to process each digit
        string temp = to_string(N);
        int count = 0;

        // Loop through each character in the string
        for (auto x : temp) {
          
            // Convert the character to an integer
            int curr = x - '0';

            // Check if the digit is non-zero and divides N evenly
            if (curr != 0 && N % curr == 0) {
                count++; // Increment the count if conditions are met
            }
        }

        // Return the final count of digits that divide N
        return count;
    }
 // Dry Run:
            // Iteration 1: 
            // x = '1', curr = 1, N % curr = 120 % 1 = 0 → count = 1

            // Iteration 2:
            // x = '2', curr = 2, N % curr = 120 % 2 = 0 → count = 2

            // Iteration 3:
            // x = '0', curr = 0, skip the iteration because division by 0 is not allowed
       
};
