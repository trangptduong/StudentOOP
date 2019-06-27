# include <cassert>
# include <iostream>
# include <algorithm>
# include "../my_code/tvector.h"

using namespace std;

template <typename T>
int copy_vector(MyVec<T> v) {
	MyVec<T> local_v = v;
	return local_v.size();
}

const int VEC_SZ = 20;


int main() {
	MyVec<int> iv = MyVec<int>();
	for (int i = 0; i < VEC_SZ; i++) {
		iv.push_back(i);
		copy_vector(iv);
	}

	assert(iv[VEC_SZ - 1] == VEC_SZ - 1);
	for (int i = 0; i < iv.size(); i++) {
		iv[i] *= 2;
	}
	assert(iv[VEC_SZ - 1] == 38);
	MyVec<int> v3;
	for (int i = 9; i < 100; i += 9) {
		v3.push_back(i);
	}

	assert(v3[1] == 18);
	// cout << "Checking vector 3" << endl;
	print_vector(v3);
	
	MyVec<int> v2 = iv;
	assert(v2 == iv);
	// cout << "Checking vector 2" << endl;
	print_vector(v2);

	v2 = v3;
	assert(v2 == v3);
	// cout << "Checking vector 2 after assignment" << endl;
	print_vector(v2);

	// cout << "Checking vector 3 mod 9" << endl;
	for (int i = 0; i < v3.size(); i++) {
		assert((v3[i] % 9) == 0);
	}
	
	// cout << "Creating string vector" << endl;
	MyVec<string> sv = MyVec<string>(10, "Hello");

	for (int i = 0; i < sv.size(); i++) {
		assert(sv[i] == "Hello");
	}
	
	//cout << "Printing vector sv" << endl;
	print_vector(sv);
	/*
	*/
}