// https://practice.geeksforgeeks.org/problems/shortest-direction/0

#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	cin.ignore();
	while(t--){
		string s;
		getline(cin, s);
		unordered_map<char, int> m;
		size_t n = s.length();
		for(size_t i = 0; i < n; ++i){
			m[s.at(i)]++;
		}
		char ns_dir, ew_dir;
		if(m['N'] >= m['S'])
			ns_dir = 'N';
		else
			ns_dir = 'S';
		if(m['E'] >= m['W'])
			ew_dir = 'E';
		else
			ew_dir = 'W';
		int ns_num = max(m['N'], m['S']) - min(m['N'], m['S']);
		int ew_num = max(m['E'], m['W']) - min(m['E'], m['W']);
		if(ew_dir == 'E'){
			for(int i = 0; i < ew_num; ++i){
				cout << 'E';
			}
			for(int i = 0; i < ns_num; ++i){
				cout << ns_dir;
			}
		}
		else{
			for(int i = 0; i < ns_num; ++i){
				cout << ns_dir;
			}
			for(int i = 0; i < ew_num; ++i){
				cout << 'W';
			}
		}
		cout << "\n";
	}
	return 0;
}