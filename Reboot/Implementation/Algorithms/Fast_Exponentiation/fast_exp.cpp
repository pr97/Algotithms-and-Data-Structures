#include <bits/stdc++.h>

using namespace std;

#define ll long long

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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll x, y;
	cin >> x >> y;
	cout << fast_pow(x, y);
}