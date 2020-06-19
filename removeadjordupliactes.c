
//remove duplicates from string

#include <stdio.h>
#include <string.h>
int main()
{
    char str[20]="aabbaa";
    char str[20]="aabbcc";
    char str1[20];
    int i=0;
    int j=0;
    for(int i=0;str[i]!='\0';i++)
    {
        if (str[i]!=str[i+1])
       { str1[j]=str[i];
        j++;
       }
        
    }
    str1[j]='\0';
    puts(str1);
    
    

    return 0;
}


-----------------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>//remove duplicates at any location
void compareforduplicates(char str[],char str1[]);
int *hashmapcreation(char hashmap_str[]);
//char *sort(char str[]);
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

void compareforduplicates(char str[],char str1[])
{
	
	int flag=0;
	int ptr[27]=hashmapcreation(str);
	int p1[27]=hashmapcreation(str1);
	for(int i=0;i<27;i++)
	{	if (ptr[i]!=p1[i])
			flag=0;
			
		else
			flag=1;
	
	}
if (flag==1)
printf("True");
else
printf("False");	
}	
	
int *hashmapcreation(char hashmap_str[])
{	int h_str[27]={0};
     for(int i=0;hashmap_str[i]!='\0';i++)
		if 	(h_str[hashmap_str[i]-'a']==1)
		{
			continue;
	    }
	else
	{
		h_str[hashmap_str[i]-'a']=1;
	}
	return h_str;
}
