#include <bits/stdc++.h>

using namespace std;

int lcs_length(string& a, string& b, int n, int m){
	int dp[n + 1][m + 1];
	for(int i = 0; i <= n; ++i)
		dp[i][0] = 0;
	for(int j = 0; j <= m; ++j)
		dp[0][j] = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			if(a.at(i - 1) == b.at(j - 1)){
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);	
			}
		}
// 		cout << "\n";
	}
	return dp[n][m];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		cin.ignore();
		string a, b;
		getline(cin, a);
		getline(cin, b);
		cout << lcs_length(a, b, n, m) << "\n";
	}
	return 0;
}