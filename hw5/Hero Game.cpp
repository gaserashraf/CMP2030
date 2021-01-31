


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
#define INF 1e9
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
pair<int, bool> max(pair<int, bool>p1, pair<int, bool>p2)
{
    if (p1.first > p2.first)
        return p1;
    return p2;
}
pair<int, bool> min(pair<int, bool>p1, pair<int, bool>p2)
{
    if (p1.first < p2.first)
        return p1;
    return p2;
}
const int x = 1000000000;
int n, a1, a2, b1, b2;
int dp[10005][10005];
int gaser(int n1, int n2)
{
    if (n1 <= 0 || n2 <= 0)
    {
        if (n1 <= 0 && n2 <= 0)//n1 win
            return 2 * x;
        if (n1 <= 0)//n2 win
            return x;
        if (n2 <= 0)//n1 win
            return 2 * x;
    }
    int& ret = dp[n1][n2], action1, action2;
    if (ret != 0)
        return ret;


    action1 = 1 + gaser(n2 - a2, n1 - a1); //action a
    int action1win = action1 / x;
    int action2win;

    if (n1 % 3 == 0) //action b
    {
        action2 = 1 + gaser(n2 - b1, n1);
        action2win = action2 / x;
    }
    else
    {
        action2 = 1 + gaser(n2 - b2, n1 - b2);
        action2win = action2 / x;
    }
    action1 %= x;
    action2 %= x;
    if (action1win == 1 && action2win == 1)//player 1 win
        ret = max(action1, action2) + 2 * x;
    else if (action1win == 2 && action2win == 2)//player 2 win
        ret = min(action1, action2) + x;
    else if (action1win == 1)
        ret = action1 + 2 * x;
    else
        ret = action2 + 2 * x;


    return ret;
}
int main()
{

    fast();
    //freopen("bye.in", "r", stdin);

    memset(dp, 0, sizeof dp);
    cin >> n >> a1 >> a2 >> b1 >> b2;
    int ans = gaser(n, n);
    if (ans / x == 2)
        cout << "1 ";
    else
        cout << "2 ";
    cout << ans % x;
    cout << "\n";

    return 0;
}