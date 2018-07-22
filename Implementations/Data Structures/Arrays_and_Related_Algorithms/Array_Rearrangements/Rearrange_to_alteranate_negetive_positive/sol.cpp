#include <bits/stdc++.h>
using namespace std;

int partition_with_pivot_0(int a[], int l, int r){
    int pivot_value = 0;
    int i = l - 1;
    for(int j = l; j <= r - 1; ++j){
        if(a[j] < pivot_value)
        {
            ++i;
            swap(a[j], a[i]);
        }
    }
    int pivot = i + 1;
    return pivot;
}

int rearrange(int a[], int n, int pivot){
    // 'pivot' represents the index of the first non-negetive value.
    int num_non_negetive = n - pivot;
    int num_negetive = n - num_non_negetive;
    bool more_positive_numbers = (num_non_negetive > num_negetive);
    int shift_lim;
    if(!more_positive_numbers){
        int shift = num_negetive - num_non_negetive;
        for(int i = pivot - 1, j = n - 1, ctr = 0; ctr < shift; ++ctr){
            swap(a[i], a[j]);
            --i;
            --j;
            --pivot;
        }
    }
    
    if(pivot % 2 == 1){
        for(int i = 0; i < pivot; i += 2){
            swap(a[i], a[pivot + i]);
        }    
    }
    else{
        for(int i = 0; i < pivot; i += 2){
            swap(a[i], a[pivot + i + 1]);
        }
    }
    
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    int a[n];
	    for(int i = 0; i < n; ++i)
	        cin >> a[i];
	    int pivot = partition_with_pivot_0(a, 0, n - 1);
	    rearrange(a, n, pivot);
	    for(int i = 0; i < n; ++i)
	        cout << a[i] << " ";
        cout << "\n";
	}
	return 0;
}