#include<bits/stdc++.h>
using namespace std;
struct Node {
int data;
struct Node * right, * left;
};
void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = (Node *)malloc(sizeof(Node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }
    if(val < (*tree)->data)
    { insert(&(*tree)->left, val);}
    else if(val > (*tree)->data)
    { insert(&(*tree)->right, val);}
}
void inorder(Node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
Node * deleteNode(Node *root,  int );
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
        root = NULL;
        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);}
        int r;
        cin>>r;
        root = deleteNode(root,r);
        inorder(root);
        cout<<endl;
    }
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* The structure of a BST Node is as follows:
struct Node {
  int data;
  Node * right, * left;
}; */

Node* get_leftmost(Node* root){
    if(!root)
        return NULL;
    if(!root->left)
        return root;
    return get_leftmost(root->left);
}

Node* deleteNode(Node *root,  int x){
    if(!root)
        return NULL;
    if(x < root->data)
        root->left = deleteNode(root->left, x);
    else if(x > root->data)
        root->right = deleteNode(root->right, x);
    else{
        Node* temp;
        if(!root->left){
            temp = root->right;
            delete root;
            return temp;
        }
        if(!root->right){
            temp = root->left;
            delete root;
            return temp;
        }
        Node* s = get_leftmost(root->right);
        root->data = s->data;
        root->right = deleteNode(root->right, s->data);
    }
    return root;
}