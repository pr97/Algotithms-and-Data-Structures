#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n, x;
		cin >> n >> x;
		vector<int> c(n);
		for(int i = 0; i < n; ++i){
			cin >> c.at(i);
		}
		sort(c.begin(), c.end());
		int sum = 0, ctr = 0;		
		bool all_fill = false;
		bool sum_exceed = false;
		for(int i = 0; i < n && sum <= x; ++i){
			sum += c.at(i);
			++ctr;
			if(i == n - 1 && sum <= x) all_fill = true;
			if(sum > x){
				sum_exceed = true;
				--ctr;
			}
		}
		cout << ctr << "\n";
	}
	return 0;
}