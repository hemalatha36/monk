#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *leftptr;
struct node *rightptr;
};
struct node *root=NULL;
struct node* add(struct node* root, int data);
int length(struct node* t) ;
int main(void)
{
int n,i,a;
scanf("%d",&n);
for(i=0;i<=n-1;i++)
{
scanf("%d",&a);
root=add(root,a);
}
int r=length(root);
printf("%d",r);
return 0;
}
struct node* add(struct node* root, int data1)
{
if (root == NULL) //If the tree is empty, return a new,single node
{
root=(struct node *)malloc(sizeof(struct node));
root->data=data1;
root->leftptr=NULL;
root->rightptr=NULL;
return root;
}
else
{
if (data1 <= root->data)
root->leftptr = add(root->leftptr, data1);
else
root->rightptr = add(root->rightptr, data1); 
return root;
}
}
int length(struct node* t) 
{
if (t==NULL) 
{
return 0;
}
else
{
 
int lDepth = length(t->leftptr);
int rDepth = length(t->rightptr);
if (lDepth > rDepth) 
{	
return(lDepth+1);
}
else 
{
return(rDepth+1);
}
}
}