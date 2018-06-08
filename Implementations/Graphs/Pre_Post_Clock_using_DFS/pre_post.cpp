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
pair<vector<int>, vector<int> > pre_post_using_dfs(vector<vector<int> >&);
void explore(int, vector<bool>&, vector<vector<int> >&, vector<int>&, vector<int>&, int&);
void previsit(int, vector<int>&, int&);
void postvisit(int, vector<int>&, int&);

int main(){
	int v, e, x, y;

	cin >> v >> e;
	
	vector<vector<int> > adj(v);
	pair<vector<int>, vector<int> > pre_post;

	for(int i = 0; i < e; ++i){
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	cout << "\nAdjacency List:-\n";
	print_adjacency_list(adj);

	pre_post = pre_post_using_dfs(adj);
	cout << "\n------------------\n";
	print_vec<int>(pre_post.first);
	print_vec<int>(pre_post.second);
	return 0;
}

void previsit(int current_vertex, vector<int>& pre, int& time){
	pre[current_vertex] = time;
	++time;
}

void postvisit(int current_vertex, vector<int>& post, int& time){
	post[current_vertex] = time;
	++time;
}

pair<vector<int>, vector<int> > pre_post_using_dfs(vector<vector<int> >& adj){ //Remember to check if passing by ref multiple times is the cause if error.
	int v = adj.size();
	vector<bool> visited(v, false);
	vector<int> pre(v);
	vector<int> post(v);
	int time = 0;
	print_vec<bool>(visited);
	cout << "\nPerforming DFS on Graph...\n";
	for(int i = 0; i < v; ++i){
		if(!visited[i]) explore(i, visited, adj, pre, post, time);
	}

	//Added to dfs only for viewing the output
	print_vec<bool>(visited);

	return make_pair(pre, post);
}

void explore(int current_vertex, vector<bool>& visited, vector<vector<int> >& adj, vector<int>& pre, vector<int>& post, int& time){
	visited[current_vertex] = true;
	previsit(current_vertex, pre, time);
	cout << "Exploring vertex " << current_vertex << "\n";
	for(vector<int> :: iterator itr = adj[current_vertex].begin(); itr != adj[current_vertex].end(); ++itr){
		if(!visited[*itr]) explore(*itr, visited, adj, pre, post, time);
	}
	postvisit(current_vertex, post, time);
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