#include<iostream>
using namespace std;
main()
{
    string a[101];
    int i,j,n;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n/2;i++)
        for(j=0;j<n;j++)
    {
        if(a[i][j]!=a[n-i-1][n-j-1])
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}