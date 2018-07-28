#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	getline(cin, s);
	int n = s.length();
	for(int i = 0; i < n; ++i){
		if(s[i] != 'a' && s[i] != 'o' && s[i] != 'i' && s[i] != 'e' && s[i] != 'u' && s[i] != 'n'){
			if(i < n - 1){
				if(s[i + 1] != 'a' && s[i + 1] != 'o' && s[i + 1] != 'i' && s[i + 1] != 'e' && s[i + 1] != 'u'){
					cout << "NO";
					return 0;
				}
			}
			if(i == n - 1){
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
	return 0;
}