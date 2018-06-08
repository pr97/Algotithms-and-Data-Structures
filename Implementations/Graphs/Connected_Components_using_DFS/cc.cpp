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
vector<int> connected_components_using_dfs(vector<vector<int> >&);
void explore(int, vector<bool>&, vector<vector<int> >&, vector<int>&, int&);

int main(){
	int v, e, x, y;

	cin >> v >> e;
	
	vector<vector<int> > adj(v);
	vector<int> cc_num;

	for(int i = 0; i < e; ++i){
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x); //For directed graph, comment this line out.
	}

	cout << "\nAdjacency List:-\n";
	print_adjacency_list(adj);

	cc_num = connected_components_using_dfs(adj);
	print_vec<int>(cc_num);
	return 0;
}

vector<int> connected_components_using_dfs(vector<vector<int> >& adj){ //Remember to check if passing by ref multiple times is the cause if error.
	int v = adj.size();
	vector<int> cc_num(v);
	vector<bool> visited(v, false);
	print_vec<bool>(visited);
	int cc = 0; //Has been set to 0 for zero indexing the connected components. Set to 1 for one indexing.
	cout << "\nPerforming DFS on Graph...\n";
	for(int i = 0; i < v; ++i){
		if(!visited[i]){
			explore(i, visited, adj, cc_num, cc);
			++cc;
		}
	}

	//Added to dfs only for viewing the output
	print_vec<bool>(visited);

}

void explore(int current_vertex, vector<bool>& visited, vector<vector<int> >& adj, vector<int>& cc_num, int& cc){
	visited[current_vertex] = true;
	cout << "Exploring vertex " << current_vertex << "(cc_num = " << cc << ")" << "\n";
	cc_num[current_vertex] = cc;
	for(vector<int> :: iterator itr = adj[current_vertex].begin(); itr != adj[current_vertex].end(); ++itr){
		if(!visited[*itr]) explore(*itr, visited, adj, cc_num, cc);
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