#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		int x, y, z;
		cin >> n;
		cin >> x >> y >> z;
		int _min, mid, _max;
		_min = min({x, y, z});
		_max = max({x, y, z});
		if(_min != x && _max != x)
			mid = x;
		else if(_min != y && _max != y)
			mid = y;
		else if(_min != z && _max != z)
			mid = z;
		if(x == y)
			mid = x;
		else if(y == z)
			mid = y;
		else if(z == x)
			mid = z;
		x = _min; y = mid; z = _max;
		vector<int> num_cuts(n + 1, -1);
		num_cuts.at(0) = 0;
		for(int i = x; i <= n; ++i){
			if(num_cuts.at(i - x) != -1)
				num_cuts.at(i) = num_cuts.at(i - x) + 1;
			if(i >= y && num_cuts.at(i - y) != -1)
				num_cuts.at(i) = max(num_cuts.at(i), num_cuts.at(i - y) + 1);
			if(i >= z && num_cuts.at(i - z) != -1)
				num_cuts.at(i) = max(num_cuts.at(i), num_cuts.at(i - z) + 1);
		}
		cout << num_cuts.at(n) << "\n";
	}
	return 0;
}