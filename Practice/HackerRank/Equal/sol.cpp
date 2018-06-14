#include <bits/stdc++.h>

using namespace std;

#define INF INT_MAX;

map<vector<int>, int> mem;
vector<int> NC{1, 3, 5};
int n;

bool all_equal(vector<int>& v){
	int ref = v[0];
	for(vector<int> :: iterator itr = v.begin(); itr != v.end(); ++itr)
		if(ref != *itr) return false;
	return true;
}

int op(vector<int> state){
	cout << "[1]";
	if(all_equal(state))
		return 0;
	map<vector<int>, int> :: iterator it = mem.find(state);
	bool found = it != mem.end();
	if(found)
		return it->second;
	else{
		int MIN = INF;
		for(vector<int> :: iterator nc = NC.begin(); nc != NC.end(); ++nc){
			for(int e = 0; e < n; ++e){
				vector<int> new_state = state;
				for(int i = 0; i < n; ++i){
					if(i == e)
						continue;
					new_state[i] += *nc;
				}
				if(e == 0 && *nc == 1){
					cout << "TAG";
				}
				int operations = op(new_state); // Recursive call.
				if(operations < MIN)
					MIN = operations;

			}
		}
		mem[state] = MIN + 1;
		return MIN + 1;
	}
}

int main(int argc, char const *argv[])
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	int t;
	cin >> t;
	int min_ops; // Make sure 'min_ops' remains inside of the integer limit.
	vector<int> c;
	cout << t;
	while(t--){
		c.clear();
		cin >> n;
		c.resize(n);
		for(size_t i = 0; i < n; ++i){
			cin >> c[i];
		}
			
		min_ops = op(c);
		cout << "--"; /**/
		cout << min_ops << "\n";
	}
	return 0;
}