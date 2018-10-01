#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for(int i = 0; i < n; ++i)
			cin >> a.at(i);
		for(int i = 0; i < n; ++i)
			cin >> b.at(i);
		unordered_map<int, int> m_a, m_b;
		for(int i = 0; i < n; ++i){
			m_a[a.at(i)]++;
			m_b[b.at(i)]++;
		}
		bool are_equal = true;
		for(int i = 0; i < n; ++i){
			if(m_a[a.at(i)] != m_b[a.at(i)]){
				are_equal = false;
				break;
			}
		}
		if(are_equal)
			cout << 1;
		else
			cout << 0;
		cout << "\n";
	}
	return 0;
}