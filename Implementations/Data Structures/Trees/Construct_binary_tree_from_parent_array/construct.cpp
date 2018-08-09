#include <bits/stdc++.h>
using namespace std;
vector<int> result;
struct Node
{
int data;
Node *left,*right;
};
void printGivenLevel(Node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        result.push_back(root->data);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}
int height(struct Node* node)
{
    if (node==NULL)
        return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}
void printLevelOrder(struct Node* root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++){
        result.clear();
        printGivenLevel(root, i);
        sort(result.begin(),result.end());
        for(int i=0;i<result.size();i++)
            cout<<result[i]<<" ";
    }
}
Node *newNode(int key)
{
    Node *temp = new Node;
    temp->data  = key;
    temp->left  = temp->right = NULL;
    return (temp);
}
Node *createTree(int parent[], int n);
void inorder(Node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,k;
/*reading input stuff*/
    cin>>T;
    while(T--){
    int N;
    cin>>N;
    int a[N];
    for(int i=0;i<N;i++)
        cin>>a[i];
        struct Node *res = createTree(a,N);
       // print(res);
     //  memset(result,0,100);
       printLevelOrder(res);
     cout<<endl;
    }
    return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */
/*  Function which returns the  root of 
    the constructed binary tree. */

Node* new_node(int data){
    Node* t = new Node;
    t->data = data;
    t->left = NULL;
    t->right = NULL;
    return t;
}

Node *createTree(int parent[], int n){
    map<int, Node*> m;
    int root_val;
    for(int i = 0; i < n; ++i)
        m[i] = new_node(i);
    for(int i = 0; i < n; ++i){
        if(parent[i] != -1){
            if(!m[parent[i]]->left)
                m[parent[i]]->left = m[i];
            else
                m[parent[i]]->right = m[i];
        }
        else{
            root_val = i;
        }
    }
    return m[root_val];
}