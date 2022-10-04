#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    int x[]={0,1,2,3,4};
    int s=0,a[5][5],i,j;
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
        cin>>a[i][j];
    while(next_permutation(x,x+5))
    {
        s=max(s,a[x[0]][x[1]]+a[x[1]][x[0]]+2*(a[x[2]][x[3]]+a[x[3]][x[2]])+a[x[1]][x[2]]+a[x[2]][x[1]]+2*(a[x[3]][x[4]]+a[x[4]][x[3]]));
    }
    s=max(s,a[x[0]][x[1]]+a[x[1]][x[0]]+2*(a[x[2]][x[3]]+a[x[3]][x[2]])+a[x[1]][x[2]]+a[x[2]][x[1]]+2*(a[x[3]][x[4]]+a[x[4]][x[3]]));
    cout<<s<<endl;
}