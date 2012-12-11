#include <stdlib.h>
#include <stdio.h>

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
	char a[4] = {2,4,3,5};
	quicksort(a,4);
	int i;
	for(i=0;i<4;i++)
		printf("%4d",a[i]);
	return 0;
}
