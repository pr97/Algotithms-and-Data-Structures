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
#define DEBUGseqout(_A,_N) cout << "\n>>> "; seqout(_A,_N); cout << "\n"
#define ll long long

int stringnum2int(string s) {
    stringstream sstream(s);
    int res = 0;
    sstream >> res;
    return res;
}

int char2digit(char c) {
    return c - '0';
}

char digit2char(int i) {
    return '0' + i;
}

int randinrange(int l, int r) {
    // inclusive of l and r
    return rand() % (r - l + 1) + l;
}

ll n;
ll a[100005];
ll c[100005] = {};
unordered_map<ll, pair<ll, ll> > m;
ll num_triplets;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        m.clear();
        num_triplets = 0;
        cin >> n;
        seqin(a,n);
        c[0] = a[0];
        for(int i = 1; i < n; ++i) {
            c[i] = c[i - 1] ^ a[i];
        }
        for(int i = 0; i < n; ++i) {
            m[c[i]].first += i;
            m[c[i]].second++;
        }
        num_triplets += m[0].first;
        for(int i = 0; i < n; ++i) {
            m[c[i]].first -= i;
            --m[c[i]].second;
            num_triplets += m[c[i]].first - (m[c[i]].second) * (i + 1);
        }
        cout << num_triplets << "\n";
    }
    return 0;
}