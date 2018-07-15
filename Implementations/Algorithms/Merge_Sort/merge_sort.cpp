#include <bits/stdc++.h>

using namespace std;

void merge_array(vector<int>& a, int l, int mid, int r){
	int n1 = mid - l + 1;
	int n2 = r - mid; // index 'mid' is not included in the second sub-array and so '1' isn't added.
	vector<int> t1(n1), t2(n2);
	
	// Code for copying the contents of the array into the temporary arrays.
	for(int i = 0; i < n1; ++i){
		t1.at(i) = a.at(l + i);
	}
	for(int i = 0; i < n2; ++i){
		t2.at(i) = a.at(mid + 1 + i);
	}

	// Code for merging.
	int i = 0, j = 0, k = l;
	while(i < n1 && j < n2){
		if(t1.at(i) <= t2.at(j)){
			a.at(k) = t1.at(i);
			++i;
		}
		else{
			a.at(k) = t2.at(j);
			++j;
		}
		++k;
	}

	while(i < n1){
		a.at(k) = t1.at(i);
		++i; ++k;
	}

	while(j < n2){
		a.at(k) = t2.at(j);
		++j; ++k;
	}
	assert(k == r + 1); // Sanity check.
}

void merge_sort(vector<int>& a, int l, int r){
	int mid = (l + r) / 2;
	if(l < r){
		merge_sort(a, l, mid);
		merge_sort(a, mid + 1, r);
		merge_array(a, l, mid, r);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a.at(i);
	cout << "Before sort: ";
	for (int i = 0; i < n; ++i)
		cout << a.at(i) << " ";
	merge_sort(a, 0, n - 1);
	cout << "\nAfter sort: ";
	for (int i = 0; i < n; ++i)
		cout << a.at(i) << " ";
	return 0;
}