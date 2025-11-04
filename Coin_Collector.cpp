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

  vll a(n + 1);
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  
  vvll adj(n + 1);
  vvll radj(n + 1);
  for(int i = 0; i < m; i++){
    ll u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    radj[v].push_back(u);
  }

  stack<ll> st;
  vll vis(n + 1);

  function<void(ll)> dfs = [&](ll node){
    vis[node] = 1;

    for(auto itr: adj[node]){
      if(!vis[itr]){
        dfs(itr);
      }
    }

    st.push(node);
  };

  for(int i = 1; i <= n; i++){
    if(!vis[i]) dfs(i);
  }

  vis.assign(n + 1, 0);
  vll color(n + 1, 0);
  ll c = 0;

  function<void(ll, ll c)> dfs2 = [&](ll node, ll c){
    vis[node] = 1;
    color[node] = c;

    for(auto itr: radj[node]){
      if(!vis[itr]){
        dfs2(itr, c);
      }
    }
  };

  while(!st.empty()){
    ll node = st.top();
    st.pop();

    if(!vis[node]){
      c++;
      dfs2(node, c);
    }
  }

  vvll nadj(c + 1);
  vll coins(c + 1, 0);

  for(int i = 1; i <= n; i++){
    coins[color[i]] += a[i];
    for(auto itr: adj[i]){
      if(color[i] != color[itr]){
        nadj[color[i]].push_back(color[itr]);
      }
    }
  }

  vll dp(c + 1, -1);
  function<ll(ll)> dfs3 = [&](ll node){
    if(dp[node] != -1) return dp[node];

    ll ans = 0;
    for(auto itr: nadj[node]){
      ans = max(ans, dfs3(itr));
    }
    return dp[node] = coins[node] + ans;
  };

  ll ans = 0;
  for(int i = 1; i <= c; i++){
    ans = max(ans, dfs3(i));
  }
  print(ans);
}
int main(){
  fastio
  solve();
}