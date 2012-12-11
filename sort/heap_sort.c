#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char copy[128];

void swap(char  *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}
char tmp;
int heapsort(char *s,int index,int len)
{
	index--;
	tmp=s[index];
	int son=0;
	int father=index;
	for(son=index*2+1;son<len;son=2*son+1){
		tmp = s[father];
		if(son<(len-1) && s[son]<s[son+1]) son++;
		if(s[father]>s[son]) break;
		s[father] = s[son];
		father = son;
		s[son]=tmp;
	}
	s[father]=tmp;
}


//char a[6]={4,3,6,5,1,2};
int main(void)
{
	char a[10]={7,5,2,1,8,4,3,6,9,0};
	int i=0;
	for(i=0;i<sizeof(a);i++)
		a[i]=random()%100;

	int len=sizeof(a);
	/*heap*/
	for(i=len/2;i>0;i--)
		heapsort(a,i,len);

	/*sort*/
	for(i=len-1; i>=1; i--) {							  
	 tmp  = a[i];  
	 a[i] = a[0];  
	 a[0] = tmp;  
   	 heapsort(a,1,i);  
	}
	for(i=0;i<len;i++)
	printf("%3d",a[i]);
	printf("\n");
	return 0;
}
