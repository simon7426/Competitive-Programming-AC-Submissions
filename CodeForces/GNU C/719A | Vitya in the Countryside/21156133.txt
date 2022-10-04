#include<stdio.h>
main()
{
    int d,i,j,a[100];
    scanf("%d",&d);
    for(i=0;i<d;i++)
        scanf("%d",&a[i]);
    if(d<=1&&a[0]!=15&&a[0]!=0)
    {
        printf("-1");
        return 0;
    }
    else
    {
        if(a[d-1]==15)
        {
            printf("DOWN");
            return 0;
        }
        else if(a[d-1]==0)
        {
            printf("UP");
            return 0;
        }
        else
        {
            if (a[d-1]>a[d-2])
            {
                printf("UP");
                return 0;
            }
            else
            {
                printf("DOWN");
                return 0;
            }
        }
    }
}