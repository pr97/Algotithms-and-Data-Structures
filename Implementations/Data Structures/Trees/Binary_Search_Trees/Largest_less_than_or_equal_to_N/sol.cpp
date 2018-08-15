// C++ code to find the largest value smaller
// than or equal to N
#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int key;
    Node* left, *right;
};
 
// To create new BST Node
Node* newNode(int item)
{
    Node* temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
// To insert a new node in BST
Node* insert(Node* node, int key)
{
    // if tree is empty return new node
    if (node == NULL)
        return newNode(key);
 
    // if key is less then or grater then
    // node value then recur down the tree
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
 
    // return the (unchanged) node pointer
    return node;
}
 
// function to find max value less then N
int findMaxforN(Node* root, int N)
{
    /* If leaf node reached and is greater than N*/
    if (root->left == NULL && root->right == NULL && 
        root->key > N)
        return -1;
 
    /* If node's value is less than N and right value
       is NULL or grater than then return the node 
       value*/
    if ((root->key <= N && root->right == NULL) || 
        (root->key <= N && root->right->key > N))
        return root->key;
 
    // if node value is grater than N search in the
    // left subtree
    if (root->key >= N)
        return findMaxforN(root->left, N);
 
    // if node value is less than N search in the
    // right subtree
    else
        return findMaxforN(root->right, N);
}

// Self written function
void largest(Node* root, int N, int& l){
    if(!root)
        return;
    if(root->key == N){
        l = root->key;
        return;
    }
    else if(N < root->key){
        largest(root->left, N, l);
    }
    else{
        l = root->key;
        largest(root->right, N, l);
    }
}

int caller(Node* root, int N){
    int l;
    largest(root, N, l);
    return l;
}

// Driver code
int main()
{
    int N = 4;
 
    // creating following BST
    /*
                  5
               /   \ 
             2     12
           /  \    /  \ 
          1   3   9   21
                     /   \  
                    19   25  */
    Node* root = insert(root, 25);
    insert(root, 2);
    insert(root, 1);
    insert(root, 3);
    insert(root, 12);
    insert(root, 9);
    insert(root, 21);
    insert(root, 19);
    insert(root, 25);
 
    printf("%d", caller(root, N));
 
    return 0;
}