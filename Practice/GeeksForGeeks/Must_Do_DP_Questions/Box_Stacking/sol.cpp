#include <bits/stdc++.h>

using namespace std;

struct Box{
	int h;
	int d;
	int w;
};

bool compare(Box a, Box b){
	return a.d * a.w > b.d * b.w;
}

int box_stack_max_height(vector<Box>& a, int n){
	int len = 3 * n;
	vector<int> dp(len);
	int max, global_max = INT_MIN;
	for(int i = 0; i < len; ++i){
		if(i == 0){
			dp.at(i) = a.at(i).h;
		}
		else{
			max = -1;
			for(int j = 0; j < i; ++j){
				if(dp.at(j) > max && a.at(j).w > a.at(i).w && a.at(j).d > a.at(i).d){
					max = dp.at(j);
				}
			}
			if(max == -1)
				dp.at(i) = a.at(i).h;
			else
				dp.at(i) = max + a.at(i).h;
		}
		if(global_max < dp.at(i))
			global_max = dp.at(i);
	}
	return global_max;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		Box in;
		int h, w, d;
		vector<Box> a;
		for(int i = 0; i < n; ++i){
			cin >> h >> w >> d;
			in.h = h; in.w = (w > d)? w : d; in.d = (w <= d)? w : d;
			a.push_back(in);
			in.h = w; in.w = (h > d)? h : d; in.d = (h <= d)? h : d;
			a.push_back(in);
			in.h = d; in.w = (h > w)? h : w; in.d = (h <= w)? h : w;
			a.push_back(in);
		}
		sort(a.begin(), a.end(), compare);
		cout << box_stack_max_height(a, n) << "\n";

	}
	return 0;
}