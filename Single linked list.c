#include <stdio.h>
#include <stdlib.h>

typedef struct sllist{
	int val; //could be any other type
	struct sllist* next;
}sllnode;

sllnode* create(int val){
	sllnode* head=NULL;
	head=malloc(sizeof(sllnode));
	if(head==NULL) return NULL;
	head->val=val;
	head->next=NULL;
	return head;
}

int find(sllnode* head,int val){
	sllnode* trav=head;
	while(trav->val!=val && trav->next!=NULL){
		trav=trav->next;
	}
	if(trav->val==val) return 1;
	else return 0;
	
}
void print(sllnode* head){
	sllnode* trav=head;
	while(trav!=NULL){
		printf("%d\n",trav->val);
		trav=trav->next;
	}
}
sllnode* delete(sllnode* head,int val){
	sllnode* trav=head;
	if(trav->val==val){
		trav=trav->next;
		return trav;
	}
	while(trav->next->val!=val && trav->next->next!=NULL){
		trav=trav->next;
	}
	if(trav->next->val==val){
		trav->next=trav->next->next;
	}	
	return head;
}

sllnode* insert(sllnode* head,int val){
	sllnode* new_node=NULL;
	new_node=malloc(sizeof(sllnode));
	if(new_node==NULL) return NULL;
	new_node->val=val;
	new_node->next=head;	
	return new_node;
}

void destroy(sllnode* head){
	if(head->next) destroy(head->next);
	free(head);
}
int main(void){
	sllnode* sll1=NULL;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		sll1=insert(sll1,x);
	}
	print(sll1);
 	return 0;
}
