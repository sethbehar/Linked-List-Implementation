#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<typename T>

class LinkedList {

public:

	/*=== NODE CLASS DEFINITION ===*/
	struct Node {
		T data;
		Node* next;
		Node* prev;

		Node() {
			next = nullptr;
			prev = nullptr;
		}
	};
	/*=== END NODE CLASS DEFINITION ===*/


	/*=== Behaviors ===*/
	void PrintForward() const; // DONE
	void PrintReverse() const; // DONE
	void PrintForwardRecursive(const Node* node) const;
	void PrintReverseRecursive(const Node* node) const;

	/*=== Accessors ===*/
	unsigned int NodeCount() const; // DONE
	void FindAll(vector<Node*>& outData, const T& value) const; // DONE
	const Node* Find(const T& data) const; // DONE
	Node* Find(const T& data); // DONE
	const Node* GetNode(unsigned int index) const; //  DONE
	Node* GetNode(unsigned int index); // DONE
	Node* Head(); // DONE
	const Node* Head() const; // DONE
	Node* Tail(); // DONE
	const Node* Tail() const; // DONE

	/*=== Insertion ===*/
	void AddHead(const T& data); //  DONE
	void AddTail(const T& data); //  DONE
	void AddNodesHead(const T* data, unsigned int count); // DONE
	void AddNodesTail(const T* data, unsigned int count); // DONE
	void InsertAfter(Node* node, const T& data); // DONE
	void InsertBefore(Node* node, const T& data); // DONE
	void InsertAt(const T& data, unsigned int index); // DONE

	/*=== Removal ===*/
	bool RemoveHead(); // DONE
	bool RemoveTail(); // DONE
	unsigned int Remove(const T& data); // DONE
	bool RemoveAt(unsigned int index); // DONE
	void Clear(); // DONE

	/*=== Operators ===*/
	const T& operator[](unsigned int index) const; //  DONE
	T& operator[](unsigned int index); //  DONE
	bool operator==(const LinkedList<T>& rhs) const; // DONE
	LinkedList<T>& operator=(const LinkedList<T>& rhs); // DONE

	/*=== Constrcution / Destruction ===*/
	LinkedList(); // DONE
	LinkedList(const LinkedList<T>& list); // DONE
	~LinkedList(); // DONE

	
	/*=== PRIVATE CLASS VARIABLES ===*/
private:
	Node* head;
	Node* tail;
	unsigned int totalNodes;

};

/*=== Default Constrcutor ===*/
template<typename T> LinkedList<T>::LinkedList() {
	head = nullptr;
	tail = nullptr;
	totalNodes = 0;
}

/*=== DESTRUCTOR ===*/
template<typename T> LinkedList<T>::~LinkedList() {
	Node* currentNode = head;
	while (currentNode != nullptr) {
		Node* nextNode = currentNode->next;
		delete currentNode;
		currentNode = nextNode;
	}
	head = nullptr;
	tail = nullptr;
}


/*=== BEHAVIORS ===*/

// Print list from beginning
template <typename T>
void LinkedList<T>::PrintForward() const{
	Node* currentNode = head;
	while (currentNode != nullptr) {
		cout << currentNode->data << endl;
		currentNode = currentNode->next;
	}
}

//Print list from end
template <typename T>
void LinkedList<T>::PrintReverse() const {
	Node* currentNode = tail;
	while (currentNode != nullptr) {
		cout << currentNode->data << endl;
		currentNode = currentNode->prev;
	}
}

// Print forward from node recursively
template <typename T>
void LinkedList<T>::PrintForwardRecursive(const Node* node) const {
	if (node->next != nullptr) {
		cout << node->data << endl;
		node = node->next;
		PrintForwardRecursive(node);
	}
	else {
		cout << node->data << endl;
	}
}

// Print reverse from node recursively
template <typename T>
void LinkedList<T>::PrintReverseRecursive(const Node* node) const {
	if (node->prev != nullptr) {
		cout << node->data << endl;
		node = node->prev;
		PrintReverseRecursive(node);
	}
	else {
		cout << node->data << endl;
	}
}

/*=== END BEHAVIORS ===*/



/*=== ACCESSOR METHODS ===*/

// Returns total nodes in the linked list
template <typename T> 
unsigned int LinkedList<T>::NodeCount() const{
	return totalNodes;
}

// Return head node 
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Head() {
	return head;
}

// Return head node (CONST)
template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Head() const {
	return head;
}

// Return tail node 
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Tail() {
	return tail;
}

// Return tail node (CONST)
template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Tail() const {
	return tail;
}

// Returns pointer to node at 'index'
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) {
	Node* currentNode = head;
	
	if (index < 0 || index >= totalNodes) {
		throw out_of_range("Index out of bounds");
	}
	for (unsigned int i = 0; i < totalNodes; i++) {
		if (i == index) {
			return currentNode;
		}
	}
	return nullptr;
}

// Returns pointer to node at 'index' (CONST)
template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) const {
	Node* currentNode = head;

	if (index < 0 || index >= totalNodes) {
		throw out_of_range("Index out of bounds");
	}
	for (int i = 0; i < totalNodes; i++) {
		if (i == index) {
			return currentNode;
		}
	}
	return nullptr;
}

// Find first node with matching data value
// Returns pointer to the object
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data) {
	Node* currentNode = head;

	while (currentNode != nullptr) {
		if (currentNode->data == data) {
			return currentNode;
		}
		currentNode = currentNode->next;
	}
	
	return nullptr;
}

// Find first node with matching data value
// Returns pointer to the object
template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data) const {
	Node* currentNode = head;

	while (currentNode != nullptr) {
		if (currentNode->data == data) {
			return currentNode;
		}
		currentNode = currentNode->next;
	}

	return nullptr;
}


//	void FindAll(vector<Node*>& outData, const T& value) const;
template <typename T>
void LinkedList<T>::FindAll(vector<Node*>& outData, const T& value) const {
	Node* currentNode = head;

	while (currentNode != nullptr) {
		if (currentNode->data == value) {
			outData.push_back(currentNode);
		}
		currentNode = currentNode->next;
	}
}

/*=== END ACCESSOR METHODS ===*/



/*=== INSERTION ===*/

// Add nodes to front of linked list
template <typename T>
void LinkedList<T>::AddHead(const T& data) {

	// if list is empty
	if (head == nullptr) {
		head = new Node;
		head->data = data;
		tail = head;
	}
	else {

		// Create new node + give it the data
		Node* tempNode = new Node;
		tempNode->data = data;

		// set its next node to be the head node ptr
		tempNode->next = head;
		head->prev = tempNode;

		// make the head node var the newly created node
		head = tempNode;
	}
	totalNodes++;
}

// Add nodes to end of linked list
template <typename T>
void LinkedList<T>::AddTail(const T& data) {
	
	// if linked list is empty
	if (head == nullptr && tail == nullptr) {
		tail = new Node;
		tail->data = data;
		head = tail;
	}
	else {
		// Create new node + give it the data
		Node* tempNode = new Node;
		tempNode->data = data;

		// set the tail nodes next to be the newly created node
		tail->next = tempNode;
		tempNode->prev = tail;

		// set tail node var to be this newly created node
		tail = tempNode;
	}
	totalNodes++;
}

// Add array of values to beginnning of linked list
template <typename T> 
void LinkedList<T>::AddNodesHead(const T* data, unsigned int count) {
	for (unsigned int i = count - 1; i > 0; i--) {
		AddHead(data[i]);
	}
	AddHead(data[0]);
}

// Add array of values to end of linked list
template <typename T>
void LinkedList<T>::AddNodesTail(const T* data, unsigned int count) {
	for (unsigned int i = 0; i < count; i++) {
		AddTail(data[i]);
	}
}

// Insert node AFTER node, update next/prev node pointers
template <typename T>
void LinkedList<T>::InsertAfter(Node* node, const T& data) {
	Node* currentNode = head;
	int index = 0;

	while (currentNode != nullptr) {
		if (currentNode->data == node->data) {
			InsertAt(data, index + 1);
			break;
		}
		currentNode = currentNode->next;
		index++;
	}
		
}

// Insert node BEFORE node, update next/prev node pointers
template <typename T>
void LinkedList<T>::InsertBefore(Node* node, const T& data) {
	Node* currentNode = head;
	int index = 0;

	while (currentNode != nullptr) {
		if (currentNode->data == node->data) {
			InsertAt(data, index);
			break;
		}
		currentNode = currentNode->next;
		index++;
	}
}

// Insert node at certain "index", update next/prev node pointers
template <typename T>
void LinkedList<T>::InsertAt(const T& data, unsigned int index) {

	if (index < 0 || index > totalNodes) { // invalid index
		throw out_of_range("Index out of bounds.");
	}

	if (index == 0) { // insert at head if index if 0
		AddHead(data);
	}
	else {
		Node* newNode = new Node();
		newNode->data = data;
		Node* currentNode = head;
		for (unsigned int i = 0; i < index - 1; i++) {
			currentNode = currentNode->next;
		}

		newNode->next = currentNode->next;
		newNode->prev = currentNode;
		currentNode->next = newNode;
		
		if (newNode->next != nullptr)
			newNode->next->prev = newNode;
		
		totalNodes++;
		
	}


	
}
	
/*=== END INSERTION METHODS ===*/


/*=== REMOVAL OPERATIONS ===*/

// Remove first node in the list
template <typename T>
bool LinkedList<T>::RemoveHead() {	
	if (head == nullptr) {
		return false;
	}

	else if (head->next == nullptr) {
		Node* currentNode = head;
		delete currentNode;
		head = nullptr;
		tail = nullptr;
		totalNodes--;
		return true;
	}

	else {
		Node* currentNode = head;
		currentNode->next->prev = nullptr;
		head = head->next;
		delete currentNode;
		totalNodes--;
		return true;
	}
}

// Remove last node in the list
template <typename T>
bool LinkedList<T>::RemoveTail() {
	Node* currentNode;
	if (head == nullptr) {
		return false;
	}

	else if (tail->prev == nullptr) {
		currentNode = head;
		delete head;
		head = nullptr;
		tail = nullptr;
		totalNodes--;
		return true;
	}

	else {
		currentNode = tail;
		currentNode->prev->next = nullptr;
		tail = tail->prev;
		delete currentNode;
		totalNodes--;
		return true;
	}
}

// Remove node at certain "index"
template <typename T>
bool LinkedList<T>::RemoveAt(unsigned int index) {
	if (index < 0 || index >= totalNodes) {
		return false;
	}

	// if removing head (index 0)
	if (index == 0 && totalNodes > 0) {
		return RemoveHead();
	}

	// else find node to delete
	Node* currentNode = head;
	for (unsigned int i = 0; i < index; i++) {
		currentNode = currentNode->next;
	}
	 


	// if there is a node that comes after node we are deleting...
	// update next of node after node we are deleting
	if (currentNode->next != nullptr) {
		currentNode->next->prev = currentNode->prev;
	}

	//if there is a node before the one we are deleting...
	// update prev of node before we are deleting
	if (currentNode->prev != nullptr) {
		currentNode->prev->next = currentNode->next;
	}

	delete currentNode;
	totalNodes--;
	return true;
}

template <typename T>
unsigned int LinkedList<T>::Remove(const T& data) {
	unsigned int removed = 0;
	
	if (totalNodes == 0) {
		return 0;
	}

	Node* currentNode = head;
	Node* nextNode = nullptr;

	while (currentNode != nullptr) {
		nextNode = currentNode->next;
		// found same data
		if (currentNode->data == data) {
			if (currentNode->next == nullptr) {
				currentNode->prev->next = nullptr;
			}
			else if (currentNode->prev == nullptr) {
				currentNode->next->prev = nullptr;
			}
			else {
				currentNode->prev->next = currentNode->next;
				currentNode->next->prev = currentNode->prev;
			}
			delete currentNode;
			totalNodes--;
			removed++;
		}
		currentNode = nextNode;
	}
	
	return removed;
}

template <typename T>
void LinkedList<T>::Clear() {
	Node* currentNode = head;
	Node* nextNode = nullptr;

	while (currentNode != nullptr) {
		nextNode = currentNode->next;
		delete currentNode;
		currentNode = nextNode;
	}
	head = nullptr;
	tail = nullptr;
	totalNodes = 0;
}

/*=== END REMOVAL OPERATIONS ===*/



/*=== OPERATORS ===*/

// [] OVERLOAD
template <typename T>
const T& LinkedList<T>::operator[](unsigned int index) const {
	if (index < 0 || index >= totalNodes) {
		throw out_of_range("Index out of bounds.");
	}
	return GetNode(index)->data;
}
// [] OVERLOAD CONST
template <typename T>
T& LinkedList<T>::operator[](unsigned int index) {
	if (index < 0 || index >= totalNodes) {
		throw out_of_range("Index out of bounds.");
	}
	return GetNode(index)->data;
}

// Copy assignment operator
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs) {
	
	if (this == &rhs) { // self assignment
		return *this;
	}
	
	Node* currentNode = head;
	while (currentNode != nullptr) { // delete lhs 
		Node* nextNode = currentNode->next;
		delete currentNode;
		currentNode = nextNode;
	}
	head = nullptr;
	tail = nullptr;

	currentNode = rhs.head;
	while (currentNode != nullptr) { // copy data from rhs
		AddTail(currentNode->data);
		currentNode = currentNode->next;
	}
	return *this;
}

// Copy constructor
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list) {

	head = nullptr;
	tail = nullptr;	// reset list vars
	totalNodes = 0;


	Node* currentNode = list.head;
	while (currentNode != nullptr) {
		AddTail(currentNode->data);
		currentNode = currentNode->next;
	}
	delete currentNode;
}

// Overload equality operator
template <typename T>
bool LinkedList<T>::operator==(const LinkedList<T>& list) const{

	Node* currentNode = head;
	Node* otherNode = list.head;
	unsigned int comparisons = 0;

	if (totalNodes != list.NodeCount()) {
		return false;
	}

	while (currentNode != nullptr) {
		if (currentNode->data == otherNode->data) {
			comparisons++;
		}
		currentNode = currentNode->next;
		otherNode = otherNode->next;
	}

	return totalNodes == comparisons;
} 