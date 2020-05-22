/*
Author : Swanand Sapre
scsapre@gmail.com

*/


#include <stdio.h>
#include <stdlib.h>



/*------------------------------------------------------*/
//print bit pattern
void print_bits(int number){
	
	int bits=(sizeof(number) * 8); //bytes->bits
	for(int i=bits-1;i>=0;i--){	
		if( (i+1)%4==0){
			printf(" ");
		}
		printf(((number&1<<i)==0?"0":"1"));
	
	}	
	printf("\n");
}

/*1. -----------------------------------------------------*/
//count the total number of set bits in a number
int count_set_bits(int number){
int count=0;
while(number)
{
   number=number&(number-1);
   count=count+1;              //Brian approach 
}
return count;
}

/*2. -----------------------------------------------------*/
//check if the number is even or odd
int check_even_odd(int number){
if (number==0)                         //if (number&1==0) even else odd
    return 0;                          //return 0 for 0 and 1 for even and -1 for odd.

else if(number%2==0)
      return 1;
else return -1;

}

/*3. -----------------------------------------------------*/
//swap upper and lower 16 bits in 32 bit number
int swap_bytes(int number){
	int swapped_number;
swapped_number=((number&0X0000FFFF)<<16)| ((number&0XFFFF0000)>>16);
return swapped_number;
//retrun the swapped number
}

/*4 . -----------------------------------------------------*/
//check for Endianness
void check_endian(int number){
int i = 1; 
   char *c = (char*)&i; 
   if (*c)     
       printf("Little endian\n"); 
   else
       printf("Big endian\n"); 

}

/*5. ------------------------------------------------------*/
//check for pow of 2
int check_pow_2(int number){

if(number!=0 && ((number&(number-1))==0))
  return 1;

else 
	return 0;
//return 1 if true else retun 0
}




/*6. ------------------------------------------------------*/
//Rotate a number || try in place rotation 
int rotate(int number)
{
	int n=32;
 int r_number=0;
     while(n-1)
	 {  if(number&1)
		 {
			 r_number=((r_number<<1)|1);
			 
		 }
		 else
		 {	 r_number=(r_number<<1);
		 }
		 n=n-1;
		 number=number>>1;	 
		 
	 }
	 return r_number;
	 
		 
 //return rotated number 
}

/*7. ------------------------------------------------------*/
//return (number x 8) + (number / 4) without using * and / operators
int calculate(int number){
 int result;
 result=(number<<3)+(number>>2);
 return result;
    
 //return result 
}

/*8. ------------------------------------------------------*/
// generate a masks for q number of bits starting at bit position p 
int generate_mask(int q, int p ){
	int mask=0;
 while (q)
 {
	 mask=(mask | 1<<(p+q-1));
	 q=q-1;
	 
 }
 return mask;
 //return result 
}


/*9. ------------------------------------------------------*/
// return bit position of first set bit from left
int set_bit_position(int number){
	int position=32;
    for(int i=0;i<32;i++)
	{if ((number & 0X80000000)==0)
		{	position=position-1;
		   number=number<<1;
		}
		  else
		  {	  position=position-1;
		  break;
		  }
	}
	return position;
	//return result 
}
/*------------------------------------------------------*/


/*------------------------------------------------------*/
//this is a driver function
int main(){
	int number=15;
	int number2=0XFFFFFFF0;
	print_bits(number);
	//printf("%d\n",sizeof(number));
       printf("%d\n" ,count_set_bits(number));
	   printf("%d\n" ,check_even_odd(number));
	   printf("%x\n",swap_bytes(number2));
	   check_endian(3);
	   printf("%d\n",check_pow_2(number));
	   printf("%d\n",rotate(number));  
	   printf("%d\n",calculate(number));
	   printf("%x\n",generate_mask(3,20));
	   printf("Position of number %d=%d\n",number,set_bit_position(number));
	   
	return 1;
        


}
