#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <bits/stdc++.h>
using namespace std;
struct Node 
{
   int data; //data _member
   struct Node *next;//pointer to itself
}*first=NULL;       //

void create(int A[],int n)
{
   int i;
   struct Node *t,*last;   //one temporary ptr variable and other which will point to last *last
   first=(struct Node *)malloc(sizeof(struct Node));//created first 
   first->data=A[0];
   first->next=NULL;
   last=first;    //created first NODE for Oth element now need to create for other remaining.
   
   for(int i=1;i<n;i++)
   {
	 t=(struct Node *)malloc (sizeof(struct Node)); 
	 t->data=A[i]; 
	 t->next=NULL;
	 last->next=t;
	 last=t;
   }   
}
void display(struct Node *p)  //display the LinkList
{
   	while(p!=NULL)
	{
	   printf("%d ",p->data);
       p=p->next;	   
	}

}
void Rdisplay(struct Node *p)     //print in reverse.
{
    if(p!=NULL)
	{
		Rdisplay(p->next);	
        printf("%d ",p->data);		
	}
}
int count(struct Node *p)
{
	int count=0;
    while(p!=NULL)
	{
		count++;
		p=p->next;
    }
	return count;
}	
int sum(struct Node *p)
{
     int sum=0;
	 while(p!=NULL)
	 {
	    sum=sum+p->data;		
		p=p->next; 
	
	 }
	 return sum;
}	
int max(struct Node *p)
{
	int max=INT_MIN;    //SHRT_MIN=-32768
	while(p!=NULL)
	{
	   if (p->data>max)	
	   {
		   max=p->data;
       }	   
	   p=p->next;
	}
	return max;
}	
struct Node* search(struct Node *p,int key)   //returning the address if element is present
{
    while(p!=NULL)
	{
	    if(key==p->data)
		{
			return p;  //returning address of the node searched
           break;
		}
        p=p->next;		
	}
	
	return NULL;           //if element not found then return NULL address
}	
struct Node* bringatfirstsearch(struct Node *p,int key)
{
	struct Node *q=NULL;
	while(p!=NULL)
	{
	     if(p->data==key)
		 {	
	 
            q->next=p->next;
			p->next=first;
			first=p;
			return p;
    	 }
		 q=p;
		 p=p->next;
	     
	}
}	
void insert(struct Node *p,int index,int x)
{
   struct Node *t;
    if (index<0 || index > count(p))     //index invalidity condition
		return;
	t=(struct Node *)malloc (sizeof(struct Node));
    t->data=x;
	if(index==0)
	{
	    t->next=first;
        first=t;		
	}	
	else
	{
	    for(int i=0;i<index-1;i++)    //index also position-1
          p=p->next;
        t->next=p->next;
        p->next=t;   		
	}	
 }	
 /*
 void insertatlast(int x)
 {
     struct Node *t;
	 t=(struct Node * )malloc(sizeof(struct Node));
	 t->data=x;
	 t->next=NULL;
	 if(first==NULL)
	 {
		 first=last=t;
	 }
	 else
	 {
		 last->next=t;
		 last=t;
		 
	 } 
 }	
*/
void insertinsortedlist(struct Node *p,int value)
{
	struct Node *t;
	struct Node *q=NULL;
	t=(struct Node *)malloc(sizeof(struct Node));
	t->data=value;
	t->next=NULL;
	if(first==NULL)
	first=t;
else
   {
	while(p&&p->data<value)
	{
		q=p;
		p=p->next;
	}
   if(p==first)
   {
     t->next=first;
	 first=t;
	 
   }
else {   
		t->next=q->next;
		q->next=t;
      } 
   }
}
	
int delete1(struct Node *p,int pos)	
{
   struct Node *q=NULL;
   int x=-1;
   if(pos < 1 || pos >count(p))
	   return -1;
   if(pos==1)
   {
	   q=first;
	   x=first->data;
	   first=first->next;
	   free (q);
	   return x;
   }
   else
   {
	 for(int i=0;i<pos-1;i++)   
	 {
		 q=p;
         p=p->next;		 
	 }
      q->next=p->next;
      x=p->data;
      free (p);
      return x;	  
   }
}
int issorted(struct Node *p)
{
    int x=INT_MIN;
	while(p!=NULL)
	{
		if (x>p->data)
		return -1;
	x=p->data;
	p=p->next;
	
    }
	return 1;
}	
void deleteduplicates(struct Node *p)
{
	 struct Node *q;
	 q=first->next;
	 while(q!=NULL)
	{
	   if(p->data!=q->data)
	   {
          p=q;
		  q=q->next;
	   }   
	else
	  {
		p->next=q->next;
		free (q);
		q=p->next;
	  }	
	}
}
void reverseLLsliding(struct Node *p)
{
	struct Node *q=NULL;
	struct Node *r=NULL; 
	while(p!=NULL)
	{
	   r=q;
       q=p;
       p=p->next;
       q->next=r;	   
	}
	first=q;
}

void reverse2(struct Node *q,struct Node *p)
{
	if (p)
	{
		reverse2(p,p->next); 
        p->next=q;		
	}
	else
		first=q;
}	
int Nnodefromlast(struct Node *p,int n)
{
	struct Node *q=first;
	for(int i=0;i<n;i++)  //moving nodes as per number of which node to find
	{
		p=p->next;
	}
    while(p!=NULL)
	{
		p=p->next;
		q=q->next;
	}
	return q->data;
	
}	
int isloop(struct Node *p)
{
	struct Node *q;
	q=p;
	do{
		p=p->next;     //this condition because at start p and q at same position
		q=q->next;    //iterate 1 once and iterate second twice if they meet again it is loop
		if(q!=NULL)q=q->next; //checking NULL condtn if already NULL then loop out
	}while(p && q && p!=q);   //if any of the one fails loop out
	if(p==q) return 1;
	else
		return 0;
}	
struct Node * removeduplicates(struct Node *p)
{
	unordered_set <int> seen;
	struct Node *q=NULL;
	while(p!=NULL)
	{
		if(seen.find(p->data)!=seen.end())
		{
			q->next=p->next;  //changing link
			free (p);			//remove node
			
		}else
		{
			seen.insert(p->data); //new entry to set
			q=p;
		}	
		p=q->next;
	}	
	
	return first;
}	

int main()
{
   int A[]={3,5,7,20,10,15,20,20,20};
   create (A,8);
   printf("Displaying the nodes in LinkedList\n");
   display(first);
   printf("\nDisplaying the nodes in reverse of LinkedList\n");
   Rdisplay(first);
   printf("\nThe number of nodes in Linkedlist is %d \n",count(first));
   printf("\nThe sum of all the nodes in LinkedList is %d \n",sum(first));
   printf("\nThe maximum value of all nodes is %d \n",max(first));
   printf("\nThe searched item is at a particular %u\n",search(first,5));
   printf("\nThe searched item is at a particular %u\n",bringatfirstsearch(first,10));
   insert(first,3,4);
   printf("\nLinkedlist after inserting in the index and with value\n");
   display(first);
   printf("\nLinkedlist after deleting in the linkedlist is\n");
   printf("Delete item is %d",delete1(first,1));
   display(first);
   printf("\nIf value is 1 sorted else not sorted :%d\n",issorted(first));
   printf("\nThe elements after deleting are\n");
   deleteduplicates(first);
   display(first);
   printf("\nReverse of linkedlist is\n");
   reverseLLsliding(first);
   display(first);
   printf("\nReverse of linkedlist is\n");
   reverse2(NULL,first);
   display(first);
   printf("\n2nd Node from last is %d\n",Nnodefromlast(first,2));
   display(first);
   printf("\nif value 0 then no loop if 1  then loop so value is %d",isloop(first));
   printf("\nAfter deletion linkedlist is \n");
   removeduplicates(first);
   display(first);
   return 0;   
	
}	
