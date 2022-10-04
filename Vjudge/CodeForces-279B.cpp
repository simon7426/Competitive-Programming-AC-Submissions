#include<iostream>
using namespace std;
main()
{
    int n,i,j=0,count=0,max=0;
    int m,t,sum=0;
    cin>>n>>m;
    int a[n];
    for(i=0;i<n;i++)
       {
           cin>>a[i];
           sum+=a[i];
           while(sum>m)
            sum-=a[j++];
           if(count<i-j+1)
            count=i-j+1;
       }
    cout<<count<<endl;
    return 0;
}