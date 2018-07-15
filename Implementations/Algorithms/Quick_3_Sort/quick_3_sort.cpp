#include <bits/stdc++.h>

using namespace std;

pair<int, int> partition3(vector<int>& a, int l, int r){
	int i = l - 1, j = l - 1;
	int pivot = rand() % (r - l + 1) + l; // Picks random element as pivot, which is later swapped with the last element of the array.
	swap(a.at(pivot), a.at(r));
	pivot = r;
	// Such a partition scheme is followed which assumes that the pivot is located at the last inclusive index of the array, which is 'r'.
	for(int k = l; k <= r - 1; ++k){
		if(a.at(k) < a.at(pivot)){
			++i;
			j = i;
			swap(a.at(i), a.at(k));
		}
		else if(a.at(k) == a.at(pivot)){
			++j;
			swap(a.at(j), a.at(k)); 
		}
	}
	swap(a.at(j + 1), a.at(pivot));
	int pivot_start = i + 1;
	int pivot_end = j + 1;
	return make_pair(pivot_start, pivot_end);
}

void quick_sort(vector<int>& a, int l, int r){
	if(l < r){
		pair<int, int> pivots = partition3(a, l, r);
		quick_sort(a, l, pivots.first - 1);
		quick_sort(a, pivots.second + 1, r);
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