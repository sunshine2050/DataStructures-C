#include <stdio.h>
#include <stdlib.h>

typedef struct _st{
	int val; //could be any type.
	struct _st* next;
}Stack;
Stack* create(int val){
	Stack* head=NULL;
	head=malloc(sizeof(Stack));
	if(head==NULL) return NULL;
	head->val=val;
	return head;
}
Stack* push(Stack* head,int val){
	Stack* new_node=NULL;
	new_node=malloc(sizeof(Stack));
	if(new_node==NULL) return NULL;
	new_node->val=val;
	new_node->next=head;
	return new_node;
}

int pop(Stack** head){
	Stack* trav=*head;
	if(trav==NULL) exit(0);
	int k=trav->val;
	trav=trav->next;
	*head=trav;
	return k;
}
int main(void){
	Stack* st=NULL;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		st=push(st,x);
	}
	for(int i=0;i<n;i++){
		printf("%d ",pop(&st));
	}
}
