#include<stdio.h>
#include<strings.h>
main()
{
    char a[101];
    gets(a);
    int i,l,count=0,max=0;
    l=strlen(a);
    for(i=0;i<=l;i++)
    {
        count++;
        if(a[i]=='A'||a[i]=='E'||a[i]=='O'||a[i]=='I'||a[i]=='U'||a[i]=='Y'||a[i]==0)
        {
            if (count>max)
                max=count;
            count=0;
        }
    }
    if (count>max)
                max=count;
    printf("%d\n",max);
    return 0;
}