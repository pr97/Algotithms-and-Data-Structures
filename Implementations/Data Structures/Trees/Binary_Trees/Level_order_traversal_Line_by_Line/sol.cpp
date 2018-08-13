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
void levelOrder(struct Node* node);
/* Helper function to test mirror(). Given a binary
   search tree, print out its data elements in
   increasing sorted order.*/
void inOrder(struct Node* node)
{
  if (node == NULL)
    return;
  inOrder(node->left);
  printf("%d ", node->data);
  inOrder(node->right);
}
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
/* Driver program to test size function*/
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
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
     levelOrder(root);
     cout << endl;
  }
  return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */
//You are required to complete this method
Node* new_node(int val){
  Node* temp = new Node;
  temp->data = val;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}
void levelOrder(Node* node){
  if(!node)
    return;
  queue<Node*> q;
  Node* temp;
  Node* level;
  q.push(node);
  q.push(new_node(1));
  int prev_level = 1;
  while(!q.empty()){
    temp = q.front();
    q.pop();
    level = q.front();
    q.pop();
    if(level->data == prev_level)
      cout << temp->data << " ";
    else{
      cout << "$ " << temp->data << " ";
      ++prev_level;
      assert(level->data == prev_level);
    }
    if(temp->left){
      q.push(temp->left);
      q.push(new_node(prev_level + 1));
    }
    if(temp->right){
      q.push(temp->right);
      q.push(new_node(prev_level + 1));
    }
  }
  cout << "$";
}
