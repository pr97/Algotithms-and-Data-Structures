/* C++ program to convert left-right to down-right
   representation of binary tree */
#include <iostream>
#include <queue>
using namespace std;
 
// A Binary Tree Node
struct node
{
    int key;
    struct node *left, *right;
};
 
// An Iterative level order traversal based function to
// convert left-right to down-right representation.
void convert(node *root)
{
    // Base Case
    if (root == NULL)  return;
 
    // Recursively convert left an right subtrees
    convert(root->left);
    convert(root->right);
 
    // If left child is NULL, make right child as left
    // as it is the first child.
    if (root->left == NULL)
       root->left = root->right;
 
    // If left child is NOT NULL, then make right child
    // as right of left child
    else
       root->left->right = root->right;
 
    // Set root's right as NULL
    root->right = NULL;
}
 
// A utility function to traverse a tree stored in
// down-right form.
void downRightTraversal(node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        downRightTraversal(root->right);
        downRightTraversal(root->left);
    }
}
 
// Utility function to create a new tree node
node* newNode(int key)
{
    node *temp = new node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

void _convert(node* root);
 
// Driver program to test above functions
int main()
{
    // Let us create binary tree shown in above diagram
    /*
           1
         /   \
        2     3
             / \
            4   5
           /   /  \
          6   7    8
    */
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(5);
    root->right->left->left = newNode(6);
    root->right->right->left = newNode(7);
    root->right->right->right = newNode(8);
 
    _convert(root);
 
    cout << "Traversal of the tree converted to down-right form\n";
    downRightTraversal(root);
 
    return 0;
}

// Self-written function.
void _convert(node* root){
    queue<node*> q;
    if(root == NULL)
        return;
    q.push(root);
    q.push(NULL);
    node* t;
    while(!q.empty()){
        if(q.front() == NULL){
            if(q.size() == 1){
                q.pop();
                break;
            }
            q.pop();
            q.push(NULL);
            continue;
        }
        node* t = q.front();
        q.pop();
        if(t->left)
            q.push(t->left);
        if(t->right)
            q.push(t->right);
        t->right = q.front();
    }
}