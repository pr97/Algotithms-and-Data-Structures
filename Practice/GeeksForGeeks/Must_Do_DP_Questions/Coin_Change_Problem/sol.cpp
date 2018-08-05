#include <bits/stdc++.h>

using namespace std;

int num_ways_to_make_change(vector<int>& A, int m, int n){
    vector<int> a = A;
	int dp[n + 1][m + 1];
	for(int j = m; j >= 0; --j){
		dp[0][j] = 1;
	}
	for(int i = 1; i <= n; ++i){
		dp[i][m] = 0;
	}
	for(int i = 1; i <= n; ++i){
		for(int j = m - 1; j >= 0; --j){
			if(i - a[j] >= 0){
				dp[i][j] = dp[i][j + 1] + dp[i - a[j]][j];	
			}
			else{
				dp[i][j] = dp[i][j + 1];
			}
		}
	}
	return dp[n][0];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int m, n;
		cin >> m;
		vector<int> a(m);
		for(int i = 0; i < m; ++i)
			cin >> a.at(i);
		cin >> n;
		cout << num_ways_to_make_change(a, m, n) << "\n";
	}
	return 0;
}