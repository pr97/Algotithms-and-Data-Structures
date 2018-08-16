/*
* Link to question: https://practice.geeksforgeeks.org/problems/difficulty-of-sentence/0
*/

#include <bits/stdc++.h>

using namespace std;

bool is_cons(char a, unordered_set<char>& vow){
	if(vow.find(a) == vow.end())
		return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unordered_set<char> vow;
    vow.insert('a');
    vow.insert('A');
    vow.insert('e');
    vow.insert('E');
    vow.insert('i');
    vow.insert('I');
    vow.insert('o');
    vow.insert('O');
    vow.insert('u');
    vow.insert('U');
	int t;
	cin >> t;
	cin.ignore();
	while(t--){
		string s;
		getline(cin, s);
		int n = s.length();
		vector<int> space_ind;
		for(int i = 0; i < n; ++i){
			if(s.at(i) == ' ')
				space_ind.push_back(i);
		}
		int l, r;
		int hard = 0, easy = 0;
		for(int sp = 0; sp < space_ind.size(); ++sp){
			l = space_ind[sp] + 1;
			if(sp < space_ind.size() - 1){
				r = space_ind[sp + 1] - 1;
			}
			else{
				if(s.at(n - 1) == ' '){
					r = n - 2;
				}
				else{
					r = n - 1;
				}
			}
			if(l > r)
				continue;
			int consecutive_cons_cnt = 0;
			int n_cons = 0, n_vow = 0;
			bool four_consecutive = false, c_greater_than_v = false;
			for(int i = l; i <= r; ++i){
				if(is_cons(s.at(i), vow)){
					n_cons++;
					if(i > l){
						if(is_cons(s.at(i - 1), vow)){
							consecutive_cons_cnt++;
						}
						else{
							consecutive_cons_cnt = 1;
						}
						if(consecutive_cons_cnt == 4){
							four_consecutive = true;
						}
					}
					else if(i == l){
						consecutive_cons_cnt = 1;		
					}
				}
				else{
					consecutive_cons_cnt = 0;
					n_vow++;
				}
			}
			if(n_cons > n_vow){
				c_greater_than_v = true;
			}
			if(c_greater_than_v || four_consecutive){
				hard++;
				// cout << endl << s.substr(l, r - l + 1) << ": " << "hard " << n_cons << " " << n_vow << " --- " << c_greater_than_v << " " << four_consecutive;
			}
			else{
				easy++;
				// cout << endl << s.substr(l, r - l + 1) << ": " << "easy " << n_cons << " " << n_vow;
			}

		}
		l = 0;
		// cout << "\nSpaceSize: " << space_ind.size();
		if(space_ind.size() == 0){
			r = n - 1;
		}
		else{
			r = space_ind.at(0) - 1;
		}
		int consecutive_cons_cnt = 0;
		int n_cons = 0, n_vow = 0;
		bool four_consecutive = false, c_greater_than_v = false;
		for(int i = l; i <= r; ++i){
			if(is_cons(s.at(i), vow)){
				n_cons++;
				if(i > l){
					if(is_cons(s.at(i - 1), vow)){
						consecutive_cons_cnt++;
					}
					else{
						consecutive_cons_cnt = 1;
					}
					if(consecutive_cons_cnt == 4){
						four_consecutive = true;
					}
				}
				else if(i == l){
					consecutive_cons_cnt = 1;		
				}
			}
			else{
				consecutive_cons_cnt = 0;
				n_vow++;
			}
		}
		if(n_cons > n_vow){
			c_greater_than_v = true;
		}
		if(c_greater_than_v || four_consecutive){
			hard++;
			// cout << endl << s.substr(l, r - l + 1) << ": " << "hard " << n_cons << " " << n_vow << " --- " << c_greater_than_v << " " << four_consecutive;
		}
		else{
			easy++;
			// cout << endl << s.substr(l, r - l + 1) << ": " << "easy " << n_cons << " " << n_vow << " --- " << c_greater_than_v << " " << four_consecutive;
		}

		cout << 5 * hard + 3 * easy << "\n";
	}
	return 0;
}