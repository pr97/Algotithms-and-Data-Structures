/*
* Link to Question: https://practice.geeksforgeeks.org/problems/subset-sum-problem/0
*/


#include <bits/stdc++.h>

using namespace std;

bool partionable(vector<int>& a, int n){
	int T = 0;
	int S;
	for(auto i : a)
		T += i;
	if(T % 2 == 1)
		return false;
	S = T / 2;
	bool dp[n + 1][S + 1];
	for(int j = 1; j <= S; ++j)
		dp[0][j] = false;
	for(int i = 0; i <= n; ++i)
		dp[i][0] = true;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= S; ++j){
			if(j - a[i - 1] >= 0)
				dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i - 1]];
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	return dp[n][S];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; ++i)
			cin >> a.at(i);

		if(partionable(a, n))
			cout << "YES";
		else
			cout << "NO";
		cout << "\n";
	}
	return 0;
}