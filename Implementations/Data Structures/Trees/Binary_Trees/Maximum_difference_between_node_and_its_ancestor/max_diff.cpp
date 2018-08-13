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
int maxDiff(Node *root);
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
   cout<<maxDiff(root)<<endl;
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
/* Your are required to 
complete this method*/

// TILDA_FUNCTION: Gets max positive difference.
void max_diff(Node* root, int& M, int& m, int& global_max_diff){
  if(!root)
    return;
  int max = M, min = m;
  if(root->data > M){
    max = root->data;
    min = root->data;
  }
  if(root->data < m){
    min = root->data;
  }
  if(max - min > global_max_diff){
    global_max_diff = max - min;
  }
  max_diff(root->left, max, min, global_max_diff);
  max_diff(root->right, max, min, global_max_diff);
}

int max_diff(Node* root, int& global_max_diff){
  if(!root)
    return INT_MAX;
  if(root->left == NULL && root->right == NULL)
    return root->data;
  int lmin = max_diff(root->left, global_max_diff);
  int rmin = max_diff(root->right, global_max_diff);
  int curr_max_diff = root->data - min(lmin, rmin);
  if(curr_max_diff > global_max_diff)
    global_max_diff = curr_max_diff;
  return min({lmin, rmin, root->data});
}

int maxDiff(Node* root)
{
  int global_max_diff = INT_MIN;
  // int max = INT_MIN, min = INT_MAX;
  max_diff(root, global_max_diff);
  return global_max_diff;
}