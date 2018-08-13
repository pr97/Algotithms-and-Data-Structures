#include <bits/stdc++.h>
using namespace std;

void get_post(vector<int>& pre, int& pre_index, int min, int max, int size, vector<int>& post){
    if(pre_index >= size)
        return;
    if(pre[pre_index] < min || pre[pre_index] > max)
        return;
    int key = pre[pre_index];
    ++pre_index;
    get_post(pre, pre_index, min, key, size); // For left sub tree.
    get_post(pre, pre_index, key, max, size); // For right sub tree.
    post.push_back(key);
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
        int pre_index = 0;
        vector<int> post;
    	get_post(pre, pre_index, INT_MIN, INT_MAX, n, post);
    	if(pre_index < n){
            cout << "NO";
        }
        else
            for(int i = 0; i < n; ++i)
                cout << post[i] << " ";
        cout << "\n";
	}
	return 0;
}