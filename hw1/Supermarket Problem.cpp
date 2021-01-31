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
int divisor(int number)
{
    int i;
    for (i = 2; i <= sqrt(number); i++)
    {
        if (number % i == 0)
        {
            return number / i;
        }
    }
    return 1;
}
int myXOR(int x, int y)
{
    int res = 0; // Initialize result 

    // Assuming 32-bit Integer  
    for (int i = 31; i >= 0; i--)
    {
        // Find current bits in x and y 
        bool b1 = x & (1 << i);
        bool b2 = y & (1 << i);

        // If both are 1 then 0 else xor is same as OR 
        bool xoredBit = (b1 & b2) ? 0 : (b1 | b2);

        // Update result 
        res <<= 1;
        res |= xoredBit;
    }
    return res;
}
//std::getline(std::cin, a); //read string with spaces
void printDivisors(int n, vector<int>& v)
{
    // Note that this loop runs till square root 
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            // If divisors are equal, print only one 
            if (n / i == i && i > 1)
                v.push_back(i);

            else // Otherwise print both 
            {
                if (i > 1)
                    v.push_back(i);
                if (n / i > 1)
                    v.push_back(n / i);
            }
        }
    }
}
int bin(vector<int>vec, int val)
{
    int l = 0, r = vec.size() - 1, mid = r / 2;
    while (l <= r)
    {
        mid = (l + r) / 2;

        if (vec[mid]<val && vec[mid + 1]>val)
        {
            if (vec[mid + 1] == val)
                return mid + 1;
            return mid;

        }
        else if (vec[mid] > val)
        {
            r = mid - 1;
        }
        else if (vec[mid] < val)
        {
            l = mid + 1;
        }
        else if (vec[mid] == val)
            return mid;


    }
    return -1;
}
void clear(vector<bool>v)
{
    for (int i = 0; i < v.size(); i++)
        v[i] = 0;
}

bool comp(const string& s1, const string& s2)
{
    // Suppose s1 = 900, s2 = 9, then it compares
    // 9900 with 9009.
    return s2 + s1 < s1 + s2;
}
vector<string> split(const string& s, char delim) {
    vector<string> result;
    stringstream ss(s);
    string item;

    while (getline(ss, item, delim)) {
        result.push_back(item);
    }

    return result;
}
int countWords(string str)
{
    // breaking input into word using string stream 
    stringstream s(str); // Used for breaking words 
    string word; // to store individual words 

    int count = 0;
    while (s >> word)
        count++;
    return count;
}
ll power(ll x, ll y, ll p, int& c)
{
    int res = 1;     // Initialize result  
    if (x >= p)
        c++;
    x = x % p; // Update x if it is more than or  
                // equal to p 

    if (x == 0) return 0; // In case x is divisible by p; 

    while (y > 0)
    {
        // If y is odd, multiply x with result  
        if (y & 1)
        {
            if (res * x >= p)
                c++;
            res = (res * x) % p;
        }

        // y must be even now  
        y = y >> 1; // y = y/2  
        if (x * x >= p)
            c++;
        x = (x * x) % p;
    }
    return res;
}
bool isPalindrome(string str)
{
    // Start from leftmost and rightmost corners of str 
    int l = 0;
    int h = str.length() - 1;

    // Keep comparing characters while they are same 
    while (h > l)
    {
        if (str[l++] != str[h--])
        {

            return 0;
        }
    }
    return 1;
}
bool checkMuns(vector<int>vec)
{
    lp(i, vec.size())
    {
        if (vec[i] < 0)
            return 0;
    }
    return 1;
}
void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
ll power(ll x, ll y, ll p)
{
    ll res = 1;     // Initialize result  

    x = x % p; // Update x if it is more than or  
                // equal to p 

    if (x == 0) return 0; // In case x is divisible by p; 

    while (y > 0)
    {
        // If y is odd, multiply x with result  
        if (y & 1)
            res = (res * x) % p;

        // y must be even now  
        y = y >> 1; // y = y/2  
        x = (x * x) % p;
    }
    return res;
}
ll ceiLl(ll x, ll y)
{
    return (x + y - 1) / y;
}
vector<ll> divisors(ll n)
{
    vector<ll>ans;
    ll i = 1;
    for (; i * i < n; i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
            ans.push_back(n / i);
        }
    }
    if (i * i == n)
        ans.push_back(i);
    return ans;
}
vector<ll> findDivisors(ll n)//form 1 to n
{

    // Array to store the count 
    // of divisors 
    vector<ll> numFactors(n + 1);

    // For every number from 1 to n 
    for (int i = 1; i <= n; i++) {

        // Increase divisors count for 
        // every number divisible by i 
        for (int j = 1; j * i <= n; j++)
            numFactors[i * j]++;
    }

    return numFactors;
}
vector<ll> factorization(ll n) //     max n is 1e12
{     //O(sqrt(n))

    vector<ll> primes;

    for (ll i = 2; i * i <= n; ++i)    // Improve start by i = 3.
    {
        if (n % i == 0)
        {

            primes.push_back(i);
            while (n % i == 0)
            {
                n /= i;
            }
        } //Get every prime inside n.n  i^ j    is a new number
    }
    if (n > 1)
        primes.push_back(n);

    return primes;
}
bool isSubSeq(string a, string b)
{
    int idx = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == b[idx])
            idx++;
    }
    if (idx == b.length())
        return 1;
    else
        return 0;
}
bool isSubStr(string a, string b)
{

    for (int i = 0; i < a.length(); i++)
    {
        if (a.substr(i, b.length()) == b)
            return 1;
    }
    return 0;
}
bool sortbysec(const pair<int, int>& a,
    const pair<int, int>& b)
{
    return (a.second < b.second);
}
bool isEqual(string a, string b)
{
    if (a.size() != b.size())
        return 0;
    sort(vbe(a)); sort(vbe(b));
    if (a == b)
        return 1;
    return 0;
}
string bin(unsigned n)
{
    string ans = "";
    unsigned i;
    for (i = 1 << 14; i > 0; i = i / 2)
        (n & i) ? ans+='1' : ans+='0';
    return ans;
}




int ANS = 0;
int n, c;
vector<pair<int,int>>vec;
void gaser(int idx, int sum, int val)
{
    if (sum <= c)
    {
        ANS = max(ANS,val);
        
    }
    if (sum > c || idx >= n)
        return;
    gaser(idx + 1, sum + vec[idx].first,val+vec[idx].second);
    gaser(idx + 1, sum,val);
}
int main()
{
    fast();
    int t;
    t = 1;
   
    while (t--)
    {
        cin >> c;
        cin >> n;
        vec.resize(n);
        lp(i, n)
        {
            int a, b;
            cin >> a >> b;
            vec[i] = { a,b };
        }
        gaser(0, 0,0);
        cout << ANS;
        cout << "\n";
    }
    return 0;
}
//0 3 -2 5 -1
//-2 -1 0 3 5
// 0  1 2 3 4
/*
        std::cout << std::fixed;
    std::cout << std::setprecision(12);
*/