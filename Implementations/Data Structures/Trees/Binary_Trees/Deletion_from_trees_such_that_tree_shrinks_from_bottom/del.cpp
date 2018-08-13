
#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int key;
	Node* left, *right;
};
struct Node* newNode(int key)
{
	struct Node* temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
};
/* Inorder traversal of a binary tree*/
void inorder(struct Node* temp)
{
	if (!temp)
		return;
	inorder(temp->left);
	cout << temp->key << " ";
	inorder(temp->right);
}
void deletionBT(struct Node* root, int key);
/* Driver program to test size function*/
int main()
{
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
     int key;
     cin>>key;
     deletionBT(root, key);
     inorder(root);
     cout<<endl;
  }
  return 0;
}



/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
Structre of the node of the tree is as
struct Node
{
	int key;
	Node* left, *right;
};
*/
// you are required to complete this function
void delete_deepest(Node* root, Node* d_node){
  queue<Node*> q;
  q.push(root);
  Node* temp;
  while(!q.empty()){
    temp = q.front();
    q.pop();
    if(temp->right == d_node){
      temp->right = NULL;
      delete d_node;
      break;
    }
    else if(temp->right != NULL){
      q.push(temp->right);
    }
    if(temp->left == d_node){
      temp->left = NULL;
      delete d_node;
      break;
    }
    else if(temp->left != NULL){
      q.push(temp->left);
    }
  }
}
void deletionBT(struct Node* root, int key)
{
    queue<Node*> q;
    q.push(root);
    Node* temp;
    Node* key_node;
    while(!q.empty()){
      temp = q.front();
      q.pop();
      if(temp->key == key)
        key_node = temp;
      if(temp->left)
        q.push(temp->left);
      if(temp->right)
        q.push(temp->right);
    }
    Node* deepest_rightmost = temp;
    key_node->key = deepest_rightmost->key;
    delete_deepest(root, deepest_rightmost);
}