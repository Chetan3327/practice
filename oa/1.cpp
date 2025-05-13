#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  
  vector<string> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  vector<string> ans;
  for(int i = 0; i < n; i++){
    string temp = string(1, a[i][0]);
    if(i == n - 1){
      temp += a[0].back();
    }else{
      temp += a[i + 1].back();
    }
    ans.push_back(temp);
  }

  for(auto itr: ans){
    cout << itr << " ";
  }
  cout << endl;
}