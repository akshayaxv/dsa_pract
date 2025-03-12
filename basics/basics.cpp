/*
 * 🚀 Super Simple & Optimized C++ Solutions 🚀
 * Each function is explained with easy-to-remember tricks.
 */

#include<iostream>
#include<cmath>
using namespace std;

// ✅ 1️⃣ Count Digits (Optimized: O(1) using log10)
int countDigits(int n) {
    return floor(log10(n) + 1); // Compute number of digits using log10
}

// ✅ 2️⃣ Reverse a Number
int reverseNumber(int n) {
    int rev = 0;
    while(n > 0) { // Loop until all digits are reversed
        rev = rev * 10 + (n % 10); // Extract last digit and add to rev
        n /= 10; // Remove last digit from n
    }
    return rev;
}

// ✅ 3️⃣ Check Palindrome (Reverse & Compare)
bool isPalindrome(int n) {
    return n == reverseNumber(n); // Compare original with reversed number
}

// ✅ 4️⃣ GCD (Optimized Euclidean Algorithm)
int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b); // Recursively compute GCD
}


//A number is called an Armstrong number if:
// You split its digits.
// Raise each digit to the power of the total number of digits.
// Add them all up.
// If the sum matches the original number, it's an Armstrong number!
// Instead of calculating pow(x, digits) again and again, we precompute it for numbers 0 to 9 once and store it in an array.

// ✅ 5️⃣ Armstrong Number (Optimized with Precomputed Powers)
bool isArmstrong(int n) {
    int original = n, sum = 0, digits = countDigits(n);
    int power[10];  // Precompute powers of digits
    for (int i = 0; i < 10; i++) 
        power[i] = pow(i, digits);
    while(n > 0) {
        sum += power[n % 10]; // Add power of last digit
        n /= 10; // Remove last digit
    }
    return sum == original; // Check if sum matches original number
}

// ✅ 6️⃣ Print All Divisors (Optimized: O(√n))
void printDivisors(int n) {
    for (int i = 1; i * i <= n; i++) { // Loop till sqrt(n) Why? Divisors come in pairs!

        if (n % i == 0) {
            cout << i << " "; // Print divisor
            if (i != n / i) cout << n / i << " ";  // Print pair divisor
        }
    }
}

// ✅ 7️⃣ Check Prime (Optimized: O(√n) using 6k ± 1 Rule)
bool isPrime(int n) {
    if (n <= 1) return false; // 0 and 1 are not prime
    if (n <= 3) return true; // 2 and 3 are prime
    if (n % 2 == 0 || n % 3 == 0) return false; // Check divisibility by 2 and 3
    for (int i = 5; i * i <= n; i += 6) { // Check divisibility using 6k ± 1 optimization
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}


bool isPrime(int n) {
    if(n <= 1) return false;

    for(int i = 2; i < n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

// 🚀 MAIN FUNCTION (Demo Usage)
int main() {
    int n;
    cin >> n; // Take input from user
    
    cout << "Digits: " << countDigits(n) << "\n"; // Print digit count
    cout << "Reverse: " << reverseNumber(n) << "\n"; // Print reversed number
    cout << "Palindrome: " << (isPalindrome(n) ? "YES" : "NO") << "\n"; // Check palindrome
    cout << "GCD with 10: " << gcd(n, 10) << "\n"; // Compute GCD with 10
    cout << "Armstrong: " << (isArmstrong(n) ? "YES" : "NO") << "\n"; // Check Armstrong number
    cout << "Divisors: "; printDivisors(n); cout << "\n"; // Print all divisors
    cout << "Prime: " << (isPrime(n) ? "YES" : "NO") << "\n"; // Check prime number
    
    return 0;
}



