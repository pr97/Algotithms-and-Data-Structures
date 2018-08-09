// C code to modify binary tree for
// traversal using only right pointer
#include <bits/stdc++.h>
 
using namespace std;
 
// A binary tree node has data,
// left child and right child
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

void convert(Node* root);
Node* get_right(Node* root);
 
// function that allocates a new node
// with the given data and NULL left
// and right pointers.
struct Node* newNode(int data)
{
    struct Node* node = new struct Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}
 
// Function to modify tree
struct Node* modifytree(struct Node* root)
{
    struct Node* right = root->right;
    struct Node* rightMost = root;
 
    // if the left tree exists
    if (root->left) {
 
        // get the right-most of the
        // original left subtree
        rightMost = modifytree(root->left);
 
        // set root right to left subtree
        root->right = root->left;
        root->left = NULL;
    }
 
    // if the right subtree does
    // not exists we are done!
    if (!right) 
        return rightMost;
 
    // set right pointer of right-most
    // of the original left subtree
    rightMost->right = right;
 
    // modify the rightsubtree
    rightMost = modifytree(right);
    return rightMost;
}


 
// printing using right pointer only
void printpre(struct Node* root)
{
    while (root != NULL) {
        cout << root->data << " ";
        root = root->right;
    }
}
 
// Driver program to test above functions
int main()
{
    /* Constructed binary tree is
         10
        / \
       8   2
      / \  
     3   5     */
    struct Node* root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(2);
    // root->left->left = newNode(3); 
    root->left->right = newNode(5);

    root->right->left = newNode(-1);
    root->right->right = newNode(-2);
    root->left->right->left = newNode(100);
    root->right->left->left = newNode(1000);
 
    convert(root);
    printpre(root);
 
    return 0;
}

void convert(Node* root){
    if(root == NULL)
        return;
    convert(root->left);
    convert(root->right);
    Node* r = get_right(root->left);
    if(r){
        r->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }
}

Node* get_right(Node* root){
    if(root && root->right){
        return get_right(root->right);
    }
    return root;
}