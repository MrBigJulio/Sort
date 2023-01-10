#ifndef HEAP_H
#define HEAP_H
using namespace std;

class Data {
public:
	int key;
	string data;


	Data() {
	}
	
	Data(int k, string d) {
		key = k;
		data = d;
	}

	Data(Data* a) {
		key = a->key;
		data = a->data;
	}

	~Data() {
		key = NULL;
		data.clear();
	}
};

class Heap {
private:
	Data* ar;
	int arraySize;
	int records;
	int const resizeConst = 2;

public:
	Heap() {
		arraySize = 1;
		records = 0;
		ar = new Data[arraySize];
	}

	void heapSort();

	void resize() {
		arraySize = this->arraySize * resizeConst;
		Data* newArray = new Data[arraySize];
		for (int i = 0; i < arraySize / 2; i++) {
			*(newArray + i) = *(ar + i);
		}
		ar = newArray;
	}

	void add(int k, string d) {
		if (records == arraySize) resize();
		Data* newData = new Data(k, d);
		*(ar + records) = *newData;
		records++;
		this->up(records);
	}

	void up(int index) {
		if (records != 1) {
			bool flag = false;
			while (floor(index / 2) != 0 && !flag) {
				if ((ar + (index - 1))->key > (ar + int(floor(index / 2) - 1))->key) {
					Data buffer = *(ar + (index - 1));
					*(ar + (index - 1)) = *(ar + int(floor(index / 2) - 1));
					*(ar + int(floor(index / 2) - 1)) = buffer;
					index = floor(index / 2);
				}
				else flag = true;
			}
		}
	}

	Data* del() {
		if (records == 0) return nullptr;
		else {
			Data *max = new Data(*(ar));
			*(ar) = *(ar + (records - 1));
			records--;
			this->down(1);
			return max;
		}
	}

	void down(int index) {
		if (records != 0) {
			bool flag = false;
			while (((2 * index) <= records || (2 * index + 1) <= records) && !flag) {
				if ((((ar + (index - 1))->key < (ar + (2 * index - 1))->key)  && (2 * index) <= records) && (((ar + (index - 1))->key < (ar + (2 * index))->key) && (2 * index + 1) <= records)) {
					if ((ar + (2 * index - 1))->key >= (ar + (2 * index))->key) {
						Data buffer = *(ar + (index - 1));
						*(ar + (index - 1)) = *(ar + (2 * index - 1));
						*(ar + (2 * index - 1)) = buffer;
						index = (2 * index);
					}
					else {
						Data buffer = *(ar + (index - 1));
						*(ar + (index - 1)) = *(ar + (2 * index));
						*(ar + (2 * index)) = buffer;
						index = (2 * index + 1);
					}

				}
				else if (((ar + (index - 1))->key < (ar + (2 * index - 1))->key) && (2 * index) <= records) {
					Data buffer = *(ar + (index - 1));
					*(ar + (index - 1)) = *(ar + (2 * index - 1));
					*(ar + (2 * index - 1)) = buffer;
					index = (2 * index);
				}
				else if (((ar + (index - 1))->key < (ar + (2 * index))->key) && (2 * index + 1) <= records){
					Data buffer = *(ar + (index - 1));
					*(ar + (index - 1)) = *(ar + (2 * index));
					*(ar + (2 * index)) = buffer;
					index = (2 * index + 1);
				}
				else flag = true;
			}
		}
	}

	void print() {
		for (int i = 0; i < records; i++) {
			cout << (ar + i)->key << " " << (ar + i)->data << endl;
		}
		cout << endl;
	}

	/*void clear() {
		for (int i = records; i > 0; i--) {
			Data* deleted = (ar + (i - 1));
			delete deleted;
			records--;
		}
	}*/

	
};


#endif // !HEAP_H
