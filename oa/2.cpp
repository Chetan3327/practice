#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  vector<int> b(m);
  for(int j = 0; j < m; j++){
    cin >> b[j];
  }

  int ans = 0;
  for(int i = 0; i <= n - m - 1; i++){
    bool matching = true;
    for(int j = 0; j < m; j++){
      int diff = a[i + j + 1] - a[i + j];
      if((b[j] == 1 && diff <= 0) || 
         (b[j] == 0 && diff != 0) ||
         (b[j] == -1 && diff >= 0)){
          matching = false;
          break;
      }
    }
    if(matching) ans++;
  }
  cout << ans << endl;
}