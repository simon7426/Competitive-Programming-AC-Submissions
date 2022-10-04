#include<stdio.h>
#include<string.h>
#define N 101
 
int main()
{
    char players[N];
    scanf("%s",players);
    int size=strlen(players);
 
    int is_dangerous = 0;
    int i;
    int zeros = 0,ones = 0;
 
    for(i=0; i<size ; i++)
    {
        if (players[i]=='0')
        {
            ones = 0;
            zeros++;
        }
        else
        {
            zeros = 0;
            ones++;
        }
 
        if(ones==7 || zeros==7)
        {
            is_dangerous = 1;
            break;
        }
    }
 
    printf("%s",is_dangerous?"YES\n":"NO\n");
 
    return 0;
}