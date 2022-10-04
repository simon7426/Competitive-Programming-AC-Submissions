#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<vector>
using namespace std;
 main()
 {
     double n,s,sum=0;
     //vector<double> a;
     cin>>n;
     int i;
     for(i=0;i<n;i++)
     {
         cin>>s;
         sum+=(s/100);
         //a.push_back(s);
     }
     printf("%.8f\n",(sum/n)*100);
     return 0;
 }