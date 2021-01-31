


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
#define INF 1000000000
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

int main()
{

    fast();
    //freopen("bye.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    int s;
    cin >> s;
    vector<vector<pair<int,int>>>vec(n);
    lp(i, m)
    {
        int u, v,w;
        cin >> u >> v >> w;
        vec[u].push_back({v,w});
    }
    
    vector<int>dis(n, INF);
    vector<int>visited(n, 0);
    vector<int>parent(n, -1);
    dis[s] = 0;
    priority_queue<pair<int, int>>q;//{d,x}d is distance from src to x
    q.push({ 0,s });
    while (!q.empty())
    {
        int from = q.top().second;
        q.pop();
        if (visited[from])
            continue;
        visited[from] = 1;
        lp(i, vec[from].size())
        {
            int to = vec[from][i].first, w = vec[from][i].second;
            if ((!visited[to]) && dis[from] + w <= dis[to])
            {
                dis[to] = dis[from] + w;
                q.push({ -dis[to], to });
                parent[to] = from;
            }
        }
    }
    int ncity = 0;
    lp(i, n)
        if (visited[i])
            ncity++;
    int minW = 0;
    lp(i, n)
    {
        if(visited[i])
            minW = max(minW, dis[i]);
    }
    cout << ncity << " " << minW;
    cout << "\n";

    return 0;
}