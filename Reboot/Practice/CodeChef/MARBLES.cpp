#include <bits/stdc++.h>

using namespace std;

#define seqin(_A,_N) for(int _I = 0; _I < _N; ++_I) cin >> _A[_I]
#define seqin_1ind(_A,_N) for(int _I = 1; _I <= _N; ++_I) cin >> _A[_I]
#define seqout(_A,_N) for(int _I = 0; _I < _N; ++_I) cout << _A[_I] << " "
#define seqout_1ind(_A,_N) for(int _I = 1; _I <= _N; ++_I) cout << _A[_I] << " "
#define subseqout(_A,_X,_Y) for(int _I = _X; _I <= _Y; ++_I) cout << _A[_I] << " "
#define matrixin(_A,_M,_N) for(int _I = 0; _I < _M; ++_I) for(int _J = 0; _J < _N; ++_J) cin >> _A[_I][_J]
#define matrixout(_A,_M,_N) for(int _I = 0; _I < _M; ++_I){ for(int _J = 0; _J < _N; ++_J) cout << _A[_I][_J] << " "; cout << "\n";}
#define matrixin_1ind(_A,_M,_N) for(int _I = 1; _I <= _M; ++_I) for(int _J = 1; _J <= _N; ++_J) cin >> _A[_I][_J]
#define matrixout_1ind(_A,_M,_N) for(int _I = 1; _I <= _M; ++_I){ for(int _J = 1; _J <= _N; ++_J) cout << _A[_I][_J] << " "; cout << "\n";}

#define ll long long

int stringnum2int(string s) {
	stringstream sstream(s);
	int res = 0;
	sstream >> res;
	return res;
}

int randinrange(int l, int r) {
	return rand() % (r - l + 1) + l;
}

ll factorial(ll x) {
    if(x == 0 || x == 1) return 1;
    ll res = 1;
    while(x--) {
        res *= (x + 1);
    }
    return res;
}

ll nCr(ll n, ll r) { // Very inefficient and limited input constraints. Easy overflow possibility even for small values for n (~ 30).
    if(n == 0) return 1; // empirically setting return value to 1
    return factorial(n) / (factorial(n - r) * factorial(r));
}

ll efficient_nCr(ll n, ll r) {
    ll res = 1;
    if(r > n - r) r = n - r; // This line does not affect the result but affectes the efficiency as the loop below will execute a smaller number of times.
    for(int i = 0; i < r; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        cout << efficient_nCr(n - 1, k - 1) << "\n";
    }
	return 0;
}