#include <bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	Node* right;
	Node* left;	
};

void postorder(Node* root);
Node* construct_tree(vector<int>& in, vector<int>& pre, int n);
Node* construct_tree_util(vector<int>& in, int in_start, vector<int>& pre, int pre_start, int size);
Node* new_node(int val);
int search(vector<int>& v, int sz, int data);
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> in(n), pre(n);
		for(int i = 0; i < n; ++i)
			cin >> in.at(i);
		for(int i = 0; i < n; ++i)
			cin >> pre.at(i);
		Node* tree = construct_tree(in, pre, n);
		postorder(tree);
	}
	return 0;
}

Node* new_node(int val){
	Node* t = new Node;
	t->data = val;
	t->right = NULL;
	t->left = NULL;
	return t;
}

void postorder(Node* root){
	if(!root)
		return;
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}

int search(int v[], int sz, int data){
	for(int i = 0; i < sz; ++i){
		if(v.[i] == data)
			return i;
	}
	return -1;
}

Node* construct_tree(int in[], int pre[], int n){
	return construct_tree_util(in, pre, n);
}


Node* construct_tree_util(int in[], int pre[], int size){
	if(pre_start >= (size + pre_start))
		return NULL;
	int root = search(in, in_start, size, pre.at(pre_start));
	assert(root != -1); // Sanity check.
	Node* t = new_node(in.at(root));
	Node* left = construct_tree_util(in, in_start, pre, pre_start + 1, root - in_start);
	Node* right = construct_tree_util(in, root + 1, pre, pre_start + 1 + root - in_start, size - 1 - root);
	t->left = left;
	t->right = right;
	return t;
}