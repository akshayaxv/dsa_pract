#include <bits/stdc++.h>
using namespace std;

// Problem: https://www.codingninjas.com/studio/problems/subarrays-with-xor-k_6826258?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

// BRUTE FORCE APPROACH: Check all possible subarrays, calculate XOR for each, and compare it with K.
// Time Complexity: O(n^2) - Two nested loops for generating subarrays and calculating XOR
// Space Complexity: O(1) - No extra space used
int subarraysWithSumK_bruteForce(vector<int>& a, int b) {
    int ans = 0;
    int n = a.size();

    // Brute Force approach: Iterate over all subarrays
    for (int i = 0; i < n; i++) {
        int XOR = 0;  // Reset XOR for each subarray
        for (int j = i; j < n; j++) {
            XOR = XOR ^ a[j];  // Calculate XOR for the subarray
            if (XOR == b) {  // If XOR equals K, increment the answer
                ans++;
            }
        }
    }

    return ans;
}

/*
Dry Run for Brute Force Approach:
Input: a = [4, 2, 2, 6], b = 6

- For i = 0:
  - Subarray [4] XOR = 4 (not equal to 6)
  - Subarray [4, 2] XOR = 6 (increment ans)
  - Subarray [4, 2, 2] XOR = 4 (not equal to 6)
  - Subarray [4, 2, 2, 6] XOR = 6 (increment ans)

- For i = 1:
  - Subarray [2] XOR = 2 (not equal to 6)
  - Subarray [2, 2] XOR = 0 (not equal to 6)
  - Subarray [2, 2, 6] XOR = 6 (increment ans)

Final Answer = 3 (subarrays with XOR equal to 6)
*/

// OPTIMIZED APPROACH: Use prefix XOR and hashing to reduce time complexity.
// Time Complexity: O(n) - Single pass through the array and hash map operations
// Space Complexity: O(n) - Space for the hash map to store the prefix XORs
int subarraysWithSumK(vector<int>& a, int b) {
    int XOR = 0;
    int ans = 0;
    unordered_map<int, int> mp;  // Hash map to store prefix XOR and its frequency
    mp[0]++;  // To handle the case where XOR of subarray from index 0 equals K

    for (int i = 0; i < a.size(); i++) {
        XOR = XOR ^ a[i];  // Update XOR for the current index

        // Check if XOR ^ b exists in the hash map
        int x = XOR ^ b;

        // If it exists, it means there is a subarray ending at i with XOR equal to K
        ans += mp[x];

        // Store the current XOR in the map
        mp[XOR]++;
    }

    return ans;
}

/*
Dry Run for Optimized Approach:
Input: a = [4, 2, 2, 6], b = 6

- Initialize XOR = 0, ans = 0, mp = {0: 1}
- Iterating over the array:
  - i = 0, XOR = 4, x = XOR ^ 6 = 2 (mp[2] = 0), mp = {0: 1, 4: 1}
  - i = 1, XOR = 6, x = XOR ^ 6 = 0 (mp[0] = 1), ans = 1, mp = {0: 1, 4: 1, 6: 1}
  - i = 2, XOR = 4, x = XOR ^ 6 = 2 (mp[2] = 0), mp = {0: 1, 4: 2, 6: 1}
  - i = 3, XOR = 2, x = XOR ^ 6 = 4 (mp[4] = 1), ans = 2, mp = {0: 1, 4: 2, 6: 1, 2: 1}

Final Answer = 3 (subarrays with XOR equal to 6)
*/

int main() {
    vector<int> a = {4, 2, 2, 6};
    int b = 6;

    // Brute Force Solution
    int result = subarraysWithSumK_bruteForce(a, b);
    cout << "Brute Force Result: " << result << endl;  // Expected output: 3

    // Optimized Solution
    result = subarraysWithSumK(a, b);
    cout << "Optimized Result: " << result << endl;  // Expected output: 3

    return 0;
}
