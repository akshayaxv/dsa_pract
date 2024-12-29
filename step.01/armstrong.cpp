#include <bits/stdc++.h>
using namespace std;

/*
 * Q. Check whether a given number is an Armstrong number or not.
 * 
 * Definition:
 * An Armstrong number of three digits is an integer such that the sum of the cubes of its digits equals the number itself.
 * Example: 371 is an Armstrong number because 3^3 + 7^3 + 1^3 = 371.
 * 
 * Time Complexity: O(d), where d is the number of digits in the input (constant for 3-digit numbers).
 * Space Complexity: O(1), as no additional data structures are used.
 */

// Function to check if a number is an Armstrong number
string isArmstrongNumber(int n) {
    int original = n;  // Store the original number
    int sum = 0;       // Initialize the sum of cubes of digits

    // Calculate the sum of cubes of digits
    while (n > 0) {
        int digit = n % 10; // Extract the last digit
        sum += digit * digit * digit; // Add the cube of the digit to the sum
        n = n / 10; // Remove the last digit
    }

    // Check if the calculated sum equals the original number
    if (sum == original) {
        return "Yes"; // The number is an Armstrong number
    } else {
        return "No"; // The number is not an Armstrong number
    }
}

// Main function to test the program
int main() {
    int n;
    cout << "Enter a 3-digit number: ";
    cin >> n; // Input the number
    cout << "Is the number an Armstrong number? " << isArmstrongNumber(n) << endl; // Output the result
    return 0;
}

/*
Dry Run Example:

Input: n = 153
Step 1: Store original = 153, initialize sum = 0
Step 2: Extract digits and calculate cube sum:
    - Extract digit = 3 (153 % 10), sum += 3^3 = 27, n = 15
    - Extract digit = 5 (15 % 10), sum += 5^3 = 125, n = 1
    - Extract digit = 1 (1 % 10), sum += 1^3 = 1, n = 0
    Total sum = 27 + 125 + 1 = 153
Step 3: Compare sum (153) with original (153):
    - They are equal, return "Yes".

Output: "Yes"

Edge Case:
Input: n = 123
Step 1: sum = 0
Step 2: Calculate sum = 1^3 + 2^3 + 3^3 = 36
Step 3: Compare sum (36) with original (123):
    - They are not equal, return "No".

Output: "No"
*/
