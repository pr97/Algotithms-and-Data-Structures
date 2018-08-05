#include <bits/stdc++.h>

using namespace std;

int edit_distance(string& s1, string& s2, int n1, int n2){
	int insert_cost = 1, remove_cost = 1, replace_cost = 1;
	int dp[n1 + 1][n2 + 1];
	int minimum;
	for(int i = n1; i >= 0; --i){
		for(int j = n2; j >= 0; --j){
			if(i == n1 || j == n2){
				if(i == n1 && j == n2)
					dp[i][j] = 0;
				else if(i == n1)
					dp[i][j] = dp[i][j + 1] + insert_cost;
				else if(j == n2)
					dp[i][j] = dp[i + 1][j] + remove_cost;
			}
			else{
				if(s1.at(i) == s2.at(j))
					dp[i][j] = dp[i + 1][j + 1];
				else{
					minimum = dp[i][j + 1] + insert_cost;
					minimum = min(minimum, dp[i + 1][j] + remove_cost);
					minimum = min(minimum, dp[i + 1][j + 1] + replace_cost);
					dp[i][j] = minimum;
				}
			}
		}
	}
	return dp[0][0];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n1, n2;
		cin >> n1 >> n2;
		cin.ignore();
		string s1, s2;
		getline(cin, s1);
		string temp = s1;
		s1 = temp.substr(0, n1);
		s2 = temp.substr(n1 + 1, n2);
		cout << edit_distance(s1, s2, n1, n2) << "\n";
	}
	return 0;
}