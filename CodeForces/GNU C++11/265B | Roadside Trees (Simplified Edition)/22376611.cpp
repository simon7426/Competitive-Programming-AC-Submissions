#include<iostream>
using namespace std;
main()
{
    int n;
    cin>>n;
    int a,p=0,ans=0,i;
    for(i=0;i<n;i++)
    {
        cin>>a;
        if(i>0)
            ans+=1;
        if(p>a)
            ans+=(p-a)+1;
        if(p<=a)
          ans+=(a-p)+1;
        p=a;
    }
    cout<<ans<<endl;
}