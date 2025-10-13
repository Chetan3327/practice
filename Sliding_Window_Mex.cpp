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
  ll n, k;
  cin >> n >> k;

  vll a(n);
  input(a);

  map<ll, ll> freq;

  set<ll> st;
  for(int i = 0; i <= n; i++) st.insert(i); // so this will tell us, which element we don't have => mex

  for(int i = 0; i < n; i++){
    if(freq[a[i]] == 0) st.erase(a[i]); // as we now have this element this can be our mex
    freq[a[i]]++;

    if(i >= k){
      freq[a[i - k]]--;
      if(freq[a[i - k]] == 0) st.insert(a[i - k]); // ok so we dont have this element now, so it might become mex
    }

    if(i >= k - 1){
      ll mex = *st.begin(); // smallest missing no is mex
      cout << mex << sp;
    } 
  }
}
int main(){
  fastio
  solve();
}