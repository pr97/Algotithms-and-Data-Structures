#include <bits/stdc++.h>

using namespace std;

vector<int> postvisit_order;

template<class T>
void print_vec(vector<T> vec){
	cout << "\nPrinting vector: ";
	for(typename vector<T> :: iterator itr = vec.begin(); itr != vec.end(); ++itr){
		cout << *itr << " ";
	}
	cout << "\n";
}

void print_adjacency_list(vector<vector<int> >);
vector<int> SCC_using_dfs(vector<vector<int> >&);
void explore_SCC(int, vector<bool>&, vector<vector<int> >&, vector<int>&, int&);

vector<int> post_using_dfs(vector<vector<int> >&);
void explore_with_pre_post(int, vector<bool>&, vector<vector<int> >&, vector<int>&, vector<int>&, int&);
void previsit(int, vector<int>&, int&);
void postvisit(int, vector<int>&, int&);

int main(){
	int v, e, x, y;

	cin >> v >> e;
	
	vector<vector<int> > adj(v);
	vector<int> scc_num;

	for(int i = 0; i < e; ++i){
		cin >> x >> y;
		adj[x].push_back(y);
	}

	cout << "\nAdjacency List:-\n";
	print_adjacency_list(adj);

	scc_num = SCC_using_dfs(adj);

	cout << "\n----\n";
	print_vec<int>(scc_num);
	return 0;
}

vector<int> SCC_using_dfs(vector<vector<int> >& adj){ //Remember to check if passing by ref multiple times is the cause if error.
	post_using_dfs(adj);

	int v = adj.size();
	vector<bool> visited(v, false);
	vector<int> scc_num(v);
	int scc = 0;

	print_vec<bool>(visited);
	
	cout << "\nPerforming DFS on Graph...\n";
	for(vector<int> :: iterator itr = postvisit_order.begin(); itr != postvisit_order.end(); ++itr){
		cout << "\n*" << *itr;
		if(!visited[*itr]){
			explore_SCC(*itr, visited, adj, scc_num, scc);
			++scc;
		}
	}

	//Added to dfs only for viewing the output
	print_vec<bool>(visited);
	return scc_num;
}

void explore_SCC(int current_vertex, vector<bool>& visited, vector<vector<int> >& adj, vector<int>& scc_num, int& scc){
	visited[current_vertex] = true;
	scc_num[current_vertex] = scc;
	cout << "Exploring vertex " << current_vertex << "\n";
	for(vector<int> :: iterator itr = adj[current_vertex].begin(); itr != adj[current_vertex].end(); ++itr){
		if(!visited[*itr]) explore_SCC(*itr, visited, adj, scc_num, scc);
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

void explore_with_pre_post(int current_vertex, vector<bool>& visited, vector<vector<int> >& adj, vector<int>& pre, vector<int>& post, int& time){
	visited[current_vertex] = true;
	previsit(current_vertex, pre, time);
	cout << "Exploring vertex " << current_vertex << "\n";
	for(vector<int> :: iterator itr = adj[current_vertex].begin(); itr != adj[current_vertex].end(); ++itr){
		if(!visited[*itr]) explore_with_pre_post(*itr, visited, adj, pre, post, time);
	}
	postvisit(current_vertex, post, time);
}

void previsit(int current_vertex, vector<int>& pre, int& time){
	pre[current_vertex] = time;
	++time;
}

void postvisit(int current_vertex, vector<int>& post, int& time){
	post[current_vertex] = time;
	++time;
	postvisit_order.push_back(current_vertex);
}

vector<int> post_using_dfs(vector<vector<int> >& adj){ //Remember to check if passing by ref multiple times is the cause if error.
	int v = adj.size();
	vector<bool> visited(v, false);
	vector<int> pre(v);
	vector<int> post(v);
	int time = 0;
	print_vec<bool>(visited);
	cout << "\nPerforming DFS on Graph...\n";
	for(int i = 0; i < v; ++i){
		if(!visited[i]) explore_with_pre_post(i, visited, adj, pre, post, time);
	}

	//Added to dfs only for viewing the output
	print_vec<bool>(visited);

	return post;
}