#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

char subAbs(char a,char b)
{
	return (a-b)<0?(b-a):(a-b);
}

int compare(const  void *a,const void *b)
{
	return (*(char *)a - *(char *)b);
}

int setbitmap(int slope,int offset,int *bitmap)
{
	if( *(bitmap+slope) & (0x1<<offset)){
		return 1;
	}else{
		*(bitmap+slope) |= (0x1<<offset) ; 						  
	}

	return 0;
}

int IsOkArray(char data[],int len)
{
	int i;
	char *sub = NULL;

	sub = (char *)malloc(len);
	if(NULL == sub){
		return -1;
	}

	int bitmap[32]={0};

	int max = 0;
	for(i=0;i<len-1;i++){
			sub[i] = subAbs(data[i],data[i+1]);
			if(sub[i]>max){
				max = sub[i];
			}
			if(setbitmap((int)sub[i]/32,(int)sub[i]%32-1,bitmap) != 0){
				free(sub);
				return 1;
			}
	}

	i=0;
	while(i < (max/32)){
		if(bitmap[i++] != ~0){
			free(sub);
			return 1;
		}
	}

	if(bitmap[i] != ((0x1<<(max%32))-1)){
		free(sub);
		return 1;
	}
/*	
	qsort(sub,len-1,sizeof(char),compare); //O(nlgn)

	for(i=0;i<len-1;i++){
		if(sub[i] != i+1){
			return 1;
		}
	}
*/
	free(sub);
	return 0;
}
int main(void)
{
	char data1[4] = {2,5,4,6};
	char data2[12] = {1,2,4,7,11,16,22,29,37,46,56,67};

	if(IsOkArray(data1,sizeof(data1)) == 0){
		printf("data1 is ok!\n");
	}else{
		printf("data1 is wrong!\n");	
	}

	if(IsOkArray(data2,sizeof(data2)) == 0){
		printf("data2 is ok!\n");
	}else{
		printf("data2 is wrong!\n");	
	}
}
