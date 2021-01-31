#includeiostream
#includestdio.h
#include sstream
#include cstdio
#includefstream
#includealgorithm
#includevector
#include bitset
#include complex
#include deque
#include exception
#include fstream
#include functional
#include iomanip
#include ios
#include iosfwd
#include iostream
#include istream
#include iterator
#include limits
#include list
#include locale
#include map
#include memory
#include new
#include numeric
#include ostream
#include queue
#include set
#include sstream
#include stack
#include stdexcept
#include streambuf
#include string
#include typeinfo
#include utility
#include valarray
#include numeric 
#include vector
#includeunordered_map
#include stdio.h  
#include string.h 
#include math.h

using namespace std;
#define _USE_MATH_DEFINES


# define M_PI           3.14159265358979323846   pi 
#define ll long long 
#define ld long double 
#define vbe(v) ((v).begin()), ((v).end())
#define sz(v)     ((int)((v).size()))
#define clr(v, d)   memset(v, d, sizeof(v))
#define rep(i, v)   for(int i=0;isz(v);++i)
#define lp(i, n)    for(int i=0;i(int)(n);++i)
#define lpi(i, j, n)  for(int i=(j);i(int)(n);++i)
#define lpd(i, j, n)  for(int i=(j);i=(int)(n);--i)
#define MIN(x, y) (((x)  (y))  (x)  (y))  
ll GCD(ll a, ll b) { return (a)  GCD(b % a, a)  b; }
ll LCM(ll a, ll b) { return a  b  GCD(a, b); }
ll fastpow(ll b, ll p) { if (!p) return 1; ll ret = fastpow(b, p  1); ret = ret; if (p & 1) ret = b; return ret; }
void fast()
{
    ios_basesync_with_stdio(false);
    cin.tie(NULL);
}
struct Node
{
    int data;
    struct Node left,  right;
    Node(int data)
    {
        this-data = data;
        left = right = NULL;
    }
};
const int oo = 100005;

int n, m;
vectorintv1, v2;
int gaser(int idx,int sum,bool b)
{
    
    if (idx == n)
        return 0;
    int &ret = dp1[idx][sum][b];
    if (ret != 0)
        return ret;
    if(b)
        ret = max(ret, v1[idx]+ gaser(idx + 1, sum + v1[idx],!b));
    else
        ret = max(ret, v2[idx]+ gaser(idx + 1, sum + v2[idx], !b));
    ret = max(ret, gaser(idx + 1, sum , b));

    return ret;
}
int main()
{

    fast();
    freopen(bye.in, r, stdin);

    
    int n;
    cin  n;
    v1.resize(n); v2.resize(n);
    lp(i, n)
        cin  v1[i];
    lp(i, n)
        cin  v2[i];
    if(n==0)
    {
        cout0;
        return 0;
    }
    ll dp1[1000005],dp2[1000005],dp3[1000005];
    memset(dp1, 0, sizeof dp1);
    memset(dp2, 0, sizeof dp2);
    memset(dp3, 0, sizeof dp3);
    dp2[0]=v1[0]; dp3[0]=v2[0];
    lpi(i,1,n)
    {
        
        dp1[i]+=max(dp2[i-1],dp3[i-1]);
        dp2[i]+=v1[i]+max(dp1[i-1],dp3[i-1]);
        dp3[i]+=v2[i]+max(dp2[i-1],dp1[i-1]);
    }
    coutmax(dp1[n-1],max(dp2[n-1],dp3[n-1]));
    
    cout  n;
    

    return 0;
}