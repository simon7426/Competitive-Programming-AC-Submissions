#include<iostream>
#include<stack>
#include<string>
#include<cstdio>
using namespace std;
int main()
{
    int n,i,si,j,f=0;
    string s;
    stack<char> a;
    cin>>n;
    for(i=0;i<n;i++)
    {
        f=0;
        //cout<<a.size()<<" ";
        while(!a.empty())
            a.pop();
        //cout<<a.size()<<" "<<endl;
        cin>>s;
        si=s.size();
        for(j=0;j<si;j++)
        {

            if(s[j]=='('||s[j]=='{'||s[j]=='[')
                a.push(s[j]);
            else{
                    //cout<<a.top()<<" ";
            if(a.empty())
                {
                    f=1;
                    break;
                }
            else if(s[j]==')')
            {
                if(a.top()=='(')
                    a.pop();
                else
                {
                    f=1;
                    break;
                }
            }
            else if(s[j]=='}')
            {
                if(a.top()=='{')
                    a.pop();
                else
                {
                    f=1;
                    break;
                }
            }
            else if(s[j]==']')
            {
                if(a.top()=='[')
                    a.pop();
                else
                {
                    f=1;
                    break;
                }
            }
        }
    }
    (f==0&&a.empty())?cout<<"YES"<<endl:cout<<"NO"<<endl;
}
return 0;
}
