#include <iostream>
#include <vector>
using namespace std;

/* 📝 1️⃣ STRUCTURE OF A NODE (Linked List Representation)
   - A Node contains:
     1. Data (Value)
     2. Pointer to Next Node
*/
class Node {
public:
    int data;    // Node data
    Node* next;  // Pointer to the next node

    // Constructor to create a new node
    Node(int val) {
        this->data = val;
        this->next = NULL;
    }
};

/* 📝 2️⃣ INSERT A NODE AT THE BEGINNING
   - New node becomes the new head.
   - Time Complexity: O(1)
   - Space Complexity: O(1)
*/
void insertAtHead(Node*& head, int val) {
    Node* newNode = new Node(val); // Create new node
    newNode->next = head;          // Link new node to current head
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
    while (temp->next != NULL) temp = temp->next; // Traverse to last node
    temp->next = newNode; // Link last node to new node
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
    for (int i = 1; i < pos - 1 && temp != NULL; i++) temp = temp->next; // Traverse to (pos-1)th node

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
    while (temp->next && temp->next->data != val) temp = temp->next; // Find the node before target

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
        if (temp->data == key) return true; // Found key
        temp = temp->next;
    }
    return false;
}

/* 📝 8️⃣ CONVERT ARRAY TO LINKED LIST
   - Given an array, create a linked list.
   - Time Complexity: O(N)
   - Space Complexity: O(N)
*/
Node* arrayToLinkedList(vector<int>& arr) {
    if (arr.empty()) return NULL; // Edge case: Empty array

    Node* head = new Node(arr[0]); // Create head node
    Node* tail = head; // Tail keeps track of last node

    for (int i = 1; i < arr.size(); i++) {
        tail->next = new Node(arr[i]); // Create new node and link to tail
        tail = tail->next; // Move tail to new node
    }

    return head; // Return head of the linked list
}

/* 📝 9️⃣ PRINT LINKED LIST (Traversal)
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

/* 🏆 MAIN FUNCTION TO TEST ALL FUNCTIONS */
int main() {
    Node* head = NULL;

    // Convert Array to Linked List
    vector<int> arr = {1, 2, 3, 4, 5};
    head = arrayToLinkedList(arr);
    cout << "Array to Linked List: ";
    printList(head); // Output: 1 → 2 → 3 → 4 → 5 → NULL

    // Insert at head
    insertAtHead(head, 0);
    cout << "After inserting at head: ";
    printList(head); // Output: 0 → 1 → 2 → 3 → 4 → 5 → NULL

    // Insert at tail
    insertAtTail(head, 6);
    cout << "After inserting at tail: ";
    printList(head); // Output: 0 → 1 → 2 → 3 → 4 → 5 → 6 → NULL

    // Insert at position
    insertAtPosition(head, 99, 4);
    cout << "After inserting 99 at position 4: ";
    printList(head); // Output: 0 → 1 → 2 → 99 → 3 → 4 → 5 → 6 → NULL

    // Delete node
    deleteNode(head, 99);
    cout << "After deleting 99: ";
    printList(head); // Output: 0 → 1 → 2 → 3 → 4 → 5 → 6 → NULL

    // Get length
    cout << "Length of linked list: " << getLength(head) << endl; // Output: 7

    // Search element
    cout << "Searching for 3: " << (searchElement(head, 3) ? "Found" : "Not Found") << endl;
    cout << "Searching for 99: " << (searchElement(head, 99) ? "Found" : "Not Found") << endl;

    return 0;
}

