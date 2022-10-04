#include<iostream>
#include<string>
using namespace std;
main()
{
    string t;
    int a[27]={0},b[27]={0},i;
    cin>>t;
    for(i=0;i<t.size();i++)
        a[t[i]-96]++;
    cin>>t;
    for(i=0;i<t.size();i++)
        b[t[i]-96]++;
    int count=0;
    for(i=1;i<27;i++)
    {
        if(a[i]!=0&&b[i]!=0)
        {
            if(b[i]<=a[i])
                count+=b[i];
            else
                count+=a[i];
        }
        else if(a[i]==0&&b[i]!=0)
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    (count!=0)?cout<<count<<endl:cout<<-1<<endl;
    return 0;
}