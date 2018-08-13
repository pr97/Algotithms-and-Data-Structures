#include <bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	Node* left, *right;
};
Node* newNode(int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}
int sumOfLongRootToLeafPath(Node* root);
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
     cout<<sumOfLongRootToLeafPath(root)<<endl;
  }
  return 0;
}
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

//User function Template for C++
/*
structure of the node of the binary tree is as
struct Node {
	int data;
	Node* left, *right;
};
*/
// your task is to complete this function

void sum(Node* root, int l, int& L, int& curr_sum, int& res){
	if(!root)
		return;
	curr_sum += root->data;
	if(l >= L){
		if(l == L){
			if(res < curr_sum)
				res = curr_sum;
		}
		else{
			res = curr_sum;
		}
		L = l;
	}
	sum(root->left, l + 1, L, curr_sum, res);
	sum(root->right, l + 1, L, curr_sum, res);
	curr_sum -= root->data;
}

int sumOfLongRootToLeafPath(Node* root)
{
	int res = 0;
	int curr_sum = 0;
	int L = 0;
	sum(root, 1, L, curr_sum, res);
	return res;
}