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

vector<int>vec, v;
int n, d, m;
int gaser(int M, int idx)
{
    if (M == m)
    {
        return 1;
    }
    if (idx == n)
        return 0;

    int ret = 0;
    if (ret != 0)
        return ret;
    if (v.empty() || vec[idx] - v.back() == d)
    {
        v.push_back(vec[idx]);
        ret += gaser(M + 1, idx + 1);
        v.pop_back();
    }
    ret += gaser(M, idx + 1);

    return ret;
}

int main()
{

    fast();
    //freopen("bye.in", "r", stdin);

    int t;
    t = 1;
    while (t--)
    {
        
        cin >> n >> d >> m;
        vec.resize(n);
        map<int, int>dp;
        map<int, int>ma;
        set<int>s;
        lp(i, n)
        {
            cin >> vec[i];


        }
        
            //vector<bool>vis(n, 0);
        int ans = 0;
        lp(i, vec.size())
        {


            int num1 = vec[i];
            int num2 = num1 - d;

            if (m == 2)
            {
                ans += ma[num2];
            }
            dp[num1] += ma[num2];


            int num3 = num2 - d;



            dp[num1] += dp[num2];
            if (m == 3)
            {

                ans += dp[num2];
            }
            ma[vec[i]]++;
        }
        cout << ans;
        
        
        cout << "\n";
    }

    return 0;
}

/*
10 2 3
1 3 5 5 3 5 1  5 3 5
*/