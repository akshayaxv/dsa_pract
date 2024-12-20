#include <bits/stdc++.h>
using namespace std;

// Function to compute both LCM (Least Common Multiple) and GCD (Greatest Common Divisor) of two numbers A and B
class Solution {
public:
    vector<long long> lcmAndGcd(long long A , long long B) {
        // Step 1: Calculate GCD using the built-in __gcd function -- gcd(a,a%b)
        // GCD of two numbers is the largest number that divides both A and B
        long long gcd = __gcd(A, B);  // O(log(min(A, B)))  
        
        // Step 2: Calculate LCM using the formula: LCM(A, B) = (A * B) / GCD(A, B)
        long long lcm = (A * B) / gcd; // O(1), constant time for multiplication and division
        
        // Step 3: Return a vector containing both LCM and GCD
        return {lcm, gcd}; // O(1), returning a pair of values
    }
};

int main() {
    Solution solution;
    
    // Example: A = 12, B = 15
    long long A = 12, B = 15;
    
    // Call the function to get LCM and GCD
    vector<long long> result = solution.lcmAndGcd(A, B);
    
    // Output the results
    cout << "LCM: " << result[0] << ", GCD: " << result[1] << endl;

    // Dry Run Example:
    // For A = 12, B = 15:
    // Step 1: Compute GCD(12, 15)
    // __gcd(12, 15) = 3 (using Euclidean algorithm, which takes O(log(min(12, 15))) time)
    
    // Step 2: Compute LCM using formula: LCM = (12 * 15) / 3
    // LCM = 180 / 3 = 60
    
    // Step 3: The function will return [60, 3], which corresponds to:
    // LCM = 60 and GCD = 3
    
    return 0;
}

/*
Time Complexity:
- GCD computation: O(log(min(A, B))) using the Euclidean algorithm.
- LCM computation: O(1) as it's a simple multiplication and division.
- Overall time complexity: O(log(min(A, B))).

Space Complexity:
- We are only using a few variables (gcd, lcm) and returning a fixed-size vector.
- Space complexity: O(1).

Example Dry Run for A = 12 and B = 15:
1. Convert A and B to integers: A = 12, B = 15.
2. Compute the GCD: gcd(12, 15) = 3.
   - GCD steps: 12 % 15 = 12, 15 % 12 = 3, 12 % 3 = 0, so GCD = 3.
3. Compute the LCM: LCM(12, 15) = (12 * 15) / GCD(12, 15) = 180 / 3 = 60.
4. Return the result: {60, 3} (LCM = 60, GCD = 3).

End of Dry Run.
*/
