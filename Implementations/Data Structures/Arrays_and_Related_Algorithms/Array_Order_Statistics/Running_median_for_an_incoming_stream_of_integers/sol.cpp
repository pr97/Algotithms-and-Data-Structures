#include <bits/stdc++.h>

using namespace std;

#define vector_input(a, n) for(int i = 0; i < n; ++i) cin >> a[i]
#define vector_output(a, n) for(int i = 0; i < n; ++i) cout << a[i] << " "

void running_median(vector<int>& a, bool verbose = false){
	 priority_queue<int> s;
	 priority_queue<int, vector<int>, greater<int> > g;
	 float median; // Geeksforgeeks Online Judge accepts integer median (floor of actual value).
	 int n = a.size();
	 for(int i = 0; i < n; ++i){
		if(i == 0){
			median = a.at(0);
		 	s.push(a.at(0));
		}
		else if(s.size() == g.size()){
			if(a.at(i) >= median){
				g.push(a.at(i));
				median = g.top();
		 	}
		 	else{
		 		s.push(a.at(i));
		 		median = s.top();
		 	}
		}
		else if(s.size() > g.size()){
			if(a.at(i) < median){
				g.push(s.top());
				s.pop();
				s.push(a.at(i));
				median = float(s.top() + g.top()) / 2;
			}
			else{
				g.push(a.at(i));
				median = float(s.top() + g.top()) / 2;
			}
		}
		else if(g.size() > s.size()){
			if(a.at(i) > median){
				s.push(g.top());
				g.pop();
				g.push(a.at(i));
				median = float(s.top() + g.top()) / 2;
			}
			else{
				s.push(a.at(i));
				median = float(s.top() + g.top()) / 2;
			}
		}
		if(verbose)
			cout << "\nCurrent median: " << median << "\t(Number of integers read: " << i + 1 << ")";
		else
			cout << median << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);
	vector_input(a, n);
	running_median(a);
	return 0;
}