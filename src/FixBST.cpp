/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

20 4 9 1 30

firstTime = 1;
for(i=0;i<n-1;i++)
{
if( array[i]> arrray[i+1] )
{
if(firstTime)
{mismatch1 = array [i];
firsttime = 0;
}
else
{
mismatch2 = array [i+1]
}
}



TreeReplace( root, Mismtach1, mismatch2)
{
findNode(Mismacth1)->Data = Mismatch2;
FindNde(Mismatch2)->Data =Mismatch1;
|}
*/
#include <stdio.h>
#include <stdlib.h>
int find_height(struct node* node);
struct node{
	struct node * left;
	int data;
	struct node *right;
};

void fix_bst(struct node *root){
	if (root == NULL)
		return;
	int firstTime=0, i, mismatch1, mismatch2, height;
	height = find_height(root);
	int *array = (int *)malloc(height*sizeof(int *));
	for (i = 0; i<height - 1; i++)
	{
		if (array[i]> array[i + 1])
		{
			if (firstTime)
			{
				mismatch1 = array[i];
				firstTime = 0;
			}
			else
			{
				mismatch2 = array[i + 1];
			}
		}
	}
}
int find_height(struct node* node)
	{
	if (node == NULL)
		return NULL;
	else
	{
		int lheight = find_height(node->left);
		int rheight = find_height(node->right);
		if (lheight > rheight)
			return(lheight + 1);
		else
			return(rheight + 1);
	}
}