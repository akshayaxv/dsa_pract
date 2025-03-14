#include <iostream>
#include <vector>
using namespace std;

/* 📝 1️⃣ SEARCH IN ROTATED SORTED ARRAY I (Unique Elements)
   - Find the index of target in a rotated sorted array.
   - Time Complexity: O(log N)
   - Space Complexity: O(1)
*/
int searchInRotatedArray(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) return mid; // Found target

        // Left half is sorted
        if (arr[left] <= arr[mid]) {
            if (arr[left] <= target && target < arr[mid]) right = mid - 1; // Search left
            else left = mid + 1; // Search right
        }
        // Right half is sorted
        else {
            if (arr[mid] < target && target <= arr[right]) left = mid + 1; // Search right
            else right = mid - 1; // Search left
        }
    }

    return -1; // Not found
}

/*
📌 DRY RUN (Input: [4,5,6,7,0,1,2], target=0)
Step 1: mid=3, arr[3]=7 (too high, search right)
Step 2: mid=5, arr[5]=1 (too high, search left)
Step 3: mid=4, arr[4]=0 ✅ Found!
Output: 4
*/

/* 📝 2️⃣ SEARCH IN ROTATED SORTED ARRAY II (Duplicates Allowed)
   - Handle duplicate elements in a rotated sorted array.
   - Time Complexity: O(log N) (worst case O(N) when duplicates)
   - Space Complexity: O(1)
*/
bool searchInRotatedArrayII(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return true;

        // Handle duplicates by shrinking search space
        if (arr[left] == arr[mid] && arr[mid] == arr[right]) {
            left++;
            right--;
            continue;
        }

        // Normal Binary Search conditions
        if (arr[left] <= arr[mid]) {
            if (arr[left] <= target && target < arr[mid]) right = mid - 1;
            else left = mid + 1;
        } else {
            if (arr[mid] < target && target <= arr[right]) left = mid + 1;
            else right = mid - 1;
        }
    }

    return false;
}

/*
📌 DRY RUN (Input: [2,5,6,0,0,1,2], target=0)
Output: true
*/

/* 📝 3️⃣ FIND MINIMUM IN ROTATED SORTED ARRAY
   - Finds the smallest element in a rotated sorted array.
   - Time Complexity: O(log N)
   - Space Complexity: O(1)
*/
int findMinInRotatedArray(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > arr[right]) left = mid + 1;
        else right = mid;
    }

    return arr[left]; // Minimum element
}

/*
📌 DRY RUN (Input: [3,4,5,1,2])
Step 1: mid=2, arr[2]=5 (too high, search right)
Step 2: mid=3, arr[3]=1 ✅ Found min!
Output: 1
*/

/* 📝 4️⃣ FIND OUT HOW MANY TIMES AN ARRAY HAS BEEN ROTATED
   - Find the index of the minimum element (which is also the rotation count).
   - Time Complexity: O(log N)
   - Space Complexity: O(1)
*/
int countRotations(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > arr[right]) left = mid + 1;
        else right = mid;
    }

    return left; // Index of the minimum element
}

/*
📌 DRY RUN (Input: [4,5,6,7,0,1,2])
Step 1: mid=3, arr[3]=7 (too high, search right)
Step 2: mid=5, arr[5]=1 (too high, search left)
Step 3: mid=4, arr[4]=0 ✅ Rotation count = 4
Output: 4
*/

/* 📝 5️⃣ SINGLE ELEMENT IN A SORTED ARRAY
   - Find the element that appears only once (others appear twice).
   - Time Complexity: O(log N)
   - Space Complexity: O(1)
*/
int findSingleElement(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (mid % 2 == 1) mid--; // Ensure mid is even

        if (arr[mid] == arr[mid + 1]) left = mid + 2;
        else right = mid;
    }

    return arr[left]; // Single element
}

/*
📌 DRY RUN (Input: [1,1,2,3,3,4,4,8,8])
Step 1: mid=4, arr[4]=3 (even index, matches next, move right)
Step 2: mid=6, arr[6]=4 (even index, matches next, move right)
Step 3: mid=2, arr[2]=2 ✅ Found!
Output: 2
*/

/* 📝 6️⃣ FIND PEAK ELEMENT
   - Find an element that is greater than its neighbors.
   - Time Complexity: O(log N)
   - Space Complexity: O(1)
*/
int findPeakElement(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > arr[mid + 1]) right = mid;
        else left = mid + 1;
    }

    return left; // Index of peak element
}

/*
📌 DRY RUN (Input: [1,2,1,3,5,6,4])
Step 1: mid=3, arr[3]=3 (search right)
Step 2: mid=5, arr[5]=6 ✅ Found peak!
Output: 5
*/

/* 🏆 MAIN FUNCTION TO TEST ALL FUNCTIONS */
int main() {
    vector<int> arr = {4,5,6,7,0,1,2};
    
    // 1️⃣ Search in Rotated Array I
    cout << "Index of 0: " << searchInRotatedArray(arr, 0) << endl;

    // 2️⃣ Search in Rotated Array II (Duplicates)
    vector<int> arr2 = {2,5,6,0,0,1,2};
    cout << "Found 0: " << (searchInRotatedArrayII(arr2, 0) ? "true" : "false") << endl;

    // 3️⃣ Find Minimum
    cout << "Minimum Element: " << findMinInRotatedArray(arr) << endl;

    // 4️⃣ Count Rotations
    cout << "Rotation Count: " << countRotations(arr) << endl;

    // 5️⃣ Find Single Element
    vector<int> singleElementArr = {1,1,2,3,3,4,4,8,8};
    cout << "Single Element: " << findSingleElement(singleElementArr) << endl;

    // 6️⃣ Find Peak Element
    vector<int> peakArr = {1,2,1,3,5,6,4};
    cout << "Peak Element Index: " << findPeakElement(peakArr) << endl;

    return 0;
}
