#include<stdio.h>
main()
{
    int n,si[5]={0,0,0,0,0},temp,i,f=0;
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf("%d",&temp);
        si[temp]++;
    }
    f+=si[3]+si[4];
    if (si[1]>si[3])
    {
        si[1]-=si[3];
    }
    else
        si[1]=0;
    int y;
    y=si[2]/2;
    si[2]-=y*2;
    f+=y+si[2];
    if (si[1]*2>si[2])
    {
        si[1]-=si[2]*2;
        si[2]=0;
    }
    f+=si[1]/4;
    si[1]%=4;
    if (si[1]>0)
        f++;
    printf("%d",f);
}