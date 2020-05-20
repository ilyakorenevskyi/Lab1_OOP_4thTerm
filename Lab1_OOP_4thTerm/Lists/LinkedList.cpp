#include "LinkedList.h"
#include <vector>
#include "Vector.h"
#include "point.h"
#include "circle.h"
#include "line.h"
using namespace std;
template <typename T> 	Node<T>::Node(T val) : data(val), next(nullptr) {}
template <typename T> 
Node<T>::Node(T val, Node<T>* next) : data(val), next(next) {}
template <typename T>
T List<T>::  operator[] (int i) {
	int k = 0;
	Node<T>* temp = head;
	while (temp != nullptr ) {
		if (k == i) return temp->data;
		k++;
		temp = temp->next;
	}
}
template <typename T>
	List<T>::List(T first) {		//  Create first element
		head = new Node<T>(first);
		end = head;
	}
template <typename T>
List<T>::List() : head(nullptr), end(nullptr) {}
template <typename T>
void List<T>::add(T curr) {		// Add new element
	Node<T>* temp = new Node<T>(curr);
	end->next = temp;
	end = temp;
}
template <typename T>
void List<T>::insert(T key, T val) {		// Insert new element into the list
	if (Node<T> * temp = find(key)) {      //If key was found 
		Node<T>* new_el = new Node<T>(val, temp->next);
		temp->next = new_el;
		if (temp == end) end = new_el;
	}
	else {
		if (head == nullptr) {			//If list is empty, create head
			head = new Node<T>(val);
			end = head;
		}
		else {				//If list is not empty, add new node in the end
			Node<T>* new_el = new Node<T>(val);
			end->next = new_el;
			end = new_el;
		}
	}
}
template <typename T>
	Node<T>* List<T>::find(T val) {		// Search for a given item
	Node<T>* curr = head;
	while (curr) {
		if (curr->data == val) {
			break;
		}
		curr = curr->next;
	}
	return curr;
}
template <typename T>
void List<T>::output() {  // Output whole list
	Node<T>* curr = head;
	while (curr) {
		cout << curr->data << " ";
		curr = curr->next;
	}
}
template <typename T>
List<T>::~List() {			// List destruction
	Node<T>* curr, * delete_temp;
	curr = head;
	while (curr != nullptr) {
		delete_temp = curr;
		curr = curr->next;
		delete delete_temp;
	}
}
template <typename T>
void List<T>::insertionSort() {    // Insertion sort
Node<T>* curr = head;
Node<T>* sorted = head;
		while (curr->next) {
			if (curr->next->data < curr->data) {       // If next list element smaller than max element of sorted part
				Node<T>* temp = curr->next;
				curr->next = curr->next->next;
				while (sorted != curr->next) {     // Search place to insert element
					if (sorted->data > temp->data) {   // If element is smaller  than every element in sorted part
						push(temp);
						break;
					}
					if (sorted->next->data > temp->data) {   // If we have found place for element 
						temp->next = sorted->next;
						sorted->next = temp;
						break;
					}
					sorted = sorted->next;
				}
				sorted = head;
			}
			else curr = curr->next;
		}

	}
	template <typename T>
	void List<T>::push(Node<T> * new_head) {
		new_head->next = head;
		head = new_head;
	}
	template <typename T>
	void List<T>::mergeSortRecur(Node<T>** headRef)
	{
		Node<T>* head = *headRef;
		Node<T>* a;
		Node<T>* b;
		if ((head == nullptr) || (head->next == nullptr)) {
			return;
		}
		split(head, &a, &b);
		mergeSortRecur(&a);
		mergeSortRecur(&b);
		*headRef = merge(a, b);
	}
	template <typename T>
	Node<T>* List<T>::partition(struct Node<T>* head, struct Node<T>* end,struct Node<T>** newHead, struct Node<T>** newEnd)
	{
		struct Node<T>* pivot = end;
		struct Node<T>* prev = nullptr, * cur = head, * tail = pivot;
		while (cur != pivot)
		{
			if (cur->data < pivot->data)
			{
				if ((*newHead) == nullptr)
					(*newHead) = cur;

				prev = cur;
				cur = cur->next;
			}
			else 
			{
				
				if (prev)
					prev->next = cur->next;
				struct Node<T>* tmp = cur->next;
				cur->next = nullptr;
				tail->next = cur;
				tail = cur;
				cur = tmp;
			}
		}
		if ((*newHead) == nullptr)
			(*newHead) = pivot;

		(*newEnd) = tail; 
		return pivot;
	}
	template <typename T>
	 Node<T>* List<T>::getTail(struct Node<T>* cur)
	{
		while (cur != nullptr && cur->next != nullptr)
			cur = cur->next;
		return cur;
	}
	 template <typename T>
	Node<T>* List<T>::quickSortRecur(struct Node<T>* head, struct Node<T>* end)
	{
		if (!head || head == end)
			return head;
		Node<T>* newHead = nullptr, *newEnd = nullptr;
		struct Node<T>* pivot = partition(head, end, &newHead, &newEnd);
		if (newHead != pivot)
		{
			struct Node<T>* tmp = newHead;
			while (tmp->next != pivot)
				tmp = tmp->next;
			tmp->next = nullptr;
			newHead = quickSortRecur(newHead, tmp); 
			tmp = getTail(newHead);
			tmp->next = pivot;
		}
		pivot->next = quickSortRecur(pivot->next, newEnd);

		return newHead;
	}
	template <typename T>
	void List<T>::quickSort()
	{
		head = quickSortRecur(head, end);
		return;
	}
	template <typename T>
	Node<T>* List<T>::merge(Node<T>* a, Node<T>* b)
	{
		Node<T>* result = nullptr;
		if (a == nullptr)
			return (b);
		else if (b == nullptr)
			return (a);
		if (a->data <= b->data) {
			result = a;
			result->next = merge(a->next, b);
		}
		else {
			result = b;
			result->next = merge(a, b->next);
		}
		return (result);
	}
	template <typename T>
	void List<T>::split(Node<T>* source,Node<T> **frontRef, Node<T>** backRef)
	{
		Node<T>* fast;
		Node<T>* slow;
		slow = source;
		fast = source->next;
		while (fast != nullptr) {
			fast = fast->next;
			if (fast != nullptr) {
				slow = slow->next;
				fast = fast->next;
			}
		}

		*frontRef = source;
		*backRef = slow->next;
		slow->next = nullptr;
	}
	template <typename T>
	void List<T>::mergeSort() {
		mergeSortRecur(&head);
	}

	template class List<int>;
	template class List<double>;
	template class List<string>;
	template class List<float>;
	template class List<point>;
	template class List<circle>;
	template class List<line>;
	
