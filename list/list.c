/*双向链表的插入*/
#include <stdio.h>
#include <malloc.h>

typedef struct Node_List_s{
	char value;
	struct Node_List_s *prev;
	struct Node_List_s *next;
}Node_List_t;

Node_List_t *Insert(Node_List_t *L,char value)
{
	Node_List_t *List;
	Node_List_t *Lt;
	if(L == NULL){
		List = (Node_List_t *)malloc(sizeof(Node_List_t));
		if(List == NULL){
			return;
		}
		List->value = value;
		List->prev = List;
		List->next = NULL;
		return List;
	}else{
		List = L->next;
		Lt = L;
		while(List != NULL){
			Lt = Lt->next;
			List = List->next;
		}
		List = (Node_List_t *)malloc(sizeof(Node_List_t));
		if(List == NULL){
			return;
		}
		List->value = value;
		List->prev = Lt;
		List->next = NULL;
		Lt->next = List;
		
		return L;
	}
}

void DelList(Node_List_t *L,char value)
{
	Node_List_t *List;
	Node_List_t *Lt;

	if(L == NULL){
		return ;
	}

	while(L != NULL){
		Lt = L->prev;
		List = L->next;
		if(L->value == value){
			Lt->next = List;
		    List->prev = Lt;	
			free(L);
			break;
		}
		L = L->next;
	}
	return;

}

int main(void)
{
	Node_List_t *L = NULL;
	Node_List_t *List = NULL;
	char a[4]={	0,1,3,4};
	int i=0;
	for(i=0;i<sizeof(a);i++)
		L=Insert(L,a[i]);	

	List = L;
	while(L != NULL){
		printf("%4d\n",L->value);
		L = L->next;
	}

	L = List;
	DelList(L,a[2]);

	while(L != NULL){
		printf("%4d\n",L->value);
		L = L->next;
	}
	return 0;
}
