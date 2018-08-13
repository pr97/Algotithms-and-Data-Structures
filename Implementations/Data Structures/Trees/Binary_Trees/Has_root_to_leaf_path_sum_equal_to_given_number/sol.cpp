#include <bits/stdc++.h>
using namespace std;
/* A binary tre node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
bool hasPathSum(Node *, int );
struct Node* newNode(int data)
{
  struct Node* node = (struct Node*)
                       malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
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
     int a;
     cin>>a;
     cout<<hasPathSum(root,a)<<endl;
  }
  }
  return 0;
}

/*Please note that it's Function problem i.e.
you ned to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tre node
struct Node
{
    int data;
    Node* left, * right;
}; */
/*you are required to 
complete this function */

bool hasPathSum(Node *node, int sum)
{
  if(!node){
    if(sum == 0){
      return true;
    }
    else{
      return false;
    }
  }
  if(sum - node->data == 0 && node->left == NULL && node->right == NULL){
    return true;
  }
  bool l = false, r = false;
  if(node->left)
    l = hasPathSum(node->left, sum - node->data);
    if(node->right)
    r = hasPathSum(node->right, sum - node->data);
  return l || r;
}