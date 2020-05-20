#pragma once
#include <utility>
#include <iostream>

template <typename T> class ArrayList {
	T* array;
	size_t cur_size;
	size_t max_size;
	void change_size();
	int partition(int beg, int end);
	void quickSortRecur(int beg, int end);
	void merge(int beg, int med, int end);
	void mergeSortRecur(int beg, int end);
public:
	T operator[] (int i);
	ArrayList(T first);
	~ArrayList();
	void output();
	void insertionSort();
	void quickSort();
	void add(T element);
	void mergeSort();
};


