#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;

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

struct adjacency_list_element{
	int edge_cost;
	int terminal_vertex;
};

class compare{
	public:
		bool operator() (pair<int, pair<int, int> > a, pair<int, pair<int, int> > b){
			if(a.first == b.first)
				return a.first + a.second.first + a.second.second <= b.first + b.second.first + b.second.second;
			else
				return a.first < b.first;
		}
};

class Graph{
	public:
		vector<vector<adjacency_list_element> > cost_adj_list;
		int v;
		set<pair<int, pair<int, int> >, compare> sorted_edges;
		set<pair<int, int> > mst_set;
		int mst_sum;
		DisjointSet ds;
		Graph(int v){
			cost_adj_list.resize(v);
			this->v = v;
			ds = DisjointSet(v);
			mst_sum = 0;
		}
		void add_edge(int source_vertex, int terminal_vertex, int edge_cost){
			adjacency_list_element temp = {edge_cost, terminal_vertex};
			cost_adj_list.at(source_vertex).push_back(temp);
			temp.terminal_vertex = source_vertex;
			cost_adj_list.at(terminal_vertex).push_back(temp);
			sorted_edges.insert(make_pair(edge_cost, make_pair(terminal_vertex, source_vertex)));
		}
		int kruskals(){
			int ctr = 0;
			for(set<pair<int, pair<int, int> > > :: iterator itr = sorted_edges.begin(); itr != sorted_edges.end(); ++itr){
				if(ds.find((itr->second).first) != ds.find((itr->second).second)){
					++ctr;
					mst_set.insert(make_pair((itr->second).first, (itr->second).second));
					mst_sum += itr->first;
					ds._union((itr->second).first, (itr->second).second);
				}
			}
			if(ctr != v - 1) return -1;
			else return mst_sum;
		}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	Graph g(n);
	int x, y, r;
	for(int i = 0; i < m; ++i){
		cin >> x >> y >> r;
		g.add_edge(x - 1, y - 1, r); // 1 is subtracted because the question's input format follows '1' based indexing.
	}
	cout << g.kruskals();
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