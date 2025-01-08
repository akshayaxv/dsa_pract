

## **1. Bubble Sort**
### **Concept**: 
Bubble Sort repeatedly swaps adjacent elements if they are in the wrong order. After each iteration, the largest unsorted element "bubbles up" to its correct position.

### **Steps**:
1. Compare adjacent elements.
2. Swap them if the left element is greater than the right.
3. Repeat until no swaps are needed.

### **Code Pattern**:
```cpp
for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < n-i-1; j++) {
        if (arr[j] > arr[j+1]) {
            swap(arr[j], arr[j+1]);
        }
    }
}
```

### **Time Complexity**:
- Worst Case: **O(N²)**
- Best Case (already sorted): **O(N)**

---

## **2. Selection Sort**
### **Concept**:
Selection Sort selects the smallest (or largest) element in each iteration and places it in its correct position.

### **Steps**:
1. Find the minimum element in the unsorted part of the array.
2. Swap it with the first element of the unsorted part.
3. Shrink the unsorted part and repeat.

### **Code Pattern**:
```cpp
for (int i = 0; i < n-1; i++) {
    int min_idx = i;
    for (int j = i+1; j < n; j++) {
        if (arr[j] < arr[min_idx]) {
            min_idx = j;
        }
    }
    swap(arr[i], arr[min_idx]);
}
```

### **Time Complexity**:
- Worst Case: **O(N²)**
- Best Case: **O(N²)** (no early termination)

---

## **3. Insertion Sort**
### **Concept**:
Insertion Sort builds the sorted array one element at a time by inserting elements into their correct position.

### **Steps**:
1. Pick an element from the unsorted part.
2. Shift elements in the sorted part to make space.
3. Place the picked element in its correct position.

### **Code Pattern**:
```cpp
for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = key;
}
```

### **Time Complexity**:
- Worst Case: **O(N²)**
- Best Case (already sorted): **O(N)**

---

## **4. Merge Sort**
### **Concept**:
Merge Sort divides the array into halves recursively and merges them back in sorted order.

### **Steps**:
1. Recursively divide the array until each part has one element.
2. Merge these parts while sorting them.

### **Code Pattern**:
```cpp
void mergeSort(int arr[], int l, int r) {
    if (l >= r) return;
    int mid = l + (r-l)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    merge(arr, l, mid, r);
}
```

### **Time Complexity**:
- Worst Case: **O(N * log(N))**
- Space Complexity: **O(N)**

---

## **5. Quick Sort**
### **Concept**:
Quick Sort selects a pivot element, partitions the array into two halves (smaller and larger elements), and sorts each half recursively.

### **Steps**:
1. Pick a pivot.
2. Rearrange elements such that smaller ones are on the left and larger ones on the right.
3. Recursively apply Quick Sort on both halves.

### **Code Pattern**:
```cpp
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low, j = high;
    while (i < j) {
        while (arr[i] <= pivot) i++;
        while (arr[j] > pivot) j--;
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}
```

### **Time Complexity**:
- Best Case: **O(N * log(N))**
- Worst Case: **O(N²)** (if pivot selection is poor)

---

## **6. Recursive Bubble Sort**
### **Concept**:
Recursive Bubble Sort eliminates the largest element in each recursive call by bubbling it to the correct position.

### **Code Pattern**:
```cpp
void bubbleSortRecursive(int arr[], int n) {
    if (n == 1) return;
    for (int i = 0; i < n-1; i++) {
        if (arr[i] > arr[i+1]) {
            swap(arr[i], arr[i+1]);
        }
    }
    bubbleSortRecursive(arr, n-1);
}
```

---

## **7. Recursive Insertion Sort**
### **Concept**:
Recursive Insertion Sort sorts one element at a time, inserting it into its correct position recursively.

### **Code Pattern**:
```cpp
void insertionSortRecursive(int arr[], int n) {
    if (n <= 1) return;
    insertionSortRecursive(arr, n-1);
    int last = arr[n-1];
    int j = n-2;
    while (j >= 0 && arr[j] > last) {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = last;
}
```

---

