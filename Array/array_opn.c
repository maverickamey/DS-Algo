#include <stdio.h>
#include <stdlib.h>


struct array {
	int a[10];
	int length;//no of elements in array
	int size; //size of array=10 currently
};	
void display(struct array arr)
{
	int i=0;
	for(int i=0;i<arr.length;i++)
	{
		printf("%d ",arr.a[i]);
	}
}	
void append(struct array *arr,int x) //as modifying the original array so call hy reference
{
	if (arr->length>=arr->size)             //(->) similar to (*p) i.e dereferenced to get output
		printf("No space for elements to add\n");//only used when arr is ptr
	else
		arr->a[arr->length++]=x;//incrementing by post increment
	
}	
void insert(struct array *arr,int index,int x)//inserting at a index
{
  if (arr->length>=arr->size)
	  printf("No space for elements to add\n");
  else if (index>=0 && index<=arr->length)
	  for(int i=arr->length;i>index;i--)
	  {
	  arr->a[i]=arr->a[i-1];
	  }
	  arr->a[index]=x;
	  arr->length++;
	
}	
int deletefromindex(struct array *arr,int index)//delete from index
{  int x=0;
    if (arr->length==0)
      printf("Array is empty and null point exeception");
    else if (index>=0 && index<arr->length)
	{
       x=arr->a[index];
	   for(int i=index;i<=arr->length-1;i++)
	   {
		   arr->a[i]=arr->a[i+1];
	   }	   
		arr->length--;
	}
return x;
}
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;	
}	
int atstartlinearsearch(struct array *arr,int element)
{
	int i=0;
	{
		if (arr->length==0 )
      printf("Array is empty");
else 
	for(i=0;i<arr->length;i++)
		if (arr->a[i]==element)
	   {
	       swap(&arr->a[i],&arr->a[0]);
	       return 0;
	   }
	}
	return -1;
}
	
int linearsearch(struct array arr,int element)
{
    int i=0;
   if (arr.length==0 )
      printf("Array is empty");
else 
	for(i=0;i<arr.length;i++)
		if (arr.a[i]==element)
		{
			return i;
			break;
		}
	/*
	if(flag==1)
      printf("Element %d is found\n",element);
else
      printf("Element %d is not found\n",element);	
	
*/	
return -1;
}	
int binsearch(struct array arr,int element)
{   int l=0;
    int h=arr.length-1;
  	while(l<=h)
	{ 
       int mid=((l+h)/2);
              
       if (arr.a[mid]==element)
		   return mid;
	   else if(element<arr.a[mid])
		   h=mid-1;
	   else
		   l=mid+1;
	}
	return -1;
	
}	
int get(struct array arr,int index)//getting value at particular index
{
	if (index > 0 && index <arr.length)
    return arr.a[index];
	
}
void set(struct array *arr,int index,int element)//i have set the index by moving elements one should just set
{   
    if (index>0 && index<arr->length)                                            //buggy code need to figure out
	    arr->a[index]=element;
}
int max(struct array arr)
{
   int max=arr.a[0];
    for(int i=1;i<arr.length;i++)//iterate from 1 as we have already taken 0 index
	{
	     if (arr.a[i]>max)
           max=arr.a[i];			 
	}
	return max;
	
}
float average(struct array arr)
{
	int total=arr.a[0];
   for (int i=1;i<arr.length;i++)
   {
	   total=total+arr.a[i];
   }
   return (float)total/arr.length;
}	
struct array* Merge(struct array *arr1,struct array *arr2)
{
 int i,j,k;
 i=j=k=0;

 struct array *arr3=(struct array *) malloc (sizeof(struct array));

 while(i<arr1->length && j<arr2->length)
 {
 if(arr1->a[i]<arr2->a[j])
	arr3->a[k++]=arr1->a[i++];
 else
	arr3->a[k++]=arr2->a[j++];
 }
 for(;i<arr1->length;i++)
	arr3->a[k++]=arr1->a[i];
 for(;j<arr2->length;j++)
	arr3->a[k++]=arr2->a[j];
	arr3->length=arr1->length+arr2->length;
	arr3->size=10;

// return arr3;
}
int issorted(struct array arr)
{
    	for(int i=0;i<arr.length-1;i++)
		{	if(arr.a[i]>arr.a[i+1])
				return 0;
		}	
	return 1;
	
}	
int main()
{
 struct array arr={{1,2,3,4,5},5,10};
 struct array arr1={{2,9,21,28,35},5,10};
 struct array arr2={{2,3,16,18,28},5,10};
 struct array *arr3; 
 append(&arr,6);//passing address for refernece and then appending 6 at last
printf("Array after appending value is  \n");
 display(arr);
 printf("\n");
 insert(&arr,4,15);
 printf("\nArray after inserting at  index and particular value  is ");
 display(arr);
 printf("\n Value deleted at a particular index is  %d\n",deletefromindex(&arr,3));//delete at index 3
 printf("\n Display array\n ");
 display(arr);
 printf("\n Index at which searched value is using linearsearch %d \n",linearsearch(arr,4));//-1 is no element found
 printf("Index at which searched value is using linearsearch %d \n",linearsearch(arr,3));
 printf("Index at which searched value is using atstartlinearsearch %d \n",atstartlinearsearch(&arr,4));
 printf("Index at which searched value is using atstartlinearsearch %d \n",atstartlinearsearch(&arr,3));
 printf("\n Display array\n ");
 display(arr);
 printf("\nIndex at which searched value is using Binary search is %d \n",binsearch(arr,3));
 printf("Getting value at a particular index is  %d ",get(arr,3));
 set(&arr,1,15);
 printf("\nArray after setting a value at a index :\n");
 display(arr);
 printf("\nMax of array is %d \n",max(arr));
 printf("Average of array is %.2f \n",average(arr));//need exact float value
printf("Display array\n");
 display(arr);
 printf("\nValues after merging array is  \n");
arr3=Merge(&arr1,&arr2);
display(*arr3);
printf("\n");
printf("Return positive value if array is sorted %d ",issorted(arr1));
return 0;
}	
