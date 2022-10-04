#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
main()
{
    int n,i,j;
    long long a,r,ma=2000000;
    vector<int> v(ma+1,1);
    for(i=2;i*i<=ma;i++)
    {
        {
            for(j=i;i*j<=ma;j++)
                v[i*j]=0;
        }
    }
    v[0]=0;
    v[1]=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a;
        r=sqrtl(a);
        if(r*r==a&&v[r]!=0)
        {
                cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
    return 0;
}