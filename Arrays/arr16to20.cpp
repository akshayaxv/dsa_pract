#include <iostream>
#include <vector>
#include <algorithm> // For max function
using namespace std;

/* 📝 1️⃣ SORT AN ARRAY OF 0'S, 1'S, AND 2'S (Dutch National Flag Algorithm)
   - Use three pointers: low (0s), mid (1s), high (2s).
   - Time Complexity: O(N)
   - Space Complexity: O(1)
*/
void sortColors(vector<int>& arr) {
    int low = 0, mid = 0, high = arr.size() - 1;
    while (mid <= high) {
        if (arr[mid] == 0) swap(arr[low++], arr[mid++]);
        else if (arr[mid] == 1) mid++;
        else swap(arr[mid], arr[high--]);
    }
}

/*
📌 DRY RUN (Input: [2,0,2,1,1,0])
Step 1: Place 0s at start, 2s at end.
Output: [0,0,1,1,2,2]
*/

/* 📝 2️⃣ MAJORITY ELEMENT (>N/2 TIMES) (Moore's Voting Algorithm)
   - Maintain a candidate and count.
   - Time Complexity: O(N)
   - Space Complexity: O(1)
*/
int majorityElement(vector<int>& arr) {
    int candidate = 0, count = 0;
    for (int num : arr) {
        if (count == 0) candidate = num;
        count += (num == candidate) ? 1 : -1;
    }
    return candidate; // Majority element guaranteed by problem statement
}

/*
📌 DRY RUN (Input: [2,2,1,1,1,2,2])
Step 1: Candidate = 2, Count = 1 → 2, 2, 1, 1, 1, 2, 2
Output: 2
*/

/* 📝 3️⃣ KADANE'S ALGORITHM (MAXIMUM SUBARRAY SUM)
   - Maintain current sum and maximum sum.
   - Time Complexity: O(N)
   - Space Complexity: O(1)
*/
int maxSubarraySum(vector<int>& arr) {
    int maxSum = arr[0], currSum = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        currSum = max(arr[i], currSum + arr[i]); // Extend or restart subarray
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

/*
📌 DRY RUN (Input: [-2,1,-3,4,-1,2,1,-5,4])
Step 1: Calculate running sum.
Output: 6 (subarray: [4,-1,2,1])
*/

/* 📝 4️⃣ PRINT SUBARRAY WITH MAXIMUM SUM (Extended Kadane’s Algorithm)
   - Track start and end indices.
   - Time Complexity: O(N)
   - Space Complexity: O(1)
*/
vector<int> maxSubarray(vector<int>& arr) {
    int maxSum = arr[0], currSum = arr[0], start = 0, end = 0, tempStart = 0;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > currSum + arr[i]) {
            currSum = arr[i];
            tempStart = i;
        } else {
            currSum += arr[i];
        }
        if (currSum > maxSum) {
            maxSum = currSum;
            start = tempStart;
            end = i;
        }
    }
    return vector<int>(arr.begin() + start, arr.begin() + end + 1);
}

/*
📌 DRY RUN (Input: [-2,1,-3,4,-1,2,1,-5,4])
Step 1: Identify subarray contributing to max sum.
Output: [4,-1,2,1]
*/

/* 📝 5️⃣ STOCK BUY AND SELL (MAX PROFIT)
   - Track minimum price and maximum profit.
   - Time Complexity: O(N)
   - Space Complexity: O(1)
*/
int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX, maxProfit = 0;
    for (int price : prices) {
        minPrice = min(minPrice, price); // Track min price so far
        maxProfit = max(maxProfit, price - minPrice); // Track max profit
    }
    return maxProfit;
}

/*
📌 DRY RUN (Input: [7,1,5,3,6,4])
Step 1: Buy at min price (1), sell at max profit point.
Output: 5 (Buy at 1, Sell at 6)
*/

/* 🏆 MAIN FUNCTION */
int main() {
    vector<int> colors = {2, 0, 2, 1, 1, 0};
    sortColors(colors);
    cout << "Sorted Colors: ";
    for (int num : colors) cout << num << " ";
    cout << endl;

    vector<int> majorityArr = {2, 2, 1, 1, 1, 2, 2};
    cout << "Majority Element: " << majorityElement(majorityArr) << endl;

    vector<int> kadaneArr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Max Subarray Sum: " << maxSubarraySum(kadaneArr) << endl;

    vector<int> maxSubArr = maxSubarray(kadaneArr);
    cout << "Max Subarray: ";
    for (int num : maxSubArr) cout << num << " ";
    cout << endl;

    vector<int> stockPrices = {7, 1, 5, 3, 6, 4};
    cout << "Max Profit: " << maxProfit(stockPrices) << endl;

    return 0;
}

/*
⏳ TIME COMPLEXITY SUMMARY:
------------------------------------------------
| Problem                                   | Time Complexity | Space Complexity |
|-------------------------------------------|----------------|------------------|
| Sort an Array of 0's, 1's, and 2's        | O(N)           | O(1)             |
| Majority Element (>N/2 times)             | O(N)           | O(1)             |
| Kadane's Algorithm (Max Subarray Sum)     | O(N)           | O(1)             |
| Print Subarray with Max Sum               | O(N)           | O(1)             |
| Stock Buy and Sell (Max Profit)           | O(N)           | O(1)             |
------------------------------------------------
🚀 **All solutions are optimized using vectors!**
*/
