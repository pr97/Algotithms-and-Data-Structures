#include <bits/stdc++.h>

using namespace std;

#define PRIME 1000000007

long long multiply_under_modulo(long long a, long long b, long long p){
	long long res = 0;
	while(b){
		if(b & 1)
			res = (res + a) % p;
		a = (2 * a) % p;
		b = b >> 1;
	}
	return res;
}

long long power_under_modulo(long long a, long long b, long long p){
	long long res = 1;
	a = a % p;
	while(b > 0){
		if(b & 1){
			res = multiply_under_modulo(res, a, p) % p;
		}
		b = b >> 1;
		a = multiply_under_modulo(a, a, p) % p;
	}
	return res;
}


long long gcd_euclidean(long long a, long long b){
	long long t;
	while(b != 0){
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		long long a, b, n, x, y;
		cin >> a >> b >> n;
		// x = (power_under_modulo(a, n, PRIME) + power_under_modulo(b, n, PRIME));

		y = abs(a - b);
		if(!y){
			cout << (power_under_modulo(a, n, PRIME) + power_under_modulo(b, n, PRIME)) % PRIME << "\n";
			continue;
		}
		x = power_under_modulo(a, n, y) + power_under_modulo(b, n, y);
		// cout << gcd_euclidean(14 % 13, 49 % 13) << "\n";
		// cout << power_under_modulo(a, b, n) << "\n";
		cout << __gcd(x, y) % PRIME<< "\n";
	}
	return 0;
}