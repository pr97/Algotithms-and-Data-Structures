#include <bits/stdc++.h>

using namespace std;

template<class T>
void print_vec(vector<T> vec, bool print_index = false){
	int n = vec.size();
	cout << "\nPrinting vector: ";
	for(typename vector<T> :: iterator itr = vec.begin(); itr != vec.end(); ++itr){
		cout << *itr << " ";
	}
	cout << "\n";
	if(print_index){
		for(int i = 0; i < n; ++i) cout << "[" << i << "]";
		cout << "\n";
	}
}

class DisjointSet{
	public:
		vector<int> parent;
		vector<int> rank;
		int n;

		DisjointSet(int n);
		DisjointSet();
		void reset(int n);
		void _union(int x, int y);
		int find(int x);
		int find_without_path_compression(int x);
		void print_parent();
};

int main(){
	DisjointSet disjoint_set(6);
	cout << disjoint_set.find(2) << "\n";
	cout << disjoint_set.find(3) << "\n";
	disjoint_set._union(1, 2);
	disjoint_set._union(4, 5);
	disjoint_set.print_parent();
	disjoint_set._union(2, 4);
	disjoint_set._union(2, 5);
	disjoint_set.print_parent();
	return 0;
}

DisjointSet::DisjointSet(int n){
	this->n = n;
	parent.resize(n);
	rank.resize(n, 0);
	for(size_t i = 0; i < n; ++i) parent.at(i) = i;
}

DisjointSet::DisjointSet(){
	//Pass
}

void DisjointSet::reset(int n){
	parent.clear();
	parent.resize(n);
	rank.clear();
	rank.resize(n, 0);
	this->n = n;
	for(size_t i = 0; i < n; ++i) parent.at(i) = i;
}

void DisjointSet::_union(int x, int y){
	int x_id = find(x);
	int y_id = find(y);
	if(x_id == y_id) return;
	if(rank.at(x_id) < rank.at(y_id)){
		parent.at(x_id) = y_id;
		// rank.at(y) += 1; // This line is wrong. If the rank of y > rank of x the making y the parent of x will not change its rank. Remember: Rank = longest path from root to any leaf
	}
	else{
		parent.at(y_id) = x_id;
		// rank.at(x) += 1; // Just as above, this line is wrong. Rank will only change when two nodes have the same rank and one is made the parent of the other.
		if(rank.at(x_id) == rank.at(y_id)) rank.at(x_id) += 1;
	}
}

int DisjointSet::find(int x){
	//Implements the path compression heuristic.

	if(x == parent.at(x)) return x;
	else parent.at(x) = find(parent.at(x));
	return parent.at(x);
}

int DisjointSet::find_without_path_compression(int x){
	while(x != parent.at(x)) x = parent.at(x);
	return x;
}

void DisjointSet::print_parent(){
	int n = parent.size();
	cout << "\n++++++++++++++++++++++++++";
	cout << "\n";
	for(int i = 0; i < n; ++i){
		cout << "{i = " << i << " : parent(i) = " << parent.at(i) << "}";
		cout << "\n";
	}
	cout << "++++++++++++++++++++++++++\n";
}