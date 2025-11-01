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
template <typename T> void print(vector <T> &ans){for(auto &i : ans) cout<<i<<"\n"; cout<<"\n";}
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
  ll n;
  cin >> n;

  vvll adj(n);
  for(int i = 0; i < n - 1; i++){
    ll u, v;
    cin >> u >> v;
    u--;
    v--;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vll init(n);
  input(init);

  vll goal(n);
  input(goal);

  queue<vector<ll>> q;
  q.push({0, 0, 0}); // {node, flips on curr, flips on below}

  vll vis(n, 0);
  vis[0] = 1;

  vll ans;

  while(!q.empty()){
    ll size = q.size();
    for(int i = 0; i < size; i++){
      ll node = q.front()[0];
      ll currflips = q.front()[1];
      ll nextflips = q.front()[2];
      q.pop();
  
      ll currvalue = init[node];
      if(currflips) currvalue = 1 - currvalue;
  
      if(currvalue != goal[node]){
        ans.push_back(node + 1);
        currflips = 1 - currflips;
        nextflips = 1 - nextflips;
      }
  
      for(auto itr: adj[node]){
        if(!vis[itr]){
          q.push({itr, nextflips, currflips});
          vis[itr] = 1;
        }
      }
    }
  }

  print(ans.size());
  print(ans);
}
int main(){
  fastio
  solve();
}