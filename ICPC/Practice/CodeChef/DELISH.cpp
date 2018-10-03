#include <bits/stdc++.h>

using namespace std;

#define seqin(a,n) for(int i = 0; i < n; ++i) cin >> a[i]
#define seqin_1ind(a,n) for(int i = 1; i <= n; ++i) cin >> a[i]
#define seqout(a,n) for(int i = 0; i < n; ++i) cout << a[i] << " "
#define seqout_1ind(a,n) for(int i = 1; i <= n; ++i) cout << a[i] << " "
#define subseqout(a,x,y) for(int i = x; i <= y; ++i) cout << a[i] << " "

#define ll long long

ll d[(int)1e4 + 1];
ll hard_left_max[(int)1e4 + 1];
ll hard_left_min[(int)1e4 + 1];
ll hard_right_max[(int)1e4 + 1];
ll hard_right_min[(int)1e4 + 1];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		seqin_1ind(d,n);
		hard_left_min[1] = d[1];
		hard_left_max[1] = d[1];
		hard_right_min[n] = d[n];
		hard_right_max[n] = d[n];
		for(int i = 2; i <= n; ++i){
			hard_left_min[i] = min(d[i], d[i] + hard_left_min[i - 1]);
			hard_left_max[i] = max(d[i], d[i] + hard_left_max[i - 1]);
			// n - 1 - (i - 2) = n - i + 1
			hard_right_min[n - i + 1] = min(d[n - i + 1], d[n - i + 1] + hard_right_min[n - i + 1 + 1]);
			hard_right_max[n - i + 1] = max(d[n - i + 1], d[n - i + 1] + hard_right_max[n - i + 1 + 1]);
		}

		// Not required due to optimization in the above loop.
		// hard_right_min[n] = d[n];
		// hard_right_max[n] = d[n];
		// for(int i = n - 1; i >= 1; --i){
		// 	hard_right_min[i] = min(d[i], d[i] + hard_right_min[i + 1]);
		// 	hard_right_max[i] = max(d[i], d[i] + hard_right_max[i + 1]);
		// }

		// Stray code for debugging.
		// cout << "\nhard_left_max: "; subseqout(hard_left_max,1,n);
		// cout << "\nhard_left_min: "; subseqout(hard_left_min,1,n);
		// cout << "\nhard_right_max: "; subseqout(hard_right_max,1,n);
		// cout << "\nhard_right_min: "; subseqout(hard_right_min,1,n);
		// cout << "\n--------------";

		ll max_absolute_diff = INT_MIN;
		for(int i = 1; i <= n - 1; ++i){
			max_absolute_diff = max(max_absolute_diff, hard_left_max[i] - hard_right_min[i + 1]);
			max_absolute_diff = max(max_absolute_diff, hard_right_max[i + 1] - hard_left_min[i]);
		}
		cout << max_absolute_diff << "\n";
	}
	return 0;
}