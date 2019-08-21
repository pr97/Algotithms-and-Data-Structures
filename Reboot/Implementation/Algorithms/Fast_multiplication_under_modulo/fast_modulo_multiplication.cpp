#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define PRIME 1e7 + 1

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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll x, y;
	cin >> x >> y;
	cout << fast_multiply_mod(x, y, PRIME);
}