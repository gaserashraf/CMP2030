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
vector <vector<int>>vec;
map<int, int>indxToVal;
map<int, int>ValToIndx;
const int maxN = 1005005;
bool visited[maxN];


int main()
{

    fast();
    //freopen("bye.in", "r", stdin);

    int t;
    t = 1;
    while (t--)
    {
        int n;
        cin >> n;
        vec.resize(n);
        lp(i, n)
        {
            int x;
            cin >> x;
            indxToVal[i] = x;
            ValToIndx[x] = i;
        }
        int m;
        cin >> m;
        while (m--)
        {
            char c;
            cin >> c;
            int u, v;
            cin >> u >> v;
            vec[u].push_back(v);
        }
        memset(visited, 0, sizeof visited);
        queue<pair<int, int>>q;
        vector<int>LEN(n, 0);
        q.push({ 0,0 });
        visited[0] = 1;
        while (!q.empty())
        {
            int s = q.front().first, len = q.front().second;

            q.pop();
            lp(i, vec[s].size())
            {
                if (!visited[vec[s][i]])
                {
                    visited[vec[s][i]] = 1;
                    q.push({ vec[s][i] ,len + 1 });
                    LEN[vec[s][i]] = len + 1;
                }
            }
        }
        int maxLevel = -1;
        lp(i, n)
            maxLevel = max(maxLevel, LEN[i]);
        maxLevel++;
        int L = indxToVal[0] % maxLevel;
        int minValL = 100000;
        lp(i, n)
            visited[i] = 0;
        while(!q.empty())
            q.pop();
        q.push({ 0,0 });
        visited[0] = 1;
        while (!q.empty())
        {
            int s = q.front().first, len = q.front().second;

            q.pop();
            lp(i, vec[s].size())
            {
                if (!visited[vec[s][i]])
                {
                    visited[vec[s][i]] = 1;
                    q.push({ vec[s][i] ,len + 1 });
                    if (LEN[vec[s][i]] == L)
                        minValL = min(minValL, indxToVal[vec[s][i]]);
                     
                }
            }
        }
        int K = minValL % maxLevel;
        if (K == 0)
            K = 1;
        string ans = to_string(indxToVal[0]);
        vector<int>sum(maxLevel + 1);
        lp(i, n)
            visited[i] = 0;
        while (!q.empty())
            q.pop();
        q.push({ 0,0 });
        visited[0] = 1;
        while (!q.empty())
        {
            int s = q.front().first, len = q.front().second;

            q.pop();
            ll a = 0;
            lp(i, vec[s].size())
            {
                if (!visited[vec[s][i]])
                {
                    visited[vec[s][i]] = 1;
                    q.push({ vec[s][i] ,len + 1 });
                    if (LEN[vec[s][i]] % K == 0)
                    {
                        int S = indxToVal[vec[s][i]];
                        sum[LEN[vec[s][i]]] += S;
                    }

                }
            }
            
        }
        lp(i, sum.size())
            if (sum[i])
                ans += to_string(sum[i]);
        cout << ans;
        cout << "\n";
    }

    return 0;
}
