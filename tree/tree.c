#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct BiTNode_s{
	int data;
	struct BiTNode_s *LChild;
	struct BiTNode_s *RChild;
}BiTNode;

static int i = 0;
BiTNode* CreateTree()
{
	char a[10];
	BiTNode *Tree;
	scanf("%s",a);
	if(!(strcmp("quit",a))){
		Tree = NULL;
		return Tree;
	}

	Tree = (BiTNode *)malloc(sizeof(BiTNode));
	if(!Tree){
		return Tree;
	}
	Tree->data = i++;
	Tree->LChild = CreateTree();
	Tree->RChild = CreateTree();

	return Tree;
}

int pprintf(BiTNode *Tree)
{
	if(Tree == NULL){ 
		//printf("TREE is NULL!\n");
		return 0;
	}
	printf("(");
	printf("%d",Tree->data);
	if(Tree->LChild) pprintf(Tree->LChild);
	if(Tree->RChild) pprintf(Tree->RChild);
	printf(")");

	return 0;
}

int PreOrder(BiTNode *Tree)
{
	if(Tree){
		printf("%4d\n",Tree->data);
		PreOrder(Tree->LChild);
		PreOrder(Tree->RChild);
	}
}

int MidOrder(BiTNode *Tree)
{
	if(Tree){
		PreOrder(Tree->LChild);
		printf("%4d\n",Tree->data);
		PreOrder(Tree->RChild);
	}
}

int main(void)
{
	BiTNode *Tree;
	Tree = CreateTree();
	if(!Tree){
		printf("root is null!\n");
		return 0;
	}
	PreOrder(Tree);
	printf("\n");
	MidOrder(Tree);
	pprintf(Tree);
	return 0;
}
