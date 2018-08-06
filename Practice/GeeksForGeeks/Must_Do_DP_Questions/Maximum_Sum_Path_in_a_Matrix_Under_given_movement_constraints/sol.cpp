/*
* Link to Question: https://practice.geeksforgeeks.org/problems/path-in-matrix/0
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<vector<int> > a;
		for(int i = 0; i < n; ++i)
			a.push_back(vector<int>(n));
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				cin >> a.at(i).at(j);
		for(int i = n - 2; i >= 0; --i){
			for(int j = 0; j < n; ++j){
				if(j == 0){
					a.at(i).at(j) = max(a.at(i + 1).at(j), a.at(i + 1).at(j + 1)) + a.at(i).at(j);
				}
				else if(j == n - 1){
					a.at(i).at(j) = max(a.at(i + 1).at(j), a.at(i + 1).at(j - 1)) + a.at(i).at(j);	
				}
				else{
					a.at(i).at(j) = max({a.at(i + 1).at(j), a.at(i + 1).at(j + 1), a.at(i + 1).at(j - 1)}) + a.at(i).at(j);
				}
			}
		}
		int max_ = INT_MIN;
		for(int j = 0; j < n; ++j)
			max_ = (max_ > a.at(0).at(j))? max_ : a.at(0).at(j);
		cout << max_ << "\n";
	}
	return 0;
}