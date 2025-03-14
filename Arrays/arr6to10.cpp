#include <iostream>
#include <vector>
#include <unordered_set> // For Union Operation
using namespace std;

/* 📝 1️⃣ LEFT ROTATE AN ARRAY BY D PLACES (Using Reversal Algorithm)
   - Reverse first D elements, reverse remaining N-D elements, then reverse the entire array.
   - Time Complexity: O(N)
   - Space Complexity: O(1)
*/
void reverseArray(vector<int>& arr, int start, int end) {
    while (start < end) {
        swap(arr[start++], arr[end--]);
    }
}

void leftRotateByD(vector<int>& arr, int d) {
    int n = arr.size();
    d = d % n; // Handle cases where d > n
    if (d == 0) return; // No rotation needed

    reverseArray(arr, 0, d - 1); // Reverse first D elements
    reverseArray(arr, d, n - 1); // Reverse last N-D elements
    reverseArray(arr, 0, n - 1); // Reverse the entire array
}

/*
📌 DRY RUN (Input: [1, 2, 3, 4, 5], D=2)
Step 1: Reverse first D → [2, 1, 3, 4, 5]
Step 2: Reverse remaining → [2, 1, 5, 4, 3]
Step 3: Reverse entire → [3, 4, 5, 1, 2]
Output: [3, 4, 5, 1, 2]
*/

/* 📝 2️⃣ MOVE ZEROS TO END (Using Two-Pointer Approach)
   - Move all non-zero elements forward and fill remaining positions with zeros.
   - Time Complexity: O(N)
   - Space Complexity: O(1)
*/
void moveZerosToEnd(vector<int>& arr) {
    int j = 0; // Points to the next available position for a non-zero element
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != 0) swap(arr[i], arr[j++]); // Move non-zero forward
    }
}

/*
📌 DRY RUN (Input: [0, 1, 0, 3, 12])
Step 1: Swap 1 to front → [1, 0, 0, 3, 12]
Step 2: Swap 3 to front → [1, 3, 0, 0, 12]
Step 3: Swap 12 to front → [1, 3, 12, 0, 0]
Output: [1, 3, 12, 0, 0]
*/

/* 📝 3️⃣ LINEAR SEARCH
   - Traverse the array and check if the target exists.
   - Time Complexity: O(N)
   - Space Complexity: O(1)
*/
int linearSearch(vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) return i; // Return index if found
    }
    return -1; // Return -1 if not found
}

/*
📌 DRY RUN (Input: [3, 7, 1, 9, 5], Target: 9)
Step 1: Compare 3 → No
Step 2: Compare 7 → No
Step 3: Compare 1 → No
Step 4: Compare 9 → Yes
Output: Index 3
*/

/* 📝 4️⃣ FIND THE UNION OF TWO ARRAYS (Using Unordered Set)
   - Use a set to store unique elements from both arrays.
   - Time Complexity: O(N + M) (Insertions in Set)
   - Space Complexity: O(N + M)
*/
vector<int> findUnion(vector<int>& arr1, vector<int>& arr2) {
    unordered_set<int> elements; // Store unique elements
    for (int num : arr1) elements.insert(num);
    for (int num : arr2) elements.insert(num);

    return vector<int>(elements.begin(), elements.end()); // Convert set to vector
}

/*
📌 DRY RUN (Input: [1, 2, 3], [2, 3, 4])
Step 1: Insert elements from first array → {1, 2, 3}
Step 2: Insert elements from second array → {1, 2, 3, 4}
Output: [1, 2, 3, 4]
*/

/* 📝 5️⃣ FIND MISSING NUMBER IN AN ARRAY (Using XOR Approach)
   - XOR all numbers from 1 to N and XOR with all array elements.
   - Remaining value gives the missing number.
   - Time Complexity: O(N)
   - Space Complexity: O(1)
*/
int findMissingNumber(vector<int>& arr, int n) {
    int xor1 = 0, xor2 = 0;

    for (int i = 1; i <= n; i++) xor1 ^= i; // XOR all numbers from 1 to N
    for (int num : arr) xor2 ^= num; // XOR all elements in the array

    return xor1 ^ xor2; // Missing number is the remaining XOR value
}

/*
📌 DRY RUN (Input: [1, 2, 4, 5], N=5)
Step 1: XOR(1^2^3^4^5) = 1^2^3^4^5
Step 2: XOR(1^2^4^5) = 1^2^4^5
Step 3: Missing = (1^2^3^4^5) ^ (1^2^4^5) = 3 ✅
Output: 3
*/

/* 🏆 MAIN FUNCTION */
int main() {
    vector<int> arr = {1, 2, 3, 4, 5}; // Sample input for rotation
    int d = 2; // Number of rotations

    leftRotateByD(arr, d);
    cout << "Left Rotated Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    vector<int> zerosArr = {0, 1, 0, 3, 12};
    moveZerosToEnd(zerosArr);
    cout << "Array after moving zeros: ";
    for (int num : zerosArr) cout << num << " ";
    cout << endl;

    vector<int> searchArr = {3, 7, 1, 9, 5};
    int target = 9;
    cout << "Linear Search Index: " << linearSearch(searchArr, target) << endl;

    vector<int> arr1 = {1, 2, 3}, arr2 = {2, 3, 4};
    vector<int> unionResult = findUnion(arr1, arr2);
    cout << "Union of Arrays: ";
    for (int num : unionResult) cout << num << " ";
    cout << endl;

    vector<int> missingArr = {1, 2, 4, 5};
    int missingNum = findMissingNumber(missingArr, 5);
    cout << "Missing Number: " << missingNum << endl;

    return 0;
}

/*
⏳ TIME COMPLEXITY SUMMARY:
------------------------------------------------
| Problem                         | Time Complexity | Space Complexity |
|---------------------------------|----------------|------------------|
| Left Rotate an Array by D Places | O(N)           | O(1)             |
| Move Zeros to End                | O(N)           | O(1)             |
| Linear Search                    | O(N)           | O(1)             |
| Find Union of Two Arrays         | O(N + M)       | O(N + M)         |
| Find Missing Number              | O(N)           | O(1)             |
------------------------------------------------
🚀 **All solutions are optimized using vectors!**
*/
