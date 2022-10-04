#include<iostream>
#include<string>
using namespace std;
main()
{
    char a[300][300];
    int n,i,j;
    char tm,tn;
    cin>>n;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        cin>>a[i][j];
    tm=a[0][0];
    tn=a[0][1];
    if(tm==tn)
    {
        cout<<"NO"<<endl;
            return 0;
    }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
    {
        if(i==j||j==n-i-1)
        {
            if(a[i][j]!=tm)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        }
        else
        {
            if(a[i][j]!=tn)
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;
    return 0;
}