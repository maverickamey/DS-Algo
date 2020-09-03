#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node 
{
   int data;
   struct Node *next; 
}*first=NULL,*second=NULL,*third=NULL;


void create(int a[],int n)
{
   struct Node *t,*last;
   first=(struct Node *)malloc(sizeof(struct Node *));
   first->data=a[0];
   first->next=NULL;
   last=first;
   for(int i=1;i<n;i++)
   {
	 t=(struct Node *)malloc(sizeof(struct Node));
     t->data=a[i];
     t->next=NULL;
     last->next=t;
     last=t;	 
	   
   }
}	
void create2(int b[],int n)
{

   struct Node *t,*last;
   second=(struct Node *)malloc(sizeof(struct Node *));
   second->data=b[0];    
   second->next=NULL;
   last=second;
   for(int i=1;i<n;i++)
   {
     t=(struct Node *)malloc(sizeof(struct Node));
	 t->data=b[i];
	 t->next=NULL;
	 last->next=t;
	 last=t;
   }	
}	
void display(struct Node *p)
{
   while(p!=NULL)
   {
	   
      printf("%d ",p->data);
	  p=p->next;
   }	   
}	
void cocatenate(struct Node *p,struct Node *q)
{ 
    third=p;
    while(p->next!=NULL)
	{
	   p=p->next;
    }
	p->next=q;
	second=NULL;
}
/*void cocatenate(struct Node *p,struct Node *q)
{
    third=p;
    if(p->next=NULL)
    {
        p->next=second;
    }
    else
     cocatenate(p->next,q);
    
}*/
void merge(struct Node *p,struct Node *q)
{
	struct Node *last;
	if(p->data<q->data)
	{
	   third=last=p;
       p=p->next;
       third->next=NULL;	   
	}
	else
	{
	   third=last=q;
       q=q->next;	   
	   third->next=NULL;
   	}
	while(p && q)
	{
	   if(p->data<q->data)
	   {
		   last->next=p;
		   last=p;
		   p=p->next;
		   last->next=NULL;

	   }
	   else
	   {
		   last->next=q;
		   last=q;
		   q=q->next;
		   last->next=NULL;
		   
	   }
	}
	if(p)last->next=p;
	if(q)last->next=q;
}	
int main()
{
    int a[5]={10,20,30,40,50};
    int b[5]={5,15,25,35,45};	
	create(a,5);
	create2(b,5);
//	cocatenate(first,second);
//	display(third);
	printf("\n");
	merge(first,second);
	display(third);
	
	return 0;
}	
