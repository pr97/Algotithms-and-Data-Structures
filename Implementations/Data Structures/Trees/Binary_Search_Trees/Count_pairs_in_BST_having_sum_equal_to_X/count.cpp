#include <bits/stdc++.h>
using namespace std;
// structure of a node of BST
struct Node {
	int data;
	Node* left, *right;
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
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }
}
int countPairs(Node* root1, Node* root2, int x);
// Driver code
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node* root1 = NULL;
        Node* root2 = NULL;
        int n1, n2, k;
        cin>>n1;
        for(int i=0; i<n1; i++)
        {
            cin>>k;
            insert(&root1, k);
        }
        cin>>n2;
        for(int i=0; i<n2; i++)
        {
            cin>>k;
            insert(&root2, k);
        }
        int s;
        cin>>s;
        cout<<countPairs(root1, root2, s)<<"";
    }
    return 0;
}
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

//User function Template for C++
/*Structure of the Node of the BST is as
struct Node {
	int data;
	Node* left, *right;
};*/
// You are required to complete this function
void populate(Node* root, unordered_set<int>& s){
    if(!root)
        return;
    populate(root->left, s);
    s.insert(root->data);
    populate(root->right, s);
}

void get_count(Node* root, int& count, int x, unordered_set<int>& s){
    if(!root)
        return;
    get_count(root->left, count, x, s);
    if(s.find(x - root->data) != s.end())
        ++count;
    get_count(root->right, count, x, s);
}

int countPairs(Node* root1, Node* root2, int x)
{
    unordered_set<int> s;
    populate(root1, s);
    int count = 0;
    get_count(root2, count, x, s);
    return count;
}