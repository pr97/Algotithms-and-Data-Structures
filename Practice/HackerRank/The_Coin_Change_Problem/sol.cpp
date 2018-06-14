#include <bits/stdc++.h>

using namespace std;

long long get_ways(int&, int&, vector<int>&);

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int m, n, in;
	vector<int> val;
	cin >> n >> m;
	for(int i = 0; i < m; ++i){
		cin >> in;
		val.push_back(in);
	}
	cout << get_ways(n, m, val);
	return 0;
}

long long get_ways(int& n, int& m, vector<int>& val){
	long long res;
	vector<vector<long long> > mem;
	for(int i = 0; i < n + 1; ++i){
		vector<long long> x(m);
		mem.push_back(x);
	}
	for(int i = 0; i < m; ++i)
		mem[0][i] = 1;
	long long p, q;
	for(int i = 1; i <= n; ++i){
		for(int j = m - 1; j >= 0; --j){
			if(j == m - 1) p = (long long)0;
			else p = mem[i][j + 1];
			if(i - val[j] < 0) q = (long long)0;
			else q = mem[i - val[j]][j];
            mem[i][j] = p + q;
		}
	}
	res = mem[n][0];
	return res;
}