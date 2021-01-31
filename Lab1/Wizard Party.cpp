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
vector<int>vis;
vector<vector<int>>adj;
int ans = 0;
int n, m;
void sol(int a[], int n)
{
    sort(a, a + n);
    reverse(a, a + n);
    do {
        // combiantion
        bool e = 0;
        lp(i, n)
        {
            if (i == n - 1)
            {
                if (!adj[a[i]][a[0]])
                    e = 1;
            }
            else
            {
                if (!adj[a[i]][a[i + 1]])
                    e = 1;
            }
        }
        if (!e)
        {
            ans = 1;
            break;
        }
    } while (prev_permutation(a, a + n));
}
void gaser(int node,int src,int x)
{
    
    
    vis[node] = 1;
    lp(i, adj[node].size())
    {
        int child = adj[node][i];
        if (child == src && x == n-1)
        {
            ans = 1;
            return;
        }
        if (vis[child])
            continue;
        vis[child] = 1;
        gaser(child, src, x + 1);
        vis[child] = 0;
    }
    //vis[node] = 0;
    //return 0;
}
int main()
{
    fast();
    //freopen("bye.in", "r", stdin);
    int t;
    t = 1;

    int arr[11];
    while (t--)
    {
        cin >> n >> m;
        adj.clear();
        adj.resize(n);
        vis.clear();
        lp(i, n)
            arr[i] = i;
        vis.resize(n, 0);
        lp(i, n)
            adj[i] = vector<int>(n, 0);
        lp(i, m)
        {
            int u, v;
            cin >> u >> v;
            adj[u][v] = 1;
            adj[v][u] = 1;

        }
        
    
        sol(arr, n);
        if (n == 1)
            ans = 1;
        cout << ans;
        
       // cout << ans;
        cout << "\n";
    }
    return 0;
}
