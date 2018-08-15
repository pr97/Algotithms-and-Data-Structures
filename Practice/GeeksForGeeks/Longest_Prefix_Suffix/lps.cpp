#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin.ignore();
		getline(cin, s);
		int n = s.length();
		int lps[n];
		memset(lps, 0, n * sizeof(int));
		int i, j = 0;
		for(i = 1; i < n;){
			if(s[i] == s[j]){
				lps[i] = j + 1;
				++i;
				++j;
			}
			else{
				if(j == 0){
					lps[i] = 0;
					++i;
				}
				else{
					j = lps[j - 1];
				}
			}
		}
		cout << lps[n - 1] << "\n";
	}
	return 0;
}