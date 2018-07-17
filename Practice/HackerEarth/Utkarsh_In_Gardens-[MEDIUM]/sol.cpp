#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, in;
	cin >> n;
	bitset<2005> g[n];
	for(int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j) {
			cin >> in;
			if(in)
				g[i].set(j);
		}
	}
	
	long long count, result = 0;
	for(int i = 0; i < n; ++i){
		for(int j = i + 1; j < n; ++j){
			count = (g[i] & g[j]).count();
			result += (count * (count - 1)) / 2;
		}
	}
	result /= 2;
	cout << result;
	return 0;
}