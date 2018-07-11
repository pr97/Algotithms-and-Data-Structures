#include <bits/stdc++.h>

using namespace std;

int max_area_hist(vector<int>&);
int maximal_rectangle(vector<vector<char> >&);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// Code for input, function call and output goes here. The implemented algorithm is correct and runs in O(num_rows * num_columns) time. --SOLUTION_ACCEPTED_ON_LEETCODE
	return 0;
}

int maximalRectangle(vector<vector<char>>& mat) {
        
    // 'mat' is a matrix of char(s) because of the LeetCode problem format. In the general case int would be preferred.

    int m = mat.size();
    if(m == 0) return 0;
    int n = mat.at(0).size();
    vector<int> hist(n, 0);
    int max_area = 0;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(mat.at(i).at(j) - '0' == 0) hist.at(j) = 0;	// '0' has been subtracted only for enabling the algorithm to work with the LeetCode input format of a character matrix instead of an integer matrix. It's not required in the general case.
            else hist.at(j) += (mat.at(i).at(j) - '0');		// '0' has been subtracted only for enabling the algorithm to work with the LeetCode input format of a character matrix instead of an integer matrix. It's not required in the general case.
        }
        int max_area_for_hist = max_area_hist(hist);
        if(max_area_for_hist > max_area) max_area = max_area_for_hist;
    }
    return max_area;
}

int max_area_hist(vector<int>& hist){
	int n = hist.size();
	int max = 0, i = 0, area;
	vector<int> stack;
	stack.push_back(-1);
	while(!(i >= n && stack.size() == 1)){
		if(*stack.rbegin() == -1){
			stack.push_back(i);
			++i;
		}
		else if(i < n && hist.at(i) >= hist.at(*stack.rbegin()) ){
			stack.push_back(i);
			++i;
		}
		else{
		    int l = hist.at(*stack.rbegin()), b = (i - (*(stack.rbegin() + 1) + 1));
			area = l * b;
			if(area >= max){
				max = area;
			}
			stack.pop_back();
		}
	}
	return max;
}