#include<bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  Node* left;
  Node* right;
};
Node* newNode(int data)
{
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
Node *buildTree(int a[],int b[],int str,int end);
int preIndex=0;
void printPostOrder(Node *root){
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		preIndex=0;
		Node *root=NULL;
		int a[n],b[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];
		root=buildTree(a,b,0,n-1);
		printPostOrder(root);
		cout<<endl;
	}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/

int search(int in[], int data, int n){
	for(int i = 0; i < n; ++i){
		if(in[i] == data)
			return i;
	}
	return -1;
}

Node* build_tree(int in[],int pre[], int n){
	int root_index = search(in, pre[0], n);
	Node* root = newNode(pre[0]);
	Node* lst = NULL;
	Node* rst = NULL;
	if(root_index != 0){
		lst = build_tree(in, pre + 1, root_index);
	}
	if(root_index != n - 1){
		rst = build_tree(in + root_index + 1, pre + root_index + 1, n - root_index - 1);
	}
	root->left = lst;
	root->right = rst;
	return root;

}

Node* buildTree(int in[],int pre[], int inStrt, int inEnd){
	return build_tree(in, pre, inEnd - inStrt + 1);
}