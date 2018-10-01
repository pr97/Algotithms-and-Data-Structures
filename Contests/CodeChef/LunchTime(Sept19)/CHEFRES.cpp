#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		int l, r, p;
		set<pair<int, int> > s;
		for(int i = 0; i < n; ++i){
			cin >> l >> r;
			s.insert(make_pair(l, 1));
			s.insert(make_pair(r, -1));
		}
		for(int i = 0; i < m; ++i){
			cin >> p;
			set<pair<int, int> > :: iterator it = s.upper_bound(make_pair(p, 0));
			if(it == s.end())
				cout << -1;
			else{
				if(it->second == 1)
					cout << it->first - p;
				else if(it->second == -1)
					cout << 0;
			}
			cout << "\n";
		}
	}
	return 0;
}