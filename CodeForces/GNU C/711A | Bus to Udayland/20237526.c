#include<stdio.h>
main()
{
    char a[1000][5];
    int i,j,se=0,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%s",a[i]);
    for(i=0;i<n;i++)
    {
        if(a[i][0]=='O'&&a[i][1]=='O')
        {
            a[i][0]='+';
            a[i][1]='+';
            se=1;
            break;
        }
        else if(a[i][3]=='O'&&a[i][4]=='O')
        {
            a[i][3]='+';
            a[i][4]='+';
            se=1;
            break;
        }
        else
            continue;
    }
    if(se==1)
        printf("Yes\n");
    else
    {
        printf("No\n");
        goto read;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<5;j++)
            printf("%c",a[i][j]);
 
        printf("\n");
    }
    read:
        return 0;
}