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
  struct Node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);    
}
int largestBst(Node *root);
/* Driver program to test size function*/
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
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
    cout<<largestBst(root)<< endl;
  }
  return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Tree node structure  used in the program
 struct Node
 {
     int data;
     struct Node* left, *right;
};*/
/*You are required to complete this method */

bool is_bst(Node* root, int& m, int& M, int& count, int& max_count){
    if(!root){
      count = 0;
      return true;
    }
    if(root->left == NULL && root->right == NULL){
      count = 1;
      max_count = max(count, max_count);
      m = root->data;
      M = root->data;
    }
    int l_count, r_count;
    int l_min = INT_MAX, r_min = INT_MAX, l_max = INT_MIN, r_max = INT_MIN;
    bool lib = is_bst(root->left, l_min, l_max, l_count, max_count);
    bool rib = is_bst(root->right, r_min, r_max, r_count, max_count);
    m = min({root->data, l_min, r_min});
    M = max({root->data, l_max, r_max});
    count = l_count + r_count + 1;
    bool root_satisfies = root->data > l_max && root->data < r_min;
    bool res = root_satisfies && lib && rib;
    if(res){
      max_count = max(count, max_count);
    }
    return res;
}

int largestBst(Node *root)
{
  if(!root)
    return 0;
	int count = 0;
  int m = INT_MAX, M = INT_MIN;
  int max_count = 0;
  bool r = is_bst(root, m, M, count, max_count);
  return max_count;
}