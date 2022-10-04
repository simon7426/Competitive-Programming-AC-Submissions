#include<cstdio>
main()
{
    int a[100000],max=0,count=1,i,n;
    scanf("%d",&n);
     for (i = 0; i < n; i++) {
            scanf("%d",&a[i]);
     }
     for(i=0;i<n-1;i++)
     {
        if (a[i] > a[i+1]) {
                if (max < count)
                    max = count;
                count = 1;
            } else
                count++;
        }
        max<count?max=count:count=0;
        printf("%d",max);
        return 0;
}