#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	double med;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	priority_queue<int> max_heap;
	priority_queue<int, vector<int>, greater<int> > min_heap;
	for(int i = 0; i < n; ++i){
		if(min_heap.size() == max_heap.size()){
			if(max_heap.size() == 0){
				med = a[i];
				max_heap.push(a[i]);
				cout << med << endl;
				continue;
			}
			if(a[i] <= med){
				max_heap.push(a[i]);
				med = max_heap.top();
			}
			else{
				min_heap.push(a[i]);
				med = min_heap.top();
			}
		}
		else if(max_heap.size() > min_heap.size()){
			if(a[i] <= max_heap.top()){
				min_heap.push(max_heap.top());
				max_heap.pop();
				max_heap.push(a[i]);
				med = ((double)max_heap.top() + (double)min_heap.top()) / 2;
			}
			else{
				min_heap.push(a[i]);
				med = ((double)max_heap.top() + (double)min_heap.top()) / 2;
			}
		}
		else if(max_heap.size() < min_heap.size()){
			if(a[i] >= min_heap.top()){
				max_heap.push(min_heap.top());
				min_heap.pop();
				min_heap.push(a[i]);
				med = ((double)max_heap.top() + (double)min_heap.top()) / 2;
			}
			else{
				max_heap.push(a[i]);
				med = ((double)max_heap.top() + (double)min_heap.top()) / 2;
			}
		}
		cout << floor(med) << endl;
	}
	return 0;
}