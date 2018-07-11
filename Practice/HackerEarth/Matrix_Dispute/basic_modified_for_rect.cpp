#include <bits/stdc++.h>

using namespace std;

int get_largest_square_size(vector<vector<int> >);
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
	vector<vector<int> > R, C;
	R = a;
	C = a;
	if(m == 1 and n == 1)
		return 1;
	int lsi = 0; int lsj = 0;
	int max_size = 0;
	int right_r, down_r, diag_down_r, right_c, down_c, diag_down_c;
	for(int i = m - 2; i >= 0; --i){
		for(int j = n - 2; j >= 0; --j){
			right_r = R.at(i).at(j + 1);
			down_r = R.at(i + 1).at(j);
			diag_down_r = R.at(i + 1).at(j + 1);
			if(R.at(i).at(j)){
				R.at(i).at(j) = min({down_r, diag_down_r}) + 1; // Since this calculates the number of rows at that point, consideration of only down_r anf diag_down_r reqd.
			}
			right_c = C.at(i).at(j + 1);
			down_c = C.at(i + 1).at(j);
			diag_down_c = C.at(i + 1).at(j + 1);
			if(C.at(i).at(j)){
				C.at(i).at(j) = min({right_c, diag_down_c}) + 1; // Since this calculates the number of rows at that point, consideration of only right_c anf diag_down_c reqd.
			}
			if(R.at(i).at(j) * C.at(i).at(j) >= max_size){
				max_size = R.at(i).at(j) * C.at(i).at(j);
				lsi = i;
				lsj = j;
			}

		}
	}
	cout << "\n(" << lsi << ", " << lsj << ")\n";
	print_matrix(R);
	cout << "----------\n";
	print_matrix(C);
	return max_size;
}