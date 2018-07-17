#include <bits/stdc++.h>

using namespace std;

int find_pivot_in_rotated_sorted_array_in_logn_time(int a[], int l, int r){
	
	/*
	* Finds the maximum element's index in O(log(n)) time.
	* This index is the pivot index after which the 1st element of the un-rotated array is present.
	* Assumes that 'a' is sorted in ascending order.
	*/

	if(l > r)
		return -1;
	int mid = (l + r) / 2;
	if(mid < r && a[mid] > a[mid + 1])
		return mid;
	if(l < mid && a[mid - 1] > a[mid])
		return mid - 1;
	if(a[l] <= a[mid])
		return find_pivot_in_rotated_sorted_array_in_logn_time(a, mid + 1, r);
	else
		return find_pivot_in_rotated_sorted_array_in_logn_time(a, l, mid - 1);
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
		cout << find_pivot_in_rotated_sorted_array_in_logn_time(a, 0, n - 1) + 1 << "\n";
	}
	return 0;
}