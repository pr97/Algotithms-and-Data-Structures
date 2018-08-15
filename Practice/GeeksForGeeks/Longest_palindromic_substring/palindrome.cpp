#include <bits/stdc++.h>
using namespace std;

void print_substr(string s, int x, int len, int n){
	for(int i = x; i < x + len && x + len <= n; ++i){
		cout << s[i];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	cin.ignore();
	while(t--){
		string s;
		cin >> s;
		int n = s.length();
		bool dp[n][n];
		int max_len = 1;
		int start = 0;
		for(int i = 0; i < n; ++i){
			dp[i][i] = true;
		}
		for(int i = 0; i < n - 1; ++i){
			if(s[i] == s[i + 1]){
				dp[i][i + 1] = true;
				if(max_len < 2){
					start = i;
					max_len = 2;
				}
			}
			else{
				dp[i][i + 1] = false;
			}
		}
		int j;
		for(int k = 3; k <= n; ++k){
			for(int i = 0; i < n - k + 1; ++i){
				j = i + k - 1;

				if(i < n && j < n && s[i] == s[j] && dp[i + 1][j - 1] == true){
					dp[i][j] = true;
					if(k > max_len){
						max_len = k;
						start = i;
					}
				}
				else{
					dp[i][j] = false;
				}
			}
		}
		print_substr(s, start, max_len, n);
		cout << "\n";
	}
	return 0;
}