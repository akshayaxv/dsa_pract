#include <iostream>
#include <vector>
using namespace std;

/* 📝 1️⃣ BINARY SEARCH TO FIND X IN A SORTED ARRAY
   - Finds the index of X in a sorted array.
   - Time Complexity: O(log N)
   - Space Complexity: O(1)
*/
int binarySearch(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Avoid overflow

        if (arr[mid] == target) return mid; // Found X!
        else if (arr[mid] < target) left = mid + 1; // Search right
        else right = mid - 1; // Search left
    }

    return -1; // Not found
}

/*
📌 DRY RUN (Input: [1, 3, 5, 7, 9, 11], target = 7)
Step 1: mid = (0+5)/2 = 2 → arr[2] = 5 (Too low, move right)
Step 2: mid = (3+5)/2 = 4 → arr[4] = 9 (Too high, move left)
Step 3: mid = (3+3)/2 = 3 → arr[3] = 7 ✅ Found!
Output: 3
*/

/* 📝 2️⃣ LOWER BOUND IMPLEMENTATION
   - Returns the first position where X can be inserted.
   - Time Complexity: O(log N)
   - Space Complexity: O(1)
*/
int findFloor(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    int floorIndex = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] <= target) {
            floorIndex = mid;  // Potential floor found
            left = mid + 1;    // Try to find a closer value
        } else {
            right = mid - 1;
        }
    }

    return floorIndex;
}

/*
📌 DRY RUN (Input: [1,2,4,4,4,6,7], target = 4)
Step 1: Search first occurrence of 4
Output: 2 (4 is first found at index 2)
*/

/* 📝 3️⃣ UPPER BOUND and lb IMPLEMENTATION
   - Returns the position where X is greater than the given number.
   - Time Complexity: O(log N)
   - Space Complexity: O(1)
*/
int upperBound(vector<int>& arr, int target) {
    int left = 0, right = arr.size();

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= target) left = mid + 1;
        else right = mid;
    }

    return left;
}

vector<int> getFloorAndCeil(int x, vector<int> &arr) {
    sort(arr.begin(), arr.end()); // Sort the array first
    int floor = -1, ceil = -1;
    int left = 0, right = arr.size() - 1;

    // Find Floor (largest ≤ x)
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= x) {
            floor = arr[mid]; // Store the possible floor
            left = mid + 1;   // Search on the right side for a larger floor
        } else {
            right = mid - 1;
        }
    }

    left = 0, right = arr.size() - 1;

    // Find Ceil (smallest ≥ x)
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] >= x) {
            ceil = arr[mid];  // Store the possible ceil
            right = mid - 1;  // Search on the left side for a smaller ceil
        } else {
            left = mid + 1;
        }
    }

    return {floor, ceil};
}



/*
📌 DRY RUN (Input: [1,2,4,4,4,6,7], target = 4)
Step 1: Find first element > 4
Output: 5 (First number greater than 4 is at index 5)
*/

/* 📝 4️⃣ SEARCH INSERT POSITION
   - Returns index where X should be inserted.
   - Time Complexity: O(log N)
   - Space Complexity: O(1)
*/
int searchInsertPosition(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    return left; // Return the position where X can be inserted
}

/*
📌 DRY RUN (Input: [1,3,5,6], target = 2)
Step 1: Find the position where 2 should be inserted
Output: 1 (Insert at index 1)
*/

/* 📝 5️⃣ FLOOR AND CEIL IN A SORTED ARRAY
   - Floor: Largest number ≤ X
   - Ceil: Smallest number ≥ X
   - Time Complexity: O(log N)
   - Space Complexity: O(1)
*/
pair<int, int> findFloorAndCeil(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    int floor = -1, ceil = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return {arr[mid], arr[mid]};
        else if (arr[mid] < target) {
            floor = arr[mid];
            left = mid + 1;
        } else {
            ceil = arr[mid];
            right = mid - 1;
        }
    }

    return {floor, ceil};
}

/*
📌 DRY RUN (Input: [1,2,4,6,8,10], target = 5)
Step 1: Find floor (≤ 5) → 4
Step 2: Find ceil (≥ 5) → 6
Output: (Floor=4, Ceil=6)
*/

/* 📝 6️⃣ FIND FIRST AND LAST OCCURRENCE OF AN ELEMENT
   - Uses Binary Search twice.
   - Time Complexity: O(log N)
   - Space Complexity: O(1)
*/
pair<int, int> findFirstAndLast(vector<int>& arr, int target) {
    int first = lowerBound(arr, target);
    int last = upperBound(arr, target) - 1;

    if (first >= arr.size() || arr[first] != target) return {-1, -1}; // Not found

    return {first, last};
}

//orrr sol 2
int findFirst(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    int first = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            first = mid;
            right = mid - 1;  // Keep searching towards the left side
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return first;
}

// 🔎 Find the last occurrence using Binary Search
int findLast(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    int last = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            last = mid;
            left = mid + 1;  // Keep searching towards the right side
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return last;
}

// 🚀 Main Function to Find First and Last Occurrence
vector<int> searchRange(vector<int>& nums, int target) {
    int first = findFirst(nums, target);
    int last = findLast(nums, target);
    return {first, last};
}

/*
📌 DRY RUN (Input: [1,2,4,4,4,6,7], target = 4)
Output: First = 2, Last = 4
*/

/* 📝 7️⃣ COUNT OCCURRENCES OF A NUMBER IN SORTED ARRAY
   - Uses Lower Bound & Upper Bound.
   - Time Complexity: O(log N)
   - Space Complexity: O(1)
*/
int countOccurrences(vector<int>& arr, int target) {
    int first = lowerBound(arr, target);
    int last = upperBound(arr, target) - 1;

    if (first >= arr.size() || arr[first] != target) return 0; // Not found

    return last - first + 1;
}

/*
📌 DRY RUN (Input: [1,2,4,4,4,6,7], target = 4)
Step 1: First occurrence at 2
Step 2: Last occurrence at 4
Step 3: Count = last - first + 1 = 3
Output: 3
*/

/* 🏆 MAIN FUNCTION TO TEST ALL FUNCTIONS */
int main() {
    vector<int> arr = {1, 2, 4, 4, 4, 6, 7};
    
    // 1️⃣ Binary Search
    cout << "Binary Search index of 4: " << binarySearch(arr, 4) << endl;

    // 2️⃣ Lower Bound
    cout << "Lower Bound of 4: " << lowerBound(arr, 4) << endl;

    // 3️⃣ Upper Bound
    cout << "Upper Bound of 4: " << upperBound(arr, 4) << endl;

    // 4️⃣ Search Insert Position
    cout << "Insert Position for 3: " << searchInsertPosition(arr, 3) << endl;

    // 5️⃣ Floor and Ceil
    auto [floor, ceil] = findFloorAndCeil(arr, 5);
    cout << "Floor: " << floor << ", Ceil: " << ceil << endl;

    // 6️⃣ First & Last Occurrence
    auto [first, last] = findFirstAndLast(arr, 4);
    cout << "First occurrence: " << first << ", Last occurrence: " << last << endl;

    // 7️⃣ Count Occurrences
    cout << "Count occurrences of 4: " << countOccurrences(arr, 4) << endl;

    return 0;
}
