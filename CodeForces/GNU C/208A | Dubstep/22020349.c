#include<stdio.h>
#include<string.h>
main()
{
    char a[201],b[201];
    int i,j=0,flag=0,n;
    gets(a);
    n=strlen(a);
    for(i=0;i<n;i++)
    {
        if(a[i]=='W'&&a[i+1]=='U'&&a[i+2]=='B')
        {
            i+=2;
            flag=1;
        }
        else
        {
            if(j!=0&&flag==1)
            {
                b[j]=32;
                j++;
            }
            flag=0;
            b[j]=a[i];
            j++;
        }
    }
    b[j]=0;
    puts(b);
    return 0;
}