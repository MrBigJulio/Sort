#include <iostream>
#include "Heap.h"
#include "DynamicArray.h"
using namespace std;

void countingSort(int* a, int n, int m) {
	int* counts = new int[m];
	for (int i = 0; i < m; i++) {
		counts[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		counts[a[i]]++;
	}
	int k = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < counts[i]; j++) {
			a[k++] = i;
		}
	}
}

void Heap::heapSort() {
	if (records == 0) return;
	else {
		int size = records;
		while (records != 0) {
			Data buffer = *(ar);
			*(ar) = *(ar + (records - 1));
			*(ar + (records - 1)) = buffer;
			records--;
			this->down(1);
		}
		records = size;
	}
}

void bucketSort(int* a, int n, int m, int size) {
	int w = m / n;
	Array *buckets = new Array[n];
	for (int i = 0; i < size; i++) {
		int bucketIndex = floor(a[i] / w);
		buckets[bucketIndex].add(a[i]);
	}
	for (int i = 0; i < n; i++) {
		buckets[i].sort();
	}
	Array *result = new Array;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < buckets[i].numberOfRecords; j++) {
			result->add(buckets[i].ar[j]);
		}
	}
	result->print();
} 

int main() {
	/*Heap* h = new Heap();
	h->add(5, "a");
	h->add(3, "a");
	h->add(4, "a");
	h->add(10, "a");
	h->add(12, "a");
	h->add(8, "a");
	h->add(1, "a");
	h->add(6, "a");
	h->add(7, "a");
	h->print();
	h->heapSort();
	h->print();*/


	
	int a[] = {6, 4, 9, 32, 7, 5, 8, 3, 1, 45, 12, 56, 23, 89 ,65, 21, 84, 51, 48, 52};
	int c[] = { 6, 4, 9, 32, 7, 5, 8, 3, 1, 45, 12, 56, 23, 89 ,65, 21, 84, 51, 48, 52 };
	
	countingSort(a, 20, 90);
	int b = sizeof(a) / sizeof(int);
	bucketSort(c, 5, 90, b);


}