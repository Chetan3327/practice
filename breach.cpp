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
  ll n, m, k;
  cin >> n >> m >> k;

  vvll a(n, vll(m));
  input(a);
  
  vvll vis(n, vll(m, 0));
  queue<tuple<ll, ll, ll>> q;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(a[i][j] == 0){
        q.push({i, j, k});
        vis[i][j] = 1;
      }
    }
  }

  while(!q.empty()){
    auto node = q.front();
    ll x = get<0>(node);
    ll y = get<1>(node);
    ll dist = get<2>(node);
    q.pop();
    
    if(dist == 0) continue;
    for(auto dir: dirs){
      ll nx = x + dir.first;
      ll ny = y + dir.second;

      if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]){
        vis[nx][ny] = 1;
        a[nx][ny] = 0;
        q.push({nx, ny, dist - 1});
      }
    }
  }

  vvll dp(n, vll(m, 0));
  dp[0][0] = 1;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(a[i][j] == 0){
        dp[i][j] = 0;
      }else{
        dp[i][j] += (i > 0 ? dp[i - 1][j] : 0);
        dp[i][j] += (j > 0 ? dp[i][j - 1] : 0);
      }
    }
  }
  print(dp[n - 1][m - 1]);
}
int main(){
  fastio
  solve();
}