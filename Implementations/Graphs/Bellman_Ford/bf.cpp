#include <bits/stdc++.h>

using namespace std;

#define inf 0x3f3f3f3f

class Graph{
	public:
		vector<vector<int> > cost;
		vector<int> prev, dist;
		int v;
		Graph(vector<vector<int> > cost){
			this->cost = cost;
			this->v = cost.size();
			(this->prev).resize(v);
			(this->dist).resize(v, inf);
		}
		pair<int, vector<int> > bellman_ford(int src, int dst){
			/*
			* It's better to use adjacency list representation because for eaach iteration of Bellman Ford
			* algorithm, we have to relax each edge and the order doesn't matter. With the implmented matrix
			* representation, for each vertex, we try to relax each incoming edge to that vertex. This is 
			* essentially equivalent to relaxing each edge in a different order. Martrix representation would
			* involve at least O(|v|^3) operations (triple nested loop) while the list representation would
			* involve O(|v||e|) operations and is hence better. 
			*/
			vector<int> dist(v, inf); // After the kth iteration, dist.at(i) contains the shortest distance from 'src' to 'i' via atmost k edges.
			vector<int> prev(v);
			for(int i = 0; i < v; ++i)
				prev.at(i) = i;
			dist.at(src) = 0;
			bool none_relaxed = false;
			for(int k = 1; k < v; ++k){
				none_relaxed = true;

				for(int i = 0; i < v; ++i){ // It's better to use adjancency list representation. See long comment above.
					if(i ==  src)
						continue;
					for(int j = 0; j < v; ++j){ // j is enumerating incoming edges for vertex i.
						if(cost.at(j).at(i) != 0) // Assuming absence of edge is represented by a zero cost. This controversial assumption wouldn't be a concern if adjacency list is used.
							if(dist.at(i) > dist.at(j) + cost.at(j).at(i)){
								dist.at(i) = dist.at(j) + cost.at(j).at(i);
								prev.at(i) = j;
								none_relaxed = false;
							}
					}
				}
				if(none_relaxed)
					break;
			}
			int s_dist = dist.at(dst);
			int p = prev.at(dst);
			vector<int> s_path_rev;
			s_path_rev.push_back(dst);
			while(p != prev.at(p)){
				s_path_rev.push_back(p);
				p = prev.at(p);
			}
			assert(src == p);
			s_path_rev.push_back(src);
			return make_pair(s_dist, s_path_rev);
		}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int v, in;
		cin >> v;
		vector<vector<int> > cost(v);
		for(int i = 0; i < v; ++i){
			for(int j = 0; j < v; ++j){
				cin >> in;
				cost.at(i).push_back(in);
			}
		}
		int src, dst;
		cin >> src >> dst;
		Graph g(cost);
		pair<int, vector<int> > res = g.bellman_ford(src, dst);
		int& s_dist = res.first;
		vector<int>& s_path = res.second;
		cout << s_dist << "\n";
		for(vector<int> :: reverse_iterator i = s_path.rbegin(); i != s_path.rend(); ++i){
			cout << *i << " ";
		}
		cout << "\n";
	}
	return 0;
}