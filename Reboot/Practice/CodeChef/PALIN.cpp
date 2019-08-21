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

char incr_char(char c) {
    return digit2char(char2digit(c) + 1);
}

int randinrange(int l, int r) {
	return rand() % (r - l + 1) + l;
}

string next_palindrome(string s) {
    int ndigits = s.length();
    int mid = (ndigits % 2 == 1) ? (ndigits / 2) : ndigits / 2 - 1;
    bool is_palin = true;
    int i;
    if(ndigits & 1) {
        // Number of digits is odd.
        for(i = 1; mid + i < ndigits; ++i) {
            if(s[mid - i] != s[mid + i]) {
                is_palin = false;
                break;
            }
        }
        if(is_palin) {
            if(s[mid] != '9') {
                s[mid] = digit2char(char2digit(s[mid]) + 1);
            }
            else {
                int non9 = mid;
                while(s[non9] == '9' && non9 >= 0) --non9;
                if(non9 >= 0) {
                    int ii = mid - non9;
                    s[mid - ii] = incr_char(s[mid - ii]);
                    s[mid + ii] = incr_char(s[mid + ii]);
                    for(int j = mid - ii + 1; j < mid + ii; ++j) s[j] = '0';
                }
                else {
                    for(int j = 0; j < s.length(); ++j) s[j] = '0';
                    s[0] = '1';
                    s = s + string("1");
                }
            }
        }
        else {
            if(s[mid - i] > s[mid + i]) {
                // cout << "TAG";
                // for(int j = mid - i + 1; j < mid + i; ++j) s[j] = '0';
                s[mid + i] = s[mid - i];
                int jrev = mid - i - 1;
                for(int j = mid + i + 1; j < s.length(); ++j, --jrev) s[j] = s[jrev];
            }
            else {
                if(s[mid] != '9') {
                    s[mid] = incr_char(s[mid]);
                    int jrev = mid - 1;
                    for(int j = mid + 1; j < s.length(); ++j, --jrev) s[j] = s[jrev];
                }
                else {
                    int non9 = mid - 1;
                    while(s[non9] == '9' && non9 >= 0) --non9;
                    if(non9 >= 0) {
                        // cout << "asdasd";
                        int ii = mid - non9;
                        s[mid - ii] = incr_char(s[mid - ii]);
                        s[mid + ii] = s[mid - ii];
                        for(int j = mid - ii + 1; j < mid + ii; ++j) s[j] = '0';
                        int jrev = mid - ii - 1;
                        for(int j = mid + ii + 1; j < s.length(); ++j, --jrev) s[j] = s[jrev];
                    }
                    else {
                        // This case is never possible.
                        assert(false);
                        for(int j = 0; j < s.length(); ++j) s[j] = '0';
                        s[0] = '1';
                        s = s + string("1");
                    }
                }
            }
        }
    }
    else {
        // Number of digits is even.
        for(i = 1; mid + i < ndigits; ++i) {
            if(s[mid - (i - 1)] != s[mid + i]) {
                is_palin = false;
                break;
            }
        }
        if(is_palin) {
            if(s[mid] != '9') {
                s[mid] = digit2char(char2digit(s[mid]) + 1);
                s[mid + 1] = s[mid];
            }
            else {
                int non9 = mid;
                while(s[non9] == '9' && non9 >= 0) --non9;
                if(non9 >= 0) {
                    int ii = mid - non9 + 1;
                    s[mid - (ii - 1)] = incr_char(s[mid - (ii - 1)]);
                    s[mid + ii] = incr_char(s[mid + ii]); // equivalent to 's[mid + ii] = s[mid - (ii - 1)];'
                    for(int j = mid - (ii - 1) + 1; j < mid + ii; ++j) s[j] = '0';
                }
                else {
                    for(int j = 0; j < s.length(); ++j) s[j] = '0';
                    s[0] = '1';
                    s = s + string("1");
                }
            }
        }
        else {
            if(s[mid - (i - 1)] > s[mid + i]) {
                s[mid + i] = s[mid - (i - 1)];
                int jrev = mid - (i - 1) - 1;
                for(int j = mid + i + 1; j < s.length(); ++j, --jrev) s[j] = s[jrev];
            }
            else {
                if(s[mid] != '9') {
                    s[mid] = incr_char(s[mid]);
                    s[mid + 1] = s[mid];
                    int jrev = mid - 1;
                    for(int j = mid + 1 + 1; j < s.length(); ++j, --jrev) s[j] = s[jrev];
                }
                else {
                    int non9 = mid - 1;
                    while(s[non9] == '9' && non9 >= 0) --non9;
                    if(non9 >= 0) {
                        int ii = mid - non9 + 1;
                        s[mid - (ii - 1)] = incr_char(s[mid - (ii - 1)]);
                        s[mid + ii] = s[mid - (ii - 1)]; // equivalent to 'incr_char(s[mid + ii]);'
                        for(int j = mid - (ii - 1) + 1; j < mid + ii; ++j) s[j] = '0';
                        int jrev = mid - (ii - 1) - 1;
                        for(int j = mid + ii + 1; j < s.length(); ++j, --jrev) s[j] = s[jrev];
                    }
                    else {
                        // This case is never possible.
                        assert(false);
                        for(int j = 0; j < s.length(); ++j) s[j] = '0';
                        s[0] = '1';
                        s = s + string("1");
                    }
                }  
            }
        }
    }
    return s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        string n;
        cin >> n;
        cout << next_palindrome(n) << "\n";
    }
	return 0;
}