#include <bits/stdc++.h>

using namespace std;

#define vector_input(a, n) for(int i = 0; i < n; ++i) cin >> a[i]
#define vector_output(a, n) for(int i = 0; i < n; ++i) cout << a[i] << " "

void print_k_largest_sum_combination(vector<int>& a, vector<int>& b, int n, int k){

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	priority_queue<pair<int, pair<int, int> > > q;
	set<pair<int, int> > s;
	q.push(make_pair(a.at(n - 1) + b.at(n - 1), make_pair(n - 1, n - 1) ) );
	s.insert(make_pair(n - 1, n - 1));
	int ctr = k;
	int i = n - 1, j = n - 1;
	pair<int, pair<int, int> > temp;
	while(ctr--){
		temp = q.top();
		q.pop();
		i = temp.second.first;
		j = temp.second.second;
		if(i - 1 >= 0 && j - 1 >= 0){
			if(s.find(make_pair(i, j - 1)) == s.end()){
				q.push(make_pair(a.at(i) + b.at(j - 1), make_pair(i, j - 1) ) );
				s.insert(make_pair(i, j - 1));
				
			}
			if(s.find(make_pair(i - 1, j)) == s.end()){
				q.push(make_pair(a.at(i - 1) + b.at(j), make_pair(i - 1, j) ) );
				s.insert(make_pair(i - 1, j));
			}
		}
		cout << "(A : " << a.at(temp.second.first) << ") + (B : " << b.at(temp.second.second) << ") = " << temp.first << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);		
	int n, k;
	cin >> n >> k;
	vector<int> a(n), b(n);
	vector_input(a, n);
	vector_input(b, n);
	print_k_largest_sum_combination(a, b, n, k);
	return 0;
}