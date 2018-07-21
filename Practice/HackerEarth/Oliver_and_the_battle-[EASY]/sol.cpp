#include <bits/stdc++.h>

using namespace std;

string convert_to_key(int x, int y){
    return to_string(x) + string("-") + to_string(y);
}

void explore(int v, vector<vector<int> >& adj, bool visited[], int cc[], int& cc_num, int& c){
	visited[v] = true;
	cc[v] = cc_num;
	++c;
	for(vector<int> :: iterator i = adj.at(v).begin(); i != adj.at(v).end(); ++i){
		if(!visited[*i]){
			explore(*i, adj, visited, cc, cc_num, c);
		}
	}
}
pair<int, int> dfs_modified(vector<vector<int> >& adj){
	int v = adj.size();
	int cc[v];
	bool visited[v] = {};
	int cc_num = 0;
	int max = -1;
	int c = 0;
	for(int i = 0; i < v; ++i){
		if(!visited[i]){
			explore(i, adj, visited, cc, cc_num, c);
			if(c > max)
				max = c;
			++cc_num;
			c = 0;
		}
	}
	return make_pair(cc_num, max);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n, m; // n rows and m columns ((i, j) == 1) represents the presence of a zomni soldier at pos (i, j) in the battlefield).
		int ctr = -1; // At any time there are 'ctr + 1' vertices in the graph.
		int temp;
		cin >> n >> m;
		int arr[n][m];
		unordered_map<string, int> tab;
		vector<vector<int> > adj;
		// 'for loop' takes inpus as well as prepares the adjacency list.
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				cin >> arr[i][j];
				if(arr[i][j]){ // The condition is same as 'arr[i][j] == 1'.
					// cout << i << "-" << j << "\n";
					// assert(tab[convert_to_key(i, j)] == NULL);
					// tab.insert(make_pair(convert_to_key(i, j), ++ctr));
					tab[convert_to_key(i, j)] = ++ctr;
					adj.push_back(vector<int>());
					if(i == 0 && j != 0){ // 0th row, >= 1st column.
						if(arr[i][j - 1]){ // The condition is same as 'arr[i][j] == 1'.
							temp = tab[convert_to_key(i, j - 1)];
							adj.at(temp).push_back(ctr);
							adj.at(ctr).push_back(temp);
						}
					}
					if(i != 0 && j == 0){ // >= 1st row, 0th column.
						if(arr[i - 1][j]){ // The condition is same as 'arr[i][j] == 1'.
							temp = tab[convert_to_key(i - 1, j)];
							adj.at(temp).push_back(ctr);
							adj.at(ctr).push_back(temp);
						}
						if(arr[i - 1][j + 1]){ // The condition is same as 'arr[i][j] == 1'.
							temp = tab[convert_to_key(i - 1, j + 1)];
							adj.at(ctr).push_back(temp);
							adj.at(temp).push_back(ctr);
						}
					}
					if(i != 0 && j == m - 1){
						if(arr[i - 1][j]){ // The condition is same as 'arr[i][j] == 1'.
							temp = tab[convert_to_key(i - 1, j)];
							adj.at(temp).push_back(ctr);
							adj.at(ctr).push_back(temp);
						}
						if(arr[i][j - 1]){ // The condition is same as 'arr[i][j] == 1'.
							temp = tab[convert_to_key(i, j - 1)];
							adj.at(temp).push_back(ctr);
							adj.at(ctr).push_back(temp);
						}
						if(arr[i - 1][j - 1]){ // The condition is same as 'arr[i][j] == 1'.
							temp = tab[convert_to_key(i - 1, j - 1)];
							adj.at(temp).push_back(ctr);
							adj.at(ctr).push_back(temp);
						}
					}
					if(i != 0 && j != 0 && j != m - 1){
						if(arr[i - 1][j]){ // The condition is same as 'arr[i][j] == 1'.
							temp = tab[convert_to_key(i - 1, j)];
							adj.at(temp).push_back(ctr);
							adj.at(ctr).push_back(temp);
						}
						if(arr[i][j - 1]){ // The condition is same as 'arr[i][j] == 1'.
							temp = tab[convert_to_key(i, j - 1)];
							adj.at(temp).push_back(ctr);
							adj.at(ctr).push_back(temp);
						}
						if(arr[i - 1][j - 1]){ // The condition is same as 'arr[i][j] == 1'.
							temp = tab[convert_to_key(i - 1, j - 1)];
							adj.at(temp).push_back(ctr);
							adj.at(ctr).push_back(temp);
						}
						if(arr[i - 1][j + 1]){
							temp = tab[convert_to_key(i - 1, j + 1)];
							adj.at(temp).push_back(ctr);
							adj.at(ctr).push_back(temp);
						}
					}
				}
			}
		}
		pair<int, int> res = dfs_modified(adj);
		cout << res.first << " " << res.second << "\n";
	}	
	return 0;
}