// https://docs.google.com/document/d/1qWf_pj0W1ErpqUuo-fj3HJWj8U6GFik-IIWJ2zQ1Kwo/edit?tab=t.0
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
class DisjointSet{
  public:
  vector<int> parent, size;
  DisjointSet(int n){
      parent.resize(n + 1, 0);
      size.resize(n + 1, 1);
      for(int i = 0; i <= n; i++){
          parent[i] = i;
      }
  }
  int find(int node){
      if(parent[node] == node) return node;
      return parent[node] = find(parent[node]);
  }
  void unite(int u, int v){
      int uPar = find(u);
      int vPar = find(v);

      if(uPar == vPar) return ;
      if(size[uPar] < size[vPar]){
          parent[uPar] = vPar;
          size[vPar] += size[uPar];
      }else{
          parent[vPar] = uPar;
          size[uPar] += size[vPar];
      }
  }
};
void solve(){
  ll n;
  cin >> n;

  DisjointSet dsu(n);

  vvll a(n - 1);
  for(int i = 0; i < n - 1; i++){
    ll u, v, w;
    cin >> u >> v >> w;

    a[i] = {u, v, w};
  }

  auto cmp = [&](auto &a, auto &b){
    return a[2] > b[2];
  };
  sort(all(a), cmp);

  ll ans = 0;
  for(auto itr: a){
    ll u = itr[0];
    ll v = itr[1];
    ll w = itr[2];

    if(dsu.find(u) != dsu.find(v)){
      dsu.unite(u, v);
    }else{
      ans += w;
    }
  }
  print(ans);
}
int main(){
  fastio
  testcases {
    solve();
  }
}