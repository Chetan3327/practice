#include <bits/stdc++.h>
using namespace std;

vector<int> countAdjacentSameColor(int length, vector<vector<int>>& queries) {
  unordered_map<int, int> mp;
  int c = 0;

  vector<int> ans;
  for(auto query: queries){
    int idx = query[0], color = query[1];

    if (mp.count(idx)) {
        int prev = mp[idx];
        if (mp.count(idx - 1) && mp[idx - 1] == prev) c--;
        if (mp.count(idx + 1) && mp[idx + 1] == prev) c--;
    }

    mp[idx] = color;

    if (mp.count(idx - 1) && mp[idx - 1] == color) c++;
    if (mp.count(idx + 1) && mp[idx + 1] == color) c++;

    ans.push_back(c);
  }

  return ans;
}

int main() {
    int length, q;
    cin >> length >> q;
    vector<vector<int>> queries(q, vector<int>(2));
    for (int i = 0; i < q; ++i) {
        cin >> queries[i][0] >> queries[i][1];
    }

    vector<int> result = countAdjacentSameColor(length, queries);
    for (int val : result) {
        cout << val << "\n";
    }

    return 0;
}
