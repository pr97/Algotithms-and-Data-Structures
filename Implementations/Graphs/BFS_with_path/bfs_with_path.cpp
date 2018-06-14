#include <bits/stdc++.h>

#define INF 999999

using namespace std;

void print_list(list<int> l){
	cout << "\n";
	for(list<int> :: iterator itr = l.begin(); itr != l.end(); ++itr){
		cout << *itr << " ";
	}
	cout << "\n";
}

void print_vec(vector<int> vec){
	cout << "\n";
	for(vector<int> :: iterator itr = vec.begin(); itr != vec.end(); ++itr){
		cout << *itr << " ";
	}
	cout << "\n";
}
class Graph{
	public:
		vector<vector<int> > adj;
		int v, e;
		bool directed;
		vector<int> dist, prev;
		Graph(int v, bool directed = false){
			adj.resize(v);
			dist.resize(v);
			prev.resize(v);
			this->v = v;
			this->e = 0;
			this->directed = directed;
		}

		void add_edge(int x, int y){
			++e;
			if(directed){
				adj[x].push_back(y);
			}
			else{
				adj[x].push_back(y);
				adj[y].push_back(x);
			}
		}

		void BFS_with_path(int s){
			int curr;
			for(size_t i = 0; i < v; ++i){
				dist[i] = INF;
				prev[i] = i;
			}
			queue<int> q;
			dist[s] = 0;
			q.push(s);
			while(!q.empty()){
				curr = q.front();
				// cout << curr << "\n"; 
				q.pop();
				for(vector<int> :: iterator itr = adj[curr].begin(); itr != adj[curr].end(); ++itr){
					if(dist[*itr] == INF){
						q.push(*itr);
						dist[*itr] = dist[curr] + 1;
						prev[*itr] = curr;
					}
				}
			}
		}

		list<int> get_shortest_distance_path(int s, int v){
			//BFS_with_path(s);
			list<int> l;
			l.push_back(v);
			while(v != prev[v]){
				// cout << "*" << v;
				v = prev[v];
				l.push_back(v);
			}
			reverse(l.begin(), l.end());
			return l;
		}

};

int main(){
	Graph g(13);
	g.add_edge(0, 2);
	g.add_edge(0, 1);
	g.add_edge(0, 3);
	g.add_edge(0, 3);
	g.add_edge(1, 2);
	g.add_edge(1, 3);
	g.add_edge(2, 3);
	g.add_edge(4, 1);
	g.add_edge(1, 5);
	g.add_edge(5, 3);
	g.add_edge(6, 3);
	g.add_edge(2, 6);
	g.add_edge(2, 4);
	g.add_edge(4, 7);
	g.add_edge(7, 5);
	g.add_edge(5, 8);
	g.add_edge(8, 6);
	g.add_edge(6, 9);
	g.add_edge(9, 4);
	g.add_edge(10, 7);
	g.add_edge(7, 11);
	g.add_edge(11, 8);
	g.add_edge(8, 12);
	g.add_edge(12, 9);
	g.add_edge(9, 10);
	g.add_edge(0, 3);
	g.BFS_with_path(0);
	print_vec(g.prev);
	print_list(g.get_shortest_distance_path(0, 8));

	return 0;
}