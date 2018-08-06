#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		long long n, x, y, s, diff, min = LLONG_MAX;
		cin >> n;
		for(int xi = 0; xi < 60; ++xi){
			for(int yi = xi; yi < 60; ++yi){
				if(xi == yi)
					continue;
				x = ((long long)1 << xi);
				y = ((long long)1 << yi);
				s = x + y;
				diff = abs(n - s);
				if(min > diff)
					min = diff;
			}
		}
		cout << min << "\n";
	}
	return 0;
}


// long long n = 25;
// n = n | n >> 1;
// n = n | n >> 2;
// n = n | n >> 4;
// n = n | n >> 8;
// n = n | n >> 16;
// cout << ((n + 1) >> 1);