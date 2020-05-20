#include "VectorList.h"
#include "Vector.h"
#include <vector>
#include "point.h"
#include "circle.h"
#include "line.h"
using namespace std;
template <typename T>
T VectorList<T>:: operator[] (int i) {
	return myVector[i]; 
}; 
template <typename T>
VectorList<T>::VectorList(T first) {
	myVector.push_back(first);
}
template <typename T>
void VectorList<T>::add(T element) {
	myVector.push_back(element);
}
template <typename T>
void VectorList<T>::output() {
	for (int i = 0; i < myVector.size(); i++) cout << myVector[i] << " ";
	cout << endl;
}
template <typename T>
void VectorList<T>::insertionSort() {
	for (int i = 0; i < myVector.size() - 1; i++) {
		if (myVector[i + 1] < myVector[i])
			for (int j = i; j != -1; j--) {
				if (myVector[j + 1] > myVector[j]) break;
				else {
					swap(myVector[j + 1], myVector[j]);
				}
			}
	}
}
template <typename T>
int VectorList<T>::partition(int beg, int end) {
	T pivot = myVector[end];
	int i = beg;
	for (int j = beg; j <= end; j++) {
		if (myVector[j] <= pivot) {
			swap(myVector[i], myVector[j]);
			i++;
		}
	}
	return i;
}
template <typename T>
void VectorList<T>::quickSortRecur(int beg, int end) {
	if (beg >= end) {
		return;
	}
	int pivot = partition(beg, end);
	quickSortRecur(pivot, end);
	quickSortRecur(beg, pivot - 2);
}
template <typename T>
void VectorList<T>::quickSort() {
	return quickSortRecur(0, myVector.size()-1);
}
template <typename T>
void VectorList<T>::merge(int beg, int med, int end) {
	int s1 = med - beg + 1;
	int s2 = end - med;
	vector<T> a;
	vector<T> b;
	for (int i = 0; i < med - beg + 1; i++) {
		a.push_back(myVector[beg + i]);
	}
	for (int j = 0; j < end - med; j++) {
		b.push_back(myVector[med + j + 1]);
	}
	int i = 0, j = 0, k = beg;
	while (i < med - beg + 1 && j < end - med) {
		if (a[i] < b[j]) {
			myVector[k] = a[i];
			i++;
		}
		else {
			myVector[k] = b[j];
			j++;
		}
		k++;
	}
	while (i < med - beg + 1) {
		myVector[k] = a[i];
		i++;
		k++;
	}
	while (j < end - med) {
		myVector[k] = b[j];
		j++;
		k++;
	}

}
template <typename T>
void VectorList<T>::mergeSortRecur(int beg, int end) {
	if (beg < end) {
		int med = (beg + end) / 2;
		mergeSortRecur(beg, med);
		mergeSortRecur(med + 1, end);
		merge(beg, med, end);
	}
}
template <typename T>
void VectorList<T>::mergeSort() {
	mergeSortRecur(0, myVector.size() - 1);
}
template class VectorList<int>;
template class VectorList<double>;
template class VectorList<vector<int>>;
template class VectorList<string>;
template class VectorList<point>;
template class VectorList<line>;
template class VectorList<circle>;
template class VectorList<circle*>;