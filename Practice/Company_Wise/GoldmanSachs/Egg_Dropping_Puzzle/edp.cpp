#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n, k, minimum;
		cin >> n >> k;
		int dp[n + 1][k + 1];
		for(int i = 1; i <= n; ++i)
			dp[i][0] = 0;
		for(int j = 1; j <= k; ++j)
			dp[1][j] = j;
		for(int i = 2; i <= n; ++i){
			for(int j = 1; j <= k; ++j){
				if(i > j){
					dp[i][j] = dp[i - 1][j];
				}
				else{
					minimum = INT_MAX;
					for(int f = 1; f <= j; ++f){
						dp[i][j] = 1 + min(minimum, max(dp[i - 1][f - 1], dp[i][j - f]));
						minimum = (minimum < max(dp[i - 1][f - 1], dp[i][j - f]))? minimum : max(dp[i - 1][f - 1], dp[i][j - f]);
					}
				}
			}
		}
		cout << dp[n][k] << "\n";
	}
	return 0;
}