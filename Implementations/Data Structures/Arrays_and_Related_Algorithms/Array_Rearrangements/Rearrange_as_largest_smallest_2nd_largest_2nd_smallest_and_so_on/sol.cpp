#include <bits/stdc++.h>

#define vector_input(a, n) for(int i = 0; i < n; ++i) cin >> a[i]
#define vector_output(a, n) for(int i = 0; i < n; ++i) cout << a[i] << " "

using namespace std;

void rearrange(vector<int>& a, int n){
	sort(a.begin(), a.end());
	vector<int> b = a;
	int i = 0, j = n - 1, k = 0;
	while(i < j){
		a.at(k++) = b.at(i++);
		a.at(k++) = b.at(j--);
	}
	if(i == j)
		a.at(k) = b.at(j);
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