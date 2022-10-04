#include<bits/stdc++.h>
using namespace std;
char s[400010];
int cnt[400010],pos[400010],barr[400010];
main()
{
    int n;
    scanf("%s",s);
    n=strlen(s);
    int i,j;
    int tmp=0,k=0;
    for(i=0;i<n;i++)
    {
        if(s[i]=='.')
        {
            cnt[k]=tmp;
            pos[k]=i;
            tmp=0;
            k++;
        }
        else
            tmp++;
    }
    cnt[k]=tmp;
    if(cnt[0]==0||cnt[0]>8||cnt[k]>3||k==0||cnt[k]==0)
    {
        printf("NO\n");
        return 0;
    }
    int x;
    for(i=1;i<k;i++)
    {
        //printf("%d %d\n",pos[i-1],cnt[i]);
        if(cnt[i]<2||cnt[i]>11)
        {
            printf("NO\n");
            return 0;
        }
        x=pos[i-1];
        if(cnt[i]>9)
            barr[x+3]=1;
        else
            barr[x+1]=1;
    }
    //for(i=0;i<n;i++) printf("%d",barr[i]);printf("\n");
    printf("YES\n");
    for(i=0;i<n;i++)
    {
        printf("%c",s[i]);
        if(barr[i]==1)printf("\n");
    }
}