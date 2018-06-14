#include <bits/stdc++.h>

using namespace std;


class DisjointSet_{
	public:
		vector<int> parent;
		vector<int> rank;
		vector<int> num;
		int n;

		DisjointSet_(int n);
		DisjointSet_();
		void reset(int n);
		void _union(int x, int y);
		int find(int x);
		int find_without_path_compression(int x);
		void print_parent();
		pair<int, int> min_and_max_cc_sizes();
};

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n, g, b;
	cin >> n;
	DisjointSet_ ds(2 * n);
	for(int i = 0; i < n; ++i){
		cin >> g >> b;
		ds._union(g - 1, b - 1);
	}
	pair<int, int> min_max = ds.min_and_max_cc_sizes();
	cout << min_max.first << " " << min_max.second;
	return 0;
}

DisjointSet_::DisjointSet_(int n){
	this->n = n;
	parent.resize(n);
	rank.resize(n, 0);
	num.resize(n, 1);
	for(size_t i = 0; i < n; ++i) parent.at(i) = i;
}

DisjointSet_::DisjointSet_(){
	//Pass
}

void DisjointSet_::reset(int n){
	parent.clear();
	parent.resize(n);
	rank.clear();
	rank.resize(n, 0);
	this->n = n;
	for(size_t i = 0; i < n; ++i) parent.at(i) = i;
}

void DisjointSet_::_union(int x, int y){
	int x_id = find(x);
	int y_id = find(y);
	if(x_id == y_id) return;
	if(rank.at(x_id) < rank.at(y_id)){
		parent.at(x_id) = y_id;
		num.at(y_id) += num.at(x_id);
		num.at(x_id) = 0;
		// rank.at(y) += 1; // This line is wrong. If the rank of y > rank of x the making y the parent of x will not change its rank. Remember: Rank = longest path from root to any leaf
	}
	else{
		parent.at(y_id) = x_id;
		num.at(x_id) += num.at(y_id);
		num.at(y_id) = 0;
		// rank.at(x) += 1; // Just as above, this line is wrong. Rank will only change when two nodes have the same rank and one is made the parent of the other.
		if(rank.at(x_id) == rank.at(y_id)) rank.at(x_id) += 1;
	}
}

int DisjointSet_::find(int x){
	//Implements the path compression heuristic.

	if(x == parent.at(x)) return x;
	else parent.at(x) = find(parent.at(x));
	return parent.at(x);
}

int DisjointSet_::find_without_path_compression(int x){
	while(x != parent.at(x)) x = parent.at(x);
	return x;
}

void DisjointSet_::print_parent(){
	int n = parent.size();
	cout << "\n++++++++++++++++++++++++++";
	cout << "\n";
	for(int i = 0; i < n; ++i){
		cout << "{i = " << i << " : parent(i) = " << parent.at(i) << "}";
		cout << "\n";
	}
	cout << "++++++++++++++++++++++++++\n";
}

pair<int, int> DisjointSet_::min_and_max_cc_sizes(){
	int min = n + 1;
	int max = 1;
	for(int i = 0; i < n; ++i){
		if(num.at(i) < min && num.at(i) > 1){
			min = num.at(i);
		}
		if(num.at(i) > max){
			max = num.at(i);
		}
	}
	return make_pair(min, max);
}


/*
5
1 6 
2 7
3 8
4 9
2 6
*/