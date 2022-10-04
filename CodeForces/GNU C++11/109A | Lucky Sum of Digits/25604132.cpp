#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
void print(int a,int b)
    {
        int i;
        for(i=0;i<a;i++)
            cout<<4;
        for(i=0;i<b;i++)
            cout<<7;
    }
main()
{
    int n,cnt=0;
    cin>>n;
    while(n>=0)
    {
        if(n%7==0)
        {
            print(cnt,n/7);
            return 0;
        }
        n-=4;
        cnt++;
        if(n==0)
        {
            print(cnt,0);
            return 0;
        }
    }
    cout<<-1<<endl;
}