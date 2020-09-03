#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node 
{
	int data;
	struct Node *next;

}*first=NULL;

void create(int a[],int n)
{
	struct Node *last,*t;
	first=(struct Node *)malloc(sizeof(struct Node));
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
void display(struct Node *p)
{
	while(p!=NULL)
	{
	  printf("%d",p->data);
	  p=p->next;
	}	
	printf("\n");
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

int issorted(struct Node *p)
{
	int x=INT_MIN;
	while(p!=NULL)
	{
		if (x > p->data)
			return -1;
		else
			x=p->data;
		    p=p->next;
		
	}	
	return 1;
}
void reverse(struct Node *p)
{
	struct Node *q=NULL;
	struct Node *r=NULL;
		while(p->next!=NULL)
		{
			r=q;
			q=p;
			p=p->next;
			q->next=r;
		}
		first=q;
	
}
int bringatfirst(struct Node *p,int key)
{
	struct Node *q;
	
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

void concatenate(struct Node *p,struct Node *q)
{
	struct Node *third;
    struct Node *second;
	while(p->next!=NULL)
	{
		p=p->next;
	}	
	p->next=q;
	second=NULL;
    third=first;
	
}	
void merge(struct Node *p,struct Node *q)
{
	struct Node *third;
	struct Node *last;
	if (p->data < q->data)
	{
		third=last=p;
		p=p->next;
		third->next=NULL;
	}else
	{
		third=last=q;
		q=q->next;
		third->next=NULL;
	
	}
	while(p && q)
	{
		if (p->data < q->data)
		{
			last->next=p;
			last=p;
			p=p->next;
			last->next=NULL;
			
		
		}else{
			
			last->next=q;
			last=q;
			q=q->next;
			last->next=NULL;
			
		}
   }	
	if(p)last->next=p;
	if(q)last->next=q;
}	

int MiddleofLL(struct Node *p)
{
	struct Node *q;
	q=p;
	while(q!=NULL)
	{
		q=q->next;
		if(q)q=q->next;
	  if(q)	p=p->next;
	
	}	
	return p->data;
	
}	
int deleteNodewith1ptr(struct Node *p,int index)
{
	struct Node *temp;
	if(index < 0 || index > count(p))
	return 0;
	if(index==1)
	{
		first=first->next;
		free (p);
	}else
	{
	for(int i=0;i<index-1;i++)p=p->next;
	struct Node *temp=p->next;
	p->data=temp->data;
	p->next=temp->next;
	free (temp);
	}	
}

int isloop(struct Node *p)
{
	struct Node *q;
	q=p;
	while(p!=NULL && p->next!=NULL)
	{
		q=p->next;
		p=p->next->next;
		if(p==q)
		{
			return 1;
		}	
	}
	return 0;
	
}	

int detectandremoveloop(struct Node *p)
{
	struct Node *q;
	q=p;
	while(p!=NULL && p->next!=NULL)
	{
		q=p->next;
		p=p->next->next;
		if(p==q)break;
	}
	if (p!=q)return 0;
		else
		{		p=first;   //bring slow ptr at the head
			while(p->next!=q->next) //now move slow and fast ptr at same speed until they meet now 
			{
			p=p->next;		
			q=q->next;	
			}	
		    q->next=NULL;  //pt where they meet is the first node and its next is made NULL to remove loop
		}
}	

struct Node * segregate(struct Node *p)  //segregate odd and even
{
struct Node *oS=NULL,*oE=NULL,*eS=NULL,*eE=NULL;
for(struct Node *p=first;p!=NULL;p=p->next)
 {
	int x=p->data;
	if(x % 2==0)
	{
		if(eS==NULL){
			eS=p;
			eE=eS;
		}else
		{	
			eE->next=p;
			eE=eE->next;
		}
	}else
	{
		if(oS=NULL){
		oS=p;	
		oE=oS;	
	}else
	{
		oE->next=p;
		oE=oE->next;
	}
	//after the loop
	if(oS==NULL || eS==NULL)
		return;
	eE->next=oS;
	oE->next=NULL;
	
}	
  return eS;
}
int ispalindrome(struct Node *p)
{
	struct Node *q;
	q=p;
	if(p==NULL) return 1;
	else
		while(p!=NULL && p->next!=NULL)//bring the slow ptr to middle
		{
			p=p->next;
			p=p->next;
			if (p)q=q->next;
		}
	reverse(q->next);// reverse second half of list
	struct Node *t=first;
	while(q->next!=NULL)
	{
		if(t->data!=q->data)	//check if start and from middle of list is same then palindrome
		{
			return -1;
		}else
		{
			t=t->next;
			q=q->next;
		}	
	}
	return 1;

}
int getintersection(struct Node *h1,struct Node *h2)
{
	int count1=0;
	if (count(h1)>count(h2))
	  while(h1!=abs(count(h1)-count(h2)))
	  {
		  h1=h1->next;
	  }
	else
		while(h2!=abs(count(h2)-count(h1)))
	  {
		  h2=h2->next;
	  }
	while(h1!=NULL && h2!=NULL)
	{
		if (h1==h2)
			return h1->data;
		else
		{
			h1=h1->next;
			h2=h2->next;
		}
	}	
	return -1;
}	
struct Node *swapkthnode(struct Node* head, int num, int K)
{
    // If k is more than number of nodes
    if (K > num) 
      return head;
    
    // If k-th node from beginning and
    // end are same.
    if(2*K-1 == num) return head;
    
    struct Node* x_prev = NULL;
    struct Node* x = head;
    
    struct Node* y_prev = NULL;
    struct Node* y = head;
    
    int count = K-1;
    while(count--){
        x_prev = x;
        x = x->next;
    }
    
    count = num - K;
    while(count--){
        y_prev = y;
        y = y->next;
    }
    
    if(x_prev)
        x_prev->next = y;
    if(y_prev)
        y_prev->next = x;
        
    struct Node* temp = x->next;
    x->next = y->next;
    y->next = temp;
    
    if(K == 1)
        return y;
    if(K == num)
        return x;
return head;    
}
}



