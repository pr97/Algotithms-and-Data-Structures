#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll naive_manhattan_distance(int&, vector<pair<ll , ll> >&);

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<ll, ll> > a(n);
	for(int i = 0; i < n; ++i){
		cin >> a.at(i).first >> a.at(i).second;
	}
	cout << naive_manhattan_distance(n, a);
	return 0;
}

ll naive_manhattan_distance(int& n, vector<pair<ll , ll> >& a){
	ll res = 0;
	for(int i = 0; i < n - 1; ++i){
		for(int j = i + 1; j < n; ++j){
			res += (abs(a.at(i).first - a.at(j).first) + abs(a.at(i).second - a.at(j).second));
		}
	}
	return res;
}