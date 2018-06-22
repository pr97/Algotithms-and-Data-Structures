#include <bits/stdc++.h>

using namespace std;

int get_largest_square_size(vector<vector<int> >);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<vector<int> > a;
	int m, n;
	cin >> m >> n;
	for(int i = 0; i < m; ++i)
		a.push_back(vector<int>(n));
	for(int i = 0; i < m; ++i)
		for(int j = 0; j < n; ++j)
			cin >> a.at(i).at(j);

	cout << get_largest_square_size(a);
	return 0;
}

int get_largest_square_size(vector<vector<int> > a){
	int m = a.size();
	int n = a.at(0).size();
	if(m == 1 and n == 1)
		return 1;
	int lsi = 0; int lsj = 0;
	int max_size = 0;
	int right, down, diag_down;
	for(int i = m - 2; i >= 0; --i){
		for(int j = n - 2; j >= 0; --j){
			right = a.at(i).at(j + 1);
			down = a.at(i + 1).at(j);
			diag_down = a.at(i + 1).at(j + 1);
			if(a.at(i).at(j) && right && down && diag_down){
				a.at(i).at(j) = min({right, down, diag_down}) + 1;
				if(a.at(i).at(j) >= max_size){
					max_size = a.at(i).at(j);
					lsi = i;
					lsj = j;
				}
			}
		}
	}
	cout << "\n(" << lsi << ", " << lsj << ")\n";
	return max_size;
}