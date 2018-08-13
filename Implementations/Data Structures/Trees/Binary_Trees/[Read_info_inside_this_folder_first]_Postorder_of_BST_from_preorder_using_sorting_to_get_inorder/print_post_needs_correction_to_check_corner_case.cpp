#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& vec, int starting_index, int x, int sz){
    for(int i = starting_index; i < starting_index + sz; ++i){
        if(vec[i] == x)
            return i - starting_index;
    }
    return -1;
}

void print_post(vector<int>& pre, int pre_start, vector<int>& in, int in_start, int n){
    int root = search(in, in_start, pre[pre_start], n);
    if(root != 0){
        print_post(pre, pre_start + 1, in, in_start, root);
    }
    if(root != n - 1){
        print_post(pre, pre_start + root + 1, in, in_start + root + 1, n - 1 - root);
    }
    cout << in[in_start + root] << " ";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vector<int> in, pre(n);
	    for(int i = 0; i < n; ++i)
    	    cin >> pre[i];
    	in = pre;
    	sort(in.begin(), in.end());
    	print_post(pre, 0, in, 0, n);
    	cout << "\n";
	}
	return 0;
}