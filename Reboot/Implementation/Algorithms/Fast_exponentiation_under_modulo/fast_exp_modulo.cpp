#include <bits/stdc++.h>

using namespace std;

#define PRIME 1e7 + 1
#define ll long long

ll fast_multiply_mod(ll x, ll y, ll p) {
	ll res = 0;
	x %= p;
	while(y) {
		if(y & 1)
			res = (res + x) % p;
		y >>= 1;
		x = (x + x) % p;
	}
	return res;
}

ll fast_pow_mod(ll x, ll y, ll p) {
	ll res = 1;
	x %= p;
	while(y) {
		if (y & 1)
			res = fast_multiply_mod(res, x, p);
		y >>= 1;
		x = fast_multiply_mod(x, x, p);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll x, y;
	cin >> x >> y;
	cout << fast_pow_mod(x, y, PRIME);
}