#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	cin.ignore();
	while(t--){
		string f, b;
		getline(cin, f);
		getline(cin, b);
		bool res = false;
		for(int i = 0; i < 3; ++i){
			if(f.at(i) == 'o' || b.at(i) == 'o'){
				if(i == 0){
					if((f.at(1) == 'b' || b.at(1) == 'b') && (f.at(2) == 'b' || b.at(2) == 'b'))
						res = true;
				}
				if(i == 1){
					if((f.at(0) == 'b' || b.at(0) == 'b') && (f.at(2) == 'b' || b.at(2) == 'b'))
						res = true;
				}
				if(i == 2){
					if((f.at(0) == 'b' || b.at(0) == 'b') && (f.at(1) == 'b' || b.at(1) == 'b'))
						res = true;
				}
			}
		}
		if(res)
			cout << "yes";
		else
			cout << "no";
		cout << "\n";
	}
	return 0;
}