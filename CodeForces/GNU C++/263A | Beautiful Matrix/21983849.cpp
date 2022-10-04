#include<iostream>
#include<cstdlib>
using namespace std;
main()
{
    int i,j,m,tmp;
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
    {
        cin>>tmp;
        if(tmp==1)
        {
            m=abs(2-i)+abs(2-j);
            cout<<m<<endl;
            return 0;
        }
    }
}