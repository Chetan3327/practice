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
vll ans;
bool cycle = false;
void dfs(ll node, ll par, vll &vis, vll &parent, vll &depth, const vvll &adj, ll k){
  vis[node] = 1;
  parent[node] = par;

  for(auto itr: adj[node]){
    if(cycle) return;
    if(itr == par) continue;

    ll len = depth[node] - depth[itr];
    if(!vis[itr]){
      depth[itr] = 1 + depth[node];
      dfs(itr, node, vis, parent, depth, adj, k);
    }else if(len + 1 >= k + 1){
      cycle = true;
      vll path;
      
      ll curr = node;
      while(curr != itr){
        path.push_back(curr);
        curr = parent[curr];
      }
      path.push_back(itr);
      reverse(all(path));
      ans = path;
    }
  }
}
void solve(){
  ll n, m, k;
  cin >> n >> m >> k;
  
  vvll adj(n + 1);
  for(int i = 0; i < m; i++){
    ll u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vll vis(n + 1, 0);
  vll parent(n + 1, -1);
  vll depth(n + 1, 0);
  dfs(1, 1, vis, parent, depth, adj, k);

  print(ans.size());
  print(ans);
}
int main(){
  fastio
  solve();
}