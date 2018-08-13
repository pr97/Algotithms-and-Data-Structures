#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
  struct Node* node = (struct Node*)
                       malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
int findDist(Node* ,int ,int );
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     if(n==1)
     {
        int a;
        cin>>a;
        cout<<a<<endl;
     }else{
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
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
     int a,b;
     cin>>a>>b;
     cout<<findDist(root,a,b)<<endl;
  }
  }
  return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
/* Should return minimum distance between a and b 
   in a tree with given root*/

int dist(Node* root, Node* target, int lvl){
  if(!root)
    return -1;
  if(root == target)
    return lvl;
  int l = dist(root->left, target, lvl + 1);
  int r = dist(root->right, target, lvl + 1);
  return (l == -1)? r : l;
}

Node* LCA(Node* root, int a, int b){
  if(!root)
    return NULL;
  if(root->data == a || root->data == b)
    return root;
  Node* llca = LCA(root->left, a, b);
  Node* rlca = LCA(root->right, a, b);
  if(llca && rlca)
    return root;
  return (llca)? llca : rlca;
}

Node* get_node(Node* root, int& val){
  if(!root)
    return NULL;
  if(root->data == val)
    return root;
  Node* l = get_node(root->left, val);
  Node* r = get_node(root->right, val);
  return (l != NULL)? l : r;
}

int findDist(Node* root, int a, int b)
{
    Node* lca = LCA(root, a, b);
    Node* aa = get_node(root, a);
    Node* bb = get_node(root, b);
    return dist(root, aa, 0) + dist(root, bb, 0) - 2 * dist(root, lca, 0);
}