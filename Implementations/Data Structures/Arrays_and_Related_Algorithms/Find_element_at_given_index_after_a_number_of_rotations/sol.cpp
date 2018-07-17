#include <bits/stdc++.h>

using namespace std;

int get_value_at_index_after_rotations(int a[], int rot[][2], int n, int k, int index){
	for(int i = k - 1; i >= 0; --i){
		if(index >= rot[i][0] && index <= rot[i][1]){
			if(index == rot[i][0])
				index = rot[i][1];
			else
				--index;
		}
	}
	return a[index];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, index;
	cin >> n >> k >> index;
	int a[n];
	int rot[k][2];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < k; ++i)
		cin >> rot[i][0] >> rot[i][1];
	int value_at_index_after_rotations = get_value_at_index_after_rotations(a, rot, n, k, index);
	cout << value_at_index_after_rotations;
	return 0;
}