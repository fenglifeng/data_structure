#include <stdio.h>
#include <malloc.h>

typedef int SElemTYpe;/*元素类型，暂时定义成int*/

#define MAXSIZE 256
/**************************
 *栈数据结构
 ***************************/
typedef struct{
	SElemTYpe data[MAXSIZE];
	int top;
}SqStack;
/*******************************
*入栈
＊入口参数：栈指针，入栈元素
*******************************/
int Push(SqStack *S,SElemTYpe e)
{
	if(S->top == MAXSIZE-1)
		return -1;
	S->top++;
	S->data[S->top]=e;

	return 0;
}

/*******************************
 *出栈
 *入口参数：栈指针，出栈元素指针
 ******************************/
int Pop(SqStack *S,SElemTYpe *e)
{
	if(S->top == -1)
		return -1;
	*e=S->data[S->top];
	S->top--;

	return 0;
}

/************************
 *初始化栈
 *入口参数：栈指针
 ************************/
int InitStack(SqStack *S)
{
	S->top = 0;
	return 0;
}

int main(void)
{
	SElemTYpe a[5]={1,2,3,4,5};
	SqStack *S;
	
	S = (SqStack *)malloc(sizeof(SqStack));
	if(NULL == S){
		printf("malloc error!\n");
		return -1;
	}

	int reval;
	InitStack(S);
	reval = Push(S,a[4]);
	if(reval<0){
		printf("PUSH error!\n");
		return -1;
	}
	printf("push data:%d\n",S->data[S->top]);

	int b=1;
	reval = Pop(S,&b);
	if(reval<0){
		printf("Pop error \n");
		return -1;
	}
	printf("POP data:%d\n",b);

	free(S);
	return 0;
}
