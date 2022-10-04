#include<iostream>
using namespace std;
main()
{
    int n;
    cin>>n;
    int i;
    int a,b,sum;
    for(i=1;i<=n;i++)
    {
        sum=0;
        cin>>a>>b;
        if(a%2==0)
            a+=1;
        if(b%2==0)
            b-=1;
        for(int j=a;j<=b;j+=2)
            sum+=j;
        cout<<"Case "<<i<<":"<<" "<<sum<<endl;
    }
    return 0;
}
