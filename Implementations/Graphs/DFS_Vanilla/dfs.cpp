#include <bits/stdc++.h>

using namespace std;

template<class T>
void print_vec(vector<T> vec){
	cout << "\nPrinting vector: ";
	for(typename vector<T> :: iterator itr = vec.begin(); itr != vec.end(); ++itr){
		cout << *itr << " ";
	}
	cout << "\n";
}

void print_adjacency_list(vector<vector<int> >);
void dfs(vector<vector<int> >&);
void explore(int, vector<bool>&, vector<vector<int> >&);

int main(){
	int v, e, x, y;

	cin >> v >> e;
	
	vector<vector<int> > adj(v);

	for(int i = 0; i < e; ++i){
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	cout << "\nAdjacency List:-\n";
	print_adjacency_list(adj);

	dfs(adj);

	return 0;
}

void dfs(vector<vector<int> >& adj){ //Remember to check if passing by ref multiple times is the cause if error.
	int v = adj.size();
	vector<bool> visited(v, false);
	print_vec<bool>(visited);
	cout << "\nPerforming DFS on Graph...\n";
	for(int i = 0; i < v; ++i){
		if(!visited[i]) explore(i, visited, adj);
	}

	//Added to dfs only for viewing the output
	print_vec<bool>(visited);

}

void explore(int current_vertex, vector<bool>& visited, vector<vector<int> >& adj){
	visited[current_vertex] = true;
	cout << "Exploring vertex " << current_vertex << "\n";
	for(vector<int> :: iterator itr = adj[current_vertex].begin(); itr != adj[current_vertex].end(); ++itr){
		if(!visited[*itr]) explore(*itr, visited, adj);
	}
}

void print_adjacency_list(vector<vector<int> > adj){
	int ctr = 0;
	for(vector<vector<int> > :: iterator itr = adj.begin(); itr != adj.end(); ++itr){
		cout << "\n" << ctr << "> ";
		++ctr;
		for(vector<int> :: iterator it = (*itr).begin(); it != (*itr).end(); ++it){
			cout << *it << " ";
		}
	}
}