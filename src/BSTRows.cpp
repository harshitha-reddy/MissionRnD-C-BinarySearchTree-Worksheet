/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
int height(struct node* node);
struct node{
	struct node * left;
	int data;
	struct node *right;
};
/*
struct Queue{
	struct node *front;
	struct node *rear;
};
struct Queue *CreateQueue(){
	struct Queue *Q;
	struct node *temp;
	Q =(struct Queue *) malloc(sizeof(struct Queue));
	if (!Q) return NULL;
	temp = (struct node *)malloc(sizeof(struct node));
	Q->front = Q->rear = NULL;
	return Q;

}
int IsEmptyQueue(struct Queue *Q){
	return(Q->front == NULL); 
}
void EnQueue(struct Queue *Q, int data){
	struct node *newNode;
	newNode = (struct node *)malloc(sizeof(struct node));
	if (!newNode)
		return;
	newNode->data = data;
	newNode->left = NULL;
	Q->rear->right = NULL;
	if (Q->front == NULL)
		Q->front = Q->rear;
}
void DeleteQueue(struct Queue *Q){
	struct node *temp;
	while (Q){
		temp = (struct node *) Q;
		Q = (struct Queue *)Q->front;
		free(temp);
	}
	free(Q);
}
LevelOrderTraversal(root,FinalArray)
{
	int j = 0;
	Queue NodeQueue;
	NodeQueue.Insert(root);
	while (!NodeQueue.Empty())
	{
		Element = NodeQueue.Delete();
		FinalArray[j] = Element->Data;
		i++;
		if(Element->Right != NULL)
		{
			NodeQueue.Insert(Element->Left);
		}
		if(Element->Left != NULL)
		{
			NodeQueue.Insert(Element->Left);
		}
	
	}
	return j;
}*/
void level_order(struct node* root, int level, int *arr, int *i){
	if (root == NULL)
		return;
	if (level == 1)
	{
		arr[*i] = root->data;
		*i = *i + 1;
	}
	else
	{
		level_order(root->right, level - 1, arr, i);
		level_order(root->left, level - 1, arr, i);
	}
}
int* BSTRighttoLeftRows(struct node* root)
{
	if (root==NULL)
    return NULL;
	int *arr;
	arr = (int *)malloc(sizeof(int)*50);
	int fin_height, index = 0, i;
	fin_height = height(root);
	for (i = 1; i <= fin_height; i++)
		level_order(root, i, &arr[0], &index);
	return arr;
}
int height(struct node* node)
{
	if (node == NULL)
		return 0;
	else
	{
		int lheight = height(node->left);
		int rheight = height(node->right);
		if (lheight > rheight)
			return(lheight + 1);
		else return(rheight + 1);
	}
}