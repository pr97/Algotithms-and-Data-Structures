#include <bits/stdc++.h>

#define ll long long
#define INF LLONG_MAX
using namespace std;

void print_vec_of_vec(vector<vector<int> >);
void print_vec(vector<int>);

pair<int, ll> result(int&, int&, int&, vector<int>&, vector<vector<int> >&);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while(T--){
		int n, k, m;
		cin >> n >> k >> m;
		vector<int> p(n);
		for(int i = 0; i < n; ++i){
			cin >> p.at(i);
		}
		vector<vector<int> > t(n);
		for(int i = 0; i < n; ++i){
			t.at(i).resize(p.at(i));
			for(int j = 0; j < p.at(i); ++j){
				cin >> t.at(i).at(j);
			}
		}
		pair<int, ll> res = result(n, k, m, p, t);
		cout << res.first << " " << res.second << "\n";
	}

	return 0;
}

pair<int, ll> result(int& n, int& k, int& m, vector<int>& p, vector<vector<int> >& t){
	int idx; // Needs to be one-indexed ATQ.
	ll min_time;
	vector<ll> time(n, 0);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < p.at(i) - 1; ++j){
			time.at(i) += (k + t.at(i).at(j) + m);
		}
		time.at(i) += (t.at(i).at(p.at(i) - 1) + k);
	}
	ll min = INF;
	for(int i = 0; i < n; ++i){
		if(time.at(i) < min){
			idx = i;
			min = time.at(i);
		}
	}
	min_time = min;
	++idx;
	return make_pair(idx, min_time); // Remember to make idx one-indexed.
}

void print_vec_of_vec(vector<vector<int> > vec_of_vec){
	int idx = 0;
	for(vector<vector<int> > :: iterator i = vec_of_vec.begin();
		i != vec_of_vec.end();
		++i){
		cout << "\n[" << idx << "]: ";
		for(vector<int> :: iterator j = (*i).begin(); j != (*i).end(); ++j){
			cout << *j << " ";
		}
		cout << "\n";
		++idx;
	}
}

void print_vec(vector<int> vec){
	cout << "\n";
	for(vector<int> :: iterator i = vec.begin(); i != vec.end(); ++i){
		cout << *i << " ";
	}
	cout << "\n";
}