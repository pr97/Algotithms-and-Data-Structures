/*
* Link to question: https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0/?ref=self
*/

#include <bits/stdc++.h>

using namespace std;

int lis_sum(int a[], int n){
	int global_max = 1, _max = 0;
	int l[n];
	for(int i = 0; i < n; ++i){
		_max = -1;
		for(int j = 0; j < i; ++j){
			if(l[j] > _max && a[i] > a[j]){
				_max = l[j];
			}
		}
		if(_max == -1){
			l[i] = a[i];
		}
		else{
			l[i] = a[i] + _max;
		}
		global_max = max(global_max, l[i]);
	}
	return global_max;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		cout << lis_sum(a, n) << "\n";
	}
	return 0;
}