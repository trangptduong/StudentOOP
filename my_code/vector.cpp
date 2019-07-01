# include <iostream>
# include "vector.h"
# include <algorithm>
using namespace std;

void print_vector(const MyVec& v) {
	for (int i = 0; i < v.size(); i++) cout << i << " ";
	cout << endl;
}

MyVec::MyVec() : sz(0) {
	capacity = DEF_CAPACITY;
	data = new int[DEF_CAPACITY];
}

MyVec::MyVec(int sz, int val) : sz{sz} {
	capacity = max(DEF_CAPACITY, sz * CAPACITY_MULT);
	data = new int[capacity];
	for (size_t i = 0; i < sz; i++) data[i] = val;
}

MyVec::MyVec(const MyVec& v2) {
	capacity = v2.capacity;
	sz = v2.size();

	data = new int[capacity];
	// copy over existing data
	for (int i = 0; i < size(); i++) {
		data[i] = v2.data[i];
	}
}

MyVec::~MyVec() {
	delete[] data;
}

MyVec& MyVec::operator=(const MyVec& v2) {
	if (&v2 != this) {
		delete[] data;
		capacity = v2.capacity;
		sz = v2.size();
		data = new int[capacity];
		// copy over existing data
		for (int i = 0; i < size(); i++) {
			data[i] = v2.data[i];
		}
	}
	return *this;
}

/*
 * Puts an element at the back of a vector.
 * */
void MyVec::push_back(int val) {
	if (sz == capacity) {
		cout << "Increasing capacity\n";
		// get new array of capacity * 2
		capacity *= 2;
		int* new_data = new int[capacity];
		// copy over existing data
		for (int i = 0; i < size(); i++) {
			new_data[i] = data[i];
		}
		// delete old array
		delete[] data;
		// set pointer to new array
		data = new_data;
	}
	data[sz++] = val;  // data[sz] = val; sz += 1;
}

/*
 * this [] is for reading items from the MyVec:
 * It returns the i-th element.
 * */
int MyVec::operator[](int i) const {
	return data[i];
}

/*
 * this [] allows write access to items in the MyVec:
 * It returns a reference to the i-th element.
 * */
int& MyVec::operator[](int i) {
	return data[i];
}

/*
 * == is true when every element of the vectors are the same in
 * the same order. (Thus they must be the same size.)
 * */
bool operator==(MyVec& v1, MyVec& v2) {
	if (v1.size() != v2.size()) {
		return false;
	} 
	else {  // v1.size() == v2.size()
		for (int i = 0; i < v1.size();  i++) {
			if (v1[i] != v2[i]) {
				return false;
			}
		}
		return true;
	}
}

MyVec::Iterator MyVec::begin() const {
	return MyVec::Iterator(data);
}

MyVec::Iterator MyVec::end() const {
	return MyVec::Iterator(data + size());
}

void MyVec::copy(const MyVec& v2) {
	sz = v2.sz;
	capacity = v2.capacity;
	data = new int[capacity];
	for (int i = 0; i < sz; i++) {
		data[i] = v2.data[i];
	}
}