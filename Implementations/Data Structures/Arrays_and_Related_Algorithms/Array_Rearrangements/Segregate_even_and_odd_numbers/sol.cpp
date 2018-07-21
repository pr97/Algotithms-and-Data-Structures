#include <bits/stdc++.h>

using namespace std;

#define vector_input(a, n) for(int i = 0; i < n; ++i) cin >> a[i]
#define vector_output(a, n) for(int i = 0; i < n; ++i) cout << a[i] << " "

void segregate(vector<int>& a, int n){
	int i = 0, j = n - 1;
	int ctr = 0; // Verification of time complexity.
	while(i < j){
		if(a.at(i) % 2 == 0 && a.at(j) % 2 == 1){
			++i;
			--j;
			++ctr; // Verification of time complexity.
		}
		else if(a.at(i) % 2 == 1 && a.at(j) % 2 == 0){
			swap(a.at(i), a.at(j));
			++i;
			--j;
			++ctr; // Verification of time complexity.
		}
		else if(a.at(i) % 2 == 1 && a.at(j) % 2 == 1){
			while(i < j && a.at(j) % 2 == 1){
				--j;
				++ctr; // Verification of time complexity.
			}
			if(i < j){
				swap(a.at(i), a.at(j));
				++i;
				--j;
			}
		}
		else if(a.at(i) % 2 == 0 && a.at(j) % 2 == 0){
			while(i < j && a.at(i) % 2 == 0){
				++i;
				++ctr; // Verification of time complexity.
			}
			if(i < j){
				swap(a.at(i), a.at(j));
				++i;
				--j;
			}
		}
	}
	cout << "\nNumber of operations: " << ctr << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);
	vector_input(a, n);
	segregate(a, n);
	vector_output(a, n);
	return 0;
}