#include<stdio.h>
main()
{
    int n,i,j=1,s,te,a[3]={-1,-1,-1};
    scanf("%d",&n);
    scanf("%d",&a[0]);
    for(i=1;i<n;i++)
    {
        scanf("%d",&te);
        if(a[0]==te||a[1]==te||a[2]==te)
        {
            continue;
        }
        else
        {
            a[j]=te;
            j++;
        }
        if (j>3)
            {
                printf("NO\n");
                return 0;
            }
    }
    if (a[0]==-1||a[1]==-1||a[2]==-1)
    {
        printf("YES\n");
    }
    else
    {
        for (i=0;i<3;i++)
            for (j=i+1;j<3;j++)
        {
            if (a[i]>a[j])
            {
                te=a[i];
                a[i]=a[j];
                a[j]=te;
            }
        }
        a[1]-a[0]==a[2]-a[1]?printf("YES\n"):printf("NO\n");
    }
    return 0;
}