#include <bits/stdc++.h>

using namespace std;

#define PRIME ((ll)1e7 + 1)
#define ll long long

ll power(ll x, ll y) {
	ll res = 1;
	while(y--) {
		res *= x;
	}
	return res;
}

ll fast_pow(ll x, ll y) {
	ll res = 1;
	while(y) {
		if (y & 1)
			res = res * x;
		y >>= 1;
		x *= x;
	}
	return res;
}

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
	while(true) {
		ll x = rand() % 11 , y = rand() % 10;
		ll fast_res = fast_pow(x, y);
		ll res = power(x, y);
		if(fast_res != res) {
			cout << "\nMISMATCH FOUND: " << x << " " << y;
			cout << "\n" << fast_res << " " << res;
			break;
		}
		else {
			cout << "\nSEXY!";
		}
	}
	// cin >> x >> y;
	// cout << fast_pow_mod(x, y, PRIME);
	return 0;
}