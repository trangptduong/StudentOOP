#ifndef tvector_h
#define tvector_h

const int DEF_CAPACITY = 10;
const int CAPACITY_MULT = 2;

template <typename T>
class MyVec {
 public:
	MyVec() {
		sz = 0;
		capacity = DEF_CAPACITY;
		data = new T[DEF_CAPACITY];
	}

	MyVec(int sz, T val) {
		this->sz = sz;
		capacity = std::max(DEF_CAPACITY, sz * CAPACITY_MULT);
		data = new T[capacity];
		for (size_t i = 0; i < sz; i++) data[i] = val;
	}

	// copy control:
	MyVec(const MyVec<T>& v2) {
		capacity = v2.capacity;
		sz = v2.sz;
		data = new T[capacity];
		// copy over existing data
		for (int i = 0; i < size(); i++) {
			data[i] = v2.data[i];
		}
	}

	~MyVec() {
		delete[] data;
	}

	MyVec& operator=(const MyVec<T>& v2) {
		if (&v2 != this) {
			delete[] data;
			capacity = v2.capacity;
			sz = v2.size();
			data = new T[capacity];
			// copy over existing data
			for (int i = 0; i < size(); i++) {
				data[i] = v2.data[i];
			}
		}
		return *this;
	}

	void push_back(T val) {
		if (sz == capacity) {
			std::cout << "Increasing capacity\n";
			// get new array of capacity * 2
			capacity *= 2;
			T* new_data = new T[capacity];
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

	int size() const { return sz; }

	T operator[](int i) const {
		return data[i];
	}

	T& operator[](int i) {
		return data[i];

	}

private:
	void copy(const MyVec<T>& v2) {
		sz = v2.sz;
		capacity = v2.capacity;
		data = new T[capacity];
		for (int i = 0; i < sz; i++) {
			data[i] = v2.data[i];
		}
	}

	T* data;
	int sz;
	int capacity;
};


template <typename T>
void print_vector(const MyVec<T>& v) {
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}

template <typename T>
bool operator==(MyVec<T>& v1, MyVec<T>& v2) {
	if (v1.size() != v2.size()) {
		return false;
	}
	else {  // v1.size() == v2.size()
		for (int i = 0; i < v1.size(); i++) {
			if (v1[i] != v2[i]) {
				return false;
			}
		}
		return true;
	}
}


# endif