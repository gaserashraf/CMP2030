


#include<iostream>
#include<stdio.h>
#include <sstream>
#include <cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <numeric> 
#include <vector>
#include<unordered_map>
#include <stdio.h>  
#include <string.h> 
#include <math.h>

using namespace std;
#define _USE_MATH_DEFINES


# define M_PI           3.14159265358979323846  /* pi */
#define ll long long 
#define ld long double 
#define vbe(v) ((v).begin()), ((v).end())
#define sz(v)     ((int)((v).size()))
#define clr(v, d)   memset(v, d, sizeof(v))
#define rep(i, v)   for(int i=0;i<sz(v);++i)
#define lp(i, n)    for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)  for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)  for(int i=(j);i>=(int)(n);--i)
#define MIN(x, y) (((x) < (y)) ? (x) : (y))  
ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
ll fastpow(ll b, ll p) { if (!p) return 1; ll ret = fastpow(b, p >> 1); ret *= ret; if (p & 1) ret *= b; return ret; }
void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
struct Node
{
    int data;
    struct Node* left, * right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};
bool sortgaser(const pair<int, int>& a,
    const pair<int, int>& b)
{
    if (a.first > b.first)
        return 1;
    else if (a.first == b.first && a.second < b.second)
        return 1;
    return 0;
}
ll dp[100001][2];
int main()
{

    fast();
    //freopen("bye.in", "r", stdin);


    int n;
    cin >> n;
    vector<ll>he(n);
    lp(i, n)
        cin >> he[i];
    int m;
    cin >> m;
    
    int cntz = 0;
   
    set<int>s;
    lp(i, m)
    {
        ll x;
        cin >> x;
        if (!x)
            cntz++;
        else
            s.insert(x);
    }
    vector<ll>wep(vbe(s));
    m =wep.size();
    memset(dp, 0, sizeof dp);
    lp(i, 100001)
    {
        vector<pair<ll, ll>>max;
        lp(j, m)
        {
            if (wep[j] <= i)
            {
                ll val = dp[i - wep[j]][0] + wep[j];
                ll c = dp[i - wep[j]][1] + 1;
                if (val > dp[i][0])
                {
                    dp[i][0] = val;
                    dp[i][1] = c;
                }
                else if (val == dp[i][0])
                {
                    if (dp[i][1] > c)
                    {
                        dp[i][0] = val;
                        dp[i][1] = c;
                    }

                }
            }
            
        }
        
    }

    lp(i, n)
        cout << he[i]-dp[he[i]][0] << " " << dp[he[i]][1]<<"\n";
   

    cout << "\n";

    return 0;
}