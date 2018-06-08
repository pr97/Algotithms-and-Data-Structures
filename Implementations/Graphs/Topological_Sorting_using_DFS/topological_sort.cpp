#include <bits/stdc++.h>

using namespace std;

/*
INPUT:-
-------
11 11
0 1
0 2
1 3
1 2
3 4
4 5
5 7
5 6
7 8
8 9
8 10
*/

template<class T>
void print_vec(vector<T> vec){
	cout << "\nPrinting vector: ";
	for(typename vector<T> :: iterator itr = vec.begin(); itr != vec.end(); ++itr){
		cout << *itr << " ";
	}
	cout << "\n";
}

void print_adjacency_list(vector<vector<int> >);
void dfs_modified_for_topological_sorting(vector<vector<int> >&, vector<int>&);
void explore_modified_for_topological_sorting(int, vector<bool>&, vector<vector<int> >&, vector<int>&);
vector<int> topological_sort(vector<vector<int> >&);

int main(){
	int v, e, x, y;

	cin >> v >> e;
	
	vector<vector<int> > adj(v);
	vector<int> topologically_sorted_result;

	for(int i = 0; i < e; ++i){
		cin >> x >> y;
		adj[x].push_back(y);
		// adj[y].push_back(x); //Has been commented out because we can only topologically sort a DAG. Inclusion of this line would have meant the construction of an adjacency list representing an undirected graph.
	}

	cout << "\nAdjacency List:-\n";
	print_adjacency_list(adj);

	topologically_sorted_result = topological_sort(adj);

	print_vec<int>(topologically_sorted_result);

	return 0;
}

vector<int> topological_sort(vector<vector<int> >& adj){
	vector<int> ts;
	dfs_modified_for_topological_sorting(adj, ts);
	reverse(ts.begin(), ts.end());

	return ts;
}

void dfs_modified_for_topological_sorting(vector<vector<int> >& adj, vector<int>& ts){ //Remember to check if passing by ref multiple times is the cause if error.
	int v = adj.size();
	vector<bool> visited(v, false);
	print_vec<bool>(visited);
	cout << "\nPerforming DFS on Graph...\n";
	for(int i = 0; i < v; ++i){
		if(!visited[i]) explore_modified_for_topological_sorting(i, visited, adj, ts);
	}

	//Added to dfs only for viewing the output
	print_vec<bool>(visited);

}

void explore_modified_for_topological_sorting(int current_vertex, vector<bool>& visited, vector<vector<int> >& adj, vector<int>& ts){
	visited[current_vertex] = true;
	cout << "Exploring vertex " << current_vertex << "\n";
	for(vector<int> :: iterator itr = adj[current_vertex].begin(); itr != adj[current_vertex].end(); ++itr){
		if(!visited[*itr]) explore_modified_for_topological_sorting(*itr, visited, adj, ts);
	}
	ts.push_back(current_vertex);
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