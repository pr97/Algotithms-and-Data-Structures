/*
* Link to Question: https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0
*/


#include <bits/stdc++.h>

using namespace std;

#define vector_input(a, n) for(int i = 0; i < n; ++i) cin >> a[i]
#define vector_output(a, n) for(int i = 0; i < n; ++i) cout << a[i] << " "

int kadane(vector<int>& a, int n){
	if(n == 0)
		return 0;
	int max_sum = a[0];
	int curr_sum = a[0];
	int i = 0, j = 0;
	while(i < n && j < n){
		if(curr_sum < 0){
			i = j + 1;
			j = j + 1;
			if(i < n)
				curr_sum = a[i];
		}
		else{
			++j;
			if(j < n)
				curr_sum += a[j];
		}
		if(max_sum < curr_sum)
			max_sum = curr_sum;
	}
	return max_sum;
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
		vector_input(a, n);
		cout << kadane(a, n) << "\n";
	}
	return 0;
}