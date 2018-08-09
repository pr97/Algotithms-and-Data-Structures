#include<bits/stdc++.h>
using namespace std;
struct Node{
	char data;
	Node *left,*right;
};
Node *newNode(char Data)
{
    Node *new_node = new Node;
    new_node->data = Data;
    new_node->left = new_node->right = NULL;
    return new_node;
}
void preorder(Node *root){
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
Node *convertExpression(string str,int i);
int main(){
	int t;
	cin>>t;
	while(t--){
		string str;
		cin>>str;
		Node *root=convertExpression(str,0);
		preorder(root);
		cout<<endl;
	}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Complete the function below
Node is as follows
struct Node{
	char data;
	Node *left,*right;
};
*/


int search_for_colon(string s){
	stack<char> stk;
	assert(s.at(1) == '?');
	stk.push(s.at(1)); // Pushing the first certainly existing '?' symbol of ternary expression.
	for(int i = 2; i < s.length(); ++i){
		if(s.at(i) == '?')
			stk.push(s.at(i));
		else if(s.at(i) == ':')
			stk.pop();
		if(stk.empty())
			return i;
	}
}

Node* backchodi(string s){
	if(s.length() == 0)
		return NULL;
	Node* r = newNode(s.at(0));
	if(s.length() > 1){
		int colon_index = search_for_colon(s);
		string l_str = s.substr(2, (colon_index - 1) - (2) + 1);
		string r_str = s.substr(colon_index + 1, (s.length() - 1) - (colon_index + 1) + 1);
		r->left = backchodi(l_str);
		r->right = backchodi(r_str);
	}
	return r;
}
Node *convertExpression(string str,int i)
{
	return backchodi(str);
}