#include <stdio.h>
#include <string.h>

char copy[128];

void swap(char  *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}
int sort(char *s,int end)
{
	int middle = (end)/2;
	if((end)>=2){
		sort(s,middle);
		sort(s+middle+1,end-middle-1);

		int i=0,j=middle+1,k=0;

		while(i<=middle && (j<=end)){
			if(s[i]>s[j]){
				copy[k] = s[j];
				j++;
			}else{
				copy[k] = s[i];
				i++;		
			}
			k++;
		}

		while(i <= middle){
			copy[k] = s[i];
			i++;
			k++;
		}

		while(j <= end){
			copy[k] = s[j];
			j++;
			k++;
		}

		for(k=0;k<=end;k++){
			s[k] = copy[k];
		}
	}
	else if((end) == 1) 
		if(s[0]>s[1]) swap(&s[0],&s[1]); 
}


int main(void)
{
	char a[10]={1,2,5,7,8,4,3,6,9,0};
	sort(a,sizeof(a)-1);
	int i=0;
	for(i=0;i<sizeof(a);i++)
		printf("%4d",a[i]);
	printf("\n");

	return 0;
}
