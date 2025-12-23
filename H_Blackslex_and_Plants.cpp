#include <bits/stdc++.h>
using namespace std;
 
// --Jahangir--BUBT_CSE_55_8--//

class Plants {
    int n, q;
    vector<long long> water;

    long long f(long long x){
        return x * (x & -x);
    }

public:
    void read(){
        cin >> n >> q;
        water.assign(n + 1, 0);
        while(q--){
            int l, r;
            cin >> l >> r;
            for(int i = l; i <= r; i++)
                water[i] += f(i - l + 1);
        }
    }

    void output(){
        for(int i = 1; i <= n; i++)
            cout << water[i] << (i == n ? '\n' : ' ');
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        Plants p;
        p.read();
        p.output();
    }
    return 0;
}
