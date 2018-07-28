#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int> > rect(n);
	for(int i = 0; i < n; ++i)
		cin >> rect.at(i).first >> rect.at(i).second;
	for(int i = 0; i < n - 1; ++i){
		if(max(rect.at(i).first, rect.at(i).second) < min(rect.at(i + 1).first, rect.at(i + 1).second)){
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}