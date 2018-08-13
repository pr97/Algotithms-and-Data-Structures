#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *left,*right;
	Node(int d){
		data=d;
		left=right=NULL;
	}
};
int printCount(Node *root,int k);
void insert(Node *root,int a1,int a2,char lr){
	if(root==NULL)
		return;
	if(root->data==a1){
		switch(lr){
			case 'L':root->left=new Node(a2);
			break;
			case 'R':root->right=new Node(a2);
			break;
		}
	}
	else{
		insert(root->left,a1,a2,lr);
		insert(root->right,a1,a2,lr);
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
                cin>>n;
		Node *root=NULL;
		while(n--){
			int a1,a2;
			char lr;
			cin>>a1>>a2>>lr;
			if(root==NULL){
				root=new Node(a1);
				switch(lr){
					case 'L':root->left=new Node(a2);
					break;
					case 'R':root->right=new Node(a2);
					break;
				}
			}
			else{
				insert(root,a1,a2,lr);
			}
		}
		int k;
		cin>>k;
		cout<<printCount(root,k)<<endl;
	}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Complete the function below
Node is as follows:
struct Node{
	int data;
	Node *left,*right;
	Node(int d){
		data=d;
		left=right=NULL;
	}
};*/

void print_path_from_i_to_j(int a[], int I, int J){
	for(int i = I; i <= J; ++i){
		cout << a[i];
	}
}

void k_sum_paths(Node* root, int lvl, int a[], int cumsum[], int& k, int& ctr){
	if(!root)
		return;
	a[lvl] = root->data;
	if(lvl > 0){
		cumsum[lvl] = cumsum[lvl - 1] + root->data;
	}
	else{
		cumsum[lvl] = root->data;
	}
	for(int i = -1; i < lvl; ++i){
		if(i == -1){
			if(cumsum[lvl] == k){
				++ctr;
				print_path_from_i_to_j(a, i + 1, lvl);
				cout << "\n";
			}
		}
		else{
			if(cumsum[lvl] - cumsum[i] == k){
				++ctr;
				print_path_from_i_to_j(a, i + 1, lvl);
				cout << "\n";
			}
		}
	}
	k_sum_paths(root->left, lvl + 1, a, cumsum, k, ctr);
	k_sum_paths(root->right, lvl + 1, a, cumsum, k, ctr);
}

int printCount(Node *root,int k)
{
	int ctr = 0;
	int a[10];
	int cumsum[10];
	k_sum_paths(root, 0, a, cumsum, k, ctr);
	return ctr;
}