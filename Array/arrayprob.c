#include <stdio.h>
//rotate and reverse array
#include <stdlib.h>
#include <limits.h> //to get lowest and highest limit of any datatype
void reversearray(int a[],int ,int);
void printarray(int a[],int  );
void rotate(int a[],int ,int );
void leaderofarray(int a[],int );
int max_slidingwindow(int a[],int ,int );
int subArraySum(int a[],int ,int );
void Nbonacchi(int ,int );
void prefixadd(int a[],int ,int prefix_sum[]);
void reverseingroup(int a[],int ,int );
int buyandsell(int a[],int );
int buyandsell1(int a[],int);
int equilibriumpoint(int a[],int size);

int main()
{
 int a[]={1,2,3,4,5,6,7,8};
 int n=sizeof(a)/sizeof(a[0]);
 int r;
 printf("Reverse of array is\n");
 reversearray(a,0,n);
 printarray(a,n);
 printf("\n");
 int b[]={1,2,3,4,5,6,7,8};
 printf("By how much positions you need to rotate?\n");
 scanf("%d",&r);
 rotate(b,r,n);
 printf("Rotated array is:\n");
 printarray(b,n);
 printf("\n");
 int c[]={5,3,20,15,8,3};
 int m=sizeof(c)/sizeof(c[0]);
 leaderofarray(c,m);
 int d[] = { 1, 4, 2, 10, 2, 3, 1, 0, 20 }; 
    int k = 4; 
  int o=sizeof(d)/sizeof(d[0]);
 printf("\nMax sum of sliding window is=%d \n",max_slidingwindow(d,k,o));
 	int e[] = {15, 2, 4, 8, 9, 5, 10, 23}; 
	int l = sizeof(e)/sizeof(e[0]); 
	int sum = 23; 
	subArraySum(e, l, sum);
	/*
	int y=8;//no of elements
	int z=3;//sum of last 3 elements should be there
	*/
	Nbonacchi(4,8);
	int f[]={2,8,3,9,6,5,4};
	int p=sizeof(f)/sizeof(f[0]);
    //int *prefix_sum=(int *)malloc(p*sizeof(int));
    int prefix_sum[p];
	prefixadd(f,p,prefix_sum);
	int g[]={3,4,8,-9,20,6};
	int q=sizeof(g)/sizeof(g[0]);
	printf("\nEquilibrium point is  %d\n",equilibriumpoint(g,q));
	int h[]={100,80,120,130,70,60,100,125};
	int size=sizeof(h)/sizeof(h[0]);
    printf("Maximum stock buy and sell is %d\n",buyandsell(h,size));
    printf("Maximum profit by only 1 transaction is %d\n",buyandsell1(h,size));
	return 0;
}
//print array
void printarray(int a[],int n)
{
   for(int i=0;i<n;i++)
   {
	 printf("%d,",a[i]);   
   }	   
	

}
//reverse array
void reversearray(int a[],int startindex,int endindex)
{
   int temp;
   while(startindex<endindex-1)
   {
          temp=a[startindex];
		  a[startindex]=a[endindex-1];
		  a[endindex-1]=temp;
		  startindex++;
		  endindex--;
   }
}
//rotate array to shift anticlockwise
void rotate(int a[],int d,int n )
{
	if (d==0)
		return;
	else
	{
   reversearray(a,0,d);//adjusted as we used same rverse functn to do both jobs otherwise take as d-1;
   reversearray(a,d,n);
   reversearray(a,0,n);   
	}
}

void leaderofarray(int a[],int n)//print array from right with max values
{
	int *d= (int *)malloc(sizeof(int) * n);//created empty array in heap as we cant create in stack
	int j=0;
	int max=INT_MIN;//compare with lowest integer
	for (int i=n-1;i>=0;i--)
	{
		if (a[i]>max)
		{
			d[j]=a[i];    
			j++;
			max=a[i];
			
		}
	}
    printf("Leader of array are:\n");	
	printarray(d,j);
	
	free(d);//free memory space
	
	
}
//max sum of subarray for k conecutive elements
int max_slidingwindow(int a[],int k,int n)
{
	int max_sum=0;
	//int current_sum=0;
	for(int i=0;i<k;i++)
{
    max_sum+=a[i];
}
int current_sum=max_sum;
	for(int i=k;i<n;i++)
	{
		current_sum=current_sum+a[i]-a[i-k];
			if(current_sum>max_sum)
				max_sum=current_sum;
	}

return max_sum;
}
//find subarray indexes from and to of given sum	
int subArraySum(int a[],int l,int sum)
{
	
	int new_sum=0;
	int start=0;
	for(int i=0;i<l;i++)
	{	
         new_sum+=a[i];
	if(new_sum==sum)
		printf("Index from %d to %d\n",start,i);
	else if (new_sum>sum)	
	   {    //15, 2, 4, 8, 9, 5, 10, 23
		  new_sum=new_sum-a[start];
		   start=start+1;
	    }
	
    }	
	
}	
//print N bonacchi numbers
void Nbonacchi(int n,int m)
{
     	int *a=(int *)malloc(m*sizeof(int));
		a[n-1]=1;
		a[n]=1;
		for(int i=n+1;i<m;i++)
		{
			a[i]=2*a[i-1]-a[i-n-1];//a[i-1]+a[i-2]+a[i-3];   //
		}
		printf("Nbonacchi numbers are : \n");
		printarray(a,m);
			printf("\n");
		free(a);
		
}
//adding and keeping elements to solve getsum function in 0(1) Time complexity	
void prefixadd(int a[],int size,int prefix_sum[])
{
     prefix_sum[0]=a[0];
	for(int i=1;i<size;i++)
	{
	    prefix_sum[i]=prefix_sum[i-1]+a[i];
	
	}	
	printf("Prefix sums are : ");
printarray(prefix_sum,size);	
}	

//if equilibroum pt exits or not ie sum of left and sum on right of the point are same.
int equilibriumpoint(int a[],int size)
{
	int sum=0;
	int left_sum=0;
for(int i=0;i<size;i++)
   {
     sum=sum+a[i];   
    }
for(int i=0;i<size;i++)
   {
	  sum=sum-a[i];
	  
	  if(left_sum==sum)
		  return i;
	  else
		 left_sum=left_sum+a[i];
   }
	return -1;
}	
//reverseingroup
void reverseingroup(int a[],int size,int rotateby)
{ 
    int startindex=0;
    
    while(rotateby<size)
    {
        reversearray(a,startindex,rotateby-1);
      startindex=rotateby;
      rotateby=rotateby+rotateby;
    }
    reversearray(a,startindex,size-1);
     printf("Reverse values after grouping in reverse are:\n ")  ;
    printarray(a,size);
}

int buyandsell(int a[],int size)//maximum profit by buying and selling no matter what
{                               //when you sell and buy
    int profit=0;
    for(int i=0;i<size;i++)
    {
        if (a[i]<a[i+1])
        {
            profit=profit+(a[i+1]-a[i]);
        }
    }
    return profit;
}

int buyandsell1(int a[],int size)//maximum profit by only one transcation so here 
{                                //60 buy and 125 sell is the one transaction we calculated
    int Min=INT_MAX;
    int profit=0;
    for(int i=0;i<size;i++)
    {
        if(a[i]<Min)
         {
             Min=a[i];
         }
        if (profit<(a[i]-Min))
        {
            profit=a[i]-Min;//note this important we are not updating previous profit but overriding it everytime ....
        }
    }
    
    return profit;
}
