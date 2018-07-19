#include <bits/stdc++.h>

using namespace std;

int find_pivot_in_rotated_sorted_array_in_logn_time(int a[], int l, int r){
	
	/*
	* Finds the maximum element's index in O(log(n)) time.
	* This index is the pivot index after which the 1st element of the un-rotated array is present.
	* Assumes that 'a' is sorted in ascending order.
	*/

	if(r < l)
		return -1;
	int mid = (l + r) / 2;
	if(mid < r && a[mid] > a[mid + 1])
		return mid;
	if(l < mid && a[mid - 1] > a[mid])
		return mid - 1;

	if(a[l] <= a[mid])
		return find_pivot_in_rotated_sorted_array_in_logn_time(a, mid + 1 ,r);
	else
		return find_pivot_in_rotated_sorted_array_in_logn_time(a, l, mid - 1);
}

pair<int, int> find_pair_with_given_sum_in_sorted_array_NO_ROTATION(int a[], int n, int x){

	/*
	* Assumes that 'a' is sorted in ascending order.
	*/

	int l = 0, r = n - 1;
	while(l < r){
		if(a[l] + a[r] == x)
			return make_pair(l, r);
		if(a[l] + a[r] < x)
			++l;
		if(a[l] + a[r] > x)
			--r;
	}
	return make_pair(-1, -1);
}

pair<int, int> find_pair_with_given_sum_in_sorted_array_WITH_ROTATION_AT_KNOWN_PIVOT(int a[], int n, int x, int p){
	
	/*
	* Assumes that 'a' is sorted in ascending order.
	*/

	int l = p + 1, r = (n + p) % n; // 'r = p;' would have been just fine. 
	while(l != r){
		if(a[l] + a[r] == x)
			return make_pair(l, r);
		if(a[l] + a[r] < x)
			l = (l + 1) % n;
		if(a[l] + a[r] > x)
			r = (n + r - 1) % n;
	}
	return make_pair(-1, -1);
}

pair<int, int> find_pair_with_given_sum_in_ROTATED_AT_UNKNOWN_PIVOT_sorted_array(int a[], int n, int x){

	int pivot = find_pivot_in_rotated_sorted_array_in_logn_time(a, 0, n - 1); // logarithmic time.

	if(pivot == -1)
		return find_pair_with_given_sum_in_sorted_array_NO_ROTATION(a, n, x); // linear time
	else
		return find_pair_with_given_sum_in_sorted_array_WITH_ROTATION_AT_KNOWN_PIVOT(a, n, x, pivot); // linear time
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x;
	cin >> n >> x;
	int a[n];
	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}
	pair<int, int> res = find_pair_with_given_sum_in_ROTATED_AT_UNKNOWN_PIVOT_sorted_array(a, n, x); // O(n + log(n)) = O(n) time.
	if(res.first == -1)
		cout << "No such pair found!";
	else
		cout << a[res.first] << " " << a[res.second];
	return 0;
}