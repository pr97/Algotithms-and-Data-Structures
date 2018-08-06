#include <bits/stdc++.h>

using namespace std;

const long long PRIME = 1000000007;

long long power_under_modulo(long long a, long long b, long long p){
	long long res = 1;
	a = a % p;
	while(b > 0){
		if(b & 1){
			res = (res * a) % p;
		}
		b = b >> 1;
		a = (a * a) % p;
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
		x = (power_under_modulo(a, n, PRIME) + power_under_modulo(b, n, PRIME)) % PRIME;
		y = abs(a - b) % PRIME;
		cout << gcd_euclidean(14 % 13, 49 % 13) << "\n";
		// cout << power_under_modulo(a, b, n) << "\n";
	}
	return 0;
}