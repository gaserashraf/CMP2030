


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
const int maxN = 1000005;
int count1[maxN];
int sum[maxN];
void dfs(int node)
{
    cout << indxToVal[node] << " ";
    lp(i, vec[node].size())
        dfs(vec[node][i]);
}
void dfsNumOfNode(int s, int e)
{
    count1[s] = 1;
    lp(i, vec[s].size())
    {
        if (vec[s][i] == e)
            continue;
        dfsNumOfNode(vec[s][i], s);
        count1[s] += count1[vec[s][i]];
    }
}
void dfsSumOfNode(int s, int e)
{
    sum[s] += indxToVal[s];
    lp(i, vec[s].size())
    {
        if (vec[s][i] == e)
            continue;
        int child = vec[s][i];
        sum[child] += sum[s];
        dfsSumOfNode(child, s);

    }
}
bool gaser(vector<int>pa, int c, int level, int val)
{
    vector<int>vec;
    int D = c;
    while (c != -1)
    {
        vec.push_back(indxToVal[c]);
        c = pa[c];
    }
    sort(vbe(vec));
    return  vec[(level) / 2] == val;
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
        cin >> n;
        vec.resize(n);
        lp(i, n)
        {
            int x;
            cin >> x;
            indxToVal[i] = x;
            ValToIndx[x] = i;
        }
        int M;
        cin >> M;
        while (M--)
        {
            char c;
            cin >> c;
            int u, v;
            cin >> u >> v;
            vec[u].push_back(v);
        }
        dfsNumOfNode(0, 0);
        dfsSumOfNode(0, 0);
        queue<pair<int, int>>q;
        vector<int>LEN(n, 0);
        vector<bool>visited(n, 0);
        q.push({ 0,0 });
        visited[0] = 1;
        vector<int>par(n, 0);
        par[0] = -1;
        int ans = 0;
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
                    par[vec[s][i]] = s;
                    if ((LEN[vec[s][i]]+1) % 2 != 0)
                    {
                        if (gaser(par, vec[s][i], LEN[vec[s][i]]+1, indxToVal[vec[s][i]]))
                            ans++;
                    }
                }
            }
        }
        cout << ans+1;



       
        cout << "\n";
    }

    return 0;
}