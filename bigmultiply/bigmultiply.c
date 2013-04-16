#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

#define NUMLENTH   32
char *multibig(char *a,char *b,char *c)
{
	if(NULL == a || NULL == b || NULL == c){
		exit(0);
	}

	int len1,len2;
	len1 = strlen(a);
	len2 = strlen(b);

	int i,j;
	int len = len1 + len2 -2;
	for(i=len1-1;i>=0;i--){ 	/*因为是倒序的*/
		for(j=len2-1;j>=0;j--){
			int len3 = len - i - j;
			c[len3] += (a[i] - '0')*(b[j] - '0');
			if(c[len3] >= 10){
				c[len3+1] += (c[len3]/10);
				c[len3] %= 10;
				if(c[len3+1] >= 10){
					int k=2;
					c[len3+k]++;
					c[len3+1] %= 10;
					while(c[len3+k] >= 10){
						c[len3+k+1]++;
						c[len3+k] %= 10;
						k++;
					}
				}
			}
		}
	}

	return ;
}

int main(void)
{
	char *a = NULL;
	char *b = NULL;
	char *c = NULL;

	a =(char *) malloc(NUMLENTH);
	if(NULL == a){
		exit(0);
	}
	memset(a,0,NUMLENTH);

	b = (char *)malloc(NUMLENTH);
	if(NULL == b){
		exit(0);
	}
	memset(b,0,NUMLENTH);

	c = (char *)malloc(NUMLENTH*2+1);
	if(NULL == c){

		exit(0);
	}
	memset(c,0,NUMLENTH*2+1);

	printf("please input num 1:");
	scanf("%s",a);

	
	printf("please input num 2:");
	scanf("%s",b);

	multibig(a,b,c);	
	int flag = 0;
	int i=0;
	printf("the result:");
	for(i=NUMLENTH*2+1;i>=0;i--){
		if(*(c+i) != 0 || flag !=0){
			printf("%d",*(c+i));
			flag =1;
		}
	}
	printf("\n");
}
