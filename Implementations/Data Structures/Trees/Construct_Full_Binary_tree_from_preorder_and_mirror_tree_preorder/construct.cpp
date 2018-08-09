//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	struct Node *left, *right;
};
Node* newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}
void printInorder(Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}
Node* constructBinaryTree(int pre[], int preMirror[], int size);
// Driver program to test above functions
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int preOrder[n];
	    int preOrderMirror[n];
	    for(int i=0; i<n; i++)cin>>preOrder[i];
	    for(int i=0; i<n; i++)cin>>preOrderMirror[i];
	    printInorder(constructBinaryTree(preOrder, preOrderMirror, n));
	    cout<<endl;
    }
	return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/


/* Structre of the Node of the Binary Tree is as follows
struct Node
{
        int data;
        struct Node *left, *right;
};
*/
// your task is to complete this function
// function should create a new binary tree
// function should return the root node to the 
// new binary tree formed
int search(int a[], int data, int n){
	for(int i = 0; i < n; ++i)
		if(a[i] == data)
			return i;
	return -1;
}

Node* new_node(int data){
	Node* t = new Node;
	t->data = data;
	t->left = NULL;
	t->right = NULL;
	return t;
}

Node* construct(int pre[], int pre_m[], int n){
	if(n == 0)
		return NULL;
	if(n == 1)
		return new_node(pre[0]);
	if(n > 1){
		Node* root = new_node(pre[0]);
		int lor = search(pre_m, pre[1], n);
		root->left = construct(pre + 1, pre_m + lor, n - lor);
		root->right = construct(pre + n - lor + 1, pre_m + 1, lor - 1);
		return root;
	}
}

Node* constructBinaryTree(int pre[], int preMirror[], int size)
{
    return construct(pre, preMirror, size);
}