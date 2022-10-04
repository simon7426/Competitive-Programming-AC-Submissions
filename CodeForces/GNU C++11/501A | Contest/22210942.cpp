 #include<iostream>
 #include<algorithm>
 using namespace std;
 main()
 {
     int a,b,c,d,e,f;
     cin>>a>>b>>c>>d;
     e=max((3*a)/10,a-(a/250)*c);
     f=max((3*b)/10,b-(b/250)*d);
     if(e>f)cout<<"Misha"<<endl;
     else if(e==f)cout<<"Tie"<<endl;
     else cout<<"Vasya"<<endl;
     return 0;
 }