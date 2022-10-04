#include<iostream>
using namespace std;
main()
{
    int a[25]={},n,i,sch,sbi,sba;
    sch=sba=sbi=0;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i+=3)
    {
        sch+=a[i];
        sbi+=a[i+1];
        sba+=a[i+2];
    }
    if(sch>=sbi&&sch>=sba)
        cout<<"chest"<<endl;
    else if(sbi>=sch&&sbi>=sba)
        cout<<"biceps"<<endl;
    else if(sba>=sch&&sba>=sbi)
          cout<<"back"<<endl;
    return 0;
}