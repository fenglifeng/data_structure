#include <stdio.h>
#include <malloc.h>

#define MAXSIZE 256

/***************************************
 *定义队列结构
 * **************************************/
typedef struct {
	int data[MAXSIZE];/*数据类型，其中int可以根据需要进行修改*/
	int front; 		/*队列头指针*/
	int rear; 		/*队列尾指针*/
}SqQueue;

/********************************
 *初始化队列
 *入口参数：所需初始化队列指针
 * *****************************/
int InitQueue(SqQueue *Q)
{
	Q->front = 0;
	Q->rear = 0;

	return 0;
}
/**********************************
 * 队列长度
 * 入口参数：队列
 * 出口参数：队列长度
 ******************************** */
int QueueLength(SqQueue Q)
{
	return((Q.rear-Q.front+MAXSIZE)%MAXSIZE);
}

/*************************************
 *入队列
 *入口参数：队列，入队列的元素
 ****** ************************/
int EnQueue(SqQueue *Q,int e)
{
	if((Q->rear+1)%MAXSIZE==Q->front)	
		return -1;
	Q->data[Q->rear] = e; 	/*加入元素*/
	Q->rear = (Q->rear + 1)%MAXSIZE;  /*尾指针＋1*/

	return 0;
}

/***********************************
 *出队列
 *入口函数：队列 出队列的元素指针
 * *******************************/

int DeQueue(SqQueue *Q,int *e)
{
	if(Q->front == Q->rear)  	/*队列空。返回错误*/
		return -1;
	*e = Q->data[Q->front];    /*出队列*/
	Q->front = (Q->front + 1)%MAXSIZE;  /*队列头指针＋1*/

	return 0;
}


int main(void)
{
	SqQueue *Q;
	int a[5]={1,2,3,4,5};
	
	Q = (SqQueue*)malloc(sizeof(SqQueue));
	if(NULL == Q){
		printf("malloc failed\n");
		return -1;
	}

	int reval;
	reval = InitQueue(Q);
	if(reval < 0){
		printf("error in InitQueue\n");
		return -1;
	}

	reval= EnQueue(Q,a[2]);
	if(reval <0){
		printf("error in EnQueue");
		return -1;
	}
	
	printf(" data entry :%d\n",Q->data[Q->rear-1]);  //尾数据

	int b;
	reval = DeQueue(Q,&b);
   	if(reval<0){	
		printf("error in DeQueue\n");
		return -1;
	}

	printf("exit queue :%d\n",b);

	free(Q);

	return 0;
	
}



