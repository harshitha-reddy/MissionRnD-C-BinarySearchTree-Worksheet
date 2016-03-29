/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task :
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>
#include<stdlib.h>
void inorder_recr(struct node *root, int *arr, int *index);
void preorder_recr(struct node *root, int *arr, int *index);
void postorder_recr(struct node *root, int *arr, int *index);
struct node{
	struct node * left;
	int data;
	struct node *right;
};
void inorder(struct node *root, int *arr){
	if (arr == NULL)
		return;
	int i = 0;
	inorder_recr(root, arr, &i);

}

void inorder_recr(struct node *root, int *arr, int *index){

	if (root == NULL)
		return;
	inorder_recr(root->left, arr, index);
	arr[*index] = root->data;
	*index = *index + 1;
	inorder_recr(root->right, arr, index);


}
void preorder(struct node *root, int *arr){
	if (arr == NULL)
		return;
	int i = 0;
	preorder_recr(root, arr, &i);

}

void preorder_recr(struct node *root, int *arr, int *index){

	if (root == NULL)
		return;
	arr[*index] = root->data;
	*index = *index + 1;
	preorder_recr(root->left, arr, index);
	preorder_recr(root->right, arr, index);


}
void postorder(struct node *root, int *arr){
	if (arr == NULL)
		return;
	int i = 0;
	postorder_recr(root, arr, &i);
}

void postorder_recr(struct node *root, int *arr, int *index){
	if (root == NULL)
		return;
	postorder_recr(root->left, arr, index);
	postorder_recr(root->right, arr, index);
	arr[*index] = root->data;
	*index= *index + 1;


}

