#include <stdio.h>
#include <string.h>
#include <malloc.h>

void bigmultiply(char *a,char *b)
{
	int i,j=0;
	int len1 = strlen(a);
	int len2 = strlen(b);

	char *s,*c;
	c=(char *)malloc(len1+len2);
	s=(char *)malloc(len1+len2);
	memset(s,0,len1+len2);
	memset(c,0,len1+len2);
	for(i=0;i<len1;i++)
		for(j=0;j<len2;j++){
			s[i+j] += (a[i]-'0')*(b[j]-'0');
		}
	for(i=0;i<len1+len2;i++){
		if(s[i]>10){
			s[i-1] += (s[i]/10);
			s[i]%=10;
		}
	}
	i =0;
	while(s[i]== 0){
		i++;
	}
	printf("11111\n");
	for(j=0;i<len1+len2;i++,j++){
		c[j]=s[i]+'0';
		printf("%c",c[j]);

	}

	free(s);
}

int main()
{
	char *a="12345678";
	char *b="12345678";

	bigmultiply(a,b);

	return 0;	
}
