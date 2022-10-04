#include<stdio.h>
main()
{
    int z,y,i,j,d[4];
    scanf("%d",&y);
    read:
        y=y+1;
        z=y;
        i=0;
        while(z!=0)
        {
            d[i]=z%10;
            z=z/10;
            i++;
        }
        for (i=0;i<4;i++)
        {
            for(j=i+1;j<4;j++)
            {
                if (d[i]==d[j])
                    goto read;
            }
        }
        printf("%d",y);
        return 0;
}