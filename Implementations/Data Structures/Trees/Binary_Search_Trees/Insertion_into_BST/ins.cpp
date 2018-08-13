#include<bits/stdc++.h>
using namespace std;
struct node {
int data;
struct node * right, * left;
};
struct node *newNode(int item)
{
    struct node *temp =  new node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;}
struct node* insert(struct node* node, int data);
void inorder(node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        node *root;
        node *tmp;
        root = NULL;
        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            root = insert(root, k);
        }
        inorder(root);
        cout<<endl;
}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* The structure of a BST node is as follows:
struct node {
  int data;
  struct node * right, * left;
}; */
/* This function should insert a new node with given data and
   return root of the modified tree  */
struct node* insert(struct node* root, int data){
	if(!root){
		return newNode(data);
	}
	if(data < root->data){
		root->left = insert(root->left, data);
	}
	if(data > root->data){
		root->right = insert(root->right, data);
	}
	return root;
}