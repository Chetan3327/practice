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
void solve(){
  ll n, m;
  cin >> n >> m;
  
  vll a(n);
  input(a);

  set<ll> st;

  ll l = 0;
  ll r = n / 2 - 1;

  ll len = r - l + 1;
  for(int mask = 0; mask < (1 << len); mask++){
    ll sum = 0;
    for(int i = 0; i < len; i++){
      if(mask & (1 << i)){
        sum += a[i + l];
        sum %= m;
      }
    }
    st.insert(sum);
  }

  
  l = n / 2;
  r = n - 1;

  len = r - l + 1;

  set<ll> st2;

  ll ans = *st.rbegin();
  for(int mask = 0; mask < (1 << len); mask++){
    ll sum = 0;
    for(int i = 0; i < len; i++){
      if(mask & (1 << i)){
        sum += a[i + l];
        sum %= m;
      }
    }

    st2.insert(sum);
  }

  ans = max(ans, *st2.rbegin());

  for(auto first: st){
    auto itr = st2.lower_bound(m - first);
    ll second = *prev(itr);

    ans = max(ans, (first + second) % m);
    if(!st2.empty()){
      ans = max(ans, (first + *st2.rbegin()) % m);
    }
  }
  
  print(ans);
}
int main(){
  fastio
  solve();
}