#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n,c;
bool fun(int *a,int num)
{
    int po=a[0];
    int co=1;
    for(int i=1;i<n;i++)
    {
        if(a[i]-po>=num)
        {
            co++;
            po=a[i];
            if(c==co)
                return true;
        }
    }
    return false;
}
main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>c;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        int lo=0,hi=a[n-1],mid,ma=-1;
        while(lo<hi)
        {
            mid=lo+(hi-lo)/2;
            if(fun(a,mid)==true)
            {
                if(mid>ma)
                    ma=mid;
                lo=mid+1;
            }
            else
                hi=mid;
        }
        cout<<ma<<endl;
    }
    return 0;
}
