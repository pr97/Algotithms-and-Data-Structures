#include <bits/stdc++.h>

using namespace std;

int max_area(vector<int>);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> hist(n, 0);
	for(int i = 0;i < n; ++i)
		cin >> hist.at(i);
	cout << max_area(hist);
	return 0;
}

int max_area(vector<int> hist){
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