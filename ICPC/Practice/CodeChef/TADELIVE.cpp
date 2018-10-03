#include <bits/stdc++.h>

using namespace std;

#define seqin(a,n) for(int i = 0; i < n; ++i) cin >> a[i]
#define seqin_1ind(a,n) for(int i = 1; i <= n; ++i) cin >> a[i]
#define seqout(a,n) for(int i = 0; i < n; ++i) cout << a[i] << " "
#define seqout_1ind(a,n) for(int i = 1; i <= n; ++i) cout << a[i] << " "
#define subseqout(a,x,y) for(int i = x; i <= y; ++i) cout << a[i] << " "

#define ll long long
#define inf INT_MAX / 10

int a[(int)1e5 + 1];
int b[(int)1e5 + 1];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x, y;
	cin >> n >> x >> y;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	for(int i = 1; i <= n; ++i){
		cin >> b[i];
	}
	int sum = 0;
	for(int i = 1; i <= n; ++i){
		if(a[i] > b[i]){
			if(x){
				x--;
				sum += a[i];
			}
			else{
				y--;
				sum += b[i];
			}
		}
		else if(a[i] < b[i]){
			if(y){
				y--;
				sum += b[i];
			}
			else{
				x--;
				sum += a[i];
			}
		}
		else{
			if(x > y){
				sum += a[i];
				x--;
			}
			else{
				sum += b[i];
				y--;
			}
		}
	}
	cout << sum;
	return 0;
}