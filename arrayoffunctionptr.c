#include <stdio.h>
//#include <stdlib.h>
int select(void);
int count_set_bits(int);
int check_even_odd(int);
int check_pow_2(int);
int rotate(int);
int calculate(int);
int set_bit_position(int);



int count_set_bits(int number){
int count=0;
while(number)
{
   number=number&(number-1);
   count=count+1;              //Brian approach 
}
return count;
}

int check_even_odd(int number){
//if (0=number) 
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

int check_pow_2(int number){

if(number!=0 && ((number&(number-1))==0))  //IT clears right most bit 
  return 1;

else 
	return 0;
//return 1 if true else retun 0
}




/*6. ------------------------------------------------------*/
//Rotate a number || try in place rotation 
int rotate(int number)
{    
    int p1,p2;
	for(p1=0,p2=31;p1<p2;p1++,p2--)
	{
		if(((number>>p1)&1)!=((number>>p2)&1))
		{
	       number^=(1<<p1);
		   number^=(1<<p2);
		}
		
	}
	return number;

 /*   #if 0
	int n=32;
    int r_number=0;
     while(n)
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
	 #endif
	*/	 
 //return rotated number 
}

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

int select(void)
{
   int choice ;
printf("1.count_set_bits\n");
printf("2.check_even_odd\n");
printf("3.check_pow_2\n");
printf("4.rotate\n");
printf("5.calculate\n");
printf("6.set_bit_position\n");
printf("Enter your choice\n");
scanf("%d",&choice);
return choice;
}


int main()
{
int a,r;
int i;
int (*amey_bit_fun[]) (int)={count_set_bits,check_even_odd,swap_bytes,check_pow_2,rotate,set_bit_position};
while(1)
{
i=select();
if(i>=6)
break;
else 
printf("Enter the integer for mentioned operation?\n");
scanf("%d",&a);
r=(*amey_bit_fun[i-1])(a);
printf("Result is %d\n",r);
}





return 0;
}