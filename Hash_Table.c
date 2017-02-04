#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct sllist{
	char str[100]; //could be any type
	struct sllist* next;
}SLLIST;


SLLIST* hashTable[10];
char* hashTable2[10];

SLLIST* insert(SLLIST* head,char* str){
	SLLIST* new_node=NULL;
	new_node=malloc(sizeof(SLLIST));
	if(new_node==NULL) return NULL;
    strcpy(new_node->str, str);	
    new_node->next=head;	
	return new_node;
}
int search(SLLIST* head,char* str){
	SLLIST* trav=head;
	
	while(strcmp(trav->str,str)!=0 && trav->next!=NULL){
		trav=trav->next;
	}
	if(strcmp(trav->str,str)==0) return 1;
	else return 0;
	
}
int hash(char s[]){
	int sum=0;
	int i=0;
	for(i=0;s[i]!='\0';i++){
		sum+=s[i];
	}
	return sum%10;
}
void add(char* s){
	int x=hash(s);
	hashTable[x]=insert(hashTable[x],s);
}

int find(char* s){
	int x=hash(s);
	return search(hashTable[x],s);
}
void print(char* s){
	int x=hash(s);
	printf("%d",x);
    printf("%s",s);
}
int main(void){
	int n;
	scanf("%d",&n);
	char s[100];
	printf("Enter n Strings to add each in a different line:- ");
	for(int i=0;i<n;i++){
		fgets(s,sizeof(s),stdin);
		add(s);
	}
	printf("Enter String to find:- ");
	fgets(s,sizeof(s),stdin);

	if(find(s)==1) printf("It's there");
	else printf("It's not there");
}
