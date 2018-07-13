#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;

struct adjacency_list_element{
	int edge_cost;
	int terminal_vertex;
};

class Graph{
	public:
		vector<vector<adjacency_list_element> > cost_adj_list;
		int v;
		Graph(int v){
			cost_adj_list.resize(v);
			this->v = v;
		}
		void add_edge(int source_vertex, int terminal_vertex, int edge_cost){
			adjacency_list_element temp = {edge_cost, terminal_vertex};
			cost_adj_list.at(source_vertex).push_back(temp);
			temp.terminal_vertex = source_vertex;
			cost_adj_list.at(terminal_vertex).push_back(temp);
		}
		pair<int, vector<int> > prims(){
			vector<int> parent(v);
			int mst_sum = 0;
			for(int i = 0; i < v; ++i)
				parent.at(i) = i;
			vector<bool> visited(v, false);
			priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
			vector<int> near(v, inf);
			for(int i = 0; i < v; ++i)
				q.push(make_pair(near.at(i), i));
			q.push(make_pair(0, 0));
			while(!q.empty()){
				pair<int, int> curr = q.top();
				q.pop(); // IMP: Pop right after extraction to avoid serious bug!!!
				if(visited.at(curr.second)){
					q.pop();
					continue;
				}
				int u = curr.second, near_u = curr.first;
				mst_sum += near_u;
				visited.at(u) = true;
				for(vector<adjacency_list_element> :: iterator i = cost_adj_list.at(u).begin(); i != cost_adj_list.at(u).end(); ++i){
					if(!visited.at(i->terminal_vertex)){
						if(near.at(i->terminal_vertex) > i->edge_cost){
							parent.at(i->terminal_vertex) = u;
							near.at(i->terminal_vertex) = i->edge_cost;
							q.push(make_pair(i->edge_cost, i->terminal_vertex));
						}
					}
				}
				// q.pop(); // REMEMBER TO POP RIGHT AFTER MIN_EXTRACTION AND *NOT* HERE.
			}
			return make_pair(mst_sum, parent);
		}

};

void print_vec(vector<int> v){
	int n = v.size();
	cout << "\n";
	for(int i = 0; i < n; ++i)
		cout << v.at(i) << " ";
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Graph g(6); // pass '4' as argument for TEST_CASE_1 and '6' as argument for TEST_CASE_2.
	// TEST_CASE_1 | Expected mst_sum = 4 | Expected parent array = {0, 0, 0, 2}
	// g.add_edge(0, 2, 2);
	// g.add_edge(0, 3, 3);
	// g.add_edge(0, 1, 1);
	// g.add_edge(1, 3, 2);
	// g.add_edge(3, 2, 1);
	// -------------------------------------------------------------------------
	// TEST_CASE_2 | Expected mst_sum = 14 | Expected parent array = {}
	g.add_edge(0, 1, 4);
	g.add_edge(0, 4, 1);
	g.add_edge(0, 3, 2);
	g.add_edge(3, 4, 3);
	g.add_edge(1, 4, 5);
	g.add_edge(1, 2, 8);
	g.add_edge(1, 5, 6);
	g.add_edge(4, 5, 9);
	g.add_edge(2, 5, 1);
	// -------------------------------------------------------------------------
	pair<int, vector<int> > result = g.prims();
	cout << result.first << "\n--";
	print_vec(result.second);
	return 0;
}