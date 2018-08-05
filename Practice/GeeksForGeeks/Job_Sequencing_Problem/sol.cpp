/*
* Link to question + OJ:-
* https://practice.geeksforgeeks.org/problems/job-sequencing-problem/0 
*/

#include <bits/stdc++.h>

#define id(i) jl.at(i).id
#define d(i) jl.at(i).d
#define p(i) jl.at(i).p

using namespace std;

class DisjointSet{
	public:
		vector<int> parent;
		DisjointSet(int n){
			parent.resize(n);
			for(int i = 0; i < n; ++i){
				parent.at(i) = i;
			}
		}
		int find(int x){
			if(x != parent.at(x)){
				parent.at(x) = find(parent.at(x));
			}
			return parent.at(x);
		}
		void union_(int x, int y){
			if(find(x) != find(y)){
				parent.at(x) = y;
			}
		}
};

struct Job{
	int id;
	int d;
	int p;
};

bool custom_compare(Job a, Job b){
	return a.p > b.p;
}

int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<Job> jl(n);
		for(int i = 0; i < n; ++i){
			cin >> jl.at(i).id >> jl.at(i).d >> jl.at(i).p;
		}
		int j_ctr = 0, max_p = 0;
		sort(jl.begin(), jl.end(), custom_compare);
		DisjointSet ds(d(0) + 1);
		for(int i = 0; i < n; ++i){
			cout << "\n1TAG!\n";
			cout << ds.find(d(i)) << "---";
			if(ds.find(d(i)) != 0){
				cout << "\n2TAG!\n";
				ds.union_(d(i), ds.find(d(i) - 1));
				++j_ctr;
				max_p += p(i);
			}

		}
		cout << j_ctr << " " << max_p << "\n";
	}
	return 0;
}