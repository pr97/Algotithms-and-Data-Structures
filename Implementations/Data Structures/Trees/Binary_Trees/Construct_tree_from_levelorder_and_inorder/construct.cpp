#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    struct Node* left, *right;
};
Node* newNode(int key)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    return (node);
}
Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n);
void printPreorder(Node* node)
{
    if (node == NULL)
       return;
    cout << node->key << " ";
    printPreorder(node->left);
    printPreorder(node->right);
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int in[n],level[n];
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    for(int i=0;i<n;i++){
        cin>>level[i];
    }
    Node *root=NULL;
    root = buildTree(in, level, 0, n - 1,n);
    printPreorder(root);
    cout<<endl;
    }
    return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Complete the function below
Node is as follows:
struct Node
{
    int key;
    struct Node* left, *right;
};
*/

int search(int a[], int data, int n){
    for(int i = 0; i < n; ++i){
        if(a[i] == data)
            return i;
    }
    return -1;
}

int* get_lvl(int in[], int lvl[], int in_n, int lvl_n){
    int* res_lvl = new int[in_n];
    int k = 0;
    for(int i = 0; i < lvl_n; ++i){
        for(int j = 0; j < in_n; ++j){
            if(in[j] == lvl[i])
                res_lvl[k++] = lvl[i];
        }
    }
    return res_lvl;
}

Node* convert(int in[], int lvl[], int n){
    if(n == 0)
        return NULL;
    int root = search(in, lvl[0], n);
    Node* r = newNode(lvl[0]);
    if(root > 0){
        int* l_lvl = get_lvl(in, lvl, root, n);
        r->left = convert(in, l_lvl, root);
        delete [] l_lvl;
    }
    if(root < n - 1){
        int* r_lvl = get_lvl(in + root + 1, lvl, n - 1 - root, n);
        r->right = convert(in + root + 1, r_lvl, n - 1 - root);
        delete [] r_lvl;
    }
    return r;
}

Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n)
{
    return convert(inorder, levelOrder, n);
}