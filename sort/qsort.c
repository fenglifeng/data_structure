#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int parttion(char *s,int len)
{
	if(s == NULL || len <= 0 ){
		return -1;
	}
	int i,j,key;
	i = 0;
	j = len-1;
	key = s[0];
	char tmp;

	while(i<j){
		for(j;j>=0;j--){
			if(s[j]<key){
				tmp = s[i];
				s[i] = s[j];
				s[j] = tmp;
				break;
			}
		}

		for(i;i<j;i++){
			if(s[i]>key){
				tmp = s[i];
				s[i] = s[j];
				s[j] = tmp;
				break;
			}
		}
	}
	return i;
		
}

int quicksort(char *s,int len)
{
	int i,j;
	if(s == NULL){
		return -1;
	}
	if(len == 1){
		return 0;
	}
	i = parttion(s,len);
	if(i< 0) return 0;
	quicksort(s,i+1);
	quicksort(s+i+1,len-i-1);
	return 0;
}
int main()
{
	char a[10] = {2,4,3,5};
	int i;

	srand((unsigned )time(NULL));
	for(i=0;i<10;i++){
		a[i] = random()%100;
	}
	quicksort(a,sizeof(a)/sizeof(char));
	for(i=0;i<sizeof(a);i++)
		printf("%4d",a[i]);
	putchar('\n');
	return 0;
}
