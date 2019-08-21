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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    string inp;
    int openctr = 0;
    int isopen[n + 1] = {}; // array size is set to 'n + 1' instead of 'n' because tweets are 1 indexed according to question.
    int twt;
    while(k--) {
    	cin >> inp;
    	if(inp[2] == 'I') {
    		// Input is CLICK X
    		cin >> twt;
    		if(isopen[twt]) {
    			isopen[twt] = 0;
    			--openctr;
    		}
    		else {
    			isopen[twt] = 1;
    			++openctr;
    		}
    	}
    	else {
    		// Input is CLOSEALL
    		for(int i = 1; i <= n; ++i) isopen[i] = 0;
    		openctr = 0;
    	}
    	cout << openctr << "\n";
    }
	return 0;
}