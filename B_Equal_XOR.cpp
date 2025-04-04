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
void solve(){
  ll n, k;
  cin >> n >> k;

  vll a(2 * n);
  input(a);

  vll single, l, r;
  map<ll, ll> mpl, mpr;
  for(int i = 0; i < n; i++){
    mpl[a[i]]++;
  }
  for(int i = n; i < 2 * n; i++){
    mpr[a[i]]++;
  }

  for(auto itr: mpl){
    if(itr.second == 2){
      l.push_back(itr.first);
    }else{
      single.push_back(itr.first);
    }
  }

  for(auto itr: mpr){
    if(itr.second == 2){
      r.push_back(itr.first);
    }
  }

  // print(l);
  // print(r);
  // print(single);


  vll ansl, ansr;
  for(int i = 0; i < min({l.size(), r.size(), (size_t)k}); i++){
    ansl.push_back(l[i]);
    ansl.push_back(l[i]);
    ansr.push_back(r[i]);
    ansr.push_back(r[i]);
  }

  for(int i = 0; i < single.size(); i++){
    if(ansl.size() == 2 * k) break;
    ansl.push_back(single[i]);
    ansr.push_back(single[i]);
  }

  print(ansl);
  print(ansr);
}
int main(){
  fastio
  testcases {
    solve();
  }
}