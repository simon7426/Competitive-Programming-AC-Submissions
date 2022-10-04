#include <bits/stdc++.h>
using namespace std;

#define i64 long long
#define u32 unsigned int
#define u64 unsigned long long

#define Neg(v) memset((v), -1, sizeof(v))
#define Zero(v) memset((v), 0, sizeof(v))

#define ff first
#define ss second
#define sqr(x) ((x)*(x))
#define INF LONG_LONG_MAX
#define PI 2*acos(0)
#define pb push_back

#define WHITE 0
#define GREY  1
#define BLACK  2

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a) | (b))
#define XOR(a,b) ((a) ^ (b))

#define FLASH std::ios_base::sync_with_stdio(0);

const double eps = 1e-9;
//int r[]={1,0,-1,0};int c[]={0,1,0,-1}; ///4 Direction
//int r[]={1,1,0,-1,-1,-1,0,1};int c[]={0,1,1,1,0,-1,-1,-1};///8 direction
//int r[]={2,1,-1,-2,-2,-1,1,2};int c[]={1,2,2,1,-1,-2,-2,-1};///Knight Direction
//int r[]={2,1,-1,-2,-1,1};int c[]={0,1,1,0,-1,-1}; ///Hexagonal Direction


int gcd(int a,int b)
{
    return b==0 ? a:gcd(b,a%b);
}

int lcm(int a,int b)
{
    return a*(b/(gcd(a,b)));
}

int power( int x, int n)
{
    ///complexity O(logn)
    if(n==0)return 1;
    else if(n%2==0)
    {
        int y=power(x,n/2);
        return y*y;
    }
    else
        return x*power(x,n-1);
}

int big_mod(int base,int power,int mod)
{
    if(power==0)return 1;
    else if(power%2==0)
    {
        int y=(big_mod(base,power/2,mod))%mod;
        return (y*y)%mod;
    }
    else
    {
        int y1=base%mod;
        int y2=(big_mod(base,power-1,mod))%mod;
        return (y1*y2)%mod;
    }
}

///nCr Function

/*
int dp[1010][3];
int nCr(int n, int r)
{
    if(n==r) return dp[n][r] = 1;
    if(r==0) return dp[n][r] = 1;
    if(r==1) return dp[n][r] = n;
    if(dp[n][r]) return dp[n][r];
    return dp[n][r] = nCr(n-1,r) + nCr(n-1,r-1);
}
*/
/// Bitwise Operation

/*
#define Check(n, pos) (n & (1<<pos))
#define Set(n, pos) (n | (1<<pos))

int Unset(int a, int i)
{
	int mask;
	mask = 1 << i;
	a = a & ~mask;

	return a;
}

*/

/// Tokens

/*
vector <int> lon;
vector <string> los;

void token_of_string()
{
    char line[1000];
    gets(line);
    stringstream ss( line );
    string temp;
    while( ss >> temp )
    los.pb( temp );
}

void token_of_number()
{
    char line[1000];
    gets(line);
    stringstream ss( line );
    int num;
    while( ss >> num )
    lon.pb( num );
}

*/


///1st,2nd,3rd

/*
void func( int num )
{
    printf("%d",num);
    if(num % 10 == 1 && (num/10)%10!=1) printf("st");
    else if(num %10==2 && (num/10)%10!=1) printf("nd");
    else if(num %10==3 && (num/10)%10!=1) printf("rd");
    else printf("th");
}
*/



/***

int nth_element( int a , int d , int n)
{
    return a + (n-1) * d;
}

int nth_summation( int a , int d , int n)
{
	int temp;
    temp = 2 * a + (n-1)*d;
    temp *= n;
    temp /= 2;

    return temp;
}

***/

///Let the Hunger Games Begin



int main()
{
    return 0;
}
