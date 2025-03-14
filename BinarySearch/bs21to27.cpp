#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // For accumulate()
using namespace std;

/* 📝 1️⃣ AGGRESSIVE COWS (Binary Search on Answer)
   - Place cows in stalls to maximize minimum distance.
   - Time Complexity: O(N log M) (N = stalls, M = max distance)
   - Space Complexity: O(1)
*/
bool canPlaceCows(vector<int>& stalls, int cows, int minDist) {
    int count = 1, lastPlaced = stalls[0];

    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPlaced >= minDist) {
            count++;
            lastPlaced = stalls[i];
        }
        if (count == cows) return true;
    }

    return false;
}

int aggressiveCows(vector<int>& stalls, int cows) {
    sort(stalls.begin(), stalls.end()); // Sort stalls
    int left = 1, right = stalls.back() - stalls.front();

    while (left < right) {
        int mid = left + (right - left + 1) / 2;
        if (canPlaceCows(stalls, cows, mid)) left = mid;
        else right = mid - 1;
    }

    return left;
}

/*
📌 DRY RUN (Input: stalls=[1,2,4,8,9], cows=3)
Step 1: Binary search on minDist.
Step 2: Check if we can place cows with distance mid.
Output: 3
*/

/* 📝 2️⃣ BOOK ALLOCATION PROBLEM
   - Allocate books to students such that max pages assigned is minimized.
   - Time Complexity: O(N log M)
   - Space Complexity: O(1)
*/
bool canAllocateBooks(vector<int>& books, int students, int maxPages) {
    int count = 1, pagesSum = 0;

    for (int book : books) {
        if (book > maxPages) return false; // If a book is larger than maxPages
        if (pagesSum + book > maxPages) {
            count++;
            pagesSum = book;
        } else {
            pagesSum += book;
        }
    }

    return count <= students;
}

int bookAllocation(vector<int>& books, int students) {
    int left = *max_element(books.begin(), books.end());
    int right = accumulate(books.begin(), books.end(), 0);

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canAllocateBooks(books, students, mid)) right = mid;
        else left = mid + 1;
    }

    return left;
}

/*
📌 DRY RUN (Input: books=[12,34,67,90], students=2)
Step 1: Binary search on maxPages.
Step 2: Allocate books and check feasibility.
Output: 113
*/

/* 📝 3️⃣ SPLIT ARRAY - LARGEST SUM
   - Split array into M subarrays minimizing max sum.
   - Time Complexity: O(N log M)
   - Space Complexity: O(1)
*/
int splitArrayLargestSum(vector<int>& nums, int m) {
    int left = *max_element(nums.begin(), nums.end());
    int right = accumulate(nums.begin(), nums.end(), 0);

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canAllocateBooks(nums, m, mid)) right = mid;
        else left = mid + 1;
    }

    return left;
}

/*
📌 DRY RUN (Input: nums=[7,2,5,10,8], m=2)
Output: 18
*/

/* 📝 4️⃣ PAINTER'S PARTITION PROBLEM
   - Minimize max time for painters to paint sections.
   - Time Complexity: O(N log M)
   - Space Complexity: O(1)
*/
int paintersPartition(vector<int>& boards, int painters) {
    return bookAllocation(boards, painters); // Same as book allocation problem
}

/*
📌 DRY RUN (Input: boards=[10,20,30,40], painters=2)
Output: 60
*/

/* 📝 5️⃣ MINIMIZE MAX DISTANCE TO GAS STATION
   - Find min max distance after adding K gas stations.
   - Time Complexity: O(N log M)
   - Space Complexity: O(1)
*/
bool canPlaceGasStations(vector<int>& stations, int k, double maxDist) {
    int count = 0;

    for (int i = 1; i < stations.size(); i++) {
        count += (int)((stations[i] - stations[i - 1]) / maxDist);
    }

    return count <= k;
}

double minimizeMaxDistGasStations(vector<int>& stations, int k) {
    double left = 0, right = stations.back() - stations.front(), eps = 1e-6;

    while (right - left > eps) {
        double mid = left + (right - left) / 2;
        if (canPlaceGasStations(stations, k, mid)) right = mid;
        else left = mid;
    }

    return left;
}

/*
📌 DRY RUN (Input: stations=[1,2,3,4,5,6,7,8,9,10], k=9)
Output: 0.5
*/

/* 📝 6️⃣ MEDIAN OF TWO SORTED ARRAYS
   - Find median of two sorted arrays.
   - Time Complexity: O(log(min(N,M)))
   - Space Complexity: O(1)
*/
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) swap(nums1, nums2);
    
    int x = nums1.size(), y = nums2.size();
    int low = 0, high = x;

    while (low <= high) {
        int partitionX = (low + high) / 2;
        int partitionY = (x + y + 1) / 2 - partitionX;

        int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minX = (partitionX == x) ? INT_MAX : nums1[partitionX];

        int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minY = (partitionY == y) ? INT_MAX : nums2[partitionY];

        if (maxX <= minY && maxY <= minX) {
            if ((x + y) % 2 == 0) return (max(maxX, maxY) + min(minX, minY)) / 2.0;
            else return max(maxX, maxY);
        } else if (maxX > minY) high = partitionX - 1;
        else low = partitionX + 1;
    }

    return 0.0;
}

/*
📌 DRY RUN (Input: nums1=[1,3], nums2=[2])
Output: 2.0
*/

/* 📝 7️⃣ Kth ELEMENT OF TWO SORTED ARRAYS
   - Find Kth smallest element in two sorted arrays.
   - Time Complexity: O(log(min(N,M)))
   - Space Complexity: O(1)
*/
int kthElementSortedArrays(vector<int>& nums1, vector<int>& nums2, int k) {
    if (nums1.size() > nums2.size()) swap(nums1, nums2);
    
    int left = max(0, k - (int)nums2.size()), right = min((int)nums1.size(), k);

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums1[mid] < nums2[k - mid - 1]) left = mid + 1;
        else right = mid;
    }

    return max(left > 0 ? nums1[left - 1] : INT_MIN, k - left > 0 ? nums2[k - left - 1] : INT_MIN);
}

/*
📌 DRY RUN (Input: nums1=[2,3,4,10], nums2=[1,5,8,9], k=5)
Output: 5
*/
