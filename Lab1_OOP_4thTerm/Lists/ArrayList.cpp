#include "ArrayList.h"
#include "point.h"
#include "Vector.h"
#include "circle.h"
#include "line.h"
#include <string>
#include <vector>
using namespace std;
template <typename T>
T ArrayList<T>:: operator[] (int i) {
	return array[i];
}
template <typename T>
	ArrayList<T>::ArrayList(T first) {
		T* tmp = new T[10];
		array = tmp;
		max_size = 10;
		cur_size = 1;
		array[0] = first;
	}
	template <typename T>
	ArrayList<T>::~ArrayList() {
		delete[] array;
	}
	template <typename T>
	void ArrayList<T>::change_size() {
		max_size += 10;
		T* temp = new T[max_size];
		for (int i = 0; i < cur_size; i++) {
			temp[i] = array[i];
		}
		delete[] array;
		array = temp;
	}
	template <typename T>
	void ArrayList<T>::add(T element) {
		if (cur_size == max_size) {
			change_size();
		}
		cur_size++;
		array[cur_size - 1] = element;
	}
	template <typename T>
	void ArrayList<T>::output() { 
		for (int i = 0; i < cur_size; i++) cout << array[i] << " ";
		cout << endl;
	}
	template <typename T>
	void ArrayList<T>::insertionSort() {
		for (int i = 0; i < cur_size - 1; i++) {
			if (array[i + 1] < array[i])
				for (int j = i; j != -1; j--) {
					if (array[j + 1] > array[j]) break;
					else {
						swap(array[j + 1], array[j]);
					}
				}
		}
	}
	template <typename T>
	int ArrayList<T>::partition(int beg, int end) {
		T pivot = array[end];
		int i = beg;
		for (int j = beg; j <= end; j++) {
			if (array[j] <= pivot) {
				swap(array[i], array[j]);
				i++;
			}
		}
		return i;
	}
	template <typename T>
	void ArrayList<T>::quickSortRecur(int beg, int end) {
		if (beg >= end) {
			return;
		}
		int pivot = partition(beg, end);
		output();
		cout << pivot;
		quickSortRecur(pivot, end);
		quickSortRecur(beg, pivot - 2);
	}
	template <typename T>
	void ArrayList<T>::quickSort() {
		return quickSortRecur(0, cur_size - 1);
	}
	template <typename T>
	void ArrayList<T>::merge(int beg, int med, int end) {
		int s1 = med - beg + 1;
		int s2 = end - med;
		T* a = new T[s1];
		T* b = new T[s2];
		for (int i = 0; i < med - beg + 1; i++) {
			a[i] = array[beg + i];
		}
		for (int j = 0; j < end - med; j++) {
			b[j] = array[med + j + 1];
		}
		int i = 0, j = 0, k = beg;
		while (i < med - beg + 1 && j < end - med) {
			if (a[i] < b[j]) {
				array[k] = a[i];
				i++;
			}
			else {
				array[k] = b[j];
				j++;
			}
			k++;
		}
		while (i < med - beg + 1) {
			array[k] = a[i];
			i++;
			k++;
		}
		while (j < end - med) {
			array[k] = b[j];
			j++;
			k++;
		}
		delete[] a;
		delete[] b;
	}
	template <typename T>
	void ArrayList<T>::mergeSortRecur(int beg, int end) {
		if (beg < end) {
			int med = (beg + end) / 2;
			mergeSortRecur(beg, med);
			mergeSortRecur(med + 1, end);
			output();
			merge(beg, med, end);
		}
	}
	template <typename T>
	void ArrayList<T>::mergeSort() {
		mergeSortRecur(0, cur_size - 1);
	}
	
	template class ArrayList<int>;
	template class ArrayList<double>;
	template class ArrayList < string>;
	template class ArrayList<float>;
	template class ArrayList < point>;
	template class ArrayList <line>;
	template class ArrayList <circle>;