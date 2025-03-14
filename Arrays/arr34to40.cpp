#include <iostream>
#include <vector>
#include <unordered_map> // For Hash Maps
#include <algorithm> // For Sorting
using namespace std;

/* 📝 1️⃣ COUNT NUMBER OF SUBARRAYS WITH GIVEN XOR K (Using Hash Map)
   - Maintain prefix XOR and check occurrences.
   - Time Complexity: O(N)
   - Space Complexity: O(N)
*/
int countSubarraysWithXorK(vector<int>& arr, int k) {
    unordered_map<int, int> freq;
    int count = 0, xorSum = 0;
    for (int num : arr) {
        xorSum ^= num;
        if (xorSum == k) count++;
        if (freq.find(xorSum ^ k) != freq.end()) count += freq[xorSum ^ k];
        freq[xorSum]++;
    }
    return count;
}

/*
📌 DRY RUN (Input: [4, 2, 2, 6, 4], k=6)
Step 1: Compute prefix XOR and use hashmap to count required subarrays.
Index | Num | Prefix_XOR | Needed (XOR^k) | Count  
--------------------------------------------------
  0   |  4  |     4      |       -        |  0  
  1   |  2  |     6      |       0        |  1  → [2]  
  2   |  2  |     4      |       -        |  1  
  3   |  6  |     2      |       4        |  2  → [2,2,6]  
  4   |  4  |     6      |       0        |  4  → [6], [4,2,2,6,4]  

Output: 4
*/

/* 📝 2️⃣ MERGE OVERLAPPING INTERVALS (Sorting + Merging)
   - Sort intervals and merge overlapping ones.
   - Time Complexity: O(N log N)
   - Space Complexity: O(N)
*/
vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    for (auto& interval : intervals) {
        if (merged.empty() || merged.back()[1] < interval[0]) merged.push_back(interval);
        else merged.back()[1] = max(merged.back()[1], interval[1]);
    }
    return merged;
}

/*
📌 DRY RUN (Input: [[1,3],[2,6],[8,10],[15,18]])
Step 1: Sort intervals: [[1,3], [2,6], [8,10], [15,18]]
Step 2: Merge:
  - [1,3] and [2,6] → [1,6]
  - [8,10] remains
  - [15,18] remains
Output: [[1,6],[8,10],[15,18]]
*/

/* 📝 3️⃣ MERGE TWO SORTED ARRAYS WITHOUT EXTRA SPACE (Gap Method)
   - Use Shell Sort-like gap method.
   - Time Complexity: O(N log N)
   - Space Complexity: O(1)
*/
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // Step 1: Copy nums2 into nums1 at the end of m elements
    for (int i = 0; i < n; i++) {
        nums1[m + i] = nums2[i];
    }

    int total = m + n;
    int gap = (total / 2) + (total % 2);

    // Step 2: Apply Gap Method
    while (gap > 0) {
        int i = 0, j = gap;
        while (j < total) {
            if (nums1[i] > nums1[j]) {
                swap(nums1[i], nums1[j]);
            }
            i++;
            j++;
        }
        gap = (gap > 1) ? (gap / 2 + gap % 2) : 0; // Reduce gap size
    }
}


/*
📌 DRY RUN (Input: arr1=[1,4,7], arr2=[2,5,6])
Output: arr1=[1,2,4], arr2=[5,6,7]
*/

/* 📝 4️⃣ FIND REPEATING & MISSING NUMBER (Using XOR)
   - Use XOR properties to find missing & repeating numbers.
   - Time Complexity: O(N)
   - Space Complexity: O(1)
*/
pair<int, int> findRepeatingAndMissing(vector<int>& arr) {
    int xor1 = 0, n = arr.size();
    for (int i = 1; i <= n; i++) xor1 ^= i;
    for (int num : arr) xor1 ^= num;
    int rightmostSetBit = xor1 & -xor1;
    int x = 0, y = 0;
    for (int num : arr) (num & rightmostSetBit) ? x ^= num : y ^= num;
    for (int i = 1; i <= n; i++) (i & rightmostSetBit) ? x ^= i : y ^= i;
    for (int num : arr) if (num == x) return {x, y}; return {y, x};
}

/*
📌 DRY RUN (Input: [4,3,6,2,1,1])
Output: (Repeating=1, Missing=5)
*/

/* 📝 5️⃣ COUNT INVERSIONS (Using Merge Sort)
   - Count inversions while merging.
   - Time Complexity: O(N log N)
   - Space Complexity: O(N)
*/
int mergeAndCount(vector<int>& arr, int l, int m, int r) {
    vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);
    int i = 0, j = 0, k = l, swaps = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) arr[k++] = left[i++];
        else arr[k++] = right[j++], swaps += left.size() - i;
    }
    while (i < left.size()) arr[k++] = left[i++];
    while (j < right.size()) arr[k++] = right[j++];
    return swaps;
}

int countInversions(vector<int>& arr, int l, int r) {
    if (l >= r) return 0;
    int m = l + (r - l) / 2;
    return countInversions(arr, l, m) + countInversions(arr, m + 1, r) + mergeAndCount(arr, l, m, r);
}
int inversionCount(vector<int>& arr) {
    return countInversions(arr, 0, arr.size() - 1);
}

/*
📌 DRY RUN (Input: [5,3,2,4,1])
Output: 9 (Inversions: (5,3), (5,2), (5,4), etc.)
*/

/* 📝 6 MAXIMUM PRODUCT SUBARRAY (Kadane’s Algorithm Variation)
   - Maintain `maxProd` and `minProd` because negative numbers flip signs.
   - Time Complexity: O(N)
   - Space Complexity: O(1)
*/
int maxProductSubarray(vector<int>& arr) {
    int maxProd = arr[0], minProd = arr[0], result = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < 0) swap(maxProd, minProd);
        maxProd = max(arr[i], maxProd * arr[i]);
        minProd = min(arr[i], minProd * arr[i]);
        result = max(result, maxProd);
    }
    return result;
}

/*
📌 DRY RUN (Input: [2, 3, -2, 4])
Step 1: Track max & min product at each step
Index | Num  | MaxProd | MinProd | Result
----------------------------------------
  0   |  2   |   2    |   2     |   2
  1   |  3   |   6    |   3     |   6
  2   | -2   |  -2    |  -12    |   6
  3   |  4   |   4    |  -48    |   6

Output: 6 (Subarray: [2,3])
*/

/* 📝 7 REVERSE PAIRS (Using Modified Merge Sort)
   - Count pairs `(i, j)` where `i < j` and `arr[i] > 2 * arr[j]`
   - Approach: Modify Merge Sort to count such pairs while merging.
   - Time Complexity: O(N log N)
   - Space Complexity: O(N)
*/
int mergeAndCountReversePairs(vector<int>& arr, int l, int m, int r) {
    int count = 0, j = m + 1;

    // Count valid reverse pairs
    for (int i = l; i <= m; i++) {
        while (j <= r && arr[i] > 2LL * arr[j]) j++;
        count += (j - (m + 1));
    }

    // Merge step
    vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);
    int i = 0, k = l;
    j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }
    while (i < left.size()) arr[k++] = left[i++];
    while (j < right.size()) arr[k++] = right[j++];

    return count;
}

int countReversePairs(vector<int>& arr, int l, int r) {
    if (l >= r) return 0;
    int m = l + (r - l) / 2;
    int count = countReversePairs(arr, l, m) + countReversePairs(arr, m + 1, r);
    count += mergeAndCountReversePairs(arr, l, m, r);
    return count;
}
int reversePairs(vector<int>& nums) {
    return countReversePairs(nums, 0, nums.size() - 1);
}

/*
📌 DRY RUN (Input: [1, 3, 2, 3, 1])
Step 1: Divide and sort → [1, 3] & [2, 3, 1]
Step 2: Count valid pairs:
  - (3,1) and (3,1) are valid.
Step 3: Merge sorted arrays → [1,1,2,3,3]
Output: 2
*/


/* 🏆 MAIN FUNCTION TO TEST ALL FUNCTIONS */
int main() {
    vector<int> xorArr = {4, 2, 2, 6, 4};
    cout << "Count of subarrays with XOR K: " << countSubarraysWithXorK(xorArr, 6) << endl;

    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> mergedIntervals = mergeIntervals(intervals);
    cout << "Merged Intervals: ";
    for (auto v : mergedIntervals) cout << "[" << v[0] << "," << v[1] << "] ";
    cout << endl;

    vector<int> arr1 = {1,4,7}, arr2 = {2,5,6};
    mergeSortedArrays(arr1, arr2);
    cout << "Merged Arrays: ";
    for (int num : arr1) cout << num << " ";
    for (int num : arr2) cout << num << " ";
    cout << endl;

    vector<int> rmArr = {4,3,6,2,1,1};
    auto [repeating, missing] = findRepeatingAndMissing(rmArr);
    cout << "Repeating: " << repeating << ", Missing: " << missing << endl;

    return 0;
}
