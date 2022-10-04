#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int Sod(int x)
{
    int y=0;
    while(x!=0)
    {
        y+=x%10;
        x/=10;
    }
    return y;
}
main()
{
    string s;
    cin>>s;
    int i,si=s.size(),sum=0;
    for(i=0;i<si;i++) sum+=s[i]-'0';
    if(si<2) {cout<<0<<endl;return 0;}
    int k=1;
    while(sum/10!=0)
    {
        sum=Sod(sum);
        k++;
    }
    cout<<k<<endl;
    return 0;
}