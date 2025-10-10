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
struct segmenttree {
  ll n;
  vll a;

  void init(ll n){
    this->n = n;
    a.resize(4 * n, 0);
  }

  ll comb(ll a, ll b){
    // change this 
    // also check return value of query fn
    return min(a, b);
  }

  void build(ll s, ll e, ll node, vll& nums){
    if(s == e){
      a[node] = nums[s];
      return ;
    }

    ll mid = s + (e - s) / 2;

    build(s, mid, 2 * node + 1, nums);
    build(mid + 1, e, 2 * node + 2, nums);

    a[node] = comb(a[2 * node + 1], a[2 * node + 2]);
  }
  void build(vll &nums){
    build(0, n - 1, 0, nums);
  }

  ll query(ll s, ll e, ll l, ll r, ll node){
    if(s > r || e < l) return LLONG_MAX;

    if(l <= s && e <= r){
      return a[node];
    }

    ll mid = s + (e - s) / 2;

    ll q1 = query(s, mid, l, r, 2 * node + 1);
    ll q2 = query(mid + 1, e, l, r, 2 * node + 2);

    return comb(q1, q2);
  }
  ll query(ll l, ll r){
    return query(0, n - 1, l, r, 0);
  }

  void update(ll s, ll e, ll idx, ll val, ll node){
    if(s == e){
      a[node] = val;
      return ;
    }

    ll mid = s + (e - s) / 2;
    if(idx <= mid){
      update(s, mid, idx, val, 2 * node + 1);
    }else{
      update(mid + 1, e, idx, val, 2 * node + 2);
    }

    a[node] = comb(a[2 * node + 1], a[2 * node + 2]);
  }
  void update(ll idx, ll val){
    update(0, n - 1, idx, val, 0);
  }
};
void solve(){
  ll n, q;
  cin >> n >> q;

  vll a(n);
  input(a);

  segmenttree st;
  st.init(n);
  st.build(a);

  for(int i = 0; i < q; i++){
    ll type;
    cin >> type;

    if(type == 1){
      ll k, u;
      cin >> k >> u;
      k--;

      st.update(k, u);
    }else{
      ll l, r;
      cin >> l >> r;
      l--;
      r--;

      ll min = st.query(l, r);
      print(min);
    }
  }
}
int main(){
  fastio
  solve();
}