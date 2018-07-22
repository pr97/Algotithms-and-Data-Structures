#include <bits/stdc++.h>

using namespace std;

#define array_input(a, n) for(int i = 0; i < n; ++i) cin >> a[i]

int min_swaps(int a[], int n, int k){
	int k_count = 0;
	int count = 0;
	int max_count = -1;
	for(int i = 0; i < n; ++i){
		if(a[i] <= k)
			++k_count;
	}
	for(int i = 0; i < k_count; ++i){
		if(a[i] <= k)
			++count;
	}
	max_count = count;
	for(int i = k_count; i < n; ++i){
		if(a[i - k_count] <= k)
			--count;
		if(a[i] <= k)
			++count;
		if(count > max_count)
			max_count = count;
	}
	return k_count - max_count;
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
		array_input(a, n);
		int k;
		cin >> k;
		cout << min_swaps(a, n, k) << "\n";
	}
	return 0;
}