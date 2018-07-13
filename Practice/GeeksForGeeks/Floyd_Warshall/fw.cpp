#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;

class Graph{
	public:
		vector<vector<int> > cost;
		int v;
		Graph(int v, vector<vector<int> > cost){
			this->v = v;
			(this->cost).resize(v);
			for(int i = 0; i < v; ++i){
				for(int j = 0; j < v; ++j){
					// if(cost.at(i).at(j) == 0 && i != j)
					// 	(this->cost).at(i).push_back(inf);
					// else
					// 	(this->cost).at(i).push_back(cost.at(i).at(j));
					(this->cost).at(i).push_back(cost.at(i).at(j));
				}
			}
		}
		vector<vector<int> > floyd_warshall(){
			vector<vector<int> > res = cost;
			for(int k = 0; k < v; ++k){
				for(int i = 0; i < v; ++i){
					for(int j = 0; j < v; ++j){
						if(res.at(i).at(j) > res.at(i).at(k) + res.at(k).at(j))
							res.at(i).at(j) = res.at(i).at(k) + res.at(k).at(j);
					}
				}
			}
			return res;
		}
};

void print_matrix(vector<vector<int> > mat){
	int m = mat.size();
	cout << "\n";
	if(m == 0)
		return;
	int n = mat.at(0).size();
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j)
			cout << mat.at(i).at(j) << " ";
		cout << "\n";
	}
	cout << "\n";
}

void print_matrix_in_line(vector<vector<int> > mat){
	int m = mat.size();
	if(m == 0)
		return;
	int n = mat.at(0).size();
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j)
			cout << mat.at(i).at(j) << " ";
	}
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int v, e, in;
		cin >> v;
		vector<vector<int> > cost(v);
		for(int i = 0; i < v; ++i){
			for(int j = 0; j < v; ++j){
				cin >> in;
				cost.at(i).push_back(in);
			}
		}
		Graph g(v, cost);
		print_matrix_in_line(g.floyd_warshall());
	}
	
	return 0;
}