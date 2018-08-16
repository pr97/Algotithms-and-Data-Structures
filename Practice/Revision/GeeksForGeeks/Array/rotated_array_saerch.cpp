#include <iostream>
using namespace std;

int binary_search_normal(int a[], int l, int r, int k){
	if(l <= r){
		int m = (l + r) / 2;
		if(a[m] == k)
			return m;
		if(a[m] > k){
			return binary_search_normal(a, l, m - 1, k);
		}
		if(a[m] < k){
			return binary_search_normal(a, m + 1, r, k);
		}
	}
	return -1;
}

int binary_search_for_decreasing(int a[], int l, int r, int k){
	if(l <= r){
		int m = (l + r) / 2;
		if(a[m] == k)
			return m;
		if(a[m] < k){
			return binary_search_for_decreasing(a, l, m - 1, k);
		}
		if(a[m] > k){
			return binary_search_for_decreasing(a, m + 1, r, k);
		}
	}
	return -1;
}

int binary_search_bitonic(int a[], int n,  int l, int r){
	if(l == r){
		return l;
	}
	int m = (l + r) / 2;
	if(m == 0){
		return m;
	}
	if(a[m] > a[m - 1] && a[m] > a[m + 1])
		return m;
	if(a[m - 1] < a[m] && a[m] < a[m + 1])
		return binary_search_bitonic(a, n, m + 1, r);
	if(a[m - 1] > a[m] && a[m] > a[m + 1])
		return binary_search_bitonic(a, n, l, m - 1);
}

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
		int n, x;
		cin >> n >> x;
		int a[n];
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		int p = binary_search_bitonic(a, n, 0, n - 1);
		// cout << ">>>" << p << "<<<";
		int index = -1;
		if(p == -1){
			index = binary_search_normal(a, 0, n - 1, x);
		}
		if(index == -1){
			index = binary_search_normal(a, 0, p, x);
			// cout << index << "<";
		}
		if(index == -1){
			index = binary_search_for_decreasing(a, p + 1, n - 1, x);
			// cout << index << "<";
		}
		if(index != -1)
			cout << index;
		else
			cout << "OOPS! NOT FOUND";
		cout << "\n";

	}
	return 0;
}