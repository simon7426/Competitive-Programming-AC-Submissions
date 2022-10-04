#include<cstdio>
#include<iostream>
#include<vector>
#define max 100010
using namespace std;
main()
{
    vector<bool>v(max,false);
    int i;
    for(i=1;i*i<max;i++)
        v[i*i]=true;
    int a,b,c;
        while(scanf("%d%d",&a,&b)==2)
        {
            if(a!=0&&b!=0){
            c=0;
            for(i=a;i<=b;i++)
            {
                if(v[i]==true)
                    c++;
            }
            cout<<c<<endl;
            }
        }
    return 0;
}
