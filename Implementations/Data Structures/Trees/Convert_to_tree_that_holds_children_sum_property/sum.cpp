/* Program to convert an aribitary binary tree to
   a tree that holds children sum property */
 
#include <stdio.h>
#include <stdlib.h>
 
struct node
{
  int data;
  struct node* left;
  struct node* right;
};
 
/* This function is used to increment left subtree */
void increment(struct node* node, int diff);
 
/* Helper function that allocates a new node
 with the given data and NULL left and right
 pointers. */
struct node* newNode(int data);
 
/* This function changes a tree to to hold children sum
   property */
void convertTree(struct node* node)
{
  int left_data = 0,  right_data = 0, diff;
 
  /* If tree is empty or it's a leaf node then
     return true */
  if (node == NULL ||
     (node->left == NULL && node->right == NULL))
    return;
  else
  {
    /* convert left and right subtrees  */
    convertTree(node->left);
    convertTree(node->right);
 
    /* If left child is not present then 0 is used
       as data of left child */
    if (node->left != NULL)
      left_data = node->left->data;
 
    /* If right child is not present then 0 is used
      as data of right child */
    if (node->right != NULL)
      right_data = node->right->data;
 
    /* get the diff of node's data and children sum */
    diff = left_data + right_data - node->data;
 
    /* If node's children sum is greater than the node's data */
    if (diff > 0)
       node->data = node->data + diff;
 
    /* THIS IS TRICKY --> If node's data is greater than children sum,
      then increment subtree by diff */
    if (diff < 0)
      increment(node, -diff);  // -diff is used to make diff positive
  }
}
 
/* This function is used to increment subtree by diff */
void increment(struct node* node, int diff)
{
  /* IF left child is not NULL then increment it */
  if(node->left != NULL)
  {
    node->left->data = node->left->data + diff;
 
    // Recursively call to fix the descendants of node->left
    increment(node->left, diff);  
  }
  else if (node->right != NULL) // Else increment right child
  {
    node->right->data = node->right->data + diff;
 
    // Recursively call to fix the descendants of node->right
    increment(node->right, diff);
  }
}
 
/* Given a binary tree, printInorder() prints out its
   inorder traversal*/
void printInorder(struct node* node)
{
  if (node == NULL)
    return;
 
  /* first recur on left child */
  printInorder(node->left);
 
  /* then print the data of node */
  printf("%d ", node->data);
 
  /* now recur on right child */
  printInorder(node->right);
}
 
/* Helper function that allocates a new node
 with the given data and NULL left and right
 pointers. */
struct node* newNode(int data)
{
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
void _increment(node* root, int diff);
 
void convert(node* root);

/* Driver program to test above functions */
int main()
{
  struct node *root = newNode(50);
  root->left        = newNode(7);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left  = newNode(1);
  root->right->right = newNode(30);
 
  printf("\n Inorder traversal before conversion ");
  printInorder(root);
 
  // convertTree(root); // Call to already rpesent function.
  convert(root); // Call to self-written function.
 
  printf("\n Inorder traversal after conversion ");
  printInorder(root);
 
  // getchar();
  return 0;
}

// Self written function.
void convert(node* root){
  if(root == NULL)
    return;
  if(root->left == NULL && root->right == NULL)
    return;
  int diff;
  convert(root->left);
  convert(root->right);
  int l_data = 0, r_data = 0;
  if(root->right)
    r_data = root->right->data;
  if(root->left)
    l_data = root->left->data;
  diff = (l_data + r_data) - root->data;
  if(diff == 0)
    return;
  if(diff > 0){
    root->data += diff;
  }
  if(diff < 0)
    if(root->left)
      _increment(root->left, -diff);
    else if(root->right)
      _increment(root->right, -diff);
}

void _increment(node* root, int diff){
  if(!root)
    return;
  root->data += diff;
  if(root->left)
    _increment(root->left, diff);
  else if(root->right)
    _increment(root->right, diff);
}