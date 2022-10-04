#include<iostream>
using namespace std;
main()
{
    int i,n,a,b,c,t1,t2,t3;
    cin>>n;
    a=b=c=0;
    for(i=0;i<n;i++)
    {
        cin>>t1>>t2>>t3;
        a+=t1;
        b+=t2;
        c+=t3;
    }
    if(a==0&&b==0&&c==0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}