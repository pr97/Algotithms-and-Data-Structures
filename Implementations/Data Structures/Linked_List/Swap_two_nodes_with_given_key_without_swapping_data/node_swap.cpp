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
		Node* get_nth_node(int n){
			if(this->head == NULL)
				return NULL;
			int ctr = 1;
			Node* t = this->head;
			while(t != NULL && ctr != n){
				t = t->next;
				++ctr;
			}
			if(ctr != n)
				return NULL;
			if(t != NULL)
				return t;
		}
		int length(){
			if(this->head == NULL)
				return 0;
			int ctr = 0;
			Node* t = this->head;
			while(t != NULL){
				++ctr;
				t = t->next;
			}
			return ctr;
		}
		Node* get_nth_node_from_end(int n){
			int len = this->length();
			return this->get_nth_node(len - n + 1);
		}
		Node* get_nth_node_from_end_optimized_with_two_pointers(int n){
			if(this->head == NULL)
				return NULL;
			if(n == 0) // If this 'if' statement is not present, the function ouputs the expected 'NULL' value but takes O(n) time instead of O(1).
				return NULL;
			Node* ref = this->head;
			Node* t = this->head;
			int ctr = n;
			while(ref != NULL && ctr--){
				ref = ref->next;
			}
			if(ref == NULL && ctr != 0)
				return NULL;
			while(ref != NULL){
				t = t->next;
				ref = ref->next;
			}
			return t;
		}
		Node* get_mid_node(){
			Node* slow = this->head;
			Node* fast = this->head;
			if(fast == NULL)
				return NULL;
			if(fast->next == NULL)
				return fast;
			// while(fast->next != NULL && fast->next->next != NULL){ // Gets FIRST mid node in case of even number of nodes.
			// 	slow = slow->next;
			// 	fast = fast->next->next;
			// }
			while(fast != NULL && fast->next != NULL){ // Gets SECOND mid node in case of even number of nodes.
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
		void swap_nodes_without_swapping_data(int key1, int key2){
			Node* t1 = this->head;
			Node* t2 = this->head;
			Node* prev1 = NULL;
			Node* prev2 = NULL;
			Node* t1_next;
			Node* t2_next;
			while(t1 != NULL && t2 != NULL && (t1->data != key1 || t2->data != key2)){
				if(t1->data != key1){
					prev1 = t1;
					t1 = t1->next;
				}
				if(t2->data != key2){
					prev2 = t2;
					t2 = t2->next;
				}
			}
			if(t1 == NULL || t2 == NULL)
				return;
			if(t1 != t2){
				if(t1 == this->head && t1->next != t2){
					prev2->next = t1;
					t1_next = t1->next;
					t1->next = t2->next;
					t2->next = t1_next;
					this->head = t2;
				}
				else if(t1 == this->head){
					/*
					* Here t1->next == t2 is not required
					* because had it been equal the first if statement
					* above could never be executed and this
					* if statement would evaluate to true immidiately
					* after. 
					*/
					t1->next = t2->next;
					t2->next = t1;
					this->head = t2;
				}
				else if(t2 == this->head && t2->next != t1){
					prev1->next = t2;
					t1_next = t1->next;
					t1->next = t2->next;
					t2->next = t1_next;
					this->head = t1;
				}
				else if(t2 == this->head){
					t2->next = t1->next;
					t1->next = t2;
					this->head = t1;
				}
				else if(t1->next == t2){
					prev1->next = t2;
					t1->next = t2->next;
					t2->next = t1;
				}
				else if(t2->next == t1){
					t2->next = t1->next;
					prev2->next = t1;
					t1->next = t2;
				}
				else{
					t1_next = t1->next;
					t2_next = t2->next;
					prev2->next = t1;
					prev1->next = t2;
					t1->next = t2_next;
					t2->next = t1_next;
				}
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

void swapNodes(Node** head_ref, int x, int y) // Learn how this works.
{
 
    // Nothing to do if x and y are same
    if (x == y)
        return;
 
    Node **a = NULL, **b = NULL;
 
    // search for x and y in the linked list
    // and store therir pointer in a and b
    while (*head_ref) {
 
        if ((*head_ref)->data == x) {
            a = head_ref;
        }
 
        else if ((*head_ref)->data == y) {
            b = head_ref;
        }
 
        head_ref = &((*head_ref)->next);
    }
 
    // if we have found both a and b
    // in the linked list swap current
    // pointer and next pointer of these
    if (a && b) {
 
        swap(*a, *b);
        swap(((*a)->next), ((*b)->next));
    }
}

int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	LinkedList ll;
	ll.append(1);
	ll.append(2);
	ll.append(3);
	ll.append(4);
	ll.append(5);
	ll.print_list();
	// ll.swap_nodes_without_swapping_data(2, 26);
	swapNodes(&ll.head, 1, 2);
	cout << "\nAfter swap:-";
	ll.print_list();
	return 0;
}