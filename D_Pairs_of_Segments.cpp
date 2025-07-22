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
vvll dp;
ll solve(ll idx, bool selected, const vector<pair<ll, ll>> &a, ll n, vvll &dp){
  if(idx == n) return 0;

  if(dp[idx][selected] != -1) return dp[idx][selected];

  ll ans = 0;
  if(selected){
    for(int j = idx + 1; j < n; j++){
      if(a[idx].second >= a[j].first){
        ll k = j + 1;
        while(k < n && a[k].first <= max(a[idx].second, a[j].second)) k++;

        ans = max(ans, 2LL + max(solve(k, 1, a, n, dp), solve(k, 0, a, n, dp)));
      }
    }
  }else{
    ans = max(solve(idx + 1, 1, a, n, dp), solve(idx + 1, 0, a, n, dp));
  }

  return dp[idx][selected] = ans;
}
void solve(){
  ll n;
  cin >> n;

  vector<pair<ll, ll>> a(n);
  for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
  sort(all(a));

  vvll dp(n, vll(2, -1));

  ll ans = n - max(solve(0, 0, a, n, dp), solve(0, 1, a, n, dp));
  print(ans);
}
int main(){
  fastio
  testcases{
    solve();
  }
}