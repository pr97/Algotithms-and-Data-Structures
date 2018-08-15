/*
* Link to question: https://practice.geeksforgeeks.org/problems/leaders-in-an-array/0/?ref=self
*/

#include <bits/stdc++.h>

using namespace std;

void leaders(int a[], int n){
	int max = a[n - 1];
	vector<int> v;
	v.push_back(a[n - 1]);
	for(int i = n - 2; i >= 0; --i){
		if(a[i] > max){
			v.push_back(a[i]);
			max = a[i];
		}
	}
	for(auto i = v.rbegin(); i != v.rend(); ++i)
		cout << *i << " ";
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
		leaders(a, n);
		cout << "\n";
	}
	return 0;
}