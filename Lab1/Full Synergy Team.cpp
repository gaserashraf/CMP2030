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
string alpha = "abcdefghijklmnopqrstuvwxyz";
void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<int>ans;
vector<int>vec;
vector<vector<int>>adj;
int ma = 0;
bool cycile(vector<int>v)
{
    lp(i, v.size())
    {
        lp(j, v.size())
        {
            if (i == j)
                continue;
            if (!adj[v[i]][v[j]])
                return 0;
        }
    }
    return 1;
}
void gaser(int idx)
{
    if (idx == vec.size())
    {
        if (cycile(ans))
        {
            ma = max(ma, int(ans.size()));
        }
        return;
    }
    ans.push_back(vec[idx]);
    gaser(idx + 1);
    ans.pop_back();
    gaser(idx + 1);
}
int main()
{
    fast();
    //freopen("bye.in", "r", stdin);
    int t;
    t = 1;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        adj.clear();
        adj.resize(n);
        lp(i, n)
            vec.push_back(i);
        lp(i, n)
            adj[i] = vector<int>(n,0);
        lp(i, m)
        {
            int u, v;
            cin >> u >> v;
            adj[u][v] = 1;
            adj[v][u] = 1;
        }
        gaser(0);
        cout << ma;
        cout << "\n";
    }
    return 0;
}