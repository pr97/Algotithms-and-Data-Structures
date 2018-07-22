#include <bits/stdc++.h>

using namespace std;

#define vector_input(a, n) for(int i = 0; i < n; ++i) cin >> a[i]
#define vector_output(a, n) for(int i = 0; i < n; ++i) cout << a[i] << " "

int partition(vector<int>& a, int l, int r){
	int pivot = rand() % (r - l + 1) + l;
	swap(a.at(pivot), a.at(r));
	pivot = r;
	int i = l - 1;
	for(int j = l; j <= r - 1; ++j){
		if(a.at(j) < a.at(pivot)){
			++i;
			swap(a.at(i), a.at(j));
		}
	}
	swap(a.at(i + 1), a.at(pivot));
	pivot = i + 1;
	return pivot;
}

int kth_min(vector<int>& a, int l, int r, int k){
	if(k > 0 && k <= (r - l + 1)){
		int n = r - l + 1;
		int pivot = partition(a, l, r);
		// cout << "\nTAG! - " << l << r << k << " | p = " << pivot;
		if(pivot - l + 1 == k) // Comparing with 'k - 1' because standard c++ vector is 0-indexed.
			return a.at(pivot);
		else if(pivot - l + 1 > k)
			return kth_min(a, l, pivot - 1, k);
		else
			return kth_min(a, pivot + 1, r, k - (pivot - l + 1));
	}
	return INT_MAX;
}

int main(int argc, char const *argv[]){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	vector_input(a, n);
	int val = kth_min(a, 0, n - 1, k);
	cout << val;
	return 0;
}