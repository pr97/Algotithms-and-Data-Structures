#include <bits/stdc++.h>

using namespace std;

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n, ctr;
		int i = 2;
		cin >> n;
		bool a[1000000];
		if(n == 1){
			cout << 1;
			continue;
		}
		else{
			a[0] = false;
			a[1] = true;
			ctr = 1;
			while(ctr != n){
				a[i] = false;
				if(i % 2 == 0 ){
					a[i] = a[i] || a[i / 2];
				}
				if(i % 3 == 0){
					a[i] = a[i] || a[i / 3];
				}
				if(i % 5 == 0){
					a[i] = a[i] || a[i / 5];
				}
				if(a[i]){
					++ctr;
				}
				++i;
			}
			
		}
		cout << i - 1 << "\n";
	}
	return 0;
}