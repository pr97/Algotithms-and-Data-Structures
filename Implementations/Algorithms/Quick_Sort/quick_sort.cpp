#include <bits/stdc++.h>

using namespace std;

int partition(vector<int>& a, int l, int r){
	int i = l - 1;
	int pivot = rand() % (r - l + 1) + l; // Picks random element as pivot, which is later swapped with the last element of the array.
	swap(a.at(pivot), a.at(r));
	pivot = r;
	// Such a partition scheme is followed which assumes that the pivot is located at the last inclusive index of the array, which is 'r'.
	for(int j = l; j <= r - 1; ++j){
		if(a.at(j) <= a.at(pivot)){
			++i;
			swap(a.at(i), a.at(j));
		}
	}
	swap(a.at(i + 1), a.at(pivot));
	pivot = i + 1;
	return pivot;
}

void quick_sort(vector<int>& a, int l, int r){
	if(l < r){
		int pivot = partition(a, l, r);
		quick_sort(a, l, pivot - 1);
		quick_sort(a, pivot + 1, r);
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
	quick_sort(a, 0, n - 1);
	cout << "\nAfter sort: ";
	for (int i = 0; i < n; ++i)
		cout << a.at(i) << " ";	
	return 0;
}