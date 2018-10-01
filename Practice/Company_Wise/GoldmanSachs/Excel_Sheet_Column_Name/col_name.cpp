#include <bits/stdc++.h>

using namespace std;

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		n = n - 1;
		char alphabet = 'A';
		char a[26];
		for(int i = 0; i < 26; ++i)
			a[i] = alphabet++;
	// 	if(n <= 26){
	// 		cout << a[n] << "\n";
	// 		continue;
	// 	}
		int rem = 1;
		stack<int> s;
		while(n != 0){
			rem = n % 26;
			n /= 26;
			s.push(rem);
		}
		while(!s.empty()){
			cout << a[s.top()];
			s.pop();
		}
		cout << "\n";
	}
	return 0;
}