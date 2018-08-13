#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node *left, *right;
};
// function to get a new node
Node* getNode(int data)
{
	Node *newNode = new Node;
	newNode->data = data;
	newNode->left = newNode->right = NULL; 
	return newNode;
}
void inorderTraversal(Node* root)
{
	if (!root)return;
	inorderTraversal(root->left);
	cout << root->data << " ";
	inorderTraversal(root->right); 
}
// you need to complete this function
Node* constructBst(int arr[], int n);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
        Node *root = constructBst(arr, n);
        inorderTraversal(root);
        cout<<endl;
    }
	return 0; 
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

//User function Template for C++
/*
Structure of the Node of the node of the bst 
should be as
struct Node
{
	int data;
	Node *left, *right;
};
*/
// You are required to complete this function

struct NodeDetails{
	Node* ptr;
	int min, max;
};

Node* constructBst(int arr[], int sz)
{
    if(sz==0)return NULL;
    queue<NodeDetails> q;
    NodeDetails n;
    Node* root;
    n.ptr = getNode(arr[0]);
    n.min = INT_MIN;
    n.max = INT_MAX;
    root = n.ptr;
    int i = 1;
    NodeDetails t;
    q.push(n);
    while(i < sz){
    	t = q.front();
    	q.pop();

    	if(i < sz && arr[i] > t.min && arr[i] < t.ptr->data){
    		n.ptr = getNode(arr[i]);
    		n.min = t.min;
    		n.max = t.ptr->data;
    		t.ptr->left = n.ptr;
    		q.push(n);
    		++i;
    	}
    	if(i < sz && arr[i] > t.ptr->data && arr[i] < t.max){
    		n.ptr = getNode(arr[i]);
    		n.min = t.ptr->data;
    		n.max = t.max;
    		t.ptr->right = n.ptr;
    		q.push(n);
    		++i;
    	}

    }
	return root;
}