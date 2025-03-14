#include <iostream>
#include <vector>
#include <cmath> // For pow() function
using namespace std;

/* 📝 1️⃣ FIND SQUARE ROOT (Binary Search)
   - Find the integer part of the square root.
   - Time Complexity: O(log N)
   - Space Complexity: O(1)
*/
int findSquareRoot(int n) {
    int left = 0, right = n, ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if ((long long)mid * mid <= n) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return ans;
}

/*
📌 DRY RUN (Input: 25)
Step 1: mid=12, mid^2=144 (too high, move left)
Step 2: mid=6, mid^2=36 (too high, move left)
Step 3: mid=4, mid^2=16 (too low, move right)
Step 4: mid=5, mid^2=25 ✅ Found
Output: 5
*/

/* 📝 2️⃣ FIND Nth ROOT OF A NUMBER (Binary Search)
   - Find the Nth root of a given number using binary search.
   - Time Complexity: O(log M)
   - Space Complexity: O(1)
*/
int findNthRoot(int n, int m) {
    double left = 1, right = m, eps = 1e-6;

    while ((right - left) > eps) {
        double mid = left + (right - left) / 2;
        if (pow(mid, n) < m)
            left = mid;
        else
            right = mid;
    }

     int root = round(left); // ✅ Round to nearest integer
    // ✅ Check if the result is an exact integer root
    if (pow(root, n) == m) return root;
    return -1; // ❌ If not an integer root, return -1
}

/*
📌 DRY RUN (Input: N=3, M=27)
Step 1: Check mid values using pow(mid, 3)
Step 2: Narrow down the range to find 3rd root of 27.
Output: 3
*/

/* 📝 3️⃣ KOKO EATING BANANAS (Binary Search on Answer)
   - Find the minimum eating speed for Koko to finish bananas in H hours.
   - Time Complexity: O(N log M)
   - Space Complexity: O(1)
*/
bool canEatAll(vector<int>& piles, int k, int h) {
    long hoursNeeded = 0;
    for (int pile : piles) {
        hoursNeeded += (pile + k - 1) / k; // ceil(pile/k)
    }
    return hoursNeeded <= h;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int left = 1, right = *max_element(piles.begin(), piles.end());

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canEatAll(piles, mid, h)) right = mid;
        else left = mid + 1;
    }

    return left;
}

/*
📌 DRY RUN (Input: [3,6,7,11], H=8)
Step 1: Binary search on K (eating speed)
Step 2: Check if Koko can finish in H hours.
Output: 4
*/

/* 📝 4️⃣ MINIMUM DAYS TO MAKE M BOUQUETS (Binary Search)
   - Find the minimum number of days needed to make M bouquets.
   - Time Complexity: O(N log M)
   - Space Complexity: O(1)
*/
bool canMakeBouquets(vector<int>& bloomDay, int m, int k, int days) {
    int count = 0, bouquets = 0;
    for (int bloom : bloomDay) {
        if (bloom <= days) {
            count++;
            if (count == k) {
                bouquets++;
                count = 0;
            }
        } else count = 0;
    }
    return bouquets >= m;
}

int minDaysToMakeMBouquets(vector<int>& bloomDay, int m, int k) {
    if ((long long)m * k > bloomDay.size()) return -1;
    int left = *min_element(bloomDay.begin(), bloomDay.end());
    int right = *max_element(bloomDay.begin(), bloomDay.end());

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canMakeBouquets(bloomDay, m, k, mid)) right = mid;
        else left = mid + 1;
    }

    return left;
}

/*
📌 DRY RUN (Input: [1,10,3,10,2], m=3, k=1)
Step 1: Binary search on days to find min days.
Step 2: Check if we can make M bouquets.
Output: 3
*/

/* 📝 5️⃣ FIND THE SMALLEST DIVISOR
   - Find the smallest divisor such that sum(arr[i] / divisor) <= threshold.
   - Time Complexity: O(N log M)
   - Space Complexity: O(1)
*/
bool isValidDivisor(vector<int>& nums, int divisor, int threshold) {
    int sum = 0;
    for (int num : nums) {
        sum += (num + divisor - 1) / divisor; // Equivalent to ceil(num/divisor)
    }
    return sum <= threshold;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int left = 1, right = *max_element(nums.begin(), nums.end());

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (isValidDivisor(nums, mid, threshold)) right = mid;
        else left = mid + 1;
    }

    return left;
}

/*
📌 DRY RUN (Input: [1,2,5,9], threshold=6)
Step 1: Binary search on divisor values.
Step 2: Find the smallest divisor such that sum(arr[i]/div) ≤ threshold.
Output: 5
*/

/* 📝 6️⃣ CAPACITY TO SHIP PACKAGES WITHIN D DAYS
   - Find the minimum capacity required to ship packages within D days.
   - Time Complexity: O(N log M)
   - Space Complexity: O(1)
*/
bool canShipInDays(vector<int>& weights, int capacity, int days) {
    int currWeight = 0, requiredDays = 1;
    for (int weight : weights) {
        if (currWeight + weight > capacity) {
            requiredDays++;
            currWeight = 0;
        }
        currWeight += weight;
    }
    return requiredDays <= days;
}

int shipWithinDays(vector<int>& weights, int days) {
    int left = *max_element(weights.begin(), weights.end());
    int right = accumulate(weights.begin(), weights.end(), 0);

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canShipInDays(weights, mid, days)) right = mid;
        else left = mid + 1;
    }

    return left;
}

/*
📌 DRY RUN (Input: [1,2,3,4,5,6,7,8,9,10], D=5)
Step 1: Binary search to find min capacity required.
Output: 15
*/

/* 📝 7️⃣ KTH MISSING POSITIVE NUMBER
   - Find the Kth missing positive number.
   - Time Complexity: O(log N)
   - Space Complexity: O(1)
*/
int findKthMissingPositive(vector<int>& arr, int k) {
    int left = 0, right = arr.size();
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] - (mid + 1) < k) left = mid + 1;
        else right = mid;
    }

    return left + k;
}

/*
📌 DRY RUN (Input: [2,3,4,7,11], k=5)
Step 1: Binary search to find kth missing number.
Output: 9
*/

int main() {
    cout << "Square Root of 25: " << findSquareRoot(25) << endl;
    cout << "3rd Root of 27: " << findNthRoot(3, 27) << endl;
    cout << "Kth Missing Number: " << findKthMissingPositive({2,3,4,7,11}, 5) << endl;
}
