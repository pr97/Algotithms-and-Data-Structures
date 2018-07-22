#include <bits/stdc++.h>

using namespace std;

void print_parent(vector<int> vec){
	int n = vec.size();
	cout << "\n++++++++++++++++++++++++++";
	cout << "\n";
	for(int i = 0; i < n; ++i){
		cout << "{i = " << i << " : parent(i) = " << vec.at(i) << "}";
		cout << "\n";
	}
	cout << "++++++++++++++++++++++++++\n";
}

int main(){
	for(int i = 1; i <= 15000; ++i){
		cout << 1 << " " << i + 15000;
	}
	return 0;
}