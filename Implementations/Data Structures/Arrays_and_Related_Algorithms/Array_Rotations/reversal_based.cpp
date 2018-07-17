#include <bits/stdc++.h>

using namespace std;

void reverse(int a[], int l, int r){
	
	/*
	* Warning: 'Out of Bounds' error checking is not done for 'l' and 'r'.
	*/

	int len = r - l + 1;
	for(int i = 0; i < len / 2; ++i){
		swap(a[l], a[r]);
		++l;
		--r;
	}
}

void rotate_reversal_based(int a[], int n, int d, bool rotate_left = true){
	d = d % n;
	if(d == 0)
		return;
	if(rotate_left){
		reverse(a, 0, d - 1);
		reverse(a, d, n - 1);
		reverse(a, 0, n - 1);
	}
	else{
		reverse(a, n - d, n - 1);
		reverse(a, 0, n - d - 1);
		reverse(a, 0, n - 1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, d, rotate_left;
	cin >> n >> d >> rotate_left; // 'rotate_left' '1' for left rotation, '0' for right rotation. Defaults to '1'.
	int a[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	rotate_reversal_based(a, n, d, bool(rotate_left)); // Last Parameter: 'true' for left rotation, 'false' for right rotation. Defaults to 'true'.
	for(int i = 0; i < n; ++i)
		cout << a[i] << " ";
	return 0;
}