/*
* Link to question: https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0
*/

#include <bits/stdc++.h>

using namespace std;

int lis_length(int a[], int n){
    if(n == 0)
        return 0;
	int global_max = 1;
	int mem[n];
	int max, curr;
	for(int i = 0; i < n; ++i){
		max = 1;
		if(i == 0){
			mem[i] = 1;
			global_max = 1;
			continue;
		}
		for(int j = 0; j < i; ++j){
			if(a[i] > a[j]){
				curr = mem[j] + 1;
				if(curr > max){
					max = curr;
				}
			}
		}
		mem[i] = max;
		if(max > global_max)
			global_max = max;
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
		cout << lis_length(a, n) << "\n";
	}
	return 0;
}