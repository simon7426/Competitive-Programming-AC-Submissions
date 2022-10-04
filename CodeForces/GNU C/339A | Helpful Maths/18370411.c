#include<stdio.h>
#include<string.h>
main()
{
    char a[1000];
    int s,i=0,j,temp;
    scanf("%s",a);
    s=strlen(a);
    while (i<s&&s!=1)
    {
        j=i+2;
       while (j<s)
       {
            if(a[i]>a[j]&&a[j]!='\0')
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        j=j+2;
       }
        i=i+2;
    }
    printf("%s",a);
}