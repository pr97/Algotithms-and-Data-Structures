#include <bits/stdc++.h>

using namespace std;

int minimum_jumps(vector<int>& a, int n){
	int min;
	vector<int> dp(n);
	dp.at(n - 1) = 0;
	for(int i = n - 2; i >= 0; --i){
		min = INT_MAX - 1;
		for(int j = i + 1; j <= i + a.at(i) && j <= n - 1; ++j){
			if(min > dp.at(j)){
				min = dp.at(j);
			}

		}
		dp.at(i) = min + 1;
	}
	if(dp.at(0) == INT_MAX)
		return -1;
	return dp.at(0);
}

int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; ++i)
			cin >> a.at(i);
		cout << minimum_jumps(a, n) << "\n";
	}
	return 0;
}