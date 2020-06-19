#include <stdio.h>
#include <string.h>
int conversiontoint(char str[]);
int main()
{
    char str[20];
    //int num;
    printf("Enter the number");
    scanf("%s",str);
    printf("The number is %d",conversiontoint(str));

    return 0;
}
int conversiontoint(char str[])
{
    int num=0;
    int i=0;
    while(str[i]!='\0')
    {
        num=num * 10 + (str[i]-48);
        i=i+1;
    }
    return num;

    
}
