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
			  string s;
	  while(n){
	  	n = n - 1;

	  int x=n%26;
	  s+= (char)(x+'A');
	  n=n/26;
	  }	
      reverse(s.begin(),s.end());
      cout<<s<<endl;
	}
	return 0;
}