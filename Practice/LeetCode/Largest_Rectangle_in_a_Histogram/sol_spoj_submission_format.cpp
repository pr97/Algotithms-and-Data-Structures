#include <bits/stdc++.h>

using namespace std;

long long max_area(vector<long long>);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	cin >> n;
	while(n != 0){
		vector<long long> hist(n, 0);
		for(long long i = 0;i < n; ++i)
			cin >> hist.at(i);
		cout << max_area(hist) << "\n";
		cin >> n;
	}
	return 0;
}

long long max_area(vector<long long> hist){
	long long n = hist.size();
	long long max = 0, i = 0, area;
	vector<long long> stack;
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
		    long long l = hist.at(*stack.rbegin()), b = (i - (*(stack.rbegin() + 1) + 1));
			area = l * b;
			if(area >= max){
				max = area;
			}
			stack.pop_back();
		}
	}
	return max;
}