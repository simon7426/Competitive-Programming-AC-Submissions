#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define mp make_pair
#define endl '\n'

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007
//#define harmonic(n) 0.57721566490153286l+log(n)

#define mem(a,b) memset(a, b, sizeof(a) )
#define sqr(a) ((a) * (a))

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; ///4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};///8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};///Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; ///Hexagonal Direction

inline int in() { int x; scanf("%d", &x); return x; }
inline ll inl() { ll x;scanf("%I64d",&x); return x;}
inline double ind() { double x;scanf("%lf",&x);return x;}

int gcd(int a,int b) { return b==0 ? a:gcd(b,a%b);}
int power( int x, int n)
{
    if(n==0)return 1;
    else if(n%2==0)
    {
        int y=power(x,n/2);
        return y*y;
    }
    else
        return x*power(x,n-1);
}
//abcdefghijklmnopqrstuvwxyz//
struct bigint
{
    vector<int> num;
    static const int base=1000*1000*1000;
    static const int basedig=9;
    string leadzeromodifier;

    /// Constructors && setters ///

    void setleadingzeromodifier()
    {
        leadzeromodifier="%0xd";
        leadzeromodifier[2]='0'+basedig;
    }
    void set(int val)
    {
        num.clear();
        if(val==0)
            num.push_back(0);
        while(val)
        {
            num.push_back(val%base);
            val/=base;
        }
    }

    void set(long long val)
    {
        num.clear();
        if(val==0)
            num.push_back(0);
        while(val)
        {
            num.push_back(val%base);
            val/=base;
        }
    }

    void set(string &val)
    {
        num.clear();
        for(int i= (int) val.length();i>=0;i-=basedig)
        {
            int add=0;
            for(int j=max(0,i-basedig+1);j<=i;j++)
                add=add*10+val[j]-'0';
            num.push_back(add);
        }
    }

    void operator = (int value)
    {
        set(value);
    }

    void operator = (long long value)
    {
        set(value);
    }

    void operator = (string &value)
    {
        set(value);
    }

    bigint()
    {
        setleadingzeromodifier();
        set(0);
    }
    bigint(int val)
    {
        setleadingzeromodifier();
        set(val);
    }
    bigint(string val)
    {
        setleadingzeromodifier();
        set(val);
    }

    /// Size Methods ///

    int size()
    {
        return (int) num.size();
    }

    int digitnum()
    {
        int result=0;
        for(int i=0;i<num.size()-1;i++)
            result+=basedig;
        int lastnum=num.back();
        while(lastnum)
        {
            result++;
            lastnum/=10;
        }
        return result;
    }

    /// I/O ///

    void read()
    {
        string s;
        cin>>s;
        num.clear();
        for(int i=s.length()-1;i>=0;i-=basedig)
        {
            int add=0;
            for(int j=max(0,i-basedig+1);j<=i;j++)
                add=add*10+s[j]-'0';
            num.push_back(add);
        }
    }

    void print()
    {
        printf("%d",num.back());
        for(int i=num.size()-2;i>=0;i--)
        {
            printf(leadzeromodifier.c_str(),num[i]);
        }
    }
    void println()
    {
        print();
        printf("\n");
    }
    string tostring()
    {
        string res="";
        for(int i=0;i<num.size();i++)
        {
            int cur=num[i];
            //cout<<num[i]<<" ";
            for(int j=1;j<=basedig;j++)
            {
                if(cur==0 && i==num.size()-1)
                    break;
                res.append(1,(char)'0'+cur%10);
                cur/=10;
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }

    /// Addition ///

    void sumthis(bigint number)
    {
        int carry=0;
        for(int i=0;i<max((int)num.size(),number.size())||carry;i++)
        {
            if(i==num.size())
                num.push_back(0);
            if(i>=number.size())
                carry=num[i]+carry;
            else
                carry=num[i]+carry+number.num[i];
            num[i]=carry%base;
            carry/=base;
        }
    }

    void sumthis(int number)
    {
        int carry=number;
        for(int i=0;i<num.size()||carry;i++)
        {
            if(i==num.size())
                num.push_back(0);
            carry=num[i]+carry;
            num[i]=carry%base;
            carry/=base;
        }
    }

    bigint sum(bigint number)
    {
        bigint result=*this;
        result.sumthis(number);
        return result;
    }

    bigint sum(int number)
    {
        bigint result=*this;
        result.sumthis(number);
        return result;
    }

    void operator += (bigint number)
    {
        sumthis(number);
    }

    void operator += (int number)
    {
        sumthis(number);
    }

    bigint operator + (bigint number)
    {
        sum(number);
    }

    bigint operator + (int number)
    {
        sum(number);
    }

    ///subtraction///

    void subThis(bigint number) {
        int carry = 0;
        for (int i = 0; i < (int)number.size() || carry; i++) {
            if (i < (int)number.size())
                num[i] -= carry + number.num[i];
            else
                num[i] -= carry;
            if (num[i] < 0) {
                carry = 1;
                num[i] += base;
            }
            else
                carry = 0;
        }
        while (num.size() > 1 && num.back() == 0)
            num.pop_back();
    }

    void subThis(int number) {
        int carry = -number;
        for (int i = 0; carry > 0; i++) {
            num[i] -= carry;
            if (num[i] < 0) {
                carry = 1;
                num[i] += base;
            }
            else
                carry = 0;
        }
        while (num.size() > 1 && num.back() == 0)
            num.pop_back();
    }

    bigint sub(bigint number) {
        bigint result = *this;
        result.subThis(number);
        return result;
    }

    bigint sub(int number) {
        bigint result = *this;
        result.subThis(number);
        return result;
    }

    void operator -= (bigint number) {
        subThis(number);
    }

    void operator -= (int number) {
        subThis(number);
    }

    bigint operator - (bigint number) {
        return sub(number);
    }

    bigint operator - (int number) {
        return sub(number);
    }

    ///multiplication///

    bigint mult(bigint number) {
        bigint product;
        product.num.resize(num.size() + number.size());
        for (int i = 0; i < (int)num.size(); i++) {
            for (int j = 0, carry = 0; j < (int)number.size() || carry; j++) {
                long long cur = product.num[i + j] + num[i] * 1ll * (j < (int)number.size() ? number.num[j] : 0) + carry;
                product.num[i + j] = int (cur % base);
                carry = int (cur / base);
            }
        }
        while (product.size() > 1 && product.num.back() == 0)
            product.num.pop_back();
        return product;
    }

    void multThis(bigint number) {
        *this = mult(number);
    }

    void multThis(int number) {
        int carry = 0;
        for (int i = 0; i < (int)num.size() || carry; ++i) {
            if (i == num.size())
                num.push_back (0);
            long long cur = carry + num[i] * 1ll * number;
            num[i] = int (cur % base);
            carry = int (cur / base);
        }
        while (num.size() > 1 && num.back() == 0)
            num.pop_back();
    }

    bigint mult(int number) {
        bigint result = *this;
        result.multThis(number);
        return result;
    }

    void operator *= (bigint number) {
        multThis(number);
    }

    void operator *= (int number) {
        multThis(number);
    }

    bigint operator * (bigint number) {
        return mult(number);
    }

    bigint operator * (int number) {
        return mult(number);
    }

    void multThisByPowerOfTen(int power) {
        int baseNums = power / basedig;
        int curLen = (int)num.size();
        num.resize(curLen + baseNums);
        for (int i = num.size() - 1; i >= baseNums; i--) {
            num[i] = num[i - baseNums];
        }
        for (int i = baseNums - 1; i >= 0; i--)
            num[i] = 0;
        power %= basedig;
        int multBy = (int)pow(10.0, power);
        multThis(multBy);
    }

    ///Division(with integers)///

    void divThis(int number) {
        int carry = 0;
        for (int i= (int)num.size() - 1; i >= 0; i--) {
            long long cur = num[i] + carry * 1ll * base;
            num[i] = int (cur / number);
            carry = int (cur % number);
        }
        while (num.size() > 1 && num.back() == 0)
            num.pop_back();
    }

    bigint div(int number) {
        bigint result = *this;
        result.divThis(number);
        return result;
    }

    void operator /= (int number) {
        divThis(number);
    }

    bigint operator / (int number) {
        return div(number);
    }

    void divThisByPowerOfTen(int power) {
        int baseNums = power / basedig;
        int curLen = (int)num.size();
        for (int i = 0; i < (int)num.size() - baseNums; i++) {
            num[i] = num[i + baseNums];
        }
        for (int i = 1; i <= baseNums; i++)
            num.pop_back();
        power %= basedig;
        int divBy = (int)pow(10.0, power);
        divThis(divBy);
    }

    ///mod(with integers)///

    void modThis(int number) {
        int carry = 0;
        for (int i= (int)num.size() - 1; i >= 0; i--) {
            long long cur = num[i] + carry * 1ll * base;
            num[i] = int (cur / number);
            carry = int (cur % number);
        }
        set(carry);
    }

    bigint mod(int number) {
        bigint result = *this;
        result.modThis(number);
        return result;
    }

    void operator %= (int number) {
        modThis(number);
    }

    bigint operator % (int number) {
        return mod(number);
    }

    ///comparison///

    //Returns: -1 - this number is less than argument, 0 - equal, 1 - this number is greater
    int compareTo(bigint number) {
        if ((int)num.size() < number.size())
            return -1;
        if ((int)num.size() > number.size())
            return 1;
        for (int i = (int)num.size() - 1; i >= 0; i--) {
            if (num[i] > number.num[i])
                return 1;
            if (num[i] < number.num[i])
                return -1;
        }
        return 0;
    }

    //Returns: -1 - this number is less than argument, 0 - equal, 1 - this number is greater
    int compareTo(int number) {
        if (num.size() > 1 || num[0] > number)
            return 1;
        if (num[0] < number)
            return -1;
        return 0;
    }

    bool operator < (bigint number) {
        return compareTo(number) == -1;
    }

    bool operator < (int number) {
        return compareTo(number) == -1;
    }

    bool operator <= (bigint number) {
        return compareTo(number) != 1;
    }

    bool operator <= (int number) {
        return compareTo(number) != 1;
    }

    bool operator == (bigint number) {
        return compareTo(number) == 0;
    }

    bool operator == (int number) {
        return compareTo(number) == 0;
    }

    bool operator > (bigint number) {
        return compareTo(number) == 1;
    }

    bool operator > (int number) {
        return compareTo(number) == 1;
    }

    bool operator >= (bigint number) {
        return compareTo(number) != -1;
    }

    bool operator >= (int number) {
        return compareTo(number) != 1;
    }

    bool operator != (bigint number) {
        return compareTo(number) != 0;
    }

    bool operator != (int number) {
        return compareTo(number) != 0;
    }
};
int nn,aa;
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    while(scanf("%d%d",&nn,&aa)==2)
    {
        bigint n,a,sum;
        n.set(nn);
        a.set(aa);
        sum.set(0);
        for(int i=1;i<=nn;i++)
        {
            bigint x;
            x.set(1);
            for(int j=1;j<=i;j++)
            {
                x*=aa;
            }
            x*=i;
            sum+=x;
        }
        sum.print();
        printf("\n");
    }
}

