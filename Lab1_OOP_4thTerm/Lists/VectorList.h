#pragma once
#include <vector>
#include <utility>
#include <iostream>

using namespace std;
template <typename T>
struct VectorList {
private:
	vector<T> myVector;
public:
	T operator[] (int i);
	VectorList(T first);
	void add(T element);
	void output();
	void insertionSort();
	int partition(int beg, int end);
	void quickSortRecur(int beg, int end);
	void quickSort();
	void merge(int beg, int med, int end);
	void mergeSortRecur(int beg, int end);
	void mergeSort();
};
