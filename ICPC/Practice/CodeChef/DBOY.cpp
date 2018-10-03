#include <bits/stdc++.h>

using namespace std;

#define seqin(a,n) for(int i = 0; i < n; ++i) cin >> a[i]
#define seqin_1ind(a,n) for(int i = 1; i <= n; ++i) cin >> a[i]
#define seqout(a,n) for(int i = 0; i < n; ++i) cout << a[i] << " "
#define seqout_1ind(a,n) for(int i = 1; i <= n; ++i) cout << a[i] << " "
#define subseqout(a,x,y) for(int i = x; i <= y; ++i) cout << a[i] << " "

#define ll long long
#define inf INT_MAX / 10

int h[501];
int k[501];

int dp[501][1001];

void set_dp_base_cases(){
	for(int i = 0; i < 1001; ++i){
		dp[0][i] = inf;
	}
	for(int i = 0; i < 501; ++i){
		dp[i][0] = 0;
	}
}

void populate_dp(int n, int s){
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= 1000; ++j){
			if(j - k[i] >= 0){
				dp[i][j] = min(dp[i - 1][j], dp[i][j - k[i]] + 1);
			}
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n;
	cin >> t;
	set_dp_base_cases();
	while(t--){
		cin >> n;
		seqin_1ind(h,n);
		seqin_1ind(k,n);
		int M = INT_MIN;
		for(int i = 1; i <= n; ++i){
			M = max(M, h[i]);
		}
		// sort(k + 1, k + n + 1, greater<int>()); // Not required. The DP population routine takes care of minimization.
		populate_dp(n, 2 * M);
		int ctr = 0;
		for(int i = 1; i <= n; ++i){
			ctr += dp[n][2 * h[i]];
		}
		cout << ctr << "\n";
	}
	return 0;
}