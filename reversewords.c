#include <stdio.h>
#include <string.h>
//Reverse the string words
int main()
{
    char str[200];
    int i=0,j=0,len=0,startIndex=0,endIndex=0;
    printf("Enter the string sentence\n");
    gets(str);
    len=strlen(str);
    endIndex=len-1;
    //printf("%d",len);
    for(i = len - 1; i >= 0; i--)
{
	if(str[i] == ' ' || i == 0)
	{
		if(i == 0)
		{
			startIndex = 0;
		}
		else
		{
			startIndex = i + 1;
		}
		for(j = startIndex; j <= endIndex; j++)
		{
			printf("%c", str[j]);
		}
		endIndex = i - 1;
		printf(" ");				
	} 
}

    return 0;
}
