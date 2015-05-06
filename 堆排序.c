#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *left,*right;
}BTNode;
int front,rear=0;

BTNode *CreatBTree(int *D,int n,BTNode ** Q)//创建完全二叉树
{
	BTNode *root,*t;
	BTNode *p;
	int i;
	root=(BTNode *)malloc(sizeof(BTNode));
	root->data=D[0];
	root->left=root->right=NULL;
	t=root;
	t=NULL;
	Q[++rear]=root;
	for(i=1;i<n;i++)
	{
		if(t==NULL)    t=Q[++front];//出队

		p=(BTNode *)malloc(sizeof(BTNode));
		p->data=D[i];
		p->left=p->right=NULL;
		if(!t->left)
			t->left=p;
		else{
			t->right=p;
			t=NULL;
		}
			Q[++rear]=p;

	}
	return root;
}

//void Print(BTNode **root)
//{
//	BTNode ** t;
	
//}

void Phead(BTNode *root,BTNode **Q)//转换成大根堆
{
	int k,temp,tag;
	BTNode * t;
	
	while(1){
		k=front;
		tag=0;
		while(k > 0){
			t=Q[k];
			if(t->data < t->left->data){
				temp=t->data;
				t->data=t->left->data;
				t->left->data=temp;
				tag=1;
			}
			else if(t->data < t->right->data){
				temp=t->data;
				t->data=t->right->data;
				t->right->data=temp;
				tag=1;
			}
			k--;
		}
		if(tag==0)
			break;
	}
}

int main(void)
{
	int D[8]={3,2,5,8,4,7,6,9};
	BTNode *root;
	int i,temp;
	BTNode **Q;
	Q=(BTNode **)malloc(9*sizeof(BTNode *));
	root=CreatBTree(D,8,Q);
	
		Phead(root,Q);
		/*while(rear > 1){         //while(rear>1)
			temp=root->data;
			root->data=Q[rear]->data;
			Q[rear]->data=temp;

			if(Q[front]->right != NULL){
				printf("%3d",Q[front]->data);
				Q[front]->right=NULL;
			}
			else{
				Q[front]->left=NULL;
				front--;
			}
			Phead(root,Q);
		}*/

	for(i=8;i>=1;i--)
	{
		printf("%3d",Q[i]->data);
	}
}