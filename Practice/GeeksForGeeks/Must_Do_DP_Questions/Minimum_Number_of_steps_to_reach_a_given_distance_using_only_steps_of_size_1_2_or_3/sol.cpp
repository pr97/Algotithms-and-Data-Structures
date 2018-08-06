/*
* Link to Question: https://practice.geeksforgeeks.org/problems/count-number-of-hops/0
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
		vector<int> a(n + 1, 0);
		a.at(0) = 1;
		for(int i = 1; i <= n; ++i){
			if(i - 1 >= 0)
				a.at(i) += a.at(i - 1);
			if(i - 2 >= 0)
				a.at(i) += a.at(i - 2);
			if(i - 3 >= 0)
				a.at(i) += a.at(i - 3);
		}

		cout << a.at(n) << "\n";
	}
	return 0;
}