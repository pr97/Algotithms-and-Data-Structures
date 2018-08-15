#include <bits/stdc++.h>
using namespace std;

void print_array(char a[], int sz){
	for(int i = 0; i < sz; ++i)
		cout << a[i];
	cout << " ";
}

void permute_util(char* s, unordered_map<char, int>& cnt, char perm[], int level, int& n){
	if(level == n){
		print_array(perm, n);
		return;
	}
	for(int i = 0; i < n; ++i){
		if(cnt[s[i]] == 0)
			continue;
		--cnt[s[i]];
		perm[level] = s[i];
		permute_util(s, cnt, perm, level + 1, n);
		++cnt[s[i]];
	}

}

void permute(char* s, bool lexicographically = true){
	int n = strlen(s);
	if(lexicographically)
		sort(s, s + n);
	unordered_map<char, int> cnt;
	for(int i = 0; i < n; ++i)
		++cnt[s[i]];
	char perm[n];
	permute_util(s, cnt, perm, 0, n);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		char* s;
		gets(s);
		int n = strlen(s);
		permute(s);
		cout << "\n";
	}
	return 0;
}