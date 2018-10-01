#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, cnt = 0, s, j;
	cin >> t;
	while(t--){
		cin >> n;
		cnt = 0;
		for(int i = 0; i < n; ++i){
			cin >> s >> j;
			if(j - s > 5){
				++cnt;
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}