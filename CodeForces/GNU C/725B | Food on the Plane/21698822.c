#include<stdio.h>
main()
{
    long long w,x,y,s;
    char a;
    scanf("%I64d%c",&w,&a);
    x=w-1;
    switch (a)
    {
    case 'f':
        y=1;
        break;
    case 'e':
        y=2;
        break;
    case 'd':
        y=3;
        break;
    case 'a':
        y=4;
        break;
    case 'b':
        y=5;
        break;
    case 'c':
        y=6;
        break;
    default:
        y=0;
        break;
    }
    if (x%4==0||x%4==2)
        s=(x/4)*16+y;
    else
        s=(x/4)*16+7+y;
    printf("%I64d\n",s);
    return 0;
}