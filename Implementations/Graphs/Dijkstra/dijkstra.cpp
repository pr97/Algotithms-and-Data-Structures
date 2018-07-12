#include <bits/stdc++.h>

#define inf 99999999

using namespace std;

class compare{
	public:
		bool operator() (pair<int, int> a, pair<int, int> b){
			if(a.first == b.first){
				return a.second > b.second;
			}
			else{
				return a.first > b.first;
			}
		}
};

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
		pair<int, vector<int> > dijkstra(int src, int dst){
			for(int i = 0; i < v; ++i)
				prev.at(i) = i;
			vector<bool> visited(v, false);
			priority_queue<pair<int, int>, vector<pair<int, int> >, compare> heap;
			heap.push(make_pair(0, src));

			for(int i = 1; i < v; ++i)
				heap.push(make_pair(inf, i));
			
			while(!heap.empty()){
				pair<int, int> node = heap.top();
				if(!visited.at(node.second)){
					visited.at(node.second) = true;
					int u = node.second;
					dist.at(u) = node.first;
					for(int j = 0; j < v; ++j){
						if(cost.at(u).at(j) != 0){ // HackerEarth input format uses 0 in cost matrix to denote absence of direct edge.
							if(dist.at(j) > dist.at(u) + cost.at(u).at(j)){
								dist.at(j) = dist.at(u) + cost.at(u).at(j);
								prev.at(j) = u;
								heap.push(make_pair(dist.at(j), j));
							}
						}
					}
				}
				heap.pop();
			}
			int shortest_distance = dist.at(dst);
			int p = prev.at(dst);
			vector<int> path;
			path.push_back(dst);
			while(p != prev.at(p)){
				path.push_back(p);
				p = prev.at(p);
			}
			assert(p == src);
			path.push_back(p);
			return make_pair(shortest_distance, path);	
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
		pair<int, vector<int> > res = g.dijkstra(src, dst);
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