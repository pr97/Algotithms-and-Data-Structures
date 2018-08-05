#include <bits/stdc++.h>

using namespace std;

#define s(i) time.at(i).second.first
#define f(i) time.at(i).first
#define index(i) time.at(i).second.second

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<pair<int, pair<int, int> > > time(n);
		for(int i = 0; i < n; ++i){
			cin >> time.at(i).second.first;
			time.at(i).second.second = i + 1;
		}
		for(int i = 0; i < n; ++i){
			cin >> time.at(i).first;
		}
		sort(time.begin(), time.end());
		cout << index(0) << " ";
		int last_finish = f(0);
		for(int i = 1; i < n; ++i){
			if(s(i) >= last_finish){
				cout << index(i) << " ";
				last_finish = f(i);
			}
		}
		cout << "\n";
	}
	return 0;
}