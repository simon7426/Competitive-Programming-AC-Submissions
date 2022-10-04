#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string s,t;
int b[10010],n,m;

void prekmp()
{
    int i=0,j=-1;
    b[0]=-1;
    while(i<m)
    {
        while(j>=0&&t[i]!=t[j]) j=b[j];
        i++,j++;
        b[i]=j;
    }
}
void kmp()
{
    prekmp();
    int i=0,j=0;
    while(i<n)
    {
        while(j>=0&&s[i]!=t[j]) j=b[j];
        i++,j++;
        if(j==m)
        {
            cout<<"Match Found at "<<i-j<<endl;
            j=b[j];
        }
    }
}


main()
{
    cin>>s>>t;
    cout<<s<<" "<<t<<endl;
    n=s.size();
    m=t.size();
    kmp();
    for(int i=0;i<m;i++)
        cout<<b[i]<<" ";
    cout<<endl;
    for(int i=0;i<m;i++)
    {
        cout<<t[i]<< " "<< b[i]<<endl;
    }
}
