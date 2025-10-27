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
#define MOD 998244353
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
const int MAX = 1e6 + 5;
int fact[MAX], inv_fact[MAX];
bool isFactInit = false;
void precompute_factorials() {
  isFactInit = true;
  fact[0] = inv_fact[0] = 1;
  for (int i = 1; i < MAX; i++) {
    fact[i] = 1LL * fact[i - 1] * i % MOD;
  }
  inv_fact[MAX - 1] = expo(fact[MAX - 1], MOD - 2, MOD);
  for (int i = MAX - 2; i >= 1; i--) {
    inv_fact[i] = 1LL * inv_fact[i + 1] * (i + 1) % MOD;
  }
}
int combination(int n, int r) {
  if (!isFactInit) precompute_factorials();
  if (r < 0 || r > n) return 0;
  return 1LL * fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}
int permutation(int n, int r) {
  if (!isFactInit) precompute_factorials();
  if (r < 0 || r > n) return 0;
  return 1LL * fact[n] * inv_fact[n - r] % MOD;
}
void solve(){
  ll n;
  cin >> n;
  
  vll a(n);
  input(a);

  ll ans = 1;
  for(int i = 0; i < n; i += 3){
    vll b = {a[i], a[i + 1], a[i + 2]};
    sort(all(b));
    
    if(b[0] == b[2]){
      ans = mod_mul(ans, 3LL, MOD);
    }else if(b[0] == b[1]){
      ans = mod_mul(ans, 2LL, MOD);
    }else{
      ans = mod_mul(ans, 1LL, MOD);
    }
  }

  ans = mod_mul(ans, combination(n / 3, n / 6), MOD);
  print(ans);
}
int main(){
  fastio
  solve();
}