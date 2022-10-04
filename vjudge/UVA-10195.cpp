#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    double a,b,c;
    while(scanf("%lf %lf %lf",&a,&b,&c)!=EOF){
    double s=(a+b+c)/2.0;
    double ar=sqrt(s*(s-a)*(s-b)*(s-c));
    if(s==0.0)
    {
        cout<<"The radius of the round table is: 0.000"<<endl;
        continue;
    }
    cout<<"The radius of the round table is: "<<setprecision(3)<<fixed<<ar/s<<endl;
    }
}
