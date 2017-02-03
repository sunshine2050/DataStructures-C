#include <stdio.h>
#include <stdlib.h>

typedef struct dllist{
	int val; //could be any type
	struct dllist* next;
}DLLIST;

typedef struct _Queue{
	DLLIST* head;
	DLLIST* tail;
}Queue;

void enqueue(Queue* q,int val){
	DLLIST* new_node;
	new_node=malloc(sizeof(DLLIST));
	if(new_node==NULL) exit(-1);
	new_node->next=NULL;
	new_node->val=val;
	if((*q).tail==NULL){
		(*q).head=new_node;
		(*q).tail=new_node;
		(*q).head->next=NULL;
		(*q).tail->next=NULL;
	}
	else{
		(*q).tail->next=new_node;
		(*q).tail=new_node;
	}
}
int dequeue(Queue* q){
	DLLIST* new_node;
	int k;
	if((*q).head==NULL){ perror("Empty"); return -1;}
	else{
		new_node=(*q).head;
		k=(*q).head->val;
		(*q).head=(*q).head->next;
		if((*q).head==NULL) (*q).tail==NULL;
		free(new_node);
	}
	return k;
}
int main(void) {
	Queue q;
	q.head=NULL;
	q.tail=NULL;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) enqueue(&q,i);
	for(int i=0;i<n;i++) printf("%d",dequeue(&q));
	
	return 0;
}
