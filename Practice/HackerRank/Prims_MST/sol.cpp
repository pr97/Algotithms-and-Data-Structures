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
				if(!visited.at(curr.second)){
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
				}
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
	int n, m;
	cin >> n >> m;
	Graph g(n);
	int x, y, r;
	for(int i = 0; i < m; ++i){
		cin >> x >> y >> r;
		g.add_edge(x - 1, y - 1, r); // 1 is subtracted because the question's input format follows '1' based indexing.
	}
	int not_required;
	cin >> not_required;
	pair<int, vector<int> > result = g.prims();
	cout << result.first << "\n";
	return 0;
}