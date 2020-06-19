#include <stdio.h>
#include <string.h>
void compareforduplicates(char str[],char str1[]);
char *sort(char str[]);
int main()
{
    char str[20];
    char str1[20];
    printf("Enter the first string\n");
    gets(str);
    printf("Enter the second string\n");
    gets(str1);
	
    compareforduplicates(str,str1);
    return 0;
}

/*
void compareforduplicates(char str[],char str1[])
{
    
    int hashmap[27]={0};
	int k=0;
	if (strlen(str)==strlen(str1))                    //AAMEY  //YMAEA
	{		
      for(int i=0;i<str[i]!='\0';i++)
    {
        for(int j=0;j<str[j]!='\0';j++)
        {
		if (str[i]==str[j] )
            {
               continue; 
				
            }
        }
    }
    }
    else
		printf("Both strings are of unequal length);
    
}
*/
void compareforduplicates(char str[],char str1[])
{
	
     if ((strcmp(sort(str),sort(str1)))==0)
	 
		 printf("Both string are same");
		 else
			 printf("Both strings are different");


	 
	
}	

char *sort(char str[])
{
	char temp;
	for(int i=0;i<strlen(str)-1;i++)
	{
	    for(int j=i+1;j<strlen(str);j++)
		{
               if (str[i]>str[j])
			   {
				   temp=str[i];
			       str[i]=str[j];
				   str[j]=temp;
			   }
        }			
		
	}
    return str;
}
