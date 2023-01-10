#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
using namespace std;

class Array {
private:
	
	int arraySize;
	int startArraySize = 1;
	
	int resizeCoefficent = 2;

public:
	int* ar;
	int numberOfRecords = 0;
	Array();
	Array(const Array&);
	void resize();
	void add(int);
	void print(int);
	void edit(int, int);
	void clear();
	void swap(int*, int*);
	void sort();
	void info();

	void bubbleSort();
	void print() {
		for (int i = 0; i < numberOfRecords; i++) {
			cout << *(ar + i) << endl;
		}
		cout << endl;
	}
};

Array::Array() {
	arraySize = startArraySize;
	ar = new int[arraySize];
	*ar = 0;
}

Array::Array(const Array& obj) {
	arraySize = obj.arraySize;
	numberOfRecords = obj.numberOfRecords;
	ar = new int[arraySize];
	for (int i = 0; i < arraySize; i++) {
		*(ar + i) = *(obj.ar + i);
	}
}

void Array::resize() {
	Array* copyArray = new Array(*this);
	arraySize = copyArray->arraySize * resizeCoefficent;
	numberOfRecords = copyArray->numberOfRecords;
	delete[] ar;
	ar = new int[arraySize];
	for (int i = 0; i < arraySize; i++) {
		if (i < copyArray->arraySize) {
			*(ar + i) = *(copyArray->ar + i);
		}
		else
		{
			*(ar + i) = 0;
		}
	}
	delete copyArray;
}

void Array::add(int record) {
	if (numberOfRecords >= arraySize)
		resize();
	*(ar + numberOfRecords) = record;
	numberOfRecords++;
};

void Array::print(int index) {
	if (index >= arraySize) {
		cout << "Error! Out of range!" << endl;
	}
	else 
		cout <<  *(ar + index) << endl;
}

void Array::edit(int index, int record) {
	if (index >= numberOfRecords)
		cout << "Error! Out of range!" << endl;
	else
		*(ar + index) = record;
}

void Array::clear() {
	for (int i = 0; i < numberOfRecords; i++) {
		*(ar + i) = 0;
	}
	numberOfRecords = 0;
}

void Array::swap(int* a, int* b) {
	int copy = *a;
	*a = *b;
	*b = copy;
}

void Array::sort() {
	for (int i = 0; i < numberOfRecords - 1; i++) {
		for (int j = 0; j < numberOfRecords - i - 1; j++) {
			if (ar[j] > ar[j + 1]) {
				swap(&ar[j], &ar[j + 1]);
			}
		}
	}
}

void Array::info() {
	cout << "Number of records in array: " << numberOfRecords << endl;
	cout << "Actual size of array: " << arraySize << endl;
	cout << "Position of array in memory: " << this << endl;
}
#endif // !DYNAMICARRAY_H
