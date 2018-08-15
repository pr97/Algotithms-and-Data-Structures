#include <bits/stdc++.h>

using namespace std;

int partition(vector<int>& a, int l, int r){
	int pivot = rand() % (r - l + 1) + l;
	swap(a[pivot], a[r]);
	pivot = r;
	int i = l - 1;
	for(int j = l; j <= r - 1; ++j){
		if(a[j] < a[pivot]){
			++i;
			swap(a[j], a[i]);
		}
	}
	swap(a[i + 1], a[pivot]);
	pivot = i + 1;
	return pivot;
}

void qsort(vector<int>& a, int l, int r){
	if(l > r)
		return;
	int p = partition(a, l , r);
	qsort(a, l, p - 1);
	qsort(a, p + 1, r);
}

int main(){
	int n;
	cin >> n;
	std::vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	for(int i = 0; i < n; ++i){
		cout << a[i] << " ";
	}
	cout << "\n";
	qsort(a, 0, n - 1);
	for(int i = 0; i < n; ++i){
		cout << a[i] << " ";
	}
	return 0;
}