#include <bits/stdc++.h>
 
using namespace std;
 
template<class T>
class MaxHeap{
	public:
		vector<T> a;
		int size, capacity; // 'size' holds the number of elements currently in the heap. 'size - 1' is the index of the last element.
		MaxHeap(){
			this->size = 0;
			this->capacity = 0;
		}
		MaxHeap(vector<int> vec){
			for(vector<int> :: iterator itr = vec.begin(); itr != vec.end(); ++itr)
				this->insert(T(*itr));
		}
		int parent(int i){
			return (i - 1) / 2;
		}
		int left_child(int i){
			return 2 * i + 1;
		}
		int right_child(int i){
			return 2 * i + 2;
		}
		void shift_up(int i){
			while( parent(i) >= 0 && a.at(i) > a.at(parent(i)) ){
				swap(a.at(i), a.at(parent(i)));
				i = parent(i);
			}
		}
		void shift_down(int i){
			while(i < size){
				int min_index = i;
				if(left_child(i) < size && a.at(min_index) < a.at(left_child(i)))
					min_index = left_child(i);
				if(right_child(i) < size && a.at(min_index) < a.at(right_child(i)))
					min_index = right_child(i);
				if(min_index == i)
					return;
				else
					swap(a.at(i), a.at(min_index));
				i = min_index;
			}
		}
		void insert(T item){
			if(size == capacity){
				if(a.size() == 0)
					capacity = 1;
				else
					capacity *= 2;
				a.resize(capacity);
			}
			a.at(size) = item;
			shift_up(size);
			++size;
		}
		T extract_max(){
			if(size > 0){
				T top = a.at(0);
				swap(a.at(0), a.at(size - 1));
				--size;
				shift_down(0);
				return top;
			}
			else{
				cout << "\nFATAL ERROR: Can't extract. Heap size 0!\n";
				exit(1);
			}
		}
		void print_heap(){
			if(size == 0){
				cout << "heap size: " << size << "\narray container capacity: " << capacity;
				return;
			}
			cout << "heap size: " << size << "\narray container capacity: " << capacity << "\n\n";
			int level = 1;
			int level_limit = pow(2, level);
			int curr_index = 0;
			while(curr_index < size){
				if(curr_index == level_limit - 1){
					cout << "\n";
					++level;
					level_limit = pow(2, level);
				}
				cout << a.at(curr_index) << " ";
				++curr_index;
			}
			cout << "\n";
		}

		vector<T> heap_sort(){
			vector<T> reserve = a;
			int n = size;
			int t = size;
			while(t--){
				T item = extract_max();
				a.at(size) = item;
			}
			vector<T> sorted = a;
			sorted.resize(n);
			a = reserve;
			size = n;
			return sorted;
		}
		void clear(){
			size = 0;
			capacity = 0;
			a.resize(0);
		}
};

void print_vec(vector<int> v){
	int n = v.size();
	for(int i = 0; i < n; ++i){
		cout << v.at(i) << " ";
	}
	cout << "\n";
}


// Driver main function for testing.
int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	MaxHeap<int> heap;
	heap.insert(15);
	heap.insert(14);
	heap.insert(13);
	heap.insert(10);
	heap.insert(11);
	heap.insert(12);
	heap.insert(0);
	heap.insert(1);
	heap.insert(2);
	heap.insert(6);
	heap.insert(5);
	heap.insert(4);
	heap.insert(3);
	heap.insert(7);
	heap.insert(8);
	heap.insert(9);
	heap.insert(45);
	cout << "\n---------------------------\n";
	// cout << heap.extract_max() << " (exp: 45)\n"; 
	// cout << heap.extract_max() << " (exp: 15)\n";
	// cout << heap.extract_max() << " (exp: 14)\n";
	// cout << heap.extract_max() << " (exp: 13)\n";
	// cout << heap.extract_max() << " (exp: 12)\n";
	// cout << heap.extract_max() << " (exp: 11)\n";
	// cout << heap.extract_max() << " (exp: 10)\n";
	// cout << heap.extract_max() << " (exp: 9)\n";
	// cout << heap.extract_max() << " (exp: 8)\n";
	heap.print_heap();
	print_vec(heap.a);
	heap.print_heap();
	cout << "\n calling heap_sort\n";
	vector<int> sorted = heap.heap_sort();
	print_vec(heap.a);
	heap.print_heap();
	cout << "SORTED: ";
	print_vec(sorted);
	heap.clear();
	// cout << "\n+++++++++++++++++++++++++++++++++++\n";
	// MaxHeap<int> h(vector<int>({5, 4, 3, -1, 4}));
	// h.print_heap();
	// cout << h.extract_max() << " (exp: 5)\n";
	// cout << h.extract_max() << " (exp: 4)\n";
	// cout << h.extract_max() << " (exp: 4)\n";
	// h.print_heap();
	// h.insert(-4);
	// h.insert(2);
	// h.insert(10);
	// h.print_heap();
	// cout << h.extract_max() << " (exp: 10)\n";
	// cout << h.extract_max() << " (exp: 3)\n";
	// h.print_heap();
	return 0;
}