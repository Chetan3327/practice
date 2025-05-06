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
  string a;
  cin >> a;

  string b;
  cin >> b;

  ll n = a.size();

  ll t, qc;
  cin >> t >> qc;

  ll c = 0;
  for(int i = 0; i < n; i++) c += (a[i] != b[i]);

  queue<pair<ll, ll>> q;
  ll time = 0;
  while(qc--){
    time++;

    // release blocks
    while(!q.empty() && q.front().second <= time){
      int idx = q.front().first;
      q.pop();

      c += (a[idx] != b[idx]);
    }

    ll type;
    cin >> type;

    if(type == 1){
      ll idx;
      cin >> idx;
      idx--;
      // block idx from both strings 

      c -= (a[idx] != b[idx]);
      q.push({idx, time + t});
    }else if(type == 2){
      ll s1, idx1, s2, idx2;
      cin >> s1 >> idx1 >> s2 >> idx2;
      idx1--;
      idx2--;

      c -= (a[idx1] != b[idx1]);
      c -= (a[idx2] != b[idx2]);

      if(s1 == s2){
        if(s1 == 1){
          swap(a[idx1], a[idx2]);
        }else{
          swap(b[idx1], b[idx2]);
        }
      }else{
        if(s1 == 2){
          swap(idx1, idx2);
        }
        swap(a[idx1], b[idx2]);
      }

      c += (a[idx1] != b[idx1]);
      c += (a[idx2] != b[idx2]);
    }else if(type == 3){
      if(c == 0){
        print("YES");
      }else{
        print("NO");
      }
    }
  }
}
int main(){
  fastio
  testcases {
    solve();
  }
}