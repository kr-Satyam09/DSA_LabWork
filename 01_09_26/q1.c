/*
	Q1) WACP to reverse a single linked list
	i.Print the whole linked list in reverse order
	ii. Interchange first node with last node
*/

#include<stdio.h>
#include<stdlib.h>

typedef  struct node
{
	int data;
	struct node *next;
}sl;

sl *append(sl *top,int data)
{
	sl *p=(sl*)malloc(sizeof(sl));
	p->data=data;
	p->next=NULL;
	if(top==NULL)
		return p;
	sl *t=top;
	while(t->next!=NULL)
		t=t->next;
	t->next=p;
return top;
}

void disp(sl *top)
{
	if(top==NULL)
		return;
	disp(top->next);
	printf("%d->",top->data);
}

sl *swap(sl *top)
{
	if(top==NULL || top->next==NULL)
		return top;
	if(top->next->next==NULL)
	{
		sl *s=top->next;
		s->next=top;
		top->next=NULL;
		return s;
	}
	sl *prev=NULL;
	sl *last=top;
	while(last->next!=NULL)
	{
		prev=last;
		last=last->next;
	}
	prev->next=top;
	last->next=top->next;
	top->next=NULL;
return last;
}

void standard(sl *top)
{
	sl *t=top;
	while(t!=NULL)
	{
		printf("%d->",t->data);
		t=t->next;
	}
	printf("NULL\n");
}

int main()
{
	sl *top=NULL;
	int n,v;
	printf("\nEnter number of nodes");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("\nEnter value:");
		scanf("%d",&v);
		top=append(top,v);
	}
	printf("\nOriginal linked list:");
	standard(top);
	printf("\nReverse linked list");
	disp(top);
	printf("NULL\n");
	top=swap(top);
	printf("\nLinled list after swapping:");
	standard(top);
return 0;
}
