#include <bits/stdc++.h>

#define vector_input(a, n) for(int i = 0; i < n; ++i) cin >> a[i]
#define vector_output(a, n) for(int i = 0; i < n; ++i) cout << a[i] << " "

using namespace std;

void rearrange(vector<int>& a, int n){
	for(int i = 0; i < n - 1; ++i){
		if(a.at(i) != 0 && a.at(i + 1) == a.at(i)){
			a.at(i) *= 2;
			a.at(i + 1) = 0;
		}

	}
	
	// Push zeros to end in O(n) space.
	// ---------------
	// vector<int> b(a);
	// int i = 0, j = n - 1;
	// for(int k = 0; k < n; ++k){
	// 	if(b.at(k) != 0)
	// 		a.at(i++) = b.at(k);
	// 	else
	// 		a.at(j--) = b.at(k);
	// }
	// _________________________

	// Push zeros to end in O(1) space and single pass.
	int count  = 0;
	for(int i = 0; i < n; ++i){
		if(a.at(i) != 0)
			swap(a.at(count++), a.at(i));
	}
	//________________________________________________
}

int main(){
	ios_base::sync_with_stdio(false);	
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n);
		vector_input(a, n);
		rearrange(a, n);
		vector_output(a, n);
		cout << "\n";
	}
	return 0;
}