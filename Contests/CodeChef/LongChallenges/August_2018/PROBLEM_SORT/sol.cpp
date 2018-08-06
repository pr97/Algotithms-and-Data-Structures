#include <bits/stdc++.h>

using namespace std;

int coupled_partition(vector<int>& a, vector<int>& b, int l, int r){
	int pivot = rand() % (r - l + 1) + l;
	swap(a[pivot], a[r]);
	swap(b[pivot], b[r]);
	pivot = r;
	int i = l - 1;
	for(int j = l; j <= r - 1; ++j){
		if(a[j] < a[pivot]){
			++i;
			swap(a[j], a[i]);
			swap(b[j], b[i]);
		}
	}
	swap(a[i + 1], a[pivot]);
	swap(b[i + 1], b[pivot]);
	pivot = i + 1;
	return pivot;
}

void coupled_q_sort(vector<int>& a, vector<int>& b, int l, int r){
	if(l >= r)
		return;
	int p = coupled_partition(a, b, l, r);
	coupled_q_sort(a, b, l, p - 1);
	coupled_q_sort(a, b, p + 1, r);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int p, s;
	cin >> p >> s;
	vector<vector<int> > sc;
	vector<vector<int> > ns;
	for(int i = 0; i < p; ++i){
		sc.push_back(vector<int>(s));
		ns.push_back(vector<int>(s));
	}
	for(int i = 0; i < 2 * p; ++i){
		if(i % 2 == 0)
			for(int j = 0; j < s; ++j)
				cin >> sc[i / 2][j];
		else
			for(int j = 0; j < s; ++j)
				cin >> ns[i / 2][j];
	}
	vector<pair<int, int> > v;
	int n;
	for(int i = 0; i < p; ++i){
		coupled_q_sort(sc[i], ns[i], 0, s - 1);
	}
	for(int i = 0; i < p; ++i){
		n = 0;
		for(int j = 0; j < s - 1; ++j){
			if(ns[i][j] > ns[i][j + 1])
				++n;
		}
		v.push_back(make_pair(n, i + 1));
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < p; ++i)
		cout << v[i].second << "\n";
	return 0;
}