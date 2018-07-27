#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	cin.ignore();
	string s, e = "";
	int last = -1;
	getline(cin, s);
	sort(s.begin(), s.end());
	int sum = 0;
	bool not_possible = false;
	for(int i = 0; i < n; ++i){
		if(i == 0){
			sum += (s[i] - 'a' + 1);
			e = e + s[i];
			++last;
		}
		else{
			if(s[i] - e[last] > 1){
				e = e + s[i];
				++last;
				sum += (s[i] - 'a' + 1);
			}
		}
		if(last == k - 1)
				break;
		if(i == n - 1 && last != k - 1)
			not_possible = true;
	}
	if(not_possible)
		cout << -1;
	else
		cout << sum;
	return 0;
}