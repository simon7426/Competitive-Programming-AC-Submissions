//unfinished
#include<stdio.h>
#include<math.h>
main()
{
    int a,s;
    scanf("%d",&a);
    switch (a)
    {
    case 4:
    case 7:
    case 44:
    case 77:
    case 47:
    case 74:
    case 444:
    case 474:
    case 477:
    case 777:
    case 747:
    case 744:
        printf("YES");
        break;
    default:
        {
        if (a%4==0||a%7==0||a%44==0||a%47==0||a%74==0||a%77==0||a%444==0||a%474==0||a%477==0||a%777==0||a%744==0||a%747==0)
            printf ("YES");
         else
            printf("NO");
        }
 
    }
}