#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};
void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node;
    new_node->data  = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}
bool isPalindrome(Node *head);
/* Driver program to test above function*/
int main()
{
  int T,i,n,l;
    cin>>T;
    while(T--){
    struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
   	cout<<isPalindrome(head)<<endl;
    // cout << "\n++++++++++++++++++++++++\n";
    // Node* t = head;
    // while(t){
    //     cout << t->data << " ";
    //     t = t->next;
    // }
    // cout << "\n++++++++++++++++++++++++\n";
    }
    return 0;
}

// 2
// 3
// 1 2 1
// 4
// 1 2 3 4

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of the Node is
struct Node
{
    int data;
    struct Node* next;
};*/
/*You are required to complete this method */

Node* get_mid(Node* head){
    if(!head){
        return NULL;
    }
    Node* fast;
    Node* slow;
    fast = head;
    slow = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void reverse_ll(Node* reverse_from, Node*& rev_head){
    if(!reverse_from)
        return;
    // assert(prev->next == reverse_from);
    Node* prev = NULL;
    Node* curr = reverse_from;
    Node* next = curr->next;
    while(curr){
        curr->next = prev;
        prev = curr;
        curr = next;
        if(curr)
            next = curr->next;
    }
    rev_head = prev;
}

bool isPalindrome(Node *head)
{
    Node* rev_head;
    Node* reverse_from = get_mid(head);
    reverse_ll(reverse_from, rev_head);
    Node* t = head, *rt = rev_head;
    bool is_palindrome = false;
    while(t->next != rt && t->next != rt->next){
        if(t->data != rt->data){
            is_palindrome = false;
            break;
        }
        else
            is_palindrome = true;
        t = t->next;
        rt = rt->next;
    }
    reverse_ll(rev_head, reverse_from); // reverse_from is just passed as a dummy. Any other useless variable of 'Node*' could have been passed.
    return is_palindrome;
}