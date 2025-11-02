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

  vvll a(n, vll(m));
  input(a);

  auto check = [&](ll mid){
    vvll b(n, vll(m, 0));
    for(ll i = 0; i < n; i++){
      for(ll j = 0; j < m; j++){
        b[i][j] = (a[i][j] >= mid);
      }
    }

    vvll pre(n + 1, vll(m + 1, 0));
    for(ll i = 1; i <= n; i++){
      for(ll j = 1; j <= m; j++){
        pre[i][j] = b[i - 1][j - 1] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
      }
    }

    for(ll x1 = 1; x1 <= n; x1++){
      for(ll y1 = 1; y1 <= m; y1++){
        ll x2 = x1 + mid - 1;
        ll y2 = y1 + mid - 1;

        if(x2 > n || y2 > m) continue;
        ll sum = pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1];
        if(sum == mid * mid) return true;
      }
    }

    return false;
  };

  ll l = 1;
  ll r = 1e6;

  ll ans = l;
  while(l <= r){
    ll mid = l + (r - l) /  2;

    if(check(mid)){
      ans = mid;
      l = mid + 1;
    }else{
      r = mid - 1;
    }
  }
  print(ans);
}
int main(){
  fastio
  testcases{
    solve();
  }
}