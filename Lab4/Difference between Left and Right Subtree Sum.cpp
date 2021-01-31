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
void dfs(node* root)
{
    if (root == NULL)
        return;
    dfs(root->l);
    dfs(root->r);
    if (root->l)//backtracking (lma yrg3)
    {
        root->size += root->l->size;
        root->sum += root->l->sum;
    }
    if (root->r)
    {
        root->size += root->r->size;
        root->sum += root->r->sum;
    }
}
ll ans = 0, R;
void gaser(node* root)
{
    if (root == NULL)
        return;


    ll  sumL = 0, sumR = 0;
    if (root->l)//backtracking (lma yrg3)
    {

        sumL += root->l->sum;
    }
    if (root->r)
    {
        sumR += root->r->sum;
    }
    if (abs(sumL - sumR) <= R)
        ans++;
    gaser(root->l);
    gaser(root->r);
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
        ll n, m;
        cin >> n >> m;
        R = m;
        vector<node>vec;
        lp(i, n)
        {
            ll x;
            cin >> x;
            node N(x);
            vec.push_back(N);
        }
        int q;
        cin >> q;
        while (q--)
        {
            char d;
            ll u, v;
            cin >> d >> u >> v;
            if (d == 'L')
                vec[u].l = &vec[v];
            else
                vec[u].r = &vec[v];
        }
        dfs(&vec[0]);
        gaser(&vec[0]);
        cout << ans;
        cout << "\n";
    }

    return 0;
}

/*
10 2 3
1 3 5 5 3 5 1  5 3 5
*/