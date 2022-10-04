#include<iostream>
using namespace std;
main()
{
    int n,i,j,sp,k;
    cin>>n;
    sp=2*n;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<sp;j++)
            cout<<" ";
        sp-=2;
        for(j=0;j<=i;j++)
            {cout<<j;if(j!=i)cout<<" ";}
        for(j=i-1;j>=0;j--)
            cout<<" "<<j;
        cout<<endl;
    }
    sp=2;
    for(i=n;i>0;i--)
    {
        for(j=0;j<sp;j++)
            cout<<" ";
        sp+=2;
        for(j=0;j<i;j++)
            {cout<<j;if(j!=i-1)cout<<" ";}
        for(j=i-2;j>=0;j--)
            cout<<" "<<j;
        cout<<endl;
    }
    return 0;
}