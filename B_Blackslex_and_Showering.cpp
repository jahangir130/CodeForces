#include <bits/stdc++.h>
using namespace std;
 
// --Jahangir--BUBT_CSE_55_8--//

class BlackslexShowering {
    int n;
    vector<long long> a;

public:
    void read() {
        cin >> n;
        a.resize(n);
        for(int i = 0; i < n; i++) cin >> a[i];
    }

    long long solve() {
        long long total = 0;
        for(int i = 0; i + 1 < n; i++)
            total += llabs(a[i] - a[i + 1]);

        long long ans = total;

        for(int i = 0; i < n; i++){
            long long cur = total;
            if(i > 0) cur -= llabs(a[i] - a[i - 1]);
            if(i + 1 < n) cur -= llabs(a[i] - a[i + 1]);
            if(i > 0 && i + 1 < n) cur += llabs(a[i - 1] - a[i + 1]);
            ans = min(ans, cur);
        }

        return ans;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        BlackslexShowering solver;
        solver.read();
        cout << solver.solve() << '\n';
    }
    return 0;
}
