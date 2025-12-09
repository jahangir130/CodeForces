#include <bits/stdc++.h>
using namespace std;
 
// --Jahangir--BUBT_CSE_55_8--//

struct Op {
    int l, r;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAXL = 7;
    vector<vector<vector<vector<Op>>>> trans(MAXL + 1);

    for (int L = 4; L <= MAXL; L++) {
        int S = 1 << L;
        trans[L].assign(S, vector<vector<Op>>(S));
        vector<vector<pair<int, Op>>> adj(S);

        for (int x = 0; x < S; x++) {
            vector<int> bits(L);
            for (int i = 0; i < L; i++) bits[i] = (x >> i) & 1;

            for (int l = 0; l < L - 1; l++) {
                for (int r = l + 1; r < L; r++) {
                    bool ok = true;
                    int i = l, j = r;
                    while (i < j) {
                        if (bits[i] != bits[j]) { ok = false; break; }
                        i++; j--;
                    }
                    if (!ok) continue;
                    int mask = ((1 << (r - l + 1)) - 1) << l;
                    int y = x ^ mask;
                    adj[x].push_back({y, {l, r}});
                }
            }
        }

        for (int s0 = 0; s0 < S; s0++) {
            vector<int> dist(S, -1), par(S, -1);
            vector<Op> parOp(S);
            queue<int> q;
            dist[s0] = 0;
            q.push(s0);

            while (!q.empty()) {
                int v = q.front(); q.pop();
                for (auto &e : adj[v]) {
                    int u = e.first;
                    if (dist[u] == -1) {
                        dist[u] = dist[v] + 1;
                        par[u] = v;
                        parOp[u] = e.second;
                        q.push(u);
                    }
                }
            }

            for (int t = 0; t < S; t++) {
                vector<Op> path;
                int v = t;
                while (v != s0) {
                    Op o = parOp[v];
                    path.push_back(o);
                    v = par[v];
                }
                reverse(path.begin(), path.end());
                trans[L][s0][t] = path;
            }
        }
    }

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        string s, t;
        cin >> n >> s >> t;

        if (s == t) {
            cout << 0 << '\n';
            continue;
        }

        vector<int> cur(n);
        for (int i = 0; i < n; i++) cur[i] = s[i] - '0';
        vector<Op> ans;

        int pos = 0;
        while (n - pos > 7) {
            int L = 4;
            int s_state = 0, t_state = 0;
            for (int i = 0; i < L; i++) {
                if (cur[pos + i]) s_state |= 1 << i;
                if (t[pos + i] == '1') t_state |= 1 << i;
            }
            auto &path = trans[L][s_state][t_state];
            for (auto o : path) {
                ans.push_back({pos + o.l + 1, pos + o.r + 1});
                for (int k = o.l; k <= o.r; k++) cur[pos + k] ^= 1;
            }
            pos += 4;
        }

        int L = n - pos;
        if (L > 0) {
            int s_state = 0, t_state = 0;
            for (int i = 0; i < L; i++) {
                if (cur[pos + i]) s_state |= 1 << i;
                if (t[pos + i] == '1') t_state |= 1 << i;
            }
            auto &path = trans[L][s_state][t_state];
            for (auto o : path) {
                ans.push_back({pos + o.l + 1, pos + o.r + 1});
                for (int k = o.l; k <= o.r; k++) cur[pos + k] ^= 1;
            }
        }

        bool ok = true;
        for (int i = 0; i < n; i++) if (cur[i] != t[i] - '0') ok = false;
        if (!ok || (int)ans.size() > 2 * n) {
            cout << -1 << '\n';
            continue;
        }

        cout << ans.size() << '\n';
        for (auto &o : ans) cout << o.l << ' ' << o.r << '\n';
    }

    return 0;
}
