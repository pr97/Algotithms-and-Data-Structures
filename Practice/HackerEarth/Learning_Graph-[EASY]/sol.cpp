#include <bits/stdc++.h>

using namespace std;

int partition_modified(vector<int>& v, int l, int r, vector<int>& key){
	int pivot = rand() % (r - l + 1) + l;
	swap(v.at(pivot), v.at(r));
	pivot = r;
	int i = l - 1;
	for(int j = l; j <= r - 1; ++j){
		if(key[v.at(j)] > key[v.at(pivot)]){ // DESCENDING ORDER.
			++i;
			swap(v.at(i), v.at(j));
		}
		else if(key[v.at(j)] == key[v.at(pivot)]){
			if(v.at(j) > v.at(pivot)){ // DESCENDING ORDER.
				++i;
				swap(v.at(i), v.at(j));
			}
		}
	}
	swap(v.at(pivot), v.at(i + 1));
	pivot = i + 1;
	return pivot; 
}

void quick_sort_modified(vector<int>& v, int l, int r, vector<int>& key){
	if(l < r){
		int p = partition_modified(v, l, r, key);
		quick_sort_modified(v, l, p - 1, key);
		quick_sort_modified(v, p + 1, r, key);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k, in1, in2;
	cin >> n >> m >> k;
	vector<vector<int> > adj(n + 1);
	vector<int> val(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> val[i];
		adj.at(i).push_back(0);
	}
	for(int i = 0; i < m; ++i){
		cin >> in1 >> in2;
		adj.at(in1).push_back(in2);
		adj.at(in2).push_back(in1);
	}

	// Solution code.
	for(int i = 1; i <= n; ++i){
		if(k >= adj.at(i).size()){ // k follows 1-indexing.
			cout << -1 << "\n";
			continue;
		}
		quick_sort_modified(adj.at(i), 1, adj.at(i).size() - 1, val);
		cout << adj.at(i).at(k) << "\n";
	}
	return 0;
}