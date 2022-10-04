#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    int n,i,k;
    cin>>n>>k;
    if(n<k||(k==1&&n!=1))
        {cout<<-1<<endl;
        return 0;}
    if(n==1)
    {
        cout<<'a'<<endl;return 0;
    }
    k-=2;
    for(i=0;i<n-1-k;i+=2)
    {
        cout<<"ab";
    }
    if((n-k)&1)
        cout<<'a';
    for(i=0;i<k;i++)
    {
        cout<<(char)('c'+i);
    }
    return 0;
}