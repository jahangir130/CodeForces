#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;
    string X;
    cin >> X;

    int k = 0;
    for (char c : X) {
        if (c == '0') k++;
    }

    // Indices are 1-based for the problem logic
    vector<int> s1, s2, s3, s4;
    for (int i = 0; i < N; ++i) {
        int idx = i + 1;
        int val = X[i] - '0';
        if (idx <= k) {
            if (val == 0) s1.push_back(idx); // 0 in L (Happy)
            else s2.push_back(idx);          // 1 in L (Anomaly)
        } else {
            if (val == 0) s3.push_back(idx); // 0 in R (Anomaly)
            else s4.push_back(idx);          // 1 in R (Happy)
        }
    }

    // Case 0: Already sorted
    if (s2.empty()) {
        cout << 0 << "\n";
        return;
    }

    // Case 1: Can be done in 1 op
    // Possible if we don't have BOTH s1 and s4 present
    if (s1.empty() || s4.empty()) {
        cout << 1 << "\n";
        string ans(N, 'B'); 
        // Group A takes the anomalies S2 and S3
        for (int x : s2) ans[x - 1] = 'A';
        for (int x : s3) ans[x - 1] = 'A';
        // If s1 is empty, s4 (Happy) is in B.
        // If s4 is empty, s1 (Happy) is in B.
        cout << ans << "\n";
        return;
    }

    // Case 2: Needs 2 ops
    cout << 2 << "\n";
    
    // Op 1: Create Reverse Sorted state (11...100...0)
    // Group A: S1 + S2 + S4
    // Group B: S3
    string ans1(N, 'A');
    for (int x : s3) ans1[x - 1] = 'B';
    cout << ans1 << "\n";

    // Op 2: Reverse All to get Sorted state
    // Group A: All
    string ans2(N, 'A');
    cout << ans2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}