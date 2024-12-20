#include <bits/stdc++.h>
using namespace std;

// Sieve of Eratosthenes using vector<bool>
// Time Complexity: O(n * log(log(n))) 
//   - Outer loop runs up to √n
//   - Inner loop marks multiples of primes.
// Space Complexity: O(n) 
//   - For the vector<bool> to store primality of numbers.

void sieve(int n) {
    // Create a vector of size (n+1) initialized to true
    vector<bool> prime(n + 1, true); // O(n)

    // Mark non-prime numbers
    for (int i = 2; i * i <= n; i++) { // Outer loop runs up to √n
        if (prime[i]) { // If i is prime
            // Mark multiples of i as non-prime
            for (int p = i * i; p <= n; p += i) { // Starts at i^2, skips by i
                prime[p] = false;
            }
        }
    }

    // Print all prime numbers up to n
    for (int i = 2; i <= n; i++) { 
        if (prime[i]) { // If the number is still marked as prime
            cout << i << " "; // Print the prime number
        }
    }
    cout << endl; // New line after printing all primes
}

int main() {
    int n;
    cin >> n; // Input the number n
    sieve(n); // Call the sieve function to find all primes up to n
    return 0;
}

/*
Dry Run Example:
Input: n = 10

1. Initialize:
   prime = [true, true, true, true, true, true, true, true, true, true, true] (1-based index)

2. Iteration 1 (i = 2):
   - 2 is prime.
   - Mark multiples of 2: 4, 6, 8, 10.
   - prime = [true, true, true, true, false, true, false, true, false, true, false]

3. Iteration 2 (i = 3):
   - 3 is prime.
   - Mark multiples of 3: 9.
   - prime = [true, true, true, true, false, true, false, true, false, false, false]

4. Iteration 3 (i = 4):
   - 4 is not prime (already marked as false).

5. Output:
   - Traverse prime from 2 to 10.
   - Indices where prime[i] = true are: 2, 3, 5, 7.

Output:
2 3 5 7
*/
