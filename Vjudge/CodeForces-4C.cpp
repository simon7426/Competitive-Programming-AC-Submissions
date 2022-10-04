#include<iostream>
#include<map>
#include<string>
using namespace std;
main()
{
    map<string,int> a;
    int n,i;
    string s;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>s;
        if(a[s]==0)
            {cout<<"OK"<<endl;a[s]++;}
        else
            {
                cout<<s<<a[s]<<endl;a[s]++;
            }
    }
    return 0;
}
