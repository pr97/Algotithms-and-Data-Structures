#include <bits/stdc++.h>

using namespace std;

int a[(int)1e5];
int dp[(int)1e5];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0; i < n; ++i){
			cin >> a[i];
		}
		dp[n - 1] = 1;
		for(int i = n - 2; i >= 0; --i){
			if(a[i] > 0 ^ a[i + 1] > 0)
				dp[i] = dp[i + 1] + 1;
			else
				dp[i] = 1;
		}
		for(int i = 0; i < n; ++i){
			cout << dp[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}