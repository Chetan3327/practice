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
  
  vector<string> a(n);
  input(a);

  // block all B
  ll g = 0;
  for(int x = 0; x < n; x++){
    for(int y = 0; y < m; y++){
      g += (a[x][y] == 'G');
      if(a[x][y] == 'B'){
        for(auto dir: dirs){
          ll nx = x + dir.first;
          ll ny = y + dir.second;

          if(nx >= 0 && nx < n && ny >= 0 && ny < m){
            if(a[nx][ny] == 'G'){
              print("No");
              return;
            }

            if(a[nx][ny] == '.'){
              a[nx][ny] = '#';
            }
          }
        }
      }
    }
  }

  // check if all G can escape
  queue<pair<ll, ll>> q;
  vvll vis(n, vll(m, 0));
  if(a[n - 1][m - 1] == '#'){
    if(g){
      print("No");
      return;
    }
  }

  q.push({n - 1, m - 1});
  vis[n - 1][m - 1] = 1;
  
  while(!q.empty()){
    ll size = q.size();
    for(int i = 0; i < size; i++){
      ll x = q.front().first;
      ll y = q.front().second;
      q.pop();
      
      vis[x][y] = 1;

      for(auto dir: dirs){
        ll nx = x + dir.first;
        ll ny = y + dir.second;

        if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && a[nx][ny] != '#'){
          if(a[nx][ny] == 'G'){
            g--;
          }

          q.push({nx, ny});
          vis[nx][ny] = 1;
        }
      }
    }
  }

  if(g == 0){
    print("Yes");
  }else{
    print("No");
  }
}
int main(){
  fastio
  testcases{
    solve();
  }
}