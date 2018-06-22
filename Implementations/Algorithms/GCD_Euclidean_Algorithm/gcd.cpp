#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
	int temp;
	while(b != 0){
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int main(){
	while(true){
		int x, y;
		cin >> x >> y;
		cout << "GCD: " << gcd(x, y) << "\n";
		cin.ignore();
	}
	return 0;
}