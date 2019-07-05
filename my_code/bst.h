# include <iostream>

void indent(int level) {
	// indent more at each level:
	for (int i = 0; i < level; i++) std::cout << "  ";
}

template <typename T>
class Bst {
	friend void print_bst(const Bst<T>& bst, int level = 0) {
		indent(level);
		level++;

		std::cout << "data: " << bst.data << std::endl;
		indent(level + 1);
		std::cout << "left: ";

		if (!bst.left) std::cout << "nullptr\n";
		else {
			std::cout << "\n";
			indent(level);
			print_bst(*bst.left, level);
		}
		indent(level + 1);
		std::cout << "right: ";
		if (!bst.right) std::cout << "nullptr\n";
		else {
			std::cout << "\n";
			indent(level);
			print_bst(*bst.right, level);
		}
		std::cout << std::endl;
	}

 public:
	Bst(T d, Bst* p = nullptr, Bst* l = nullptr, Bst* r = nullptr)
		: data(d), parent(p), left(l), right(r) {}

	Bst<T>* insert(const T d) {
		if (d == data) return nullptr;

		else if (d < data) {  // look at the left side
			if (!left) {  // left == nullptr
				left = new Bst(d, this);  // get pointer points to this left node
				return left;
			}
			else {
				return left->insert(d);  // do it recursively on the left tree
			}
		}

		else {  // d > data -> look at the right side
			if (!right) {  // right == nullptr
				right = new Bst(d, this);  // get pointer points to this right node
				return right;
			}
			else {
				return right->insert(d);  // do it recursively on the right tree
			}
		}	
	}

	T max() {
		if (!right) {  // right == nullptr
			return data;
		}
		return right->max();
	}

	T min() {
		if (!left) {  // left == nullptr
			return data;
		}
		return left->min();
	}

	Bst<T>* search(const T d) {
		if (d == data) return this;

		else if (d < data) { // look at the left side
			if (!left) {
				return nullptr;
			}
			else {
				return left->search(d);  // do it recursively on the left tree
			}
		}

		else {   // d > data -> look at the right side
			if (!right) {
				return nullptr;
			}
			else {
				return right->search(d);  // do it recursively on the right tree
			}
		}
	}

	Bst<T>* predecessor(const T d) {
		Bst<T>* node = search(d);

		if (node->left) {  // node.left != null
			// return min((node->right).get_val());
			return search(node->left->max());
		}

		else {
			Bst<T>* parent = node->parent;
			while (parent) {  // parent != null
				if (parent->get_val() < node->get_val()) {
					break;
				}
				parent = parent->parent;
			}
			return parent;
		}
	};

	Bst<T>* successor(const T d) {
		Bst<T>* node = search(d);
		if (node->right) {  // node.right != null
			// return min((node->right).get_val());
			return search(node->right->min());

		}
		else {
			Bst<T>* parent = node->parent;
			while (parent) {  // parent != null
				if (parent->get_val() > node->get_val()) {
					break;
				}
				parent = parent->parent;
			}
			return parent;
		}
	};

	T get_val() const {
		return data;
	}

	Bst<T>* find(const T d) const {
		return nullptr;
	}

 private:
	T data;
	Bst* parent;
	Bst* left;
	Bst* right;
};


//template <typename T>
//void print_bst(const Bst<T>& bst) {
//void print_bst(Bst<int> bst) {
//    std::cout << "data: " << bst.data << "; left: ";
//
//    if (!bst.left) std::cout << "nullptr ";
//    else {
//        std::cout << "\t\n";
//        print_bst(*bst.left);
//    }
//    std::cout << "; right: ";
//    if (!bst.right) std::cout << "nullptr ";
//    else {
//        std::cout << "\t\n";
//        print_bst(*bst.right);
//    }
//    std::cout << std::endl;
//}