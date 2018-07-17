#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
	int temp;
	while(b != 0){
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}
int abs(int x){
	return (x < 0)? (-x) : x;
}

int mod(int a, int b){
	
	/*
	* Takes into consideration the cyclic nature of the modular arithmetic in relation to modulus of negative numbers.
	*/

	if(a < 0){
		return b - (abs(a) % b);
	}
	else{
		return a % b;
	}
}

void juggling_rotate(int a[], int n, int d, bool rotate_left = true){
	d = d % n;
	if(d == 0)
		return;
	int sets = gcd(n, d), j, temp, k;
	for(int i = 0; i < sets; ++i){
		j = i;
		temp = a[i]; // same as 'temp = a[j];'
		for(int x = 0; x < n / sets; ++x){
			if(rotate_left)
				k = mod(j + d, n);
			else
				k = mod(j - d, n);

			if(k == i)
				a[j] = temp;
			else
				a[j] = a[k];

			j = k;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, d, rotate_left = 1;
	cin >> n >> d >> rotate_left; // 'rotate_left' '1' for left rotation, '0' for right rotation. Defaults to '1'.
	int a[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	juggling_rotate(a, n, d, bool(rotate_left)); // Last Parameter: 'true' for left rotation, 'false' for right rotation. Defaults to 'true'.
	for(int i = 0; i < n; ++i)
		cout << a[i] << " ";
	return 0;
}