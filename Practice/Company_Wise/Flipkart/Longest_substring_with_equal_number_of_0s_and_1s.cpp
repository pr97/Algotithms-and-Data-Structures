// https://practice.geeksforgeeks.org/problems/longest-substring-with-equal-number-of-0s-and-1s/0

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
		int num_zeros = 0, num_ones = 0;
		int n = s.length();
		for(int i = 0; i < n; ++i){
			if(s.at(i) == '0')
				++num_zeros;
			else
				++num_ones;
		}
		cout << endl << num_zeros << " " << num_ones << endl;
		int minimum = min(num_zeros, num_ones);
		cout << minimum * 2;
		cout << "\n";
	}
	return 0;
}