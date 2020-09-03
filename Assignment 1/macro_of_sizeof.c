//author:Amey Juvatkar
//ameyjuvatkar123@gmail.com
//Macro of size off in C:

#include <stdio.h>

#define SIZEOF(object) (char *)(&object+1) - (char *)(&object)             
 
 int main()
 {
	 int x=10;
	 float y=100;
	 int arr[10];
	 printf("Size of int x =%ld\n",SIZEOF(x));
	 printf("Size of int y =%ld\n",SIZEOF(y));
	 printf("Size of int x =%ld\n",SIZEOF(arr));
	 
	 return 0;
 }

