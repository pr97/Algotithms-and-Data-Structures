#include <bits/stdc++.h>

using namespace std;

#define nex(i) (i+n/2)%n

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	bool flag;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; ++i){
			cin >> a[i];
		}
		if(n % 2 != 0){
			cout << "NO" << "\n";
			continue;
		}
		flag = true;
		for(int i = 0; i < n / 2; ++i){
			if(a[i] != a[nex(i)]){
				if(a[i] == -1 || a[nex(i)] == -1){
					if(a[i] == -1){
						a[i] = a[nex(i)];
					}
					else{
						a[nex(i)] = a[i];
					}
				}
				else{
					flag = false;
					break;
				}
			}
			else{
				if(a[i] == -1){
					a[i] = 1;
					a[nex(i)] = 1;
				}
			}
		}
		if(flag == false){
			cout << "NO" << "\n";
			continue;
		}
		else{
			cout << "YES" << "\n";
			for(int i = 0; i < n; ++i){
				cout << a[i] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}

// /* Solution upto subtask 2 */

// #include <bits/stdc++.h>

// using namespace std;

// int main(){
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	int t;
// 	cin >> t;
// 	while(t--){
// 		int n;
// 		cin >> n;
// 		if(n % 2 != 0){
// 			cout << "NO" << "\n";
// 			continue;
// 		}
// 		vector<int> a(n);
// 		for(int i = 0; i < n; ++i){
// 			cin >> a[i];
// 		}
// 		cout << "YES" << "\n";
// 		for(int i = 0; i < n; ++i){
// 			cout << 1 << " ";
// 		}
// 		cout << "\n";
// 	}
// 	return 0;
// }

#include <bits/stdc++.h>

using namespace std;

#define nex(i) (i+n/2)%n


