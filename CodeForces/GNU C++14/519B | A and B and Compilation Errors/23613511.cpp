#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    long long int i,s1,s2,s3,s;
    s1=s2=s3=0;
    for(i=0;i<n;i++)
    {
        cin>>s;
        s1+=s;
    }
    for(i=0;i<n-1;i++)
    {
        cin>>s;
        s2+=s;
    }
    for(i=0;i<n-2;i++)
    {
        cin>>s;
        s3+=s;
    }
    cout<<s1-s2<<" "<<s2-s3<<endl;
    return 0;
}