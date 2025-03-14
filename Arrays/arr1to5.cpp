#include <iostream>
#include <vector>
#include <limits.h> // For INT_MIN
using namespace std;

/* 📝 1️⃣ FIND LARGEST ELEMENT IN AN ARRAY
   - Traverse the array and track the maximum element.
   - Time Complexity: O(N)
   - Space Complexity: O(1) (No extra space used)
*/
int findLargest(vector<int>& arr) {
    int largest = INT_MIN; // Initialize with the smallest possible value
    for (int num : arr) {
        if (num > largest) largest = num; // Update if a larger element is found
    }
    return largest;
}

/*
📌 DRY RUN (Input: [3, 7, 1, 9, 5])
Step 1: largest = -∞
Step 2: Compare → 3, 7, 1, 9, 5 → Max is 9 ✅
Output: 9
*/

/* 📝 2️⃣ FIND SECOND LARGEST ELEMENT WITHOUT SORTING
   - Use two variables to track the largest and second largest.
   - Time Complexity: O(N)
   - Space Complexity: O(1)
*/
int findSecondLargest(vector<int>& arr) {
    int largest = INT_MIN, secondLargest = INT_MIN;
    for (int num : arr) {
        if (num > largest) {
            secondLargest = largest; // Update second largest
            largest = num; // Update largest
        } else if (num > secondLargest && num != largest) {
            secondLargest = num; // Update second largest if it's not the largest
        }
    }
    return (secondLargest == INT_MIN) ? -1 : secondLargest;
}

/*
📌 DRY RUN (Input: [3, 7, 1, 9, 5])
Step 1: largest = -∞, secondLargest = -∞
Step 2: 3 → largest=3, 7 → largest=7, secondLargest=3, ...
Step 3: Final largest=9, secondLargest=7 ✅
Output: 7
*/

/* 📝 3️⃣ CHECK IF THE ARRAY IS SORTED
   - Traverse and compare adjacent elements.
   - If any pair is unsorted, return false.
   - Time Complexity: O(N)
   - Space Complexity: O(1)
*/
bool isSorted(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        if (arr[i] > arr[i + 1]) return false; // Found an unsorted pair
    }
    return true;
}

/*
📌 DRY RUN (Input: [1, 2, 3, 5, 4])
Step 1: Compare (1,2), (2,3), (3,5) ✅
Step 2: Compare (5,4) ❌ → Not sorted
Output: false
*/

/* 📝 4️⃣ REMOVE DUPLICATES FROM A SORTED ARRAY
   - Use a two-pointer approach to shift unique elements.
   - Time Complexity: O(N)
   - Space Complexity: O(1)
*/
int removeDuplicates(vector<int>& arr) {
    if (arr.empty()) return 0;
    int j = 0; // Pointer for unique elements
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] != arr[j]) arr[++j] = arr[i]; // Move unique element to correct position
    }
    return j + 1; // New length of the modified array
}

/*
📌 DRY RUN (Input: [1, 1, 2, 2, 3])
Step 1: j=0, i=1 → Skip 1 (duplicate)
Step 2: i=2 → Move 2 to j+1 position, ...
Step 3: Final array: [1, 2, 3, _, _]
Output: Length = 3
*/

/* 📝 5️⃣ LEFT ROTATE AN ARRAY BY ONE PLACE
   - Store the first element, shift all elements left, and put the first at the end.
   - Time Complexity: O(N)
   - Space Complexity: O(1)
*/
void leftRotateByOne(vector<int>& arr) {
    if (arr.empty()) return;
    int first = arr[0]; // Store first element
    for (int i = 0; i < arr.size() - 1; i++) {
        arr[i] = arr[i + 1]; // Shift left
    }
    arr[arr.size() - 1] = first; // Put the first element at the end
}

/*
📌 DRY RUN (Input: [1, 2, 3, 4, 5])
Step 1: Store 1, shift left → [2, 3, 4, 5, _]
Step 2: Place stored 1 at end → [2, 3, 4, 5, 1]
Output: [2, 3, 4, 5, 1]
*/

/* 🏆 MAIN FUNCTION */
int main() {
    vector<int> arr = {3, 7, 1, 9, 5}; // Sample input array

    // 1️⃣ Find the largest element
    cout << "Largest Element: " << findLargest(arr) << endl;

    // 2️⃣ Find the second largest element
    cout << "Second Largest Element: " << findSecondLargest(arr) << endl;

    // 3️⃣ Check if the array is sorted
    cout << "Is Sorted? " << (isSorted(arr) ? "Yes" : "No") << endl;

    // 4️⃣ Remove duplicates from a sorted array
    vector<int> sortedArr = {1, 1, 2, 2, 3};
    int newLength = removeDuplicates(sortedArr);
    cout << "After Removing Duplicates: ";
    for (int i = 0; i < newLength; i++) cout << sortedArr[i] << " ";
    cout << endl;

    // 5️⃣ Left rotate array by one place
    vector<int> rotateArr = {1, 2, 3, 4, 5};
    leftRotateByOne(rotateArr);
    cout << "Left Rotated Array: ";
    for (int num : rotateArr) cout << num << " ";
    cout << endl;

    return 0;
}

/*
⏳ TIME COMPLEXITY SUMMARY:
-------------------------------------
| Problem                        | Time Complexity | Space Complexity |
|---------------------------------|----------------|------------------|
| Largest Element in an Array     | O(N)           | O(1)             |
| Second Largest Element          | O(N)           | O(1)             |
| Check if Array is Sorted        | O(N)           | O(1)             |
| Remove Duplicates (Sorted)      | O(N)           | O(1)             |
| Left Rotate Array by One Place  | O(N)           | O(1)             |
-------------------------------------
🚀 **Optimized! No extra space used (except for result storage).**
*/

