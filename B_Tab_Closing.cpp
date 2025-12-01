#include <bits/stdc++.h>
using namespace std;
 
// --Jahangir--BUBT_CSE_55_8--//

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long a, b, n;
        cin >> a >> b >> n;
        long long nb = n * b;
        if (a == b || nb <= a) cout << 1 << '\n';
        else cout << 2 << '\n';
    }
    return 0;
}
