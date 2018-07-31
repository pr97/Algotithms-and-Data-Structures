#include <bits/stdc++.h>

using namespace std;

long long num_subarrays(vector<long long>& a, int n, long long k){
	long long ctr = 0;
	long long prod = a[0];
	int sub_size;
	if(prod < k){
		ctr = 1;
	}
	int i = 0, j = 0;
	while(j <= n - 1){
		if(prod >= k){
			if(i == j){
				++i;
				++j;
				if(i < n){
					prod = a[i];
					if(prod < k)
						ctr += 1;
				}
			}
			else{
				prod = prod / a[i];
				++i;
				if(prod < k){
					sub_size = j - i + 1;
					ctr += sub_size;
				}
			}
		}
		else{
			if(j + 1 < n){
				prod = prod * a[j + 1];
				if(prod < k){
					sub_size = j + 1 - i + 1;
					ctr += sub_size;
				}
			}
			++j;
		}
	}
	return ctr;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
    	int n;
    	long long k;
    	cin >> n >> k;
    	vector<long long> a(n);
    	for(int i = 0; i < n; ++i)
    		cin >> a[i];
    	long long result = num_subarrays(a, n, k);
    	cout << result << "\n";
    }
	return 0;
}