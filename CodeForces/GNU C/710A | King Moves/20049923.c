#include<stdio.h>
main()
{
    int i;
    char a[2];
    gets(a);
    if(a[0]=='a'||a[0]=='h')
        {
            if(a[1]=='1'||a[1]=='8')
                printf("3\n");
            else
                printf("5\n");
        }
    else if (a[1]=='1'||a[1]=='8')
    {
        printf("5\n");
    }
    else
        printf("8\n");
    return 0;
}