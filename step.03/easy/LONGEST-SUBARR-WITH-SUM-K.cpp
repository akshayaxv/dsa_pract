#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Brute Force Approach:
    // Time Complexity: O(N^2) -> We check all possible subarrays.
    // Space Complexity: O(1) -> No extra space used.
    // Explanation:
    // - We iterate through all pairs of start and end indices to find subarrays.
    // - For each subarray, we calculate its sum and check if it equals k.
    // Dry Run:
    // A = [1, -1, 5, -2, 3], k = 3
    // Step 1: Subarray [1], Sum = 1
    // Step 2: Subarray [1, -1], Sum = 0
    // Step 3: Subarray [1, -1, 5], Sum = 5
    // Step 4: Subarray [1, -1, 5, -2], Sum = 3 (valid subarray, length = 4)
    // Output: 4
    int longestSubarrayBruteForce(vector<int>& arr, int n, int k) {
        int maxLength = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += arr[j];
                if (sum == k) {
                    maxLength = max(maxLength, j - i + 1);
                }
            }
        }
        return maxLength;
    }

    // Optimized Approach (Using Hashmap):
    // Time Complexity: O(N) -> Single traversal of the array.
    // Space Complexity: O(N) -> Space for the hashmap.
    // Explanation:
    // - We keep a running sum while iterating through the array.
    // - We use a hashmap to store the first occurrence of each cumulative sum.
    // - If the sum at any point is `current_sum - k`, it means we found a valid subarray.
    // Dry Run:
    // A = [1, -1, 5, -2, 3], k = 3
    // Step 1: Cumulative sum = 1, first occurrence: 1 at index 0
    // Step 2: Cumulative sum = 0, first occurrence: 0 at index 1
    // Step 3: Cumulative sum = 5, first occurrence: 5 at index 2
    // Step 4: Cumulative sum = 3, valid subarray found from index 0 to 3 (length = 4)
    // Output: 4
    int longestSubarrayOptimized(vector<int>& arr, int n, int k) {
        unordered_map<int, int> sumMap;
        int maxLength = 0;
        int current_sum = 0;
        
        for (int i = 0; i < n; i++) {
            current_sum += arr[i];
            
            if (current_sum == k) {
                maxLength = i + 1;
            }
            
            if (sumMap.find(current_sum - k) != sumMap.end()) {
                maxLength = max(maxLength, i - sumMap[current_sum - k]);
            }
            
            if (sumMap.find(current_sum) == sumMap.end()) {
                sumMap[current_sum] = i;
            }
        }
        
        return maxLength;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, -1, 5, -2, 3};
    int k = 3;
    int n = arr.size();
    
    // Brute Force Approach
    cout << "Brute Force Approach: Longest subarray length is: " << sol.longestSubarrayBruteForce(arr, n, k) << endl;
    
    // Optimized Approach
    cout << "Optimized Approach: Longest subarray length is: " << sol.longestSubarrayOptimized(arr, n, k) << endl;
    
    return 0;
}
