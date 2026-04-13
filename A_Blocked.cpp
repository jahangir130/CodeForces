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
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());

        bool ok = true;
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i - 1]) {
                ok = false;
                break;
            }
        }

        if (!ok) {
            cout << -1 << '\n';
        } else {
            for (int i = n - 1; i >= 0; i--) {
                cout << a[i] << (i ? ' ' : '\n');
            }
        }
    }

    return 0;
}