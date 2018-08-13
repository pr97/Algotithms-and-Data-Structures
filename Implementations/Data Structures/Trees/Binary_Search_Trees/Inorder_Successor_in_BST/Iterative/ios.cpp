#include<bits/stdc++.h>
using namespace std;
struct Node {
int data;
struct Node * right, * left;
};
Node * inOrderSuccessor(Node *, Node* );
Node* search(Node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == key)
       return root;
    
    // Key is greater than root's key
    if (root->data < key)
       return search(root->right, key);
 
    // Key is smaller than root's key
    return search(root->left, key);
}
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
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }
}
int getCountOfNode(Node *root, int l, int h)
{
    if (!root) return 0;
    if (root->data == h && root->data == l)
        return 1;
    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) + getCountOfNode(root->right, l, h);
    else if (root->data < l)
         return getCountOfNode(root->right, l, h);
    else return getCountOfNode(root->left, l, h);
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;
        root = NULL;
        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);
        }
        int k;
        cin>>k;
        Node* s=search(root,k);
        Node *R= inOrderSuccessor(root,s);
    if(R==NULL)
    cout<<-1;
    else
     cout<<R->data;
     cout<<endl;
    }
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of Node
struct Node {
int data;
Node * right, * left;
};*/
/* The below function should return the node which is 
inorder successor of given node x. */

Node* get_left_most(Node* root){
    if(!root)
        return NULL;
    if(!root->left)
        return root;
    return get_left_most(root->left);
}

Node * inOrderSuccessor(Node *root, Node *x){
    if(!x || !root)
        return NULL;
    if(x->right){
        return get_left_most(x->right);
    }
    Node* s = NULL;
    while(root){
        if(x->data < root->data){
            s = root;
            root = root->left;
        }
        else if(x->data > root->data){
            root = root->right;
        }
        else{
            break;
        }
    }
    return s;
}