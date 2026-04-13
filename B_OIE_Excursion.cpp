#include <bits/stdc++.h>
using namespace std;

//--Jahangir--BUBT_CSE_55_8--//

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        long long m;
        cin >> n >> m;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int cnt = 1;
        bool ok = true;

        for (int i = 1; i < n; i++) {
            if (a[i] == a[i - 1]) cnt++;
            else cnt = 1;

            if (cnt >= m) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}