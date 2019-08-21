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

int c[100005], h[100005], rad[100005];
int n;
bool all_zombies_killable;

int valid(int x) {
    if(x >= 1 && x <= n) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        all_zombies_killable = true;
        cin >> n;
        seqin_1ind(c,n);
        seqin_1ind(h,n);
        memset(rad + 1, 0, n * sizeof(int));
        for(int i = 1; i <= n; ++i) {
            if(valid(i - c[i])) rad[i - c[i]] += 1;
            else rad[1] += 1;
            if(valid(i + c[i] + 1)) rad[i + c[i] + 1] -= 1; 
        }
        for(int i = 2; i <= n; ++i) {
            rad[i] = rad[i - 1] + rad[i];
        }
        sort(rad + 1, rad + 1 + n);
        sort(h + 1, h + 1 + n);
        for(int i = 1; i <= n; ++i) {
            if(h[i] != rad[i]) {
                all_zombies_killable = false;
                break;
            }
        }
        if(all_zombies_killable) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}