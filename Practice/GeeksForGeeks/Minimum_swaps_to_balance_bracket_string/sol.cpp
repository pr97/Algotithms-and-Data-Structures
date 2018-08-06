/*
* Link to question: https://practice.geeksforgeeks.org/problems/minimum-swaps-for-bracket-balancing/0
*/

#include <bits/stdc++.h>

using namespace std;

long long min_swaps(string& S, int n){
    string s = S;
	long long res = 0;
	int count = 0;
	int p = 0;
	vector<int> pos;
	for(int i = 0; i < n; ++i)
		if(s.at(i) == '[')
			pos.push_back(i);
	for(int i = 0; i < n; ++i){
		if(s.at(i) == '['){
			++count;
			++p;
		}
		if(s.at(i) == ']'){
			--count;
			if(count < 0){
				res += (pos[p] - i);
				swap(s.at(i), s.at(pos[p]));
				count = 1;
				++p;
			}
		}
	}
	// 	assert(!count);
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin.ignore();
		getline(cin, s);
		cout << min_swaps(s, n) << "\n";
	}	
	return 0;
}