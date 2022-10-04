#include<iostream>
#include<cstdio>
using namespace std;
main()
{
    int a,b,c,d,e,f;
    while(scanf("%d%d%d%d",&a,&b,&c,&d))
    {
        if(a==0&&b==0&&c==0&&d==0)
            break;
        else
        {
            e=c-a;
            f=d-b;
            if(f<0){
                f+=60;
                e-=1;
            }
            if(e<0)
                e+=24;
            cout<<(e*60)+f<<endl;
        }
    }
    return 0;
}
