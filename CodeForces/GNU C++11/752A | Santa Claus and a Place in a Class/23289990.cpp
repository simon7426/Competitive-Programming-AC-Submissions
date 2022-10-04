#include<iostream>
#include<cmath>
using namespace std;
 main()
 {
      int n,m,p,a,b;
      cin>>n>>m>>p;
      m*=2;
      if(p%m!=0)
      {
          a=p/m;
          a++;
          p%=m;
          b=p/2;
          if(p%2==0)
          {
              cout<<a<<" "<<b<<" "<<'R'<<endl;
          }
          else
              cout<<a<<" "<<b+1<<" "<<'L'<<endl;
      }
      else
      {
          a=p/m;
          p=p-(a-1)*m;
          b=p/2;
          if(p%2==0)
          {
              cout<<a<<" "<<b<<" "<<'R'<<endl;
          }
          else
              cout<<a<<" "<<b+1<<" "<<'L'<<endl;
      }
      return 0;
 }