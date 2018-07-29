#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	int last_max_index;
	vector<int> l(n);
	int max_index;
	for(int i = 0; i < n; ++i){
		if(i == 0){
			l[i] = 1;
		}
		else{
			max_index = 0;
			for(int j = 1; j < i; ++j){
				if(a[i] > a[j] && l[j] > l[max_index])
					max_index = j;
			}
			if(max_index == 0)
				l[i] = l[0];
			else
				l[i] = 1 + l[max_index];

		}
	}
	int max_len = -1;
	for(int i = 0; i < n; ++i){
		if(l[i] > max_len)
			max_len = l[i];
	}
	cout << max_len;
	return 0;
}