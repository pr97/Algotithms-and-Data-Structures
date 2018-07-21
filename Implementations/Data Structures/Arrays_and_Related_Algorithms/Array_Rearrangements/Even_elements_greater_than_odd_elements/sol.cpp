#include <bits/stdc++.h>

#define vector_input(a, n) for(int i = 0; i < n; ++i) cin >> a[i]
#define vector_output(a, n) for(int i = 0; i < n; ++i) cout << a[i] << " "

using namespace std;

bool p = false;

void merge(vector<int>& a, int l, int mid, int r){
	int n1 = mid - l + 1;
	int n2 = r - mid;
	vector<int> t1(n1), t2(n2);
	for(int i = 0; i < n1; ++i)
		t1.at(i) = a.at(l + i);
	for(int i = 0; i < n2; ++i)
		t2.at(i) = a.at(mid + 1 + i);

	int i = 0, j = 0, k = l;
	while(i < n1 && j < n2){
		if(t1.at(i) < t2.at(j)){
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
		++i;
		++k;
	}
	while(j < n2){
		a.at(k) = t2.at(j);
		++j;
		++k;
	}
	assert(i == n1 && j == n2 && k - l == n1 + n2); // Sanity check.
}

void merge_sort(vector<int>& a, int l, int r){
	if(r > l){
		int mid = (l + r) / 2;
		merge_sort(a, l, mid);
		merge_sort(a, mid + 1, r);
		merge(a, l, mid, r);
	}
}

void rearrange(vector<int>& a, int n){
	vector<int> b = a;
	// int j = 0, k;
	// if(n % 2 == 1)
	// 	k = n / 2 + 1;
	// else
	// 	k = n / 2;
	int j = 0, k = n - 1;
	for(int i = 0; i < n; ++i){
		if((i + 1) % 2 == 0){
			a.at(i) = b.at(k--);
		}
		else
			a.at(i) = b.at(j++);
	}
	// if(n % 2 == 1)
	// 	assert(j == n / 2 + 1);
	// else
	// 	assert(j == n / 2);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n);
		vector_input(a, n);
		merge_sort(a, 0, n - 1);
		rearrange(a, n);
		vector_output(a, n);
		cout << "\n";
	}
	return 0;
}