// O(n^2) solution to http://codeforces.com/contest/1008/problem/C
// The algorithm seems correct.
// No wrong answer, but TLE on largest test case with only two values in the input array.

#include <bits/stdc++.h>

using namespace std;

int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	int n;
	cin >> n;
	// int a[n];
	vector<int> a(n);
	// for(int i = 0; i < n; ++i)
	// 	a[i] = (rand() % 2) + 1;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	// for(int i = 0; i < n; ++i)
	// 	cout << a[i] << " ";
	sort(a.begin(), a.end());
	unordered_set<int> s;
	int ctr = 0;
	int j;
	int k;
	int i_lower_limit;
	int last_known_val = a[0];
	bool seen_earlier = false;
	unordered_map<int, int> limits;
	for(int i = 0; i < n; ++i){
		if(a[i] != last_known_val){
			last_known_val = a[i];
			seen_earlier = false;
		}
		if(!seen_earlier){
			limits[a[i]] = i;
			seen_earlier = true;
		}
	}
	// if(limits.size() == 2){
	// 	int max = -INT_MAX;
	// 	for(auto i = limits.begin(); i != limits.end(); ++i){
	// 		if(max < i->first)
	// 			max = i->first;
	// 	}
	// 	cout << n - limits[max];
	// 	return 0;
	// }

	for(auto itr = limits.begin(); itr != limits.end(); ++itr)
		// cout << "\n" << itr->first << ": " << itr->second;
	for(int i = n - 1; i >= 0; --i){
		if(s.find(i) == s.end()){
			s.insert(i);
			j = limits[a[i]] - 1;
			if(j <= 0)
				break;
			k = 1;
			while(j >= 0){
				// while((j - k >= 0) && s.find(j - k) != s.end())
				// 	++k;
				// if(j - k >= 0){
				// 	++ctr;
				// 	s.insert(j - k);
				// }
				// j = j - k;
				// k = 1;
				if(s.find(j) == s.end()){
					// cout << "\ni: " << i << "\tj: " << j;
					s.insert(j);
					ctr++;
					j = limits[a[j]] - 1;
				}
				else{
					// cout << "\n.";
					--j;	
				}
			}
		}
	}
	cout << ctr;
	return 0;
}