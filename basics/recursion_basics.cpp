// Recursion Explained with Simple Examples
#include <iostream>
using namespace std;

// 1️⃣ Print "Hello" N times (Basic Recursion)
void printNtimes(int n) {
    if (n == 0) return; // Base case: stop when n is 0
    cout << "Hello\n";
    printNtimes(n - 1); // Recursive call with decremented N
}

// 2️⃣ Print a Name N times
void printName(int n) {
    if (n == 0) return;
    cout << "Alice\n"; // Print name
    printName(n - 1); // Recursive call
}

// 3️⃣ Print Numbers from 1 to N
void print1ToN(int i, int n) {
    if (i > n) return; // Base case
    cout << i << " ";
    print1ToN(i + 1, n); // Recursive call with i+1
}

// 4️⃣ Print Numbers from N to 1
void printNto1(int n) {
    if (n == 0) return;
    cout << n << " ";
    printNto1(n - 1); // Recursive call with N-1
}

// 5️⃣ Sum of First N Numbers
int sumOfN(int n) {
    if (n == 0) return 0; // Base case
    return n + sumOfN(n - 1); // Sum formula
}

// 6️⃣ Factorial of N
int factorial(int n) {
    if (n == 1) return 1; // Base case
    return n * factorial(n - 1); // Recursive factorial
}

// 7️⃣ Reverse an Array
void reverseArray(int arr[], int left, int right) {
    if (left >= right) return; // Base case
    swap(arr[left], arr[right]); // Swap first & last
    reverseArray(arr, left + 1, right - 1); // Move inwards
}

// 8️⃣ Check if a String is a Palindrome
bool isPalindrome(string &s, int left, int right) {
    if (left >= right) return true; // Base case
    if (s[left] != s[right]) return false; // Mismatch
    return isPalindrome(s, left + 1, right - 1); // Move inwards
}

// 9️⃣ Find the Nth Fibonacci Number
int fibonacci(int n) {
    if (n <= 1) return n; // Base cases: Fib(0) = 0, Fib(1) = 1
    return fibonacci(n - 1) + fibonacci(n - 2); // Recurrence relation
}

int main() {
    int n;
    cin >> n;
    
    // Function Calls for Testing
    printNtimes(n);
    printName(n);
    print1ToN(1, n);
    printNto1(n);
    cout << "\nSum: " << sumOfN(n);
    cout << "\nFactorial: " << factorial(n);
    
    // Reverse an Array
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    reverseArray(arr, 0, n - 1);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    
    // Check Palindrome
    string s;
    cin >> s;
    cout << (isPalindrome(s, 0, s.size() - 1) ? "YES" : "NO");
    
    // Fibonacci Number
    cout << "\nFibonacci: " << fibonacci(n);
    
    return 0;
}
