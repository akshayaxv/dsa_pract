#include <iostream>
#include <vector>
#include <unordered_map> // For Hash Maps
#include <unordered_set> // For 2Sum Problem
using namespace std;

/* 📝 1️⃣ MAXIMUM CONSECUTIVE ONES
   - Traverse array, track max count of consecutive 1s.
   - Time Complexity: O(N)
   - Space Complexity: O(1)
*/
int maxConsecutiveOnes(vector<int>& arr) {
    int maxCount = 0, count = 0;
    for (int num : arr) {
        if (num == 1) count++; // Increment for 1
        else count = 0; // Reset if 0
        maxCount = max(maxCount, count); // Track max sequence
    }
    return maxCount;
}

/*
📌 DRY RUN (Input: [1,1,0,1,1,1])
Step 1: count=2, reset at 0, count=3
Output: 3
*/

/* 📝 2️⃣ FIND NUMBER THAT APPEARS ONCE (Using XOR)
   - XOR cancels out duplicates: `a ⊕ a = 0`
   - Time Complexity: O(N)
   - Space Complexity: O(1)
*/
int findSingleNumber(vector<int>& arr) {
    int result = 0;
    for (int num : arr) result ^= num; // XOR all numbers
    return result;
}

/*
📌 DRY RUN (Input: [4, 1, 2, 1, 2])
Step 1: 4⊕1⊕2⊕1⊕2 = (4⊕1⊕1)⊕(2⊕2) = 4⊕0⊕0 = 4
Output: 4
*/

/* 📝 3️⃣ LONGEST SUBARRAY WITH GIVEN SUM K (ONLY POSITIVES)
   - Use Sliding Window (Two Pointer Technique)
   - Time Complexity: O(N)
   - Space Complexity: O(1)
*/
int longestSubarrayWithSumK(vector<int>& arr, int k) {
    int left = 0, right = 0, sum = 0, maxLen = 0;
    while (right < arr.size()) {
        sum += arr[right]; // Expand window
        while (sum > k) sum -= arr[left++]; // Shrink window
        if (sum == k) maxLen = max(maxLen, right - left + 1);
        right++;
    }
    return maxLen;
}

/*
📌 DRY RUN (Input: [1,2,3,7,5], K=12)
Step 1: Expand → [1,2,3,7] (Sum=13), Shrink → [2,3,7] (Sum=12)
Output: 3 (subarray: [2,3,7])
*/

/* 📝 4️⃣ LONGEST SUBARRAY WITH SUM K (POSITIVES + NEGATIVES)
   - Use Hash Map to store sum at each index
   - Time Complexity: O(N)
   - Space Complexity: O(N)
*/
int longestSubarrayWithSumKNegatives(vector<int>& arr, int k) {
    unordered_map<int, int> prefixSum;
    int sum = 0, maxLen = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i]; // Compute prefix sum
        if (sum == k) maxLen = i + 1;
        if (prefixSum.find(sum - k) != prefixSum.end()) 
            maxLen = max(maxLen, i - prefixSum[sum - k]); // Check for previous sum
        if (prefixSum.find(sum) == prefixSum.end()) prefixSum[sum] = i;
    }
    return maxLen;
}

/*
📌 DRY RUN (Input: [10,15,-5,15,-10,5], K=5)
Step 1: Compute Prefix Sum, store in map.
Step 2: Check if sum-k exists in map.
Output: 5
*/

/* 📝 5️⃣ 2SUM PROBLEM (Using Hash Map)
   - Store elements in a set and check for complement.
   - Time Complexity: O(N)
   - Space Complexity: O(N)
*/
vector<int> twoSum(vector<int>& arr, int target) {
    unordered_map<int, int> numIndex;
    for (int i = 0; i < arr.size(); i++) {
        int complement = target - arr[i];
        if (numIndex.find(complement) != numIndex.end()) 
            return {numIndex[complement], i}; // Found Pair
        numIndex[arr[i]] = i;
    }
    return {}; // No Pair Found
}

/*
📌 DRY RUN (Input: [2, 7, 11, 15], Target=9)
Step 1: 9-2=7 → Found at index 1
Output: [0,1]
*/

/* 🏆 MAIN FUNCTION */
int main() {
    vector<int> onesArr = {1, 1, 0, 1, 1, 1};
    cout << "Max Consecutive Ones: " << maxConsecutiveOnes(onesArr) << endl;

    vector<int> uniqueArr = {4, 1, 2, 1, 2};
    cout << "Single Occurring Number: " << findSingleNumber(uniqueArr) << endl;

    vector<int> sumArr = {1, 2, 3, 7, 5};
    int k = 12;
    cout << "Longest Subarray with Sum K (Positives): " << longestSubarrayWithSumK(sumArr, k) << endl;

    vector<int> mixedArr = {10, 15, -5, 15, -10, 5};
    int kNeg = 5;
    cout << "Longest Subarray with Sum K (Positives + Negatives): " << longestSubarrayWithSumKNegatives(mixedArr, kNeg) << endl;

    vector<int> twoSumArr = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(twoSumArr, target);
    cout << "2Sum Indices: " << result[0] << " " << result[1] << endl;

    return 0;
}

/*
⏳ TIME COMPLEXITY SUMMARY:
------------------------------------------------
| Problem                                     | Time Complexity | Space Complexity |
|---------------------------------------------|----------------|------------------|
| Maximum Consecutive Ones                     | O(N)           | O(1)             |
| Find Single Occurring Number (XOR)           | O(N)           | O(1)             |
| Longest Subarray with Sum K (Positives)      | O(N)           | O(1)             |
| Longest Subarray with Sum K (Pos+Negatives)  | O(N)           | O(N)             |
| 2Sum Problem (Using Hash Map)                | O(N)           | O(N)             |
------------------------------------------------
🚀 **All solutions are optimized using vectors!**
*/
