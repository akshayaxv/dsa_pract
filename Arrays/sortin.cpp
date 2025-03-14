#include <iostream>
#include <vector>
using namespace std;

/* 📝 1️⃣ SELECTION SORT
   - Find the smallest element and swap it with the first element.
   - Repeat for the remaining subarray.
   - Time Complexity: O(N²)
   - Space Complexity: O(1) (In-place sorting)
*/
void selectionSort(vector<int>& arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // Assume the first element is the smallest
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) minIndex = j; // Find the smallest element
        }
        swap(arr[i], arr[minIndex]); // Swap with the first element
    }
}

/* 📝 2️⃣ BUBBLE SORT (Iterative)
   - Repeatedly swap adjacent elements if they are in the wrong order.
   - Largest elements "bubble up" to the end.
   - Time Complexity: O(N²)
   - Space Complexity: O(1)
*/
void bubbleSort(vector<int>& arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false; // Track if swapping occurs
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // If no swaps, array is already sorted
    }
}

/* 📝 3️⃣ RECURSIVE BUBBLE SORT
   - Perform one pass and recursively call for the remaining elements.
   - Time Complexity: O(N²)
*/
void recursiveBubbleSort(vector<int>& arr, int n) {
    if (n == 1) return; // Base case
    for (int i = 0; i < n - 1; i++) { 
        if (arr[i] > arr[i + 1]) swap(arr[i], arr[i + 1]);
    }
    recursiveBubbleSort(arr, n - 1); // Recursively call for the smaller subarray
}

/* 📝 4️⃣ INSERTION SORT (Iterative)
   - Build the sorted array one item at a time.
   - Place each element in its correct position.
   - Time Complexity: O(N²) Worst, O(N) Best (Already sorted)
   - Space Complexity: O(1)
*/
void insertionSort(vector<int>& arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; // Shift elements to the right
            j--;
        }
        arr[j + 1] = key; // Insert the element in the correct position
    }
}

/* 📝 5️⃣ RECURSIVE INSERTION SORT
   - Recursively insert elements one by one in the sorted part.
   - Time Complexity: O(N²)
*/
void recursiveInsertionSort(vector<int>& arr, int n) {
    if (n <= 1) return; // Base case
    recursiveInsertionSort(arr, n - 1); // Sort first n-1 elements
    int key = arr[n - 1], j = n - 2;
    while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j]; // Shift elements
        j--;
    }
    arr[j + 1] = key; // Insert the last element in the correct position
}

/* 📝 6️⃣ MERGE SORT
   - Divide array into halves, sort each, and merge.
   - Time Complexity: O(N log N)
   - Space Complexity: O(N) (Extra space for merging)
*/
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return; // Base case
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

/* 📝 7️⃣ QUICK SORT
   - Pick a pivot, partition the array, and recursively sort both halves.
   - Time Complexity: O(N log N) (Best & Average), O(N²) (Worst)
   - Space Complexity: O(log N) (Recursive calls)
*/
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) swap(arr[++i], arr[j]);
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* 🏆 MAIN FUNCTION */
int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    int n = arr.size();

    cout << "Original Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    // Call sorting function (Uncomment one at a time to test)
    // selectionSort(arr, n);
    // bubbleSort(arr, n);
    // recursiveBubbleSort(arr, n);
    // insertionSort(arr, n);
    // recursiveInsertionSort(arr, n);
    // mergeSort(arr, 0, n - 1);
    // quickSort(arr, 0, n - 1);

    cout << "Sorted Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}

/*
📌 DRY RUN (Example Input: [64, 25, 12, 22, 11])
🔹 Selection Sort:
   Pass 1: [11, 25, 12, 22, 64]
   Pass 2: [11, 12, 25, 22, 64]
   Pass 3: [11, 12, 22, 25, 64]
   Pass 4: [11, 12, 22, 25, 64] ✅ Sorted

⏳ TIME COMPLEXITY SUMMARY:
-------------------------------------
| Algorithm      | Best   | Worst    |
|---------------|--------|----------|
| SelectionSort | O(N²)  | O(N²)    |
| BubbleSort    | O(N)   | O(N²)    |
| InsertionSort | O(N)   | O(N²)    |
| MergeSort     | O(NlogN) | O(NlogN) |
| QuickSort     | O(NlogN) | O(N²)  |
-------------------------------------
*/

