#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
main()
{
    string s;
    cin>>s;
    int n=s.size(),i;
    char c='a',d;
    bool f=true;
    if(s[0]!=c)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    for(i=0;i<n;i++)
    {
        d=c+1;
        //cout<<c<<" "<<d<<" "<<s[i]<<endl;
        if(s[i]<=c)continue;
        else
        {
            if(s[i]!=d)
            {
                f=false;
                break;
            }
            c++;
        }
    }
    if(f==false)
    {
        cout<<"NO"<<endl;
    }
    else
        cout<<"YES"<<endl;
    return 0;
}