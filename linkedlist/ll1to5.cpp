#include <iostream>
using namespace std;

/* 📝 1️⃣ STRUCTURE OF A NODE (Linked List Representation)
   - A Node contains:
     1. Data (Value)
     2. Pointer to Next Node
*/
struct Node {
    int data;     // Data of node
    Node* next;   // Pointer to next node

    // Constructor to create a new node
    Node(int val) {
        data = val;
        next = NULL;
    }
};


#include <iostream>
#include <vector>
using namespace std;

/* 📝 1️⃣ STRUCTURE OF A NODE */
class Node {
public:
    int data;
    Node* next;

    // Default constructor
    Node() {
        data = 0;
        next = NULL;
    }

    // Parameterized Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

/* 📝 2️⃣ SOLUTION: CONSTRUCT LINKED LIST FROM ARRAY */
class Solution {
public:
    Node* constructLL(vector<int>& arr) {
        if (arr.empty()) return NULL; // Edge case: Empty array

        // Step 1: Create the head node
        Node* head = new Node(arr[0]); 
        Node* tail = head; // Tail keeps track of last node

        // Step 2: Iterate through array to create and link nodes
        for (int i = 1; i < arr.size(); i++) {
            tail->next = new Node(arr[i]); // Create new node and link to tail
            tail = tail->next; // Move tail to new node
        }

        return head; // Return head of the linked list
    }
};

/* 📝 3️⃣ PRINT LINKED LIST (Traversal) */
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " → ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

/* 🏆 MAIN FUNCTION TO TEST THE SOLUTION */
int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5};

    Node* head = sol.constructLL(arr);
    cout << "Constructed Linked List: ";
    printList(head); // Output: 1 → 2 → 3 → 4 → 5 → NULL

    return 0;
}


/* 📝 2️⃣ INSERT A NODE AT THE BEGINNING
   - New node becomes the new head.
   - Time Complexity: O(1)
   - Space Complexity: O(1)
*/
void insertAtHead(Node*& head, int val) {
    Node* newNode = new Node(val); // Create a new node
    newNode->next = head;          // Link new node to old head
    head = newNode;                // Update head
}

/* 📝 3️⃣ INSERT A NODE AT THE END
   - Traverse to the last node and insert.
   - Time Complexity: O(N) (Traversing required)
   - Space Complexity: O(1)
*/
void insertAtTail(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) { // If list is empty, new node becomes head
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) { // Traverse to last node
        temp = temp->next;
    }
    temp->next = newNode; // Link last node to new node
}
// if returning head
class Solution {
  public:
    Node* insertAtEnd(Node* head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return head;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode; return head;
}



/* 📝 4️⃣ INSERT A NODE AT A GIVEN POSITION
   - Insert at the given position (1-based index)
   - Time Complexity: O(N) (Traversing required)
   - Space Complexity: O(1)
*/
void insertAtPosition(Node*& head, int val, int pos) {
    if (pos == 1) { // Insert at head case
        insertAtHead(head, val);
        return;
    }

    Node* newNode = new Node(val);
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) { // Traverse to (pos-1)th node
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Position out of bounds!" << endl;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

/* 📝 5️⃣ DELETE A NODE BY VALUE
   - Find the node with given value and delete.
   - Time Complexity: O(N) (Traversing required)
   - Space Complexity: O(1)
*/
void deleteNode(Node*& head, int val) {
    if (head == NULL) return; // Empty list

    if (head->data == val) { // Delete head case
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    while (temp->next && temp->next->data != val) {
        temp = temp->next; // Traverse to find node before target
    }

    if (temp->next == NULL) return; // Value not found

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

/* 📝 6️⃣ FIND LENGTH OF LINKED LIST
   - Traverse the list and count nodes.
   - Time Complexity: O(N)
   - Space Complexity: O(1)
*/
int getLength(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

/* 📝 7️⃣ SEARCH FOR AN ELEMENT
   - Traverse the list to check if key exists.
   - Time Complexity: O(N)
   - Space Complexity: O(1)
*/
bool searchElement(Node* head, int key) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) return true;
        temp = temp->next;
    }
    return false;
}

/* 📝 8️⃣ PRINT LINKED LIST (Traversal)
   - Print all nodes of the linked list.
   - Time Complexity: O(N)
   - Space Complexity: O(1)
*/
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " → ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

/* 📌 DRY RUN FOR LINKED LIST OPERATIONS
Step 1: Insert 10, 20, 30 at the end
         [10] → [20] → [30] → NULL
Step 2: Insert 5 at the beginning
         [5] → [10] → [20] → [30] → NULL
Step 3: Insert 25 at position 3
         [5] → [10] → [25] → [20] → [30] → NULL
Step 4: Delete node with value 10
         [5] → [25] → [20] → [30] → NULL
Step 5: Find length
         Output: 4
Step 6: Search for 25 (Found) and 100 (Not Found)
         Output: true, false
*/

/* 🏆 MAIN FUNCTION TO TEST ALL FUNCTIONS */
int main() {
    Node* head = NULL;

    // Insert at tail
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    cout << "After inserting at tail: ";
    printList(head); // Output: 10 → 20 → 30 → NULL

    // Insert at head
    insertAtHead(head, 5);
    cout << "After inserting at head: ";
    printList(head); // Output: 5 → 10 → 20 → 30 → NULL

    // Insert at position
    insertAtPosition(head, 25, 3);
    cout << "After inserting 25 at position 3: ";
    printList(head); // Output: 5 → 10 → 25 → 20 → 30 → NULL

    // Delete node by value
    deleteNode(head, 10);
    cout << "After deleting 10: ";
    printList(head); // Output: 5 → 25 → 20 → 30 → NULL

    // Get length
    cout << "Length of linked list: " << getLength(head) << endl; // Output: 4

    // Search element
    cout << "Searching for 25: " << (searchElement(head, 25) ? "Found" : "Not Found") << endl; // Output: Found
    cout << "Searching for 100: " << (searchElement(head, 100) ? "Found" : "Not Found") << endl; // Output: Not Found

    return 0;
}
