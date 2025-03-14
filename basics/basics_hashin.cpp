#include <iostream>
#include <unordered_map> // For hash map
#include <vector>       // For storing multiple max/min elements
#include <limits.h>     // For INT_MAX, INT_MIN
using namespace std;

// Function to count frequencies and find highest & lowest frequency elements
void analyzeFrequencies(int arr[], int n) {
    unordered_map<int, int> freq; // Hash map to store element frequencies

    // Step 1: Count frequencies of elements
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++; // Increase count of current element
    }

    // Step 2: Print element frequencies
    cout << "\nElement - Frequency\n";
    for (auto it : freq) {
        cout << it.first << " - " << it.second << endl;
    }

    // Step 3: Initialize variables for highest & lowest frequency
    int maxFreq = INT_MIN, minFreq = INT_MAX;
    vector<int> maxElems, minElems; // Store elements with max/min frequency

    // Step 4: Find max/min frequency elements
    for (auto it : freq) {
        int element = it.first;
        int count = it.second;

        // Update max frequency elements
        if (count > maxFreq) {
            maxFreq = count;  // Update max frequency
            maxElems = {element}; // Reset and store new max element
        } else if (count == maxFreq) {
            maxElems.push_back(element); // Store multiple elements with same max frequency
        }

        // Update min frequency elements
        if (count < minFreq) {
            minFreq = count;  // Update min frequency
            minElems = {element}; // Reset and store new min element
        } else if (count == minFreq) {
            minElems.push_back(element); // Store multiple elements with same min frequency
        }
    }

    // Step 5: Print highest & lowest frequency elements
    cout << "\nHighest Frequency Element(s) (Count: " << maxFreq << "): ";
    for (int ele : maxElems) cout << ele << " ";
    cout << endl;

    cout << "Lowest Frequency Element(s) (Count: " << minFreq << "): ";
    for (int ele : minElems) cout << ele << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n; // Input size of array

    int arr[n]; // Array to store elements
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Input array elements
    }

    analyzeFrequencies(arr, n); // Call function to analyze frequencies
    return 0;
}

/*
🔥 DRY RUN (Step-by-step execution)

📌 Input:
Enter the size of the array: 7
Enter the array elements: 4 3 1 3 4 4 2

📝 Step 1: Count Frequencies
4 → 3 times
3 → 2 times
1 → 1 time
2 → 1 time

📝 Step 2: Print Element Frequencies
Element - Frequency
4 - 3
3 - 2
1 - 1
2 - 1

📝 Step 3: Find Max & Min Frequency Elements
Max Frequency = 3 (Element: 4)
Min Frequency = 1 (Elements: 1, 2)

📌 Output:
Highest Frequency Element(s) (Count: 3): 4
Lowest Frequency Element(s) (Count: 1): 1 2
*/

/*
⏳ TIME COMPLEXITY ANALYSIS
--------------------------------
- **Counting Frequencies** (Hash Map Insertion) → O(N)
- **Finding Max/Min Frequency** (Map Traversal) → O(N)
- **Printing Output** → O(N)
--------------------------------
✅ **Overall Time Complexity:** O(N) (Linear time)
✅ **Space Complexity:** O(N) (for Hash Map storage)
--------------------------------
💡 Optimized! Faster than sorting (O(N log N)) or nested loops (O(N²))
*/

