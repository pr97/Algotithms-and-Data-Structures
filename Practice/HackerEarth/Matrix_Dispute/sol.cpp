#include <bits/stdc++.h>

using namespace std;

void print_matrix(vector<vector<int> >);
pair<int, int> largest_rect_perrmute(vector<vector<int> >);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int r, c, in;
		cin >> r >> c;
		vector<vector<int> > a(r);
		for(int i = 0; i < r; ++i){
			for(int j = 0; j < c; ++j){
				cin >> in;
				a.at(i).push_back(in);
			}
		}
		pair<int, int> res = largest_rect_perrmute(a);
		cout << res.first << " " << res.second << "\n";
	}
	return 0;
}

pair<int, int> largest_rect_perrmute(vector<vector<int> > a){
	int r = a.size();
	int c = a.at(0).size();
	int max_with_row, max_with_col;
	
	return make_pair(max_with_row, max_with_col);
}

void print_matrix(vector<vector<int> > a){
	int r = a.size();
	int c = a.at(0).size();
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			cout << a.at(i).at(j) << " ";
		}
		cout << "\n";
	}
}