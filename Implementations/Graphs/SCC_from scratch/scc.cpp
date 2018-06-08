#include <bits/stdc++.h>

using namespace std;

/*
INPUT:-
-------
1 0
0 2
2 1
0 3
3 4
*/


template<class T>
void print_vec(vector<T> vec){
	cout << "\nPrinting vector: ";
	for(typename vector<T> :: iterator itr = vec.begin(); itr != vec.end(); ++itr){
		cout << *itr << " ";
	}
	cout << "\n";
}

class DirectedGraph{
	private:
		vector<bool> visited;
		int time;
	public:
		vector<vector<int> > adj;
		int v, e;
		int scc;
		vector<int> preorder, postorder, topologically_sorted, descensing_postorder, scc_num;

		DirectedGraph(int v_in, vector<vector<int> > adj_in, bool reverse_DirectedGraph = false){
			v = v_in;
			if(!reverse_DirectedGraph) adj = adj_in;
			else{
			    adj.resize(adj_in.size());
				for(int i = 0; i < v; ++i){
					for(vector<int> :: iterator itr = adj_in[i].begin(); itr != adj_in[i].end(); ++itr){
						adj[*itr].push_back(i);
					}
				}
			}
			preorder.resize(v);
			postorder.resize(v);
			visited.resize(v, false);
			scc_num.resize(v, 0);

		}

		DirectedGraph(int v_in){
			v = v_in;
			adj.resize(v);
			preorder.resize(v);
			postorder.resize(v);
			visited.resize(v, false);
			scc_num.resize(v, 0);
			scc = 0;
		}

		void add_edge(int x, int y){
			adj[x].push_back(y);
		}

		void previsit(int current_vertex){
			preorder[current_vertex] = time;
			++time;
		}

		void postvisit(int current_vertex){
			postorder[current_vertex] = time;
			descensing_postorder.push_back(current_vertex);
			++time;
		}

		void explore(int current_vertex,
			bool with_previsit = false,
			bool with_postvisit = false,
			bool with_topological_sorting = false,
			bool fill_scc = false){
			visited[current_vertex] = true;
			if(with_previsit) previsit(current_vertex);
			if(fill_scc){
				scc_num[current_vertex] = scc;
			}
			for(vector<int> :: iterator itr = adj[current_vertex].begin(); itr != adj[current_vertex].end(); ++itr){
				if(!visited[*itr]) explore(*itr, with_previsit, with_postvisit, with_topological_sorting, fill_scc);
			}
			if(with_postvisit) postvisit(current_vertex);
			if(with_topological_sorting) topologically_sorted.push_back(current_vertex);
		}

		void DFS(bool with_previsit = false, bool with_postvisit = false, bool with_topological_sorting = false, bool capture_descending_postorder = false){
			visited.clear();
			visited.resize(v, false);
			if(with_previsit || with_postvisit) time = 0;
			for(int i = 0; i < v; ++i){
				if(!visited[i]) explore(i, with_previsit, with_postvisit, with_topological_sorting); //DEBUG FLAG: The final boolean default argument 'fill_scc' has not been passed.
			}
			if(with_topological_sorting) reverse(topologically_sorted.begin(), topologically_sorted.end());
			if(capture_descending_postorder) reverse(descensing_postorder.begin(), descensing_postorder.end());
		}

		

		void SCC(){
			DirectedGraph g_rev(v, adj, true);
			g_rev.DFS(false, true, false, true);
			vector<int> desc_post_in_reversed_DirectedGraph = g_rev.descensing_postorder;
			scc = 0;
			visited.clear();
			visited.resize(v, false);
			for(vector<int> :: iterator itr = desc_post_in_reversed_DirectedGraph.begin(); itr != desc_post_in_reversed_DirectedGraph.end(); ++itr){
				if(!visited[*itr]) explore(*itr, false, false, false, true);
				++scc;
			}
		}

		vector<int> get_scc(){
			DirectedGraph g_rev(v, adj, true);
			g_rev.DFS(false, true, false, true);
			vector<int> desc_post_in_reversed_DirectedGraph = g_rev.descensing_postorder;
			scc = 0;
			visited.clear();
			visited.resize(v, false);
			for(vector<int> :: iterator itr = desc_post_in_reversed_DirectedGraph.begin(); itr != desc_post_in_reversed_DirectedGraph.end(); ++itr){
				if(!visited[*itr]) explore(*itr, false, false, false, true);
				++scc;
			}
			return scc_num;
		}

		void topological_sort(){
			DFS(false, false, true, false);
		}

		vector<int> get_topological_sort(){
			DFS(false, false, true, false);
			return topologically_sorted;
		}
};

int main(){
	DirectedGraph g(5);

    g.add_edge(1, 0);
    g.add_edge(0, 2);
    g.add_edge(2, 1);
    g.add_edge(0, 3);
    g.add_edge(3, 4);

    cout << "\nSCC:-\n";
    print_vec<int>(g.get_scc());
    cout << "\nTopological Sort:-\n";
    print_vec<int>(g.get_topological_sort());

    g.DFS(true, true, true, true);

    cout << "\nPrevisit:-\n";
    print_vec<int>(g.preorder);
    cout << "\nPostvisit:-\n";
    print_vec<int>(g.postorder);
	return 0;
}