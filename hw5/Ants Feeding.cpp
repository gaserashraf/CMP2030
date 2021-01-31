


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
#define INF 1e18
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
bool visited[100005];
vector<vector<int>>vec;
vector<vector<int>>reversedVec;
stack<int> s;
void dfs1(int v)
{
    visited[v] = 1;
    lp(i, reversedVec[v].size())
    {
        if (!visited[reversedVec[v][i]])
            dfs1(reversedVec[v][i]);
    }
}

void dfs(int node)
{
    visited[node] = 1;

    lp(i, vec[node].size())
    {
        if (!visited[vec[node][i]])
            dfs(vec[node][i]);
    }
    s.push(node);
}
int main()
{

    fast();
    //freopen("bye.in", "r", stdin);
    ll n, m;
    cin >> n >> m;

    vec.resize(n);

    lp(i, m)
    {
        ll u, v;
        cin >> u >> v;
        vec[u].push_back(v);
    }
    int count = 0;
    memset(visited, 0, sizeof visited);
    for (int i = 0; i < n; i++)
        if (!visited[i])
        {
            dfs(i);
        }
    reversedVec.resize(n);
    lp(i,n)
    {
        lp(j, vec[i].size())
        {
            reversedVec[vec[i][j]].push_back(i);
        }
    }

    memset(visited, 0, sizeof visited);

    ll ans = 0;
    while (!s.empty())
    {
        int t = s.top();
        s.pop();

        if (!visited[t])
        {
            dfs1(t);
            ans++;
        }
    }
    cout << ans;
    /*vector<ll>dis(n+1, INF);
    vector<bool>visited(n+1, 0);
    
    priority_queue<pair<ll, ll>>q;//{d,x}d is distance from src to x
    q.push({ 0,s });
    dis[s] = 0;
    
    while (!q.empty())
    {
        ll from = q.top().second,W=q.top().first;
        q.pop();
        if (W > dis[from])    continue;
        if (visited[from])
            continue;
        visited[from] = 1;
        
        lp(i, vec[from].size())
        {
            ll to = vec[from][i].first; ll w = vec[from][i].second;
            if (dis[from] + w < dis[to])
            {
                dis[to] = dis[from] + w;
                
                q.push({ -dis[to], to });
            }
        }
    }
    ll ncity = 0;
    ll minW = 0;
    lp(i,n)
        if(dis[i]!=INF)
            minW = max(minW, dis[i]), ncity++;;
   
    
    cout << ncity << " " << minW;*/
    cout << "\n";

    return 0;
}