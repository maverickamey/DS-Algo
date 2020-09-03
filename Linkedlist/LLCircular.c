#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node{
	int data;
	struct Node *next;
}*Head;	

void create(int a[],int n)
{
     struct Node *t,*last;
     Head=(struct Node *)malloc(sizeof(struct Node));	
	 Head->data=a[0];
	 Head->next=Head;//circular comment any pointing head on itself
	 last=Head;
	 for(int i=1;i<n;i++)
	 {
		t=(struct Node *)malloc(sizeof(struct Node));
        t->data=a[i];
		t->next=last->next;
		last->next=t;
		last=t;
	 }
}	
void display(struct Node *h)
{
    do{
		printf("%d ",h->data);
		h=h->next;
	  }while(h!=Head);//Note this step
      printf("\n");  
}	
void Rdisplay(struct Node *h)
{
   	static int flag=0;
	if(h!=Head || flag==0)
	{   flag=1;
        printf("%d ",h->data);
		h=h->next;
		Rdisplay(h->next);
	}	
	flag=0;
}
int length(struct Node *p)
{
	int len=0;
	do{
		len++;
		p=p->next;
		
	}while(p!=Head);
	return len;
	
}	
void insert(struct Node *p,int index,int ele)
{
   	struct Node *t;
	if (index < 0 || index >length(p))
       return;
   else if (index==0)
   {
       t=(struct Node *)malloc(sizeof(struct Node))	;
       t->data=ele;
       if(Head==NULL)
	   {
		  Head=t;
          Head->next=Head;		  
       }
       else
	   {
         while(p->next!=Head) p=p->next;
		 p->next=t;
		 t->next=Head;
		 Head=t;
		   
	   }	   
   }
    else
	{
         for(int i=0;i<index-1;i++)p=p->next;
		 t=(struct Node *)malloc(sizeof(struct Node));
		 t->data=ele;
		 t->next=p->next;
		 p->next=t;

	}	
}	
int delete1(struct Node *p,int index )
{   
     int x;
    struct Node *q;
    if(index <0 || index >length(p))
      return -1;
    if (index==1)
	{
      while(p->next!=Head)p=p->next;
	   x=Head->data;
	   //Head=Head->next;
	   if(Head==p)
		{
			free (Head);
			Head=NULL;
		}	
		else
		{
			p->next=Head->next;
			free (Head);
			Head=p->next;	   
		}
	}
	else 
	{
	     	for(int i=0;i<index-2;i++)p=p->next;
		q=p->next;
		p->next=q->next;
		x=q->data;
		free (q);
	}	
    return x;
}	
int main()
{
   int a[]={2,3,4,5,6};
	create(a,5);
	display(Head);
	insert(Head,4,15);
	printf("\n");
	display(Head);
	printf("\nDeleted item is %d",delete1(Head,1));
	display(Head);
	return 0;
	
}	
