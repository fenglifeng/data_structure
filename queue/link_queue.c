#include <stdio.h>
#include <malloc.h>


typedef int QElemType;

typedef struct QNode{
	QElemType  data;
	struct QNode  *next;
}QNode,*QueuePtr;

typedef struct{
	QueuePtr front,rear;/*头、尾两个指针*/
}LinkQueue;

/***********************************
 *入队列
 *入口参数：队列链表指针，入队列元素
 ***********************************/
int EnQueue(LinkQueue *Q,QElemType e)
{
	QueuePtr s= (QueuePtr)malloc(sizeof(QNode));
	if(NULL==s)
		return -1;
	s->data = e;
	s->next = NULL;
	Q->rear->next = s;    /*当前链表尾指针指向添加的链表指针*/
	Q->rear = s;          /*尾指针为新添加的链表指针*/

	return 0;
}

/**************************************
 *出队列
 *入口参数：队列链表指针，出队列元素指针
 **************************************/
int DeQueue(LinkQueue *Q,QElemType *e)
{
	QueuePtr P;
	if(Q->front== Q->rear)
		return -1;

	P = Q->front->next;   	/*将要删除的队列头赋值于P*/
	*e = P->data; 			/*出队列*/
	Q->front->next =P->next;/*删除队列头*/
	if(Q->rear==P)   		/*如果队头等于队尾，则将Q的队头队尾指向同一元素*/
		Q->rear == Q->front;

	free(P);
	return 0;
}
