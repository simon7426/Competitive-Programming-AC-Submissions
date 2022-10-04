#include<iostream>
#include<string>
using namespace std;
main()
{
    string a,b;
    cin>>a;
    b="hello";
    int digit=0,i,j=0;
    for(i=0;i<a.size();i++)
    {
        if(a[i]==b[j])
        {
            digit++;
            j++;
        }
 
    }
    if(digit==5)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}