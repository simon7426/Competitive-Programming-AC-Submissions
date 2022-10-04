#include<iostream>
using namespace std;
main()
{
    int n,i,sum1=0,sum2=0,c=0,t1,t2;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>t1>>t2;
        sum1+=t1;
        sum2+=t2;
        if(t1&1&&t2%2==0)
        {
            c++;
        }
        if(t2&1&&t1%2==0)
        {
            c++;
        }
    }
    if(sum1%2==0&&sum2%2==0)
    {
        cout<<0<<endl;
        return 0;
    }
    if(c%2==0&&c>1)
        cout<<1<<endl;
    else
        cout<<-1<<endl;
    return 0;
}