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
vector<vector<vector<ll>>> dp;
ll dfs(ll idx, ll curr, bool isTight, const string &s, ll n, ll d){
  if(idx == n){
    return (curr == 0);
  }
  if(dp[idx][curr][isTight] != -1) return dp[idx][curr][isTight];

  ll ans = 0;

  if(isTight){
    for(int digit = 0; digit <= (s[idx] - '0'); digit++){
      ans = (ans + dfs(idx + 1, (curr + digit) % d, (digit == (s[idx] - '0')), s, n, d)) % MOD;
    }
  }else{
    for(int digit = 0; digit <= 9; digit++){
      ans = (ans + dfs(idx + 1, (curr + digit) % d, 0, s, n, d)) % MOD;
    }
  }

  return dp[idx][curr][isTight] = ans;
}
void solve(){
  string k;
  cin >> k;

  ll n = k.size();
  
  ll d;
  cin >> d;

  dp.resize(n + 1, vvll(d + 1, vll(2, -1)));
  ll ans = dfs(0, 0, 1, k, n, d);  
  ans = (ans - 1LL + MOD) % MOD;
  print(ans);
}
int main(){
  fastio
  solve();
}