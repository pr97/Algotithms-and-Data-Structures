#include <bits/stdc++.h>

using namespace std;

#define vector_input(a, n) for(int i = 0; i < n; ++i) cin >> a[i]
#define vector_output(a, n) for(int i = 0; i < n; ++i) cout << a[i] << " "

int kadane_max_subarray_sum_in_linear_time(vector<int>& a, int n, int& start_index, int& end_index){
	int current_subarray_sum = 0;
	int max_subarray_sum = INT_MIN;
	int i = 0, j = 0, max_i = 0, max_j = 0;
	for(int x = 0; x < n; ++x){
		current_subarray_sum += a.at(x);
		j = x;
		if(max_subarray_sum < current_subarray_sum){
			max_subarray_sum = current_subarray_sum;
			max_i = i;
			max_j = j;
		}
		if(current_subarray_sum < 0){
			current_subarray_sum = 0;
			i = x + 1;
			j = x;
		}
	}
	start_index = max_i;
	end_index = max_j;
	return max_subarray_sum;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);		
	int n;
	cin >> n;
	vector<int> a(n);
	vector_input(a, n);
	int start, end;
	int max_subarray_sum = kadane_max_subarray_sum_in_linear_time(a, n, start, end);
	cout << max_subarray_sum << " (" << start << ", " << end << ")";
	return 0;
}