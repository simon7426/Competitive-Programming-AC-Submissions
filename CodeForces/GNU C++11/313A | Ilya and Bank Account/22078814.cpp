#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<sstream>
using namespace std;
main()
{
    int a,i,t[3];
    cin>>a;
    if(a>=0)
    {
        cout<<a<<endl;
        return 0;
    }
    t[0]=a;
    t[1]=a/10;
    if(a>-10)
        t[2]=0;
    else if(a>-100&&a<-10)
    {
        t[2]=a%10;
    }
    else
        t[2]=(a/100)*10+a%10;
    sort(t,t+3);
    cout<<t[2]<<endl;
    return 0;
}