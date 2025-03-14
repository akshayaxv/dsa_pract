#include <iostream>
#include <vector>
#include <unordered_map> // For Hash Maps
#include <algorithm> // For Sorting
using namespace std;

/* 📝 1️⃣ PRINT MATRIX IN SPIRAL ORDER
   - Traverse matrix in a spiral fashion.
   - Time Complexity: O(N*M)
   - Space Complexity: O(1) (No extra space)
*/
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    int top = 0, bottom = matrix.size() - 1;
    int left = 0, right = matrix[0].size() - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) result.push_back(matrix[top][i]); // Left to Right
        top++;
        for (int i = top; i <= bottom; i++) result.push_back(matrix[i][right]); // Top to Bottom
        right--;
        if (top <= bottom) for (int i = right; i >= left; i--) result.push_back(matrix[bottom][i]); // Right to Left
        bottom--;
        if (left <= right) for (int i = bottom; i >= top; i--) result.push_back(matrix[i][left]); // Bottom to Top
        left++;
    }
    return result;
}

/*
📌 DRY RUN (Input: [[1,2,3],[4,5,6],[7,8,9]])
Output: [1,2,3,6,9,8,7,4,5]
*/

/* 📝 2️⃣ COUNT SUBARRAYS WITH GIVEN SUM (Using Hash Map)
   - Store prefix sums and count occurrences.
   - Time Complexity: O(N)
   - Space Complexity: O(N)
*/
int countSubarraysWithSumK(vector<int>& arr, int k) {
    unordered_map<int, int> prefixSum;
    int sum = 0, count = 0;
    prefixSum[0] = 1;

    for (int num : arr) {
        sum += num;
        if (prefixSum.find(sum - k) != prefixSum.end()) count += prefixSum[sum - k];
        prefixSum[sum]++;
    }
    return count;
}

/*
📌 DRY RUN (Input: [1,1,1], k=2)
Output: 2 ([1,1] & [1,1])
*/

/* 📝 3️⃣ PASCAL'S TRIANGLE (Dynamic Programming)
   - Compute each row based on previous row.
   - Time Complexity: O(N²)
   - Space Complexity: O(1)
*/
vector<vector<int>> pascalTriangle(int numRows) {
    vector<vector<int>> triangle(numRows);
    for (int i = 0; i < numRows; i++) {
        triangle[i].resize(i + 1, 1);
        for (int j = 1; j < i; j++) triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
    }
    return triangle;
}

/*
📌 DRY RUN (Input: 5)
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
*/

/* 📝 4️⃣ MAJORITY ELEMENT (>N/3 TIMES) (Boyer-Moore Algorithm)
   - Maintain two potential candidates.
   - Time Complexity: O(N)
   - Space Complexity: O(1)
*/
vector<int> majorityElementN3(vector<int>& arr) {
    int num1 = -1, num2 = -1, count1 = 0, count2 = 0;
    for (int num : arr) {
        if (num == num1) count1++;
        else if (num == num2) count2++;
        else if (count1 == 0) num1 = num, count1 = 1;
        else if (count2 == 0) num2 = num, count2 = 1;
        else count1--, count2--;
    }

    count1 = count2 = 0;
    for (int num : arr) {
        if (num == num1) count1++;
        else if (num == num2) count2++;
    }

    vector<int> result;
    int n = arr.size();
    if (count1 > n / 3) result.push_back(num1);
    if (count2 > n / 3) result.push_back(num2);
    return result;
}

/*
📌 DRY RUN (Input: [3,2,3])
Output: [3]
*/

/* 📝 5️⃣ 3-SUM PROBLEM (Two Pointers)
   - Fix one element, use two-pointer approach for remaining sum.
   - Time Complexity: O(N²)
   - Space Complexity: O(1)
*/
vector<vector<int>> threeSum(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    vector<vector<int>> result;
    for (int i = 0; i < arr.size() - 2; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) continue;
        int left = i + 1, right = arr.size() - 1;
        while (left < right) {
            int sum = arr[i] + arr[left] + arr[right];
            if (sum == 0) {
                result.push_back({arr[i], arr[left], arr[right]});
                while (left < right && arr[left] == arr[left + 1]) left++;
                while (left < right && arr[right] == arr[right - 1]) right--;
                left++; right--;
            } else if (sum < 0) left++;
            else right--;
        }
    }
    return result;
}

/*
📌 DRY RUN (Input: [-1,0,1,2,-1,-4])
Output: [[-1,-1,2],[-1,0,1]]
*/

/* 📝 6️⃣ 4-SUM PROBLEM (Two Pointers with Sorting)
   - Fix two elements, use two-pointer approach for remaining sum.
   - Time Complexity: O(N³)
   - Space Complexity: O(1)
*/
vector<vector<int>> fourSum(vector<int>& arr, int target) {
    sort(arr.begin(), arr.end());
    vector<vector<int>> result;
    int n = arr.size();
    for (int i = 0; i < n - 3; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) continue;
        for (int j = i + 1; j < n - 2; j++) {
            if (j > i + 1 && arr[j] == arr[j - 1]) continue;
            int left = j + 1, right = n - 1;
            while (left < right) {
                long sum = (long) arr[i] + arr[j] + arr[left] + arr[right];
                if (sum == target) {
                    result.push_back({arr[i], arr[j], arr[left], arr[right]});
                    while (left < right && arr[left] == arr[left + 1]) left++;
                    while (left < right && arr[right] == arr[right - 1]) right--;
                    left++; right--;
                } else if (sum < target) left++;
                else right--;
            }
        }
    }
    return result;
}

/*
📌 DRY RUN (Input: [1,0,-1,0,-2,2], target=0)
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
*/

/* 📝 7️⃣ LARGEST SUBARRAY WITH SUM ZERO (Hash Map)
   - Store prefix sum and check occurrences.
   - Time Complexity: O(N)
   - Space Complexity: O(N)
*/
int largestSubarrayWithZeroSum(vector<int>& arr) {
    unordered_map<int, int> prefixSum;
    int sum = 0, maxLen = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if (sum == 0) maxLen = i + 1;
        if (prefixSum.find(sum) != prefixSum.end()) maxLen = max(maxLen, i - prefixSum[sum]);
        else prefixSum[sum] = i;
    }
    return maxLen;
}

