#include <bits/stdc++.h>
using namespace std;
 
// --Jahangir--BUBT_CSE_55_8--//

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> a(n);
        for(int i=0;i<n;i++) 
        cin >> a[i];

        sort(a.begin(), a.end());

        long long g = 0;
        for(int i=1;i<n;i++)
            g =gcd(g, a[i] - a[0]);

        cout << g << '\n';
    }
    return 0;
}
