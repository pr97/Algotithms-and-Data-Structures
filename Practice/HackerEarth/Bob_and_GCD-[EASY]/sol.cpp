#include <bits/stdc++.h>

using namespace std;

long long min_ops(int& k, int& n, vector<int>& a);

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int k, n;
		cin >> k >> n;
		vector<int> a(n);
		for(vector<int>::iterator i = a.begin(); i != a.end(); ++i){
			cin >> *i;
		}
		cout << min_ops(k, n, a) << "\n";
	}
	return 0;
}

long long min_ops(int& k, int& n, vector<int>& a){
	long long res = 0;
	int half_threshold = k / 2;
	int a_mod_k;
	for(int i = 0; i < n; ++i){
		a_mod_k = a.at(i) % k; 
		if(a.at(i) < k){
			res += (k - a_mod_k);
		}
		else{
			if(a_mod_k <= half_threshold){
				res += a_mod_k;
			}
			else{
				res += (k - a_mod_k);
			}
		}
	}
	return res;
}
