#include <bits/stdc++.h>

using namespace std;

void rearrange(vector<int>& a, int n){
	for(int i = 0; i < n; ++i){
		if(a[i] != i){
			if(a[i] >=0 && a[i] < n){
				int x = i;
				while(a[x] != -1 && a[x] != a[a[x]])
					swap(a[x], a[a[x]]);
			}
		}
	}
// Not required since it's given that the absence of a required element will always be denoted by '-1'. 
	for(int i = 0; i < n; ++i){
		if(a[i] != i)
			assert(a[i] == -1);
	}
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
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		rearrange(a, n);
		for(int i = 0; i < n; ++i)
			cout << a[i] << " ";
		cout << "\n";
	}
	return 0;
}

/* 
* Wrong Algorithm.
*/

// #include <bits/stdc++.h>

// using namespace std;

// void rearrange(vector<int> b, int n){
//     vector<int>& a = b;
// 	for(int i = 0; i < n; ++i){
// 		if(a[i] != i){
// 			if(a[i] >=0 && a[i] < n)
// 				swap(a[i], a[a[i]]);
// 		}
// 	}
// 	for(int i = 0; i < n; ++i){
// 		if(a[i] != i){
// // 			cout << a[i] << "-" << i << "\n";
// 			assert(a[i] == -1);
// 		}
// 	}
// }

// int main(){
// // 	ios_base::sync_with_stdio(false);
// // 	cin.tie(NULL);
// 	int t;
// 	cin >> t;
// 	while(t--){
// 		int n;
// 		cin >> n;
// 		vector<int> a(n);
// 		for(int i = 0; i < n; ++i)
// 			cin >> a[i];
// // 		cout << "TAG!";
// 		rearrange(a, n);
// 		for(int i = 0; i < n; ++i)
// 			cout << a[i] << " ";
// 		cout << "\n";
// 	}
// 	return 0;
// }