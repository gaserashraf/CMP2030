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
#define oo 999999999;
ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
ll fastpow(ll b, ll p) { if (!p) return 1; ll ret = fastpow(b, p >> 1); ret *= ret; if (p & 1) ret *= b; return ret; }
string alpha = "abcdefghijklmnopqrstuvwxyz";
void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

struct node {
    node* l, * r;
    ll size, sum;
    node(int n)
    {
        l = r = NULL;
        sum = n;
        size = 1;
    }
};
ll dp[1005][1005];    
ll grid[1005][1005];
ll n, m;

bool isVaild(int i, int j)
{
    if (j < 0 || i >= n || j < 0 || j >= m)
        return 0;
    return 1;
}
ll gaser(ll i, ll j)
{
    if (i>=n||j>=m)
        return -1e18;

    if (i == n - 1 && j == m - 1)
        return grid[i][j];


    ll& ret = dp[i][j];
    if (ret != -1e18)
        return ret;

    return  ret= grid[i][j] +max(gaser(i+1,j+1) ,max(gaser(i + 1, j), gaser(i, j + 1)));
}
int main()
{

    fast();
    //
    //freopen("nodes.in", "r", stdin);

    int t;
    t = 1;
    while (t--)
    {
        cin >> n >> m;
        lp(i, n)
            lp(j, m)
                dp[i][j] = -1e18;
        lp(i, n)
        {
            lp(j, m)
                cin >> grid[i][j];
        }
        cout << gaser(0, 0);
        cout << "\n";
    }

    return 0;
}

/*
10 2 3
1 3 5 5 3 5 1  5 3 5
*/