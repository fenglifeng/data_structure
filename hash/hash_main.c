#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define HASHSIZE 67

struct hashEntry_s{
	void *key;
	void *data;
	struct hashEntry_s *next;	
};

struct hashTable_s{
	struct hashEntry_s **hashlist;
};  
typedef struct hashTable_s hashTable_t;

unsigned long  getHashValue(char *string)
{	
 	 unsigned long ret=0;
 	 long n;
 	 unsigned long v;
 	 int r;

	if(NULL == string){
		return 0;
	}
  /*
     unsigned char b[16];
     MD5(c,strlen(c),b);
     return(b[0]|(b[1]<<8)|(b[2]<<16)|(b[3]<<24));
  */
 	 n=0x100;
  	while (*string) {
    	v=n|(*string);
     	n+=0x100;
     	r= (int)((v>>2)^v)&0x0f;
     	ret=(ret<<r)|(ret>>(32-r));
     	ret&=0xFFFFFFFFL;
     	ret^=v*v;
     	string++;
	//	printf("while is over\n");
  	}
  	return((ret>>16)^ret);
}

hashTable_t *createHashTable(void)
{
	hashTable_t *table;
	int i,len,primesize;
	table = malloc(sizeof(hashTable_t));
	if(NULL == table){	
		printf("error in createtable");
		return NULL;
	}
	len = sizeof(struct hashEntry_s *)*HASHSIZE;
	table->hashlist = malloc(len);
	if(table->hashlist == NULL){
		printf("error in createtable\n");
		exit(1);
	}
	for(i=0;i<HASHSIZE;i++)
		table->hashlist[i]=NULL;

	return table; 
}

inline struct  hashEntry_s *hashEntryNew(void *key, void *data)
{
    struct hashEntry_s *new = malloc(sizeof(struct hashEntry_s));
	memset(new,0,sizeof(struct hashEntry_s));
    new->key = key;
    new->data = data;
    new->next = NULL;
    return new;
}

int UpdateHashList(void *key,void *data,struct hashEntry_s *hashlist,hashTable_t *tab)
{
	if(hashlist !=NULL){			
		struct hashEntry_s *pos;
		for(pos=hashlist;pos != NULL;pos=pos->next){
			if(strcmp(key,pos->key)==0){
				pos->key = key;
				pos->data =data;
				return 0;
			}
		}
	}
	return -1;
}

int insertHash(void *key,void *data,hashTable_t *tab)
{
	int index;
	index =getHashValue((char *)key)%HASHSIZE;
//	printf("index:%d\n",index);
	if(UpdateHashList(key,data,tab->hashlist[index],tab)<0){
		struct hashEntry_s *l;
		l= hashEntryNew(key,data);
		if(tab->hashlist[index] == NULL){
			tab->hashlist[index] = l;
			printf("insert data:%s\n",(char *)tab->hashlist[index]->data);
		}else{
			struct hashEntry_s *pos;
			for(pos = tab->hashlist[index];pos->next !=NULL;pos->next){
					pos= l;
				}
	  	}
	  }	
	return 0;
}

void *getHashData(void *key,hashTable_t *tab)
{
	int index;
	char *get_data;
	index = getHashValue((char *)key)%HASHSIZE;
	printf("get index :%d\n",index);
	struct hashEntry_s *pos;

	for(pos = tab->hashlist[index];pos !=NULL;pos = pos->next){
		if(strcmp(key,pos->key) == 0){
			return pos->data;
		}
	}
	return NULL;
}

int removeHash(void *key,hashTable_t *tab)
{
	int index;
	index = getHashValue((char *)key)%HASHSIZE;
	struct hashEntry_s *pos;
	for(pos=tab->hashlist[index];pos != NULL;pos=pos->next,index++){
		if(strcmp(key,pos->key) == 0){
			pos->key = NULL;
			pos->data = NULL;
			if(pos->next != NULL){
				pos =pos->next;
			}else{
				tab->hashlist[index] =NULL;
			}
			return 0;
		}
		return -1;
	}
	printf("remove over!\n");
	return -1;
}
int main(void)
{
	hashTable_t *table_a;
	int i=0;
	char *data ="hello";
	char *getdata ="world" ;
	char *key ="1";
	table_a = createHashTable();
	if(table_a == NULL){
		printf("error!\n");
		return -1;
	}

	insertHash(key,data,table_a);

	getdata = getHashData(key,table_a);
	if(getdata == NULL ){
		printf("wo cao !!!\n");
	   	return -1;
	}
	printf("get hash data :%s\n",getdata);	

	char *data2="fuck!";
	insertHash(key,data2,table_a);

	getdata = getHashData(key,table_a);
	if(getdata == NULL ){
		printf("wo cao !!!\n");
	   	return -1;
	}
	printf("get hash data :%s\n",getdata);	

	removeHash(key,table_a);
	getdata = getHashData(key,table_a);
	if(getdata == NULL ){
		printf("wo cao !!!\n");
	   	return -1;
	}
	printf("get data remove:%s\n",getdata);

	free(table_a);
	return 0;
}
