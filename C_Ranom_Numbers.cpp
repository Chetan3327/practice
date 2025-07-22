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
vll a = {1, 10, 100, 1000, 10000};
ll dp[200005][6][2];
ll solve(ll idx, ll maxsofar, bool canChange, string &s){
  if(idx == -1) return 0;
  
  if(dp[idx][maxsofar][canChange] != -1) return dp[idx][maxsofar][canChange];

  ll ans = LLONG_MIN;
  if(a[s[idx] - 'A'] < a[maxsofar]){
    ans = max(ans, -1 * a[s[idx] - 'A'] + solve(idx - 1, maxsofar, canChange, s));
  }else{
    ans = max(ans, a[s[idx] - 'A'] + solve(idx - 1, s[idx] - 'A', canChange, s));
  }

  if(canChange){
    for(int ch = 0; ch < 5; ch++){
      if(ch != (s[idx] - 'A')){
        if(a[ch] < a[maxsofar]){
          ans = max(ans, -a[ch] + solve(idx - 1, maxsofar, 0, s));
        }else{
          ans = max(ans, a[ch] + solve(idx - 1, ch, 0, s));
        }
      }
    }
  }

  return dp[idx][maxsofar][canChange] = ans;
}
void solve(){
  string s;
  cin >> s;

  ll n = s.size();

  // memset(dp, -1, sizeof(dp));
  for (ll i = 0; i <= n; i++) for (int j = 0; j < 6; j++) for (int k = 0; k < 2; k++) dp[i][j][k] = -1;

  ll ans = solve(n - 1, 0, 1, s);
  print(ans);
}
int main(){
  fastio
  testcases{
    solve();
  }
}