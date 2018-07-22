#include <bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	Node* next;
};

class LinkedList{
	public:
		Node* head;
		LinkedList(){
			this->head = NULL;
		}
		Node* get_new_node(int val, Node* next_addr = NULL){
			Node* temp = new Node;
			temp->data = val;
			temp->next = next_addr;
			return temp;
		}
		void push(int val){
			// Inserts a node with data = 'val' at the front of the linked list.
			Node* new_node = get_new_node(val);
			if(this->head == NULL)
				head = new_node;
			else{
				new_node->next = this->head;
				this->head = new_node;
			}
		}
		void pop(){
			// Deletes a node from the front of the linked list.
			if(this->head != NULL){
				if(this->head->next == NULL){
					delete this->head;
					this->head = NULL;
				}
				else{
					Node* t = this->head;
					this->head = this->head->next;
					delete t;
				}
			}
		}
		void append(int val){
			// Inserts a node with data = 'val' at the end of the linked list.
			Node* new_node = get_new_node(val);
			if(this->head == NULL)
				this->head = new_node;
			else{
				Node* t = this->head;
				while(t->next != NULL)
					t = t->next;
				t->next = new_node;
			}
		}
		void de_append(){
			// Deletes a node from the end of the linked list.
			if(this->head != NULL){
				if(this->head->next == NULL){
					delete this->head;
					this->head = NULL;
				}
				else{
					Node* t = this->head;
					while(t->next->next != NULL)
						t = t->next;
					delete t->next;
					t->next = NULL;
				}
			}
		}
		void insert_after(int val, Node* prev){
			// Inserts a node after node whose address is pointed to by 'prev'.
			if(prev == NULL){
				cout << "FATAL ERROR! Invalid previous address.";
				exit(1);
			}
			Node* new_node = get_new_node(val);
			// CASE 1: When the linked list has only one node and 'prev' == head.
			// if(this->head == prev && this->head->next == NULL){
			// 	prev->next = new_node;
			// 	assert(this->head == prev && prev->next->next == NULL);
			// 	return;
			// }
			Node* t = this->head;
			while(t->next != NULL && t != prev)
				t = t->next;
			// CASE 2: When last node of linked list is found as a match for prev. This case encapsulates 'CASE 1'. Separate code for 'CASE 1' above is redundant.
			if(t->next == NULL && t == prev){
				t->next = new_node;
				return;
			}
			// CASE 3: When a node, somewhere in the middle of the linked list, is found as a match for 'prev'.
			if(t == prev){
				new_node->next = prev->next;
				prev->next = new_node;
				return;
			}
			// CASE 4: No match found for 'prev'.
			delete new_node;
			return;
		}
		void delete_node_with_address(Node* tbd){
			// Searches for a node with address pointed to by 'tbd' and deletes it of it's found.
			// Note: 'tbd' expands to 'to_be_deleted'.
			if(tbd == NULL){
				cout << "FATAL ERROR! Invalid address.";
				exit(1);
			}
			if(this->head == tbd && this->head->next == NULL){
				delete this->head;
				this->head = NULL;
				return;
			}
			if(this->head == tbd && this->head->next != NULL){
				this->head = tbd->next;
				delete tbd;
				return;
			}
			Node* t = this->head;
			while(t->next->next != NULL && t->next != tbd)
				t = t->next;
			if(t->next->next == NULL && t->next == tbd){
				delete t->next; // Equivalent to 'delete tbd;'.
				t->next = NULL;
				return;
			}
			if(t->next == tbd){
				t->next = t->next->next;
				delete tbd;
			}
		}
		void print_list(){
			Node* t = this->head;
			cout << "\nhead-->";
			while(t != NULL){
				cout << "[" << t->data << "]-->";
				if(t->next == NULL)
					cout << "X";
				t = t->next;
			}
		}
		~LinkedList(){
			cout << "\n----------------------------";
			if(this->head != NULL){ // This if condition isn't necessary. It's only present to avoid declaring a temporary pointer for no reason.
				Node* t;
				while(this->head != NULL){
					t = this->head;
					this->head = this->head->next;
					cout << "\nDeleting " << t->data;
					delete t;
				}
			}
		}
};

int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	cout << "\n";
	LinkedList ll;
	Node* rouge_address = ll.get_new_node(INT_MAX);
	// ll.insert_after(1, ll.head);
	ll.print_list();
	ll.push(1);
	ll.print_list();
	ll.insert_after(-1, ll.head); // Checks the behaviour of insert after function with only one element present in the linked list.
	ll.print_list();
	ll.insert_after(-100, rouge_address);
	ll.insert_after(-2, ll.head->next);
	ll.print_list();
	ll.push(2);
	ll.append(-3);
	ll.push(3);
	ll.print_list();
	ll.de_append();
	ll.pop();
	ll.print_list();
	ll.insert_after(0, ll.head);
	ll.print_list();
	ll.insert_after(0, ll.head->next->next->next);
	ll.print_list();
	ll.insert_after(0, ll.head->next->next->next->next->next);
	ll.print_list();
	ll.insert_after(100, ll.head->next->next->next->next->next->next);
	ll.print_list();
	cout << "\n________________________________+++++++++++++++++__________________________________";
	ll.delete_node_with_address(ll.head);
	ll.print_list();
	ll.delete_node_with_address(ll.head);
	ll.print_list();
	// At this point, the list looks like so: head-->[1]-->[-1]-->[0]-->[-2]-->[0]-->[100]-->X
	ll.delete_node_with_address(ll.head->next);
	ll.print_list();
	// At this point, the list looks like so: head-->[1]-->[0]-->[-2]-->[0]-->[100]-->X
	ll.delete_node_with_address(ll.head->next->next->next->next);
	ll.print_list();
	// At this point, the list looks like so: head-->[1]-->[0]-->[-2]-->[0]-->X
	ll.delete_node_with_address(ll.head->next->next);
	ll.print_list();
	// At this point, the list looks like so: head-->[1]-->[0]-->[0]-->X
	ll.insert_after(-2, ll.head->next);
	// At this point, the list looks like so: head-->[1]-->[0]-->[-2]-->[0]-->X
	ll.insert_after(100, ll.head->next->next->next);
	ll.print_list();
	// At this point, the list looks like so: head-->[1]-->[0]-->[-2]-->[0]-->[100]-->X
	ll.insert_after(-100, rouge_address);
	ll.delete_node_with_address(ll.head->next);
	ll.delete_node_with_address(ll.head->next->next);
	ll.print_list();
	// At this point, the list looks like so: head-->[1]-->[-2]-->[100]-->X
	ll.delete_node_with_address(ll.head->next);
	ll.print_list();
	// At this point, the list looks like so: head-->[1]-->[100]-->X
	ll.delete_node_with_address(ll.head);
	ll.print_list();
	// At this point, the list looks like so: head-->[100]-->X
	ll.delete_node_with_address(ll.head);
	ll.print_list();
	// At this point, the list looks like so: head-->
	ll.push(1);
	ll.append(100);
	ll.print_list();
	// At this point, the list looks like so: head-->[1]-->[100]-->X
	ll.delete_node_with_address(ll.head->next);
	ll.print_list();
	// At this point, the list looks like so: head-->[1]-->X
	ll.delete_node_with_address(ll.head);
	ll.print_list();
	// At this point, the list looks like so: head-->
	if(ll.head != NULL && ll.head->next == NULL)
		cout << "\nTAG! - Only one node left!";
	if(ll.head == NULL)
		cout << "\nTAG! - No node left!";
	cout << "\n";
	delete rouge_address;
	return 0;
}


/* ll_test */
	// ll.push(1);
	// ll.push(2);
	// ll.push(3);
	// ll.push(4);
	// ll.push(5);
	// ll.push(6);
	// ll.push(7);
	// ll.print_list();
	// ll.pop(); // deletes '7'.
	// ll.print_list();
	// ll.pop(); // deletes '6'.
	// ll.print_list();
	// ll.pop(); // deletes '5'.
	// ll.print_list();
	// ll.pop(); // deletes '4'.
	// ll.print_list();
	// ll.pop(); // deletes '3'.
	// ll.print_list();
	// ll.pop(); // deletes '2'.
	// ll.print_list();
	// ll.pop(); // deletes '1' (checks for the behaviour when the list contains a single element). 
	// ll.print_list();
	// ll.pop(); // checks the behaviour when the list is empty.
	// ll.print_list();
	// ll.push(1);
	// ll.print_list();
	// ll.push(2);
	// ll.push(3);
	// ll.push(4);
	// ll.push(5);
	// ll.push(6);
	// ll.push(7);
	// ll.print_list();
	// cout << "\n~^~^~^~^~^~^~^~^~^~^~^";
	// ll.append(-1);
	// ll.print_list();
	// ll.append(-2);
	// ll.print_list();
	// ll.pop();
	// ll.pop();
	// ll.pop();
	// ll.pop();
	// ll.pop();
	// ll.pop();
	// ll.pop();
	// ll.pop();
	// ll.pop();
	// ll.pop();
	// ll.pop();
	// ll.pop();
	// ll.pop();
	// ll.pop();
	// ll.pop();
	// ll.pop();
	// ll.pop();
	// ll.pop();
	// ll.pop();
	// ll.pop();
	// ll.pop();
	// ll.pop();
	// ll.print_list();
	// cout << "\nReal_append_test:-";
	// ll.append(-1);
	// ll.print_list();
	// ll.append(-2);
	// ll.print_list();
	// ll.append(-3);
	// ll.print_list();
	// ll.pop();
	// ll.print_list();
	// ll.push(-1);
	// ll.print_list();
	// ll.push(1);
	// ll.push(2);
	// ll.push(3);
	// ll.print_list();
	// // At this point, the list looks like so: head-->[3]-->[2]-->[1]-->[-1]-->[-2]-->[-3]-->X
	// cout << "\nTesting de_append (removal from the end of list).";
	// ll.de_append(); // deletes '-3'
	// ll.print_list();
	// ll.de_append(); // deletes '-2'
	// ll.print_list();
	// ll.de_append(); // deletes '-1'
	// ll.print_list();
	// ll.de_append(); // deletes '1'
	// ll.print_list();
	// ll.de_append(); // deletes '2'
	// ll.print_list();
	// ll.de_append();  // deletes '3' (checks for the behaviour when the list contains a single element). 
	// ll.print_list();
	// ll.de_append(); // checks the behaviour when the list is empty.
	// ll.print_list();
/* ll_test */