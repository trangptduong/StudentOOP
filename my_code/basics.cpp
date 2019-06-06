#include <iostream>
#include <string>
#include <vector>
#include "basics.h"

using namespace std;

/*
 * increment arg passed by copy
 * */
void inc_pass_copy(int j) {
	j++;  // this func increments j but not visibly to the outside world
}

/*
 * increment arg passed by reference
 * */
void inc_pass_ref(int& j) {
	j++;  // the variable itself is incremented and the output is now j = 9 from j = 8
}

/*
 * Fill a vector with n elements from 1 to n.
 * 1st item == 1, 2nd item == 2, etc.
 * 0 filled for you.
 * Use `push_back()` to fill the vector.
 * */
void fill_vector(vector<int>& v, int n) {
	for (int i = 1; i < n + 1; i++) {
		v.push_back(i);
	}
}

/*
 * Print all elements in a vector. Use a ranged for!
 * */
void print_vector(const vector<int>& v) {
	for (int n : v) {
		cout << n << " ";
	}
	cout << endl;  //  cout << '\n' is the same thing

}

/*
 * Print a pair of coordinates.
 * Output should look like "x = 9, y = 2".
 * */
void print_coords(coord pos) {
	cout << "x = " << pos.x << "; y = " << pos.y << endl;
}

/*
 * Square an integer.
 * */
int square(int n) {
	return n * n;
}

/*
 * Square a double.
 * */
double square(double d) {
	return d * d;
}

/*
 * Get the absolute value of a number.
 * */
int my_abs(int n) {
	int res = 0;
	if (n >= 0) {
		res = n;
	}
	else {  //n <= 0
		res = -n;
	}
	return res;
}

/*
 * Sum from 0 to n using a `while` loop.
 * */
int sum(int n) {
	int total = 0;
	int i = 0;
	while (i < n) {
		total += i;
		i++;
	}
	return total;
}

/*
 * Sum from 0 to n using a `for` loop.
 * */
int sum2(int n) {
	int total = 0;
	for (int i = 0; i < n; i++) {
		total += i;
	}
	return total;
}

/*
 * say() is built for you!
 * */
void say(std::string s) {
	cout << s << endl;
}


/*
 * Use a ranged for to pull a string apart into its bits.
 * */
void pull_apart_string(std::string s) {
	for (char c : s) {
		cout << c << " ";
	}
	cout << endl;
}