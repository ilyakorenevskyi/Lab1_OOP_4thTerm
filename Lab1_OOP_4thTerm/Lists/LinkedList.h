#pragma once
#include <iostream>
template <typename T> struct Node {
	T data;
	Node<T>* next;
	Node(T val);
	Node(T val, Node<T>* next);
};
template <typename T> class List {
	Node<T>* head;
	Node<T>* end;
	Node<T>* getTail(struct Node<T>* cur);
	Node<T>* partition(struct Node<T>* head, struct Node<T>* end, struct Node<T>** newHead, struct Node<T>** newEnd);
	void insert(T key, T val);
	Node<T>* quickSortRecur(struct Node<T>* head, struct Node<T>* end);
	void push(Node<T>* new_head);
	void split(Node<T>* source, Node<T>** frontRef, Node<T>** backRef);
	void mergeSortRecur(Node<T>** headRef);
	Node<T>* merge(Node<T>* a, Node<T>* b);
	Node<T>* find(T val);
public:
	List(T first);
	List();
	T operator[] (int i);
	void quickSort();
	void add(T curr);
	void output();
	void insertionSort();
	void mergeSort();
	~List();
};


