#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

ll sum(const string &s) {
    ll res = 0;
    for (char c : s) res += (c - '0');
    return res;
}

int main() {
    fastio;
    int n;
    cin >> n;
    vector<string> tickets(n);
    for (auto &s : tickets) cin >> s;

    // Map to store counts of {length, sum}
    map<pair<int, int>, int> freq;

    for (const auto &s : tickets) {
        freq[{s.size(), sum(s)}]++;
    }

    ll ans = 0;

    // Try all pairs (i, j)
    for (const auto &s : tickets) {
        int len1 = s.size();
        int sum1 = sum(s);

        for (int len2 = 1; len2 <= 5; ++len2) {
            int total_len = len1 + len2;
            if (total_len % 2 != 0) continue;

            int half_len = total_len / 2;

            // We check whether s can be the prefix or suffix of a lucky ticket
            // Case 1: s is prefix
            if (len1 <= half_len && len2 >= total_len - len1) {
                int req_sum = sum1;
                pair<int, int> need = {total_len - len1, req_sum};
                ans += freq[need];
            }

            // Case 2: s is suffix
            if (len1 <= half_len && len2 >= total_len - len1) {
                int req_sum = sum1;
                pair<int, int> need = {total_len - len1, req_sum};
                ans += freq[need];
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
