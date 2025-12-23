#include <bits/stdc++.h>
using namespace std;
 
// --Jahangir--BUBT_CSE_55_8--//

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin>>t)) return 0;
    while(t--){
        long long k,x;
        cin>>k>>x;
        cout << k*x + 1 << '\n';
    }
    return 0;
}
