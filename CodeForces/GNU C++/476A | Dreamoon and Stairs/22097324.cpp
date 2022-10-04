#include<iostream>
using namespace std;
main()
{
    int n,m,a,b,i,j,c=0;
    cin>>n>>m;
    if(n<m)
    {
        cout<<-1<<endl;
        return 0;
    }
    if(n%2==0)
    {
        a=n/2;
        b=0;
    }
    else
    {
        a=n/2;
        b=1;
    }
    for(i=a,j=b;i>=0;i--,j+=2)
    {
        if((i+j)%m==0)
        {
            a=i;b=j;c=1;break;
        }
    }if(c==1)
    cout<<a+b<<endl;
    else
        cout<<-1<<endl;
    return 0;
}