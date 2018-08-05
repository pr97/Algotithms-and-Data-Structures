/*
* Link to question: https://practice.geeksforgeeks.org/problems/min-sum-formed-by-digits/0
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		if(n == 1){
			cout << a[0];
			return 0;
		}
		sort(a.begin(), a.end());
		int p_sum1, p_sum2;
		int n1 = 0, n2 = 0, d1 = 0, d2 = 0;
		for(int i = n - 1; i - 1 >= 0; i -= 2){
			if(i == n - 1){
				d1 = 1;
				d2 = 1;
				n1 = a[i];
				n2 = a[i - 1];
			}
			else{
				p_sum1 = a[i] * pow(10, d1) + n1 + a[i - 1] * pow(10, d2) + n2;
				p_sum2 = a[i - 1] * pow(10, d1) + n1 + a[i] * pow(10, d2) + n2;
				if(p_sum1 < p_sum2){
					n1 = a[i] * pow(10, d1) + n1;
					n2 = a[i - 1] * pow(10, d2) + n2;
				}
				else{
					n1 = a[i - 1] * pow(10, d1) + n1;
					n2 = a[i] * pow(10, d2) + n2;	
				}
				++d1;
				++d2;
			}
		}
		if(n % 2 == 1){
			n1 = a[0] * pow(10, d1) + n1;
		}
		cout << n1 + n2 << "\n";
	}
	return 0;
}