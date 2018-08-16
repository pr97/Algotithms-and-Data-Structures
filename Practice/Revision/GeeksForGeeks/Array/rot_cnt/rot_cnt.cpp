#include <bits/stdc++.h>
using namespace std;

int binary_search_pivot(int a[], int l, int r){
	if(l > r)
		return -1;
	if(l == r)
		return l;
	int m = (l + r) / 2;
	if(m > l && a[m] < a[m - 1]){
		return m - 1;
	}
	if(m < r && a[m] > a[m + 1])
		return m;
	if(a[l] >= a[m])
		return binary_search_pivot(a, l, m - 1);
	return binary_search_pivot(a, m + 1, r);
}

int main() {
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
		int p = binary_search_pivot(a, 0, n - 1);
		cout << p + 1;
		cout << "\n";

	}
	return 0;
}