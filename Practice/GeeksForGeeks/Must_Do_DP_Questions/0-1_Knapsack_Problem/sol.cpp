#include <bits/stdc++.h>

using namespace std;

int max(vector<int> val, vector<int> wt, int n, int w){
	int max_val[n + 1][w + 1];
	for(int i = 0; i <= n; ++i){
		for(int j = 0; j <= w; ++j){
			if(i == 0)
				max_val[i][j] = 0;
			else if(j == 0)
				max_val[i][j] = 0;
			else if(j - wt[i - 1] < 0)
				max_val[i][j] = max_val[i - 1][j];
			else
				max_val[i][j] = max(max_val[i - 1][j - wt[i - 1]] + val[i - 1], max_val[i - 1][j]);
		}
	}

	return max_val[n][w];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int w;
		cin >> w;
		vector<int> val(n);
		vector<int> wt(n);
		for(int i = 0; i < n; ++i)
			cin >> val.at(i);
		for(int i = 0; i < n; ++i)
			cin >> wt.at(i);
		cout << max(val, wt, n, w) << "\n";
	}
	return 0;
}