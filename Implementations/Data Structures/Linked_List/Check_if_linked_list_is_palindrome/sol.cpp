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
		Node* get_mid_node(){
			Node* slow = this->head;
			Node* fast = this->head;
			if(fast == NULL)
				return NULL;
			if(fast->next == NULL)
				return fast;
			// while(fast->next != NULL && fast->next->next != NULL){
			// 	slow = slow->next;
			// 	fast = fast->next->next;
			// }
			while(fast != NULL && fast->next != NULL){
				slow = slow->next;
				fast = fast->next->next;
			}
			return slow;
		}
		void reverse(Node* first_node, Node** head_ref){
			// Reverses the linked list starting from the the address of the node passed as 'first_node'.
			Node* prev = NULL;
			Node* next = NULL;
			Node* current = first_node;
			while(current){ // while(current != NULL)
				next = current->next;
				current->next = prev;
				prev = current;
				current = next;
			}
			*head_ref = prev;
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
		void print_list_with_given_head(Node* custom_head){
			Node* t = custom_head;
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

bool is_ll_palindrome(LinkedList& ll){
	// Assumes that an empty linked list trivially represents a palindrome.
	if(ll.head == NULL)
		return true;
	bool result = true;
	Node* back_head;
	Node* mid_node = ll.get_mid_node();
	ll.reverse(mid_node, &back_head);
	Node* front = ll.head;
	Node* back = back_head;
	while(front != back){
		if(front->data != back->data){
			result = false;
			break;
		}
		if(front->next == back && back->next == NULL)
			break;
		front = front->next;
		back = back->next;
	}
	ll.reverse(back_head, &back_head);
	if(result)
		return true;
	return false;
}

int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	cout << "\n";
	LinkedList ll;
	Node* rouge_address = ll.get_new_node(INT_MAX);
	ll.push(1000);
	ll.push(1);
	ll.append(1);
	ll.push(-1);
	ll.append(-1);
	ll.push(2);
	ll.append(2);
	ll.print_list();
	bool is_palindrome = is_ll_palindrome(ll);
	if(is_palindrome)
		cout << "\nis palindrome.";
	else
		cout << "\nNOT palindrome.";
	cout << "\n";
	delete rouge_address;
	return 0;
}