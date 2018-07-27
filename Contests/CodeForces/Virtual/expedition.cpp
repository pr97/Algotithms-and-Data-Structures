#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	for(int i = 0; i < m; ++i)
		cin >> a.at(i);
	map<int, int> count;
	for(int i = 0; i < m; ++i)
		count[a.at(i)] = count[a.at(i)] + 1;
	int max = 0;
	int sum;
	for(int day = 1; day <= 100; ++day){
		sum = 0;
		for(int type = 1; type <= 100; ++type){
			sum += count[type] / day; 
		}
		if(sum >= n)
			max = day;
	}
	cout << max;
	return 0;
}