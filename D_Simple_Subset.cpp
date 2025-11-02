#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define ll long long
#define ld long double
#define endl "\n"
#define sp " "
#define testcases ll ts; cin >> ts; for(ll tsno = 1; tsno <= ts; tsno++)
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template <typename T> void input(vector<T> &a){for(auto &e: a) cin >> e;}
template <typename T> void input(vector<vector<T>> &a){for(auto &r: a) for(auto &c: r) cin >> c;}
template <typename T> void print(T ans){cout<<ans<<"\n";}
template <typename T> void print(vector <T> &ans){for(auto &i : ans) cout<<i<<" "; cout<<"\n";}
template <typename T> void print(vector <vector<T>> &ans){for(auto &i : ans) {{for(auto &j: i) cout<<j<<" ";} cout<<"\n";}}
#define MOD 1000000007
ll floor(ll a, ll b) {ll c = a / b; if (a % b != 0 && ((a < 0 && b > 0) || (a > 0 && b < 0))) c--; return c;}
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll mod_add(ll a, ll b, ll m){a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m){a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m){a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}
ll ceil_div(ll a, ll b) {return a / b + ((a ^ b) > 0 && a % b != 0);}
vector<pair<ll, ll>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<bool> prime;
void generatePrimes() {
    const int N = 2e6;
    if (!prime.empty()) return;
    prime.resize(N + 1, 1);
    prime[0] = prime[1] = 0;
    for (int i = 2; i <= N; i++) {
        if (prime[i]) {
            for (int j = 2 * i; j <= N; j += i) {
                prime[j] = 0;
            }
        }
    }
}
void solve(){
  ll n;
  cin >> n;
  
  vll a(n);
  input(a);
  
  map<ll, ll> mp;
  for(auto &e: a) mp[e]++;

  sort(all(a));
  a.erase(unique(a.begin(), a.end()), a.end());

  ll maxsize = 0;

  ll L = 0;
  ll R = 0;
  ll c = 0;
  ll d = 0;

  ll m = a.size();
  for(int i = 0; i < m; i++){
    for(int j = i + 1; j < m; j++){
      ll sum = a[i] + a[j];
      if(!prime[sum]) continue;

      ll c1 = prime[a[i] + a[i]] ? mp[a[i]] : 1;
      ll c2 = prime[a[j] + a[j]] ? mp[a[j]] : 1;
      
      if(c1 + c2 > maxsize){
        maxsize = c1 + c2;
        c = c1;
        L = a[i];
        d = c2;
        R = a[j];
      }
    }
  }

  
  for(int i = 0; i < n; i++){
    ll c1 = 1;
    if(c1 > maxsize){
      maxsize = c1;
      c = c1;
      L = a[i];
    }

    if(!prime[a[i] + a[i]]) continue;
    ll c2 = mp[a[i]];
    if(c2 > maxsize){
      maxsize = c2;
      c = c2;
      L = a[i];
    }
  }

  if(mp.count(1LL)){
    for(auto &e: a){
      if(!prime[e + 1]) continue;
      ll c1 = 1;
      ll c2 = mp[1];
      
      if(c1 + c2 > maxsize){
        maxsize = c1 + c2;
        c = c1;
        L = e;
        d = c2;
        R = 1;
      }
    }
  }

  print(maxsize);
  vll ans;
  while(c--) ans.push_back(L);
  while(d--) ans.push_back(R);
  print(ans);
}
int main(){
  fastio
  generatePrimes();
  solve();
}