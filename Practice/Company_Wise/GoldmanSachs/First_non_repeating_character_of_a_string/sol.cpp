#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		unordered_map<char, int> mp;
		for(int i = n - 1; i >= 0; --i){
			mp[s.at(i)]++;
		}
		bool found = false;
		char res;
		for(int i = 0; i < n; ++i){
			if(mp.at(s.at(i)) == 1){
				found = true;
				res = s.at(i);
				break;
			}
		}
		if(found)
			cout << res << "\n";
		else
			cout << -1 << "\n";
	}
	return 0;
}