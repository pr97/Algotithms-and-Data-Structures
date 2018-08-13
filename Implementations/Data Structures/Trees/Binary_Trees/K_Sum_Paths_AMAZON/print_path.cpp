// C++ program to print all paths with sum k.
#include <bits/stdc++.h>
using namespace std;
 
//utility function to print contents of
//a vector from index i to it's end
void printVector(const vector<int>& v, int i)
{
    for (int j=i; j<v.size(); j++)
        cout << v[j] << " ";
    cout << endl;
}
 
// binary tree node
struct Node
{
    int data;
    Node *left,*right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
 
// This function prints all paths that have sum k
void printKPathUtil(Node *root, vector<int>& path,
                                           int k)
{
    // empty node
    if (!root)
        return;
 
    // add current node to the path
    path.push_back(root->data);
 
    // check if there's any k sum path
    // in the left sub-tree.
    printKPathUtil(root->left, path, k);
 
    // check if there's any k sum path
    // in the right sub-tree.
    printKPathUtil(root->right, path, k);
 
    // check if there's any k sum path that
    // terminates at this node
    // Traverse the entire path as
    // there can be negative elements too
    int f = 0;
    for (int j=path.size()-1; j>=0; j--)
    {
        f += path[j];
 
        // If path sum is k, print the path
        if (f == k)
            printVector(path, j);
    }
 
    // Remove the current element from the path
    path.pop_back();
}
 
// A wrapper over printKPathUtil()
void printKPath(Node *root, int k)
{
    vector<int> path;
    printKPathUtil(root, path, k);
}
 
/* +++++++++++++++++++++++++++++++++++S E L F -- W R I T T E N+++++++++++++++++++++++++++++++++++++ */
void print_path_from_i_to_j(int a[], int I, int J){
    for(int i = I; i <= J; ++i){
        cout << a[i] << " ";
    }
}

void k_sum_paths(Node* root, int lvl, int a[], int cumsum[], int& k){
    if(!root)
        return;
    a[lvl] = root->data;
    if(lvl > 0){
        cumsum[lvl] = cumsum[lvl - 1] + root->data;
    }
    else{
        cumsum[lvl] = root->data;
    }
    for(int i = -1; i < lvl; ++i){
        if(i == -1){
            if(cumsum[lvl] == k){
                print_path_from_i_to_j(a, i + 1, lvl);
                cout << "\n";
            }
        }
        else{
            if(cumsum[lvl] - cumsum[i] == k){
                print_path_from_i_to_j(a, i + 1, lvl);
                cout << "\n";
            }
        }
    }
    k_sum_paths(root->left, lvl + 1, a, cumsum, k);
    k_sum_paths(root->right, lvl + 1, a, cumsum, k);
}

void print_k_paths_caller_function(Node* root, int k){
    int a[10];
    int cumsum[10];
    k_sum_paths(root, 0, a, cumsum, k);
}
/* +++++++++++++++++++++++++++++++++++------------------------+++++++++++++++++++++++++++++++++++++ */


// Driver code
int main()
{
    Node *root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right = new Node(-1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(2);
 
    int k = 5;
    // printKPath(root, k);
    print_k_paths_caller_function(root, k);
 
    return 0;
}