#include <iostream>
#include <cstring>
#include<map>
#include <stdio.h>
using namespace std;
#define MAX 100
 
// Structure of a tree node
struct Node
{
    char key;
    struct Node *left, *right;
};
 
// A utility function to create a new BST node
Node *newNode(char item)
{
    Node *temp =  new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
bool isSubtree(Node *T, Node *S);
 
// A utility function to store inorder traversal of tree rooted
// with root in an array arr[]. Note that i is passed as reference
void storeInorder(Node *root, char arr[], int &i)
{
    if (root == NULL)
    {
        arr[i++] = '$';
        return;
    }
    storeInorder(root->left, arr, i);
    arr[i++] = root->key;
    storeInorder(root->right, arr, i);
}
 
// A utility function to store preorder traversal of tree rooted
// with root in an array arr[]. Note that i is passed as reference
void storePreOrder(Node *root, char arr[], int &i)
{
    if (root == NULL)
    {
        arr[i++] = '$';
        return;
    }
    arr[i++] = root->key;
    storePreOrder(root->left, arr, i);
    storePreOrder(root->right, arr, i);
}
 
// Driver program to test above function
int main()
{
     int t;
 
  scanf("%d", &t);
  while(t--)
  { struct Node *child=NULL;
     map<int, Node*> m;
     int n;
     scanf(" %d",&n);
     struct Node *t2 = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (t2 == NULL)
             t2 = parent;
        }
        else
           parent = m[n1];
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     struct Node *child1;
     map<int, Node*> m1;
     int nodes;
     scanf("%d",&nodes);
     struct Node *t1 = NULL;
     while (nodes--)
     {
        Node *parent1;
        char lr1;
        int n3, n4;
        scanf("%d %d %c", &n3, &n4, &lr1);
        if (m1.find(n3) == m1.end())
        {
           parent1 = newNode(n3);
           m1[n3] = parent1;
           if (t1 == NULL)
             t1 = parent1;
        }
        else
           parent1 = m1[n3];
        child = newNode(n4);
        if (lr1 == 'L')
          parent1->left = child;
        else
          parent1->right = child;
        m1[n4]  = child;
     }
 
   cout<<isSubtree(t1,t2);
    cout<<"\n";
  }
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree node
struct Node
{
    int key;
    Node* left, * right;
}; */
/*you are required to 
complete this function */

bool is_identical(Node* a, Node* b){
    if(a == NULL && b == NULL)
        return true;
    if(a == NULL || b == NULL)
        return false;
    bool is_key_equal = a->key == b->key;
    return is_key_equal && is_identical(a->left, b->left) && is_identical(a->right, b->right);
}

bool isst(Node* r, Node* s){
    if(r == NULL){
        if(s == NULL){
            return true;
        }
        else
            return false;
    }
    if(is_identical(r, s))
        return true;
    return isst(r->left, s) || isst(r->right, s);
}

bool isSubtree(Node*  T1 ,Node * T2)
{
    // if(T1 == NULL){
    //     if(T2 == NULL)
    //         return true;
    //     else
    //         return false;
    // }
    //  queue<Node*> q;
    //  q.push(T1);
    //  Node* t;
    //  while(!q.empty()){
    //     t = q.front();
    //     q.pop();
    //     if(is_identical(t, T2))
    //         return true;
    //     if(t->left)
    //         q.push(t->left);
    //     if(t->right)
    //         q.push(t->right);
    //  }
    //  return false;
    return isst(T1, T2);
}