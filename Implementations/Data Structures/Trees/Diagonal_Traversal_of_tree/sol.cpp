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
void diagonalPrint(Node *root);
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
     diagonalPrint(root);
     cout<<endl;
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
// void diagonalPrint(Node *root){
//   if(root == NULL)
//     return;
//   Node* t;
//   queue<Node*> q;
//   q.push(root);
//   while(!q.empty()){
//     t = q.front();
//     q.pop();
//     while(t != NULL){
//       cout << t->data << " ";
//       if(t->left != NULL)
//         q.push(t->left);
//       t = t->right;
//     }
//   }
// }

/* WITH DELIMITER AFTER EACH DIAGONAL */
void diagonalPrint(Node *root){
  if(root == NULL)
    return;
  Node* t;
  queue<Node*> q;
  q.push(root);
  q.push(NULL);
  while(!q.empty()){
    t = q.front();
    q.pop();
    if(q.size() != 0 && t == NULL){
      q.push(NULL);
      cout << "\n";
    }
    while(t != NULL){
      cout << t->data << " ";
      if(t->left != NULL)
        q.push(t->left);
      t = t->right;
    }
  }
}