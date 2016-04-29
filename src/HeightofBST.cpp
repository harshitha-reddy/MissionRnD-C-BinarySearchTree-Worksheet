/*

1)Given a BST ,Find its Maximum Height 

Height of a NULL BST is 0

Height of a BST which has only one node is 1

Ex Input : 

    10 
    /\
   5 80
  /  /
 2  50
  \
   4

Height of above Tree is 4

Ex Output : Return the Height of the Tree , -1 if Invalid

2) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 11
get_sum_left for 80 returns 0
Return -1 for invalid inputs

3) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 130
get_sum_left for 80 returns 0
Return -1 for invalid inputs

*/
#include <stdlib.h>
#include <stdio.h>
int Add_tree(struct node *root);
struct node{
	struct node * left;
	int data;
	struct node *right;
};


int get_height(struct node *root){
	if (root == NULL)
		return 0;
	int left_height, right_height;
	left_height = get_height(root->left);
	right_height = get_height(root->right);
	if (left_height > right_height)
		return(left_height + 1);
	else
		return(right_height + 1);
}
int Add_tree(struct node *root){
	if (root == NULL)
		return 0;
	else
		return(root->data + Add_tree(root->left) + Add_tree(root->right));
}
int get_left_subtree_sum(struct node *root){
	if (root == NULL)
		return 0;
	int left_sum, right_sum, tree_sum;
	tree_sum = root->data;
	left_sum = get_left_subtree_sum(root->left);
	return Add_tree(root->left);
}

int get_right_subtree_sum(struct node *root){
	if (root == NULL)
		return 0;
	int tree_sum;
	tree_sum = root->data;
	return Add_tree(root->right);
}