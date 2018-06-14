#include <bits/stdc++.h>

using namespace std;

#define INF INT_MAX

int main(int argc, char const *argv[])
{
	map<vector<int>, int> m;
	vector<int> v{1, 2, 3}, e{2, 3};
	m[v] = -1;
	m[e] = 100;
	cout << m[v];
	cout << m[e];
	cout << "\n" << INF;
	return 0;
}